#include "admininterface.h"
#include "ui_admininterface.h"
#include "changepassword.h"
#include "login.h"
#include "existingusers.h"
#include "adduser.h"
#include "javaconnect.h"

AdminInterface::AdminInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admininterface)
{
    ui->setupUi(this);
    setWindowTitle("欢迎您，尊贵的管理员");
    connect(this->ui->pbtexit,SIGNAL(clicked(bool)),this,SLOT(exit()));
    connect(this->ui->pbtShowUser,SIGNAL(clicked(bool)),this,SLOT(showUser()));
    connect(this->ui->pbtCreateUser,SIGNAL(clicked(bool)),this,SLOT(addUser()));
}

void AdminInterface::exit()
{
    this->close();
    Login * lg;
    lg = new Login;
    lg->show();
}

void AdminInterface::showUser()
{
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("6");
    jc->sendmsg("test");
    jc->sendmsg("test");
    ExistingUsers * eu;
    eu = new ExistingUsers(jc->getmsg());
    eu->show();
}

void AdminInterface::addUser()
{
    AddUser * au;
    au = new AddUser;
    au->show();
}

AdminInterface::~AdminInterface()
{
    delete ui;
}
