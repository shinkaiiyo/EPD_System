#include "adduser.h"
#include "ui_adduser.h"
#include "javaconnect.h"
#include "success.h"

AddUser::AddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    setFixedSize(350,240);
    setWindowTitle("新增用户");
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
    connect(this->ui->btnCommit,SIGNAL(clicked(bool)),this,SLOT(signin()));
    connect(this->ui->btnReset,SIGNAL(clicked(bool)),this,SLOT(reload()));

}

void AddUser::shutdown()
{
    this->close();
}

void AddUser::reload()
{
    AddUser * au;
    au = new AddUser;
    au->show();
    this->close();
}

void AddUser::signin()
{
    QString acc = this->ui->leName->text();
    QString pwd = this->ui->lePassword->text();
    QString marketname = this->ui->leMarketName->text();
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("10");
    jc->sendmsg(marketname);
    jc->sendmsg(acc + "," + pwd);
    Success * sc = new Success;
    sc->show();
}

AddUser::~AddUser()
{
    delete ui;
}
