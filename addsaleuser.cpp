#include "addsaleuser.h"
#include "ui_addsaleuser.h"
#include "javaconnect.h"
#include "success.h"
AddSaleUser::AddSaleUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSaleUser)
{
    ui->setupUi(this);
    setFixedSize(285,189);
    setWindowTitle("添加售货员账户");
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
    connect(this->ui->btnSignin,SIGNAL(clicked(bool)),this,SLOT(signin()));
    connect(this->ui->btnReset,SIGNAL(clicked(bool)),this,SLOT(reload()));

}

void AddSaleUser::signin()
{
    QString acc = this->ui->leAccount->text();
    QString pwd = this->ui->lePassword->text();
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("9");
    jc->sendmsg(spName);
    jc->sendmsg(acc + "," + pwd);
    Success * sc = new Success;
    sc->show();
}

void AddSaleUser::shutdown()
{
    this->close();
}

void AddSaleUser::reload()
{
    AddSaleUser * asu;
    asu = new AddSaleUser;
    asu->show();
    this->close();
}


AddSaleUser::~AddSaleUser()
{
    delete ui;
}
