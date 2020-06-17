#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QString>
#include "admininterface.h"
#include "err.h"
#include "spadmininterface.h"
#include "spworkinterface.h"
#include "javaconnect.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(450,330);
    setWindowTitle("用户登录");
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
    connect(this->ui->btnLogin,SIGNAL(clicked(bool)),this,SLOT(login()));
    connect(this->ui->btnReset,SIGNAL(clicked(bool)),this,SLOT(reload()));
    ui->lePassword->setClearButtonEnabled(true);
    ui->lePassword->setEchoMode(ui->lePassword->Password);
}

Login::~Login()
{
    delete ui;
}
void Login::shutdown()
{
    this->close();
}
void Login::login()
{
    AdminInterface * ai;
    Err * er;
    SpAdminInterface * sai;
    SPWorkInterface * swi;
    QString acc = this->ui->leAccount->text();
    QString pwd = this->ui->lePassword->text();
    int type = this->ui->cbAccType->currentIndex();
    if(acc == "admin" && pwd == "123" && type == 0)
    {
        ai = new AdminInterface;
        ai->show();
        this->close();
    }
    else
    {
        JavaConnect * jc = new JavaConnect;
        jc->client();
        jc->sendmsg(QString::number(type));
        jc->sendmsg(acc);
        jc->sendmsg(pwd);
        QString status = jc->getmsg();
        qDebug() << "status: " << status;
        if(status == "1")
        {
            if (type == 1) {
                sai = new SpAdminInterface;
                sai->spname = acc;
                sai->show();
            }
            else if (type == 2) {
                swi = new SPWorkInterface;
                swi->name = acc;
                swi->show();
            }
            this->close();
        }
        else
        {
            er = new Err;
            er->show();
        }
    }
}

void Login::reload()
{
    Login * lg;
    lg = new Login;
    lg->show();
    this->close();
}
