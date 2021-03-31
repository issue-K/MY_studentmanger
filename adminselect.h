#ifndef ADMINSELECT_H
#define ADMINSELECT_H

#include <QWidget>
#include <adminloginmange.h>

namespace Ui {
class AdminSelect;
}

class AdminSelect : public QWidget
{
    Q_OBJECT

public:
//    explicit AdminSelect(QWidget *parent = 0);
    AdminSelect(QString username);
    ~AdminSelect();

public:
    AdminLoginMange *loginmange;

signals:
    void quick_back();

private slots:
    void on_Btnlogin_clicked();

    void on_Btnstu_clicked();

    void on_Btnback_clicked();

private:
    Ui::AdminSelect *ui;
};

#endif // ADMINSELECT_H
