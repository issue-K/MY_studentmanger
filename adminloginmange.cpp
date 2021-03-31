#include "adminloginmange.h"
#include "ui_adminloginmange.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include<QSqlQuery>

#define StyleBtn "QLabel{ text-align:center; min-width:200px; min-height:100px;} QPushButton{ width:80px; height:50px;background-color:#0088C1; color:white; border-radius:7px; font-size:18px; font-family:'lucida grande'; font-weight:bold; } QPushButton::hover{background-color:#00FFFF; color:red;}"

AdminLoginMange::AdminLoginMange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminLoginMange)
{
    ui->setupUi(this);
    //连接学生数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");//数据库服务器ip
    db.setUserName("root");//数据库用户名
    db.setPassword("123");//数据库密码
    db.setDatabaseName("mystumanger");//使用哪个数据库
    if( !db.open() )
    {
        QMessageBox::warning(this,"错误",db.lastError().text() );//打开失败,显示错误信息
        return;
    }
}

AdminLoginMange::~AdminLoginMange()
{
    delete ui;
}

void AdminLoginMange::exec_sql(QString sql, QString mess)
{
    QSqlQuery query;
    bool ok = query.exec(sql);
    if( ok )
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,"恭喜您",QString("%1成功^_^!").arg(mess) );
        box->setStyleSheet(StyleBtn);
        box->exec();
    }
    else
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Warning,"真是遗憾呢",QString("%1失败O_O").arg(mess) );
        box->setStyleSheet(StyleBtn);
        box->exec();
    }
}


void AdminLoginMange::on_Btninsert_clicked()//插入
{
    int id = ui->Lineid->text().toInt();
    int score = ui->Linescore->text().toInt();
    int age = ui->Lineage->text().toInt();
    QString name = ui->Linename->text();
    QString sex = ui->Linesex->text();
    QString qq = ui->Lineqq->text();
    QString sql = QString("insert into studentlogin(id,name,age,sex,qq,score) values('%1','%2','%3','%4','%5','%6')").arg(id).arg(name).arg(age).arg(sex).arg(qq).arg(score);
    exec_sql(sql,"插入");
}

void AdminLoginMange::on_pushButton_clicked()//查找
{
    int id = ui->LineFindId->text().toInt();
    QSqlQuery query;
    QString in = QString("select id,name,sex,score,qq,age from studentlogin where id='%1'").arg(id);
    query.exec(in);
    if( query.next() )//找到了这个学号
    {
        ui->Lineid->setText(query.value("id").toString() );
        ui->Linename->setText( query.value("name").toString() );
        ui->Lineage->setText(query.value("age").toString() );
        ui->Lineqq->setText(query.value("qq").toString() );
        ui->Linescore->setText(query.value("score").toString() );
        ui->Linesex->setText(query.value("sex").toString() );
    }
    else
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Warning,"真是遗憾呢","并没有这个人O_O~");
        box->setStyleSheet(StyleBtn);
        box->exec();
    }
}

void AdminLoginMange::on_Btnupdate_clicked()//更新
{
    int id = ui->Lineid->text().toInt();
    int score = ui->Linescore->text().toInt();
    int age = ui->Lineage->text().toInt();
    QString name = ui->Linename->text();
    QString sex = ui->Linesex->text();
    QString qq = ui->Lineqq->text();
    QString sql = QString("update studentlogin set name='%1',age='%2',sex='%3',qq='%4',score='%5' where id='%6'").arg(name).arg(age).arg(sex).arg(qq).arg(score).arg(id);
    exec_sql(sql,"更新");
}

void AdminLoginMange::on_Btndel_clicked()
{
    int id = ui->Lineid->text().toInt();
    QString sql = QString("delete from studentlogin where id='%1'").arg(id);
    exec_sql(sql,"删除");
}

void AdminLoginMange::on_Btnback_clicked()
{
    emit AdminLoginMange_close();
    this->close();
}
