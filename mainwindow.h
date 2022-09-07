/*!
  *\file
  * \brief this file describes the MainWindow class.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "secondw.h"
#include "shedule.h"
#include "cancel.h"
#include <QtSql/QSqlDatabase>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Класс MainWindow для создания объектов главного окна.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    secondw *secwindow;
    MainWindow *mainw;
     shedule *sh;
     cancel *cs;

signals:
    void sendData(QString text);
 private slots:

    /*!
     * \brief button_pressed -слот для кнопки, когда та нажата.
     *  Клик открывает secondw админ-окно.
     */
    void on_admin_pressed();
    /*!
     * \brief on_pushButton_2_clicked - слот для кнопки, когда та нажата.
     * Клик открывает user/vtornik/sreda/chetverg/pyatnica окно, где можно произвести запись к тренеру на выбранный день.
     */
    void on_shedule_clicked();
    /*!
     * \brief on_pushButton_3_clicked - слот для кнопки, когда та нажата.
     *  Клик открывает cancel окно, где можно произвести отмену записи к тренеру.
     */
    void on_cancel_clicked();
};
#endif // MAINWINDOW_H

