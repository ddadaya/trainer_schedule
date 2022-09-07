#include "ui_secondw.h"
#include "secondw.h"
secondw::secondw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondw)
{
    ui->setupUi(this);
    QPixmap pix(":/images/13131.jpg");
    this->setWindowTitle("Админ панель");
    ui->label->setPixmap(pix);
    connect((*ui).lineEdit, SIGNAL(released()), this, SLOT(button_pressed()));
    connect((*ui).lineEdit_3, SIGNAL(released()), this, SLOT(button_pressed()));
    connect((*ui).lineEdit_4, SIGNAL(released()), this, SLOT(button_pressed()));
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    
}

secondw::~secondw()
{
    delete ui;
}


void secondw::on_ponedelnik_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
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
     QString str = "SELECT * from Понедельник";
     if (!query.exec(str))
     {
         qDebug() << "Query execution failed";
         return;
     }
     ui->tableWidget->setColumnCount(4);
     QStringList labels;
     labels << "ИМЯ" << "ТЕЛЕФОН" << "ВРЕМЯ" << "СТАТУС";

     ui->tableWidget->setHorizontalHeaderLabels(labels);
     int rowCount = 0;
     while (query.next())
     {
         ui->tableWidget->insertRow(rowCount);
         QTableWidgetItem* select = new QTableWidgetItem;
         QTableWidgetItem* name = new QTableWidgetItem;
         QTableWidgetItem* phone = new QTableWidgetItem;
         QTableWidgetItem* hour = new QTableWidgetItem;
         QTableWidgetItem* status = new QTableWidgetItem;


         select->setText(query.value(0).toString());
         name->setText(query.value(1).toString());
         phone->setText(query.value(2).toString());
         hour->setText(query.value(3).toString());
         status->setText(query.value(4).toString());



         ui->tableWidget->setItem(rowCount, 0, select);
         ui->tableWidget->setItem(rowCount, 1, name);
         ui->tableWidget->setItem(rowCount, 2, phone);
         ui->tableWidget->setItem(rowCount, 3, hour);
         ui->tableWidget->setItem(rowCount, 4, status);

         rowCount++;
     }


}

void secondw::on_vtornik_clicked()
{

     ui->stackedWidget->setCurrentIndex(1);
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
     QString str = "SELECT * from Вторник";
     if (!query.exec(str))
     {
         qDebug() << "Query execution ";
         return;
     }
     ui->tableWidget_2->setColumnCount(4);
     QStringList labels;
     labels << "ИМЯ" << "ТЕЛЕФОН" << "ВРЕМЯ" << "СТАТУС";

     ui->tableWidget_2->setHorizontalHeaderLabels(labels);
     int rowCount = 0;

     while (query.next())
     {
         ui->tableWidget_2->insertRow(rowCount);
         QTableWidgetItem* select = new QTableWidgetItem;
         QTableWidgetItem* name = new QTableWidgetItem;
         QTableWidgetItem* phone = new QTableWidgetItem;
         QTableWidgetItem* hour = new QTableWidgetItem;
         QTableWidgetItem* status = new QTableWidgetItem;


         select->setText(query.value(0).toString());
         name->setText(query.value(1).toString());
         phone->setText(query.value(2).toString());
         hour->setText(query.value(3).toString());
         status->setText(query.value(4).toString());



         ui->tableWidget_2->setItem(rowCount, 0, select);
         ui->tableWidget_2->setItem(rowCount, 1, name);
         ui->tableWidget_2->setItem(rowCount, 2, phone);
         ui->tableWidget_2->setItem(rowCount, 3, hour);
         ui->tableWidget_2->setItem(rowCount, 4, status);


         rowCount++;
     }
}

void secondw::on_sreda_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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
    QString str = "SELECT * from Среда";
    if (!query.exec(str))
    {
        qDebug() << "Query execution  failed ";
        return;
    }
    ui->tableWidget_3->setColumnCount(4);
    QStringList labels;
    labels << "ИМЯ" << "ТЕЛЕФОН" << "ВРЕМЯ" << "СТАТУС";

    ui->tableWidget_3->setHorizontalHeaderLabels(labels);
    int rowCount = 0;

    while (query.next())
    {
        ui->tableWidget_3->insertRow(rowCount);
        QTableWidgetItem* select = new QTableWidgetItem;
        QTableWidgetItem* name = new QTableWidgetItem;
        QTableWidgetItem* phone = new QTableWidgetItem;
        QTableWidgetItem* hour = new QTableWidgetItem;
        QTableWidgetItem* status = new QTableWidgetItem;

        select->setText(query.value(0).toString());
        name->setText(query.value(1).toString());
        phone->setText(query.value(2).toString());
        hour->setText(query.value(3).toString());
        status->setText(query.value(4).toString());

        ui->tableWidget_3->setItem(rowCount, 0, select);
        ui->tableWidget_3->setItem(rowCount, 1, name);
        ui->tableWidget_3->setItem(rowCount, 2, phone);
        ui->tableWidget_3->setItem(rowCount, 3, hour);
        ui->tableWidget_3->setItem(rowCount, 4, status);

        rowCount++;
    }
}

