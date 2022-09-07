/*!
  *\file
  * \brief this file describes the cancel class.
*/

#ifndef CANCEL_H
#define CANCEL_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql>

namespace Ui {
class cancel;
}
/*!
 * \brief Класс Cancel для создания объектов с целью отмены визита к тренеру.
 *  Класс унаследован от MainWindow.
 */
class cancel : public QDialog
{
    Q_OBJECT

public:
    explicit cancel(QWidget *parent = nullptr);
    ~cancel();

private slots:
    /*!
     * \brief on_pushButton_clicked -слот для кнопки, когда та нажата.
     *  Клик подтвеждает введенные данные для отмены записи.
     *   Закрывает текущее окно после нажатия.
     */
    void on_confirm_clicked();

    /*!
     * \brief on_exit_clicked - слот для кнопки, когда та нажата.
     *  Кнопка выхода с окна отмены записи.
     *   Закрывает текущее окно после нажатия
     */
    void on_exit_clicked();

private:
    Ui::cancel *ui;
};

#endif // CANCEL_H
