/*!
  *\file
  * \brief this file describes the pyatnica class.
*/
#ifndef SHEDULE_H
#define SHEDULE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql>
namespace Ui {
class shedule;
}
/*!
 * \brief класс shedule - создания объектов для просмотра расписания и записи к тренеру в пятницу.
 *  Класс унаследован от MainWindow.
 */
class shedule : public QDialog
{
    Q_OBJECT

public:
    explicit shedule(QWidget *parent = nullptr);
    ~shedule();

private slots:
    /*!
     * \brief on_back_3_clicked - слот для кнопки, когда та нажата.
     *  Клик меняет страницу в виджете stacked widget на стартовую.
     */
    void on_back_5_clicked();
    /*!
     * \brief on_choose10_clicked - слот для кнопки, когда та нажата.
     *  Кнопка для выбора времени визита: 10:00.
     */
    void on_choose10_clicked();

    /*!
     * \brief on_signup10am_clicked - слот для кнопки, когда та нажата.
     *  Кнопка для подтверждения введенных данных для посещения тренера.
     *  Закрывает текущее окно после нажатия.
     */
    void on_signup10am_clicked();

    /*!
     * \brief on_choose14_clicked - слот для кнопки, когда та нажата.
     *  Кнопка для выбора времени визита: 14:00.
     */
    void on_choose14_clicked();
    /*!
     * \brief on_back_4_clicked - слот для кнопки, когда та нажата.
     *  Клик меняет страницу в виджете stacked widget на стартовую.
     */
    void on_back_6_clicked();

    /*!
     * \brief on_signup14pm_clicked - слот для кнопки, когда та нажата.
     *  Кнопка для подтверждения введенных данных для посещения тренера.
     *  Закрывает текущее окно после нажатия.
     */
    void on_signup14pm_clicked();

    /*!
     * \brief on_choose18_clicked - слот для кнопки, когда та нажата.
     *  Кнопка для выбора времени визита: 18:00.
     */
    void on_choose18_clicked();

    /*!
     * \brief on_signup18pm_clicked - слот для кнопки, когда та нажата.
     *  Кнопка для подтверждения введенных данных для посещения тренера.
     *  Закрывает текущее окно после нажатия.
     */
    void on_signup18pm_clicked();
    /*!
     * \brief on_back_clicked - слот для кнопки, когда та нажата.
     * Клик меняет страницу в виджете stacked widget на стартовую.
     */
    void on_back_2_clicked();

    /*!
     * \brief readDbAndDisplayTable функция для подключение к Базе данных.
     *  Клик осуществляет подключение и  select запрос для выгрузки данных в table widget.
     */
    void connect_bd();
    /*!
     * \brief on_exit_clicked - слот для кнопки, когда та нажата. Кнопка для выхода с текущего окна.
     *  Закрывает текущее окно после нажатия.
     */
    void on_exit_clicked();

public slots:
    void recieve(QString text);
private:
    Ui::shedule *ui;

};


#endif // SHEDULE_H