void secondw::on_new_weak_clicked()
{
     QString hour= ui->lineEdit->text();
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
     query.exec("UPDATE Понедельник SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1, ЗАНЯТОСТЬ='свободно'");
     query.exec("UPDATE Вторник SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1, ЗАНЯТОСТЬ='свободно'");
     query.exec("UPDATE Среда SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1, ЗАНЯТОСТЬ='свободно'");
     query.exec("UPDATE Четверг SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1, ЗАНЯТОСТЬ='свободно'");
     query.exec("UPDATE Пятница SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1, ЗАНЯТОСТЬ='свободно'");

}



void secondw::on_change_vt_clicked()
{
    QString hour= ui->lineEdit_3->text();
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
    query.exec("UPDATE Вторник SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1,ЗАНЯТОСТЬ='свободно' WHERE ВРЕМЯ=""'"+hour+"'"" ");

}

void secondw::on_change_sr_clicked()
{
    QString hour= ui->lineEdit_4->text();
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
    query.exec("UPDATE Среда SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1,ЗАНЯТОСТЬ='свободно' WHERE ВРЕМЯ=""'"+hour+"'"" ");
}

void secondw::on_change_pon_clicked()
{
    QString hour= ui->lineEdit->text();
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
    query.exec("UPDATE Понедельник SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1,ЗАНЯТОСТЬ='свободно' WHERE ВРЕМЯ=""'"+hour+"'"" ");

}


void secondw::on_chetverg_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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
    QString str = "SELECT * from Четверг";
    if (!query.exec(str))
    {
        qDebug() << "Query execution  failed ";
        return;
    }
    ui->tableWidget_4->setColumnCount(4);
    QStringList labels;
    labels << "ИМЯ" << "ТЕЛЕФОН" << "ВРЕМЯ" << "СТАТУС";

    ui->tableWidget_4->setHorizontalHeaderLabels(labels);
    int rowCount = 0;

    while (query.next())
    {
        ui->tableWidget_4->insertRow(rowCount);
        QTableWidgetItem* select = new QTableWidgetItem;
        QTableWidgetItem* name = new QTableWidgetItem;
        QTableWidgetItem* phone = new QTableWidgetItem;
        QTableWidgetItem* hour = new QTableWidgetItem;
        QTableWidgetItem* status = new QTableWidgetItem;

        select->setText(query.value(0).toString());
        name->setText(query.value(1).toString());
        phone->setText(query.value(2).toString());
        hour->setText(query.value(3).toString());
        status->setText(query.value(4).toString());

        ui->tableWidget_3->setItem(rowCount, 0, select);
        ui->tableWidget_3->setItem(rowCount, 1, name);
        ui->tableWidget_3->setItem(rowCount, 2, phone);
        ui->tableWidget_3->setItem(rowCount, 3, hour);
        ui->tableWidget_3->setItem(rowCount, 4, status);

        rowCount++;
    }

}

void secondw::on_pyatnica_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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
    QString str = "SELECT * from Пятница";
    if (!query.exec(str))
    {
        qDebug() << "Query execution  failed ";
        return;
    }
    ui->tableWidget_3->setColumnCount(4);
    QStringList labels;
    labels << "ИМЯ" << "ТЕЛЕФОН" << "hour" << "СТАТУС";

    ui->tableWidget_3->setHorizontalHeaderLabels(labels);
    int rowCount = 0;

    while (query.next())
    {
        ui->tableWidget_3->insertRow(rowCount);
        QTableWidgetItem* select = new QTableWidgetItem;
        QTableWidgetItem* name = new QTableWidgetItem;
        QTableWidgetItem* phone = new QTableWidgetItem;
        QTableWidgetItem* hour = new QTableWidgetItem;
        QTableWidgetItem* status = new QTableWidgetItem;

        select->setText(query.value(0).toString());
        name->setText(query.value(1).toString());
        phone->setText(query.value(2).toString());
        hour->setText(query.value(3).toString());
        status->setText(query.value(4).toString());

        ui->tableWidget_3->setItem(rowCount, 0, select);
        ui->tableWidget_3->setItem(rowCount, 1, name);
        ui->tableWidget_3->setItem(rowCount, 2, phone);
        ui->tableWidget_3->setItem(rowCount, 3, hour);
        ui->tableWidget_3->setItem(rowCount, 4, status);

        rowCount++;
    }
}

void secondw::on_exit_clicked()
{
    close();
}

void secondw::on_change_ch_clicked()
{
    QString hour= ui->lineEdit_5->text();
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
    query.exec("UPDATE Четверг SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1,ЗАНЯТОСТЬ='свободно' WHERE ВРЕМЯ=""'"+hour+"'"" ");

}

void secondw::on_change_pt_clicked()
{
    QString hour= ui->lineEdit_6->text();
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
    query.exec("UPDATE Пятница SET ИМЯ=' ',ТЕЛЕФОН=' ', СТАТУС=1,ЗАНЯТОСТЬ='свободно' WHERE ВРЕМЯ=""'"+hour+"'"" ");

}
