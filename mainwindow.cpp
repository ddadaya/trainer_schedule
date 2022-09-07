#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sh = new shedule();
    this->setWindowTitle("Главное меню");
    QPixmap pix(":/images/fon33.jpg");
    ui->label_pic->setPixmap(pix);
    connect((*ui).shedule, SIGNAL(released()), this, SLOT(button_pressed()));
    connect((*ui).lineEdit_2, SIGNAL(released()), this, SLOT(button_pressed()));
    connect(this, SIGNAL(sendData(QString)), sh, SLOT(recieve(QString)));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_admin_pressed()
{
    QString userName = ui->lineEdit_2->text();
    if (userName=="1")
    {
            secondw sec;
            sec.setModal(true);
            sec.exec();
    } else
    {
          QMessageBox::information(this,"Invalid password","This button only for admins. I bet you are not an admin.");
    }

}


void MainWindow::on_shedule_clicked()
{
    if (ui->radio_pn->isChecked())
    {
        shedule pt;
        pt.setModal(true);
        pt.exec();
        emit sendData("Понедельник");
    } else if(ui->radio_vt->isChecked())
    {
        shedule pt;
        pt.setModal(true);
        pt.exec();
        emit sendData("Вторник");
    } else if (ui->radio_sr->isChecked())
    {
        shedule pt;
        pt.setModal(true);
        pt.exec();
        emit sendData("Среда");

    } else if (ui->radio_cht->isChecked())
    {
        shedule pt;
        pt.setModal(true);
        pt.exec();
        emit sendData("Четверг");
    } else if (ui->radio_pt->isChecked())
    {
        shedule pt;
        pt.setModal(true);
        pt.exec();
        emit sendData("Пятница");
    }
}


void MainWindow::on_cancel_clicked()
{
    cancel cs;
    cs.setModal(true);
    cs.exec();
}

