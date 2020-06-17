#include "spworkinterface.h"
#include "ui_spworkinterface.h"
#include "changepassword.h"
#include "login.h"
#include "iteminfo.h"
#include "itemchange.h"
#include "javaconnect.h"

SPWorkInterface::SPWorkInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::spworkinterface)
{
    ui->setupUi(this);
    setWindowTitle("欢迎您，尊贵的用户");
    connect(this->ui->pbtChangepwd,SIGNAL(clicked(bool)),this,SLOT(changePwd()));
    connect(this->ui->pbtexit,SIGNAL(clicked(bool)),this,SLOT(exit()));
    connect(this->ui->pbtShowItems,SIGNAL(clicked(bool)),this,SLOT(showItems()));
    connect(this->ui->pbtChangeItems,SIGNAL(clicked(bool)),this,SLOT(changeItems()));
}

void SPWorkInterface::changePwd()
{
    ChangePassword * cpd;
    cpd =new ChangePassword;
    cpd->account = (QString)"worker" + (QString)"," +name;
    cpd->show();
}

void SPWorkInterface::exit()
{
    this->close();
    Login * lg;
    lg = new Login;
    lg->show();
}

void SPWorkInterface::showItems()
{
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("5");
    jc->sendmsg(name);
    jc->sendmsg("test");
    ItemInfo * ii;
    ii = new ItemInfo(jc->getmsg());
    ii->show();
}

void SPWorkInterface::changeItems()
{
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("7");
    jc->sendmsg(name);
    jc->sendmsg("test");
    ItemChange * ic;
    ic = new ItemChange(jc->getmsg());
    ic->show();
}

SPWorkInterface::~SPWorkInterface()
{
    delete ui;
}
