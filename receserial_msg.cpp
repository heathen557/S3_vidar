#include "receserial_msg.h"

receSerial_msg::receSerial_msg(QObject *parent) : QObject(parent)
{

    qDebug()<<" the thread begin "<<endl;
    sample_range = 1;
    ratio = 1;
    tof_offset = 0;
    isTranslateFlag = true;
    peak_disp_mode = true;

    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readDataSlot()),Qt::DirectConnection);

}

void receSerial_msg::readDataSlot()
{
    QByteArray temp = serial->readAll();
    QString strHex;//16进制数据

    if (!temp.isEmpty())
    {
        QDataStream out(&temp,QIODevice::ReadWrite);
        while (!out.atEnd())
        {
            qint8 outChar=0;
            out>>outChar;
            QString str=QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));

            if (str.length()>1)
            {
                strHex+=str+" ";
            }
            else
            {
                strHex+="0"+str+" ";
            }
        }
        strHex = strHex.toUpper();
        qDebug()<<" strHex = "<<strHex;
        return;

        m_buffer.append(strHex);
        int totallen = m_buffer.size();

        if(isTranslateFlag)    //转换成十进制的tof和peak进行显示解析
        {
            while(totallen)
            {
                if(totallen <27)
                    return;

               int indexOf5A = m_buffer.indexOf("5A 03 04 00 ",0);
               if(indexOf5A < 0)  //没有找到5A
               {
                   qDebug()<<QString::fromUtf8("接收数据有误，不存在5A")<<"index ="<<indexOf5A<<"buffer"<<m_buffer<<endl;
                   return;
               }else if(indexOf5A>0)  //第一次的时候前面会有冗余数据，删掉
               {
                   m_buffer = m_buffer.right(totallen-indexOf5A);
                   totallen = m_buffer.size();
                   if(totallen <27)
                       return;
               }

               //以下数据为5A打头数据

               //进行和校验
               QString single_Data = m_buffer.left(27);
               if(!msgCheck(single_Data))
                    return;

               //获取角度信息
               QString angle_str_ = single_Data.mid(12,5);
               angle_str_ = angle_str_.replace(" ", "");
               QString s1=angle_str_[0];
               QString s2=angle_str_[1];
               QString s3=angle_str_[2];
               QString s4=angle_str_[3];
               QString angle_str = s3+s4+s1+s2;
               int TOF = angle_str.toInt(NULL,16);
    //           qDebug()<<"角度"<<QString::number(angleInt);

               //获取距离信息(mm)
               QString distance_str_ = single_Data.mid(18,5);
               distance_str_ = distance_str_.replace(" ", "");
               s1=distance_str_[0];
               s2=distance_str_[1];
               s3=distance_str_[2];
               s4=distance_str_[3];
               QString distance_str = s3+s4+s1+s2;
               int PEAK = distance_str.toInt(NULL,16);
    //           qDebug()<<"距离"<<QString::number(distanceInt);


               //sample_range 样本的个数
               //向每个点的容器中添加一个新的点,完成循环存储
               int offset = tofPeak_vector.size() - 2*sample_range;
               if(offset >= 0)
               {
                   tofPeak_vector.erase(tofPeak_vector.begin(),tofPeak_vector.begin()+offset + 2);    //减去两个本身就存在的点
               }
               tofPeak_vector.push_back(TOF);
               tofPeak_vector.push_back(PEAK);


               //对样本的tof、peak取均值
               int sum_tof = 0;
               int sum_peak = 0;
               int len = tofPeak_vector.size();
               for(int ii=0; ii<len; ii+=2)
               {
                   sum_tof += tofPeak_vector[ii];
                   sum_peak += tofPeak_vector[ii+1];
               }
               TOF = sum_tof/(len/2);
               PEAK = sum_peak/(sum_peak/2);

               float result = (TOF - tof_offset) *ratio;
               result = result<0 ? 0:result;


               //PlotData_vector 对20000帧tof数据进行循环存储
               int Plot_offset = PlotData_vector.size() - 20000;
               if(Plot_offset >= 0)
               {
                   PlotData_vector.erase(PlotData_vector.begin(),PlotData_vector.begin()+Plot_offset + 1);
               }
               PlotData_vector.push_back(result);


               //StatisticData_vector 对1000帧数据进行循环存储
               int statistic_offset = StatisticData_vector.size() -1000;
               if(statistic_offset >= 0)
               {
                   StatisticData_vector.erase(StatisticData_vector.begin(),StatisticData_vector.begin() + statistic_offset + 1);
               }
               StatisticData_vector.push_back(result);


               QString DistanceStrCurrent = QString::number(result);
//             QString DistanceStrCurrent = QString("%1").arg(result,10,10,QChar(' '));
               if(peak_disp_mode)   //显示tof 和peak的值
               {
//                   QString tofpeakStr = DistanceStrCurrent.append( QString("%1").arg(PEAK,8,10,QChar(' ')) );
                   QString tofPeakStr = DistanceStrCurrent + "       " +QString::number(PEAK) +"\r\n";     //加入换行字符
                   DistanceStr.append(tofPeakStr);

               }else            //只显示tof的值
               {
                   QString tmpStr = DistanceStrCurrent + "\r\n";    //加入换行字符
                   DistanceStr.append(tmpStr);
               }



               m_buffer = m_buffer.right(totallen - 27);   //一帧处理完毕 减去该帧的长度
               totallen = m_buffer.size();
    //         qDebug()<<"total ="<<totallen<<endl;
            }
        }
        else   //直接打印16进制的数据
        {
                DistanceStr.append(m_buffer);
                m_buffer.clear();
                totallen = m_buffer.size();
        }

    }
}

bool receSerial_msg::msgCheck(QString msg)
{
    QString str1 = msg.mid(3,2);
    QString str2 = msg.mid(6,2);
    QString str3 = msg.mid(9,2);
    QString str4 = msg.mid(12,2);
    QString str5 = msg.mid(15,2);
    int num = str1.toInt(NULL,16)+str2.toInt(NULL,16)+str3.toInt(NULL,16)+str4.toInt(NULL,16);
    if(quint8(~num) == str5.toInt(NULL,16))
    {
        return true;
    }else
    {
        return false;
    }
}




