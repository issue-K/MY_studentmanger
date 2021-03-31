#include "adminselect.h"
#include "ui_adminselect.h"
#include <QDebug>
#include <adminloginmange.h>

#define StyleLab "QLabel{font-size:30px; color:#FFA07A; font-family:'lucida grande'; }"


AdminSelect::AdminSelect(QString username) :
    ui(new Ui::AdminSelect)
{
    ui->setupUi(this);

    QString word = QString("亲爱的%1,欢迎你!").arg(username);
    ui->Labwelcome->setText(word);
    ui->Labwelcome->setStyleSheet(StyleLab);
}

AdminSelect::~AdminSelect()
{
    delete ui;
}


void AdminSelect::on_Btnstu_clicked()
{
    this->hide();
    loginmange = new AdminLoginMange();
    connect(loginmange,&AdminLoginMange::AdminLoginMange_close,[=](){
        this->show();
    });
    loginmange->show();
}

void AdminSelect::on_Btnlogin_clicked()
{

}

void AdminSelect::on_Btnback_clicked()
{
    this->close();
    emit quick_back();
}
