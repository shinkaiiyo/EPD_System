#include "changepassword.h"
#include "ui_changepassword.h"
#include <QString>
#include "success.h"
#include "pwderr.h"
#include "javaconnect.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changePassword)
{
    ui->setupUi(this);
    connect(this->ui->pbtComit,SIGNAL(clicked()),this,SLOT(commit()));
    connect(this->ui->pbtExit,SIGNAL(clicked()),this,SLOT(close()));
    setWindowTitle("修改密码");
}

void ChangePassword::commit()
{
    QString fir = this->ui->le1->text();
    QString sec = this->ui->le2->text();
    if (fir == sec)
    {
        JavaConnect * jc = new JavaConnect;
        jc->client();
        jc->sendmsg("8");
        jc->sendmsg(account);
        jc->sendmsg(fir);
        Success * suc;
        suc = new Success;
        suc->show();
    }
    else
    {
        PwdErr * pe;
        pe = new PwdErr;
        pe->show();
    }
}

void ChangePassword::exit()
{
    this->close();
}

ChangePassword::~ChangePassword()
{
    delete ui;
}
