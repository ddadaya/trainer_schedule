#include "cancel.h"
#include "ui_cancel.h"
#include <QMessageBox>
cancel::cancel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cancel)
{
    ui->setupUi(this);
    QPixmap pix(":/images/13131.jpg");
    this->setWindowTitle("Отмена записи");
    ui->label->setPixmap(pix);
    connect((*ui).le1, SIGNAL(released()), this, SLOT(button_pressed()));
    connect((*ui).le2, SIGNAL(released()), this, SLOT(button_pressed()));
    connect((*ui).le3, SIGNAL(released()), this, SLOT(button_pressed()));
    ui->le1->setInputMask("99999999999");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}

cancel::~cancel()
{
    delete ui;
}

void cancel::on_confirm_clicked()
{
    QString phone =ui->le1->text();
    QString day = ui->assist->text()+ ui->le2->text()+ui->assist->text();
    QString hour = ui->assist->text()+ ui->le3->text()+ui->assist->text();
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
    if((hour!="10:00")||(hour!="14:00")||(hour!="18:00")){
        QMessageBox::information(this,"input error","invalid hour. Valid: hh:00");
    if ((day!="Понедельник")||(day!="Вторник")||(day!="Среда"))

    {QMessageBox::information(this,"input error","invalid day of week. Valid: Понедельник/Вторник/Среда");}
    else
    {
     query.exec("UPDATE"+ day +" SET NAME=' ',PHONE=' ', status_id=1 WHERE hour=""'"+hour +"'""");

     hide();
    }}

}


void cancel::on_exit_clicked()
{
    close();
}
