#ifndef ADMINLOGINMANGE_H
#define ADMINLOGINMANGE_H

#include <QWidget>

namespace Ui {
class AdminLoginMange;
}

class AdminLoginMange : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLoginMange(QWidget *parent = 0);
    ~AdminLoginMange();

    void exec_sql(QString sql,QString mess);

private slots:
    void on_Btninsert_clicked();

    void on_pushButton_clicked();

    void on_Btnupdate_clicked();

    void on_Btndel_clicked();

    void on_Btnback_clicked();

signals:
    void AdminLoginMange_close();

private:
    Ui::AdminLoginMange *ui;
};

#endif // ADMINLOGINMANGE_H
