#include "spadmininterface.h"
#include "ui_spadmininterface.h"
#include "changepassword.h"
#include "login.h"
#include "existingsaleuser.h"
#include "addsaleuser.h"
#include "iteminformation.h"
#include "itemcreate.h"
#include "javaconnect.h"
#include <QDebug>

SpAdminInterface::SpAdminInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::spadmininterface)
{
    ui->setupUi(this);
    setWindowTitle("欢迎您，尊贵的用户");
    connect(this->ui->pbtChangepwd,SIGNAL(clicked(bool)),this,SLOT(changePwd()));
    connect(this->ui->pbtexit,SIGNAL(clicked(bool)),this,SLOT(exit()));
    connect(this->ui->pbtShowUser,SIGNAL(clicked(bool)),this,SLOT(showSaleUser()));
    connect(this->ui->pbtCreateUser,SIGNAL(clicked(bool)),this,SLOT(addSaleUser()));
    connect(this->ui->pbtShowItems,SIGNAL(clicked(bool)),this,SLOT(showItems()));
    connect(this->ui->pbtChangeItems,SIGNAL(clicked(bool)),this,SLOT(createItems()));
}

void SpAdminInterface::changePwd()
{
    ChangePassword * cpd;
    cpd =new ChangePassword;
    cpd->account = (QString)"admin" + (QString)"," +spname;
    cpd->show();
}

void SpAdminInterface::exit()
{
    this->close();
    Login * lg;
    lg = new Login;
    lg->show();
}

void SpAdminInterface::showSaleUser()
{
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("3");
    jc->sendmsg(spname);
    jc->sendmsg("test");
    ExistingSaleUser * esu;
    esu = new ExistingSaleUser(jc->getmsg());
    esu->marketname = spname;
    esu->show();
}

void SpAdminInterface::addSaleUser()
{
    AddSaleUser * asu;
    asu = new AddSaleUser;
    asu->spName = spname;
    asu->show();
}

void SpAdminInterface::showItems()
{
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("4");
    jc->sendmsg(spname);
    jc->sendmsg("test");
    ItemInformation * ii;
    ii = new ItemInformation(jc->getmsg());
    ii->spname = spname;
    ii->show();
}

void SpAdminInterface::createItems()
{
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("3");
    jc->sendmsg(spname);
    jc->sendmsg("test");
    ItemCreate * ic;
    ic = new ItemCreate(jc->getmsg());
    ic->marketname = spname;
    ic->show();
}

SpAdminInterface::~SpAdminInterface()
{
    delete ui;
}
