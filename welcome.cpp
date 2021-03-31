#include "welcome.h"
#include "ui_welcome.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include<QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include <adminloginmange.h>

#define StyleLine "QLineEdit{background-color:#EDE0C8; border-radius:13px; font-size:18px; font-family:'微软雅黑'; }"
#define StyleBtn "QPushButton{background-color:#0088C1; color:white; border-radius:7px; font-size:18px; font-family:'lucida grande'; font-weight:bold; } QPushButton::hover{background-color:#00FFFF; color:red;}"
#define StyleLab "QLabel{font-size:30px; color:#EE3A8C; font-family:'lucida grande'; }"
#define StyleRadio "font-size:15px;font-family:'微软雅黑';"
#define StyleFrame "QFrame{background-image:url(':/res/wuxia2.jpg'); opacity:1.0;}"

welcome::welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    SetMyStyle();


}

welcome::~welcome()
{
    delete ui;
}

void welcome::SetMyStyle()
{
    ui->frame->setStyleSheet(StyleFrame);
    ui->username->setStyleSheet(StyleLine);
    ui->password->setStyleSheet(StyleLine);
    ui->Btnlogin->setStyleSheet(StyleBtn);
    ui->Lablogo->setStyleSheet(StyleLab);
    ui->Rtnadmin->setStyleSheet(StyleRadio);
    ui->RtnStudent->setStyleSheet(StyleRadio);
}

void welcome::paintEvent(QPaintEvent *)
{
//    QPixmap img;
//    img.load(":/res/wuxia.jpg");
//    QPainter painter(this);
//    painter.drawPixmap(0,70,230,260,img);
}

void welcome::on_Btnlogin_clicked()
{
    this->hide();
    adminselect = new AdminSelect(ui->username->text() );

    connect(adminselect,&AdminSelect::quick_back,[=](){
        this->show();
    });

    adminselect->show();
}
