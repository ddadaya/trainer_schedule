/*!
  *\file
  * \brief this file describes the secondw class.
*/

#ifndef SECONDW_H
#define SECONDW_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql>

namespace Ui {
class secondw;
}

/*!
 * \brief Класс secondw для создания объектов в админ-окне.
 *  Класс унаследован от MainWindow.
 */
class secondw : public QDialog
{
    Q_OBJECT

public:
    explicit secondw(QWidget *parent = nullptr);
    ~secondw();

private slots:
    /*!
     * \brief on_radioButton_clicked, когда нажата - отображает инофрмацию базы данных в table widget в понедельник.
     */
    void on_ponedelnik_clicked();
    /*!
     * \brief on_radioButton_2_clicked, когда нажата - отображает инофрмацию базы данных в table widget во вторник.
     */
    void on_vtornik_clicked();
    /*!
     * \brief on_radioButton_3_clicked, когда нажата - отображает инофрмацию базы данных в table widget в среду.
     */
    void on_sreda_clicked();
    /*!
     * \brief on_pushButton_clicked, когда нажата - подтверждает введенную информацию и очищает выбранные строчки в базе данных.
     */
    void on_new_weak_clicked();
    /*!
     * \brief on_pushButton_3_clicked, когда нажата - подтверждает введенную информацию и очищает выбранные строчки в базе данных.
     */
    void on_change_vt_clicked();
    /*!
     * \brief on_pushButton_4_clicked, когда нажата - подтверждает введенную информацию и очищает выбранные строчки в базе данных.
     */
    void on_change_sr_clicked();

    /*!
     * \brief on_pushButton_2_clicked, когда нажата - очищает все записи с текущей недели, когда начинается новая.
     */
    void on_change_pon_clicked();
    /*!
     * \brief on_radioButton_clicked, когда нажата - отображает инофрмацию базы данных в table widget в четверг.
     */
    void on_chetverg_clicked();
    /*!
     * \brief on_radioButton_clicked, когда нажата - отображает инофрмацию базы данных в table widget в пятницу.
     */
    void on_pyatnica_clicked();
    /*!
     * \brief on_exit_clicked,когда нажата. Кнопка для выхода с текущего окна.
     *  Закрывает текущее окно после нажатия.
     */
    void on_exit_clicked();
    /*!
     * \brief on_pushButton_5_clicked, когда нажата - подтверждает введенную информацию и очищает выбранные строчки в базе данных.
     */
    void on_change_ch_clicked();
    /*!
     * \brief on_pushButton_6_clicked, когда нажата - подтверждает введенную информацию и очищает выбранные строчки в базе данных.
     */
    void on_change_pt_clicked();

private:
    Ui::secondw *ui;

};

#endif // SECONDW_H
