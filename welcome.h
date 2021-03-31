#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QPainter>
#include <adminselect.h>

namespace Ui {
class welcome;
}

class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    ~welcome();
    void SetMyStyle();
    void paintEvent(QPaintEvent *);

public:
    AdminSelect *adminselect;



private slots:
    void on_Btnlogin_clicked();

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H
