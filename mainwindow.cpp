#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->splitter->setStretchFactor(0,2);
    ui->splitter->setStretchFactor(1,5);
    ui->splitter->setStretchFactor(1,5);
    ui->groupBox_2->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_save_pushButton_clicked()
{
    ui->groupBox_2->setVisible(true);
}
