#include "shedule.h"
#include "ui_shedule.h"

shedule::shedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shedule)
{
    ui->setupUi(this);
    QPixmap pix(":/images/newnew.jpg");
    ui->label_pic->setPixmap(pix);
    this->setWindowTitle("Запись к тренеру");
     connect_bd();
     connect((*ui).lineEdit10_3, SIGNAL(released()), this, SLOT(button_pressed()));
     connect((*ui).lineEdit10_4, SIGNAL(released()), this, SLOT(button_pressed()));
     connect((*ui).lineEdit14_3, SIGNAL(released()), this, SLOT(button_pressed()));
     connect((*ui).lineEdit14_4, SIGNAL(released()), this, SLOT(button_pressed()));
     connect((*ui).lineEdit18_3, SIGNAL(released()), this, SLOT(button_pressed()));
     connect((*ui).lineEdit18_4, SIGNAL(released()), this, SLOT(button_pressed()));
     setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

shedule::~shedule()
{
    delete ui;
}

QString resultString;
void shedule::recieve(QString text)
{
     resultString = text;
}

void shedule::connect_bd()
{

    QString dbPath = "./shedule.db";
    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QSQLITE", "DBConnection");
    dataBase.setDatabaseName(dbPath);

    if (!dataBase.open())
{
    qDebug() << "Database open error" << dataBase.lastError().text();
    return;
}
    QSqlQuery query(dataBase);

    QString str = "SELECT ВРЕМЯ,ЗАНЯТОСТЬ FROM "+resultString;
    if (!query.exec(str))
{
    qDebug() << "Query execution failed";
    return;
}



    ui->tableWidget->setColumnCount(3);
    QStringList labels;
    labels <<"ВРЕМЯ"<<"СТАТУС"<<"ВРЕМЯ";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    int rowCount = 0;

    while (query.next())
{

    ui->tableWidget->insertRow(rowCount);
    QTableWidgetItem* select = new QTableWidgetItem;
    QTableWidgetItem* hour = new QTableWidgetItem;
    QTableWidgetItem* status = new QTableWidgetItem;

    select->setText(query.value(0).toString());
    hour->setText(query.value(1).toString());
    status->setText(query.value(2).toString());

    ui->tableWidget->setItem(rowCount, 0, select);
    ui->tableWidget->setItem(rowCount, 1, hour);
    ui->tableWidget->setItem(rowCount, 2, status);
    rowCount++;
}
    QByteArray templ;
    QByteArray templ2;
    QByteArray templ3;
    QByteArray a="2";

        if(query.exec("SELECT СТАТУС FROM "+resultString)){
            if(query.next()) templ=query.value(0).toByteArray();
            if(query.next()) templ2=query.value(0).toByteArray();
            if(query.next()) templ3=query.value(0).toByteArray();
        }
        if(templ==a) ui->choose10->setEnabled(false);

        if(templ2==a) ui->choose14->setEnabled(false);

        if(templ3==a) ui->choose18->setEnabled(false);

}


void shedule::on_choose10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit10_3->clear();
    ui->lineEdit10_4->clear();
}

void shedule::on_back_2_clicked()
    {
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit10_3->clear();
    ui->lineEdit10_4->clear();
    }

void shedule::on_signup10am_clicked()
{
    QString name = ui->lineEdit10_3->text();
    QString phone = ui->lineEdit10_4->text();
        QString dbPath = "./shedule.db";
    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QSQLITE", "DBConnection");
    dataBase.setDatabaseName(dbPath);
    if (!dataBase.open())
{
    qDebug() << "Database open error" << dataBase.lastError().text();
    return;
}

    QSqlQuery query(dataBase);
    query.exec("UPDATE " +resultString+ " SET СТАТУС=2,ЗАНЯТОСТЬ='занято' WHERE ВРЕМЯ='10:00' ");
    query.exec("UPDATE " +resultString+ " SET ИМЯ=""'"+name+"'"" WHERE ВРЕМЯ='10:00' ");
    query.exec("UPDATE " +resultString+ " SET ТЕЛЕФОН="+phone+" WHERE ВРЕМЯ='10:00' ");
    hide();

}



void shedule::on_choose14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lineEdit14_3->clear();
    ui->lineEdit14_4->clear();
}
void shedule::on_back_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit14_3->clear();
    ui->lineEdit14_4->clear();
}
void shedule::on_signup14pm_clicked()
{
    QString name =ui->lineEdit14_3->text();
    QString phone = ui->lineEdit14_4->text();
        QString dbPath = "./shedule.db";
    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QSQLITE", "DBConnection");
    dataBase.setDatabaseName(dbPath);
    if (!dataBase.open())
{
    qDebug() << "Database open error" << dataBase.lastError().text();
    return;
}

    QSqlQuery query(dataBase);
    query.exec("UPDATE " +resultString+ " SET СТАТУС=2,ЗАНЯТОСТЬ='занято' WHERE ВРЕМЯ='14:00' ");
    query.exec("UPDATE " +resultString+ " SET ИМЯ=""'"+name+"'"" WHERE ВРЕМЯ='14:00' ");
    query.exec("UPDATE " +resultString+ " SET ТЕЛЕФОН="+phone+" WHERE ВРЕМЯ='14:00' ");
    hide();


}


void shedule::on_choose18_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->lineEdit18_3->clear();
    ui->lineEdit18_4->clear();
}
    void shedule::on_back_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit18_3->clear();
    ui->lineEdit18_4->clear();
}
    void shedule::on_signup18pm_clicked()
{
    QString name =ui->lineEdit18_3->text();

    QString phone = ui->lineEdit18_4->text();
        QString dbPath = "./shedule.db";
    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QSQLITE", "DBConnection");
    dataBase.setDatabaseName(dbPath);
    if (!dataBase.open())
{
    qDebug() << "Database open error" << dataBase.lastError().text();
    return;
}

    QSqlQuery query(dataBase);
    query.exec("UPDATE " +resultString+ " SET СТАТУС=2,ЗАНЯТОСТЬ='занято' WHERE ВРЕМЯ='18:00' ");
    query.exec("UPDATE " +resultString+ " SET ИМЯ=""'"+name+"'"" WHERE ВРЕМЯ='18:00' ");
    query.exec("UPDATE " +resultString+ " SET ТЕЛЕФОН="+phone+" WHERE ВРЕМЯ='18:00' ");
    hide();

}

void shedule::on_exit_clicked()
{

    close();
}
