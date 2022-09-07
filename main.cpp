#include "mainwindow.h"
//#include "sqlite/sqlite3.h"
#include "./ui_mainwindow.h"
#include <iostream>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();  
}




