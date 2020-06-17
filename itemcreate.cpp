#include "itemcreate.h"
#include "ui_itemcreate.h"
#include "javaconnect.h"
#include "success.h"

ItemCreate::ItemCreate(const QString& users,QWidget *parent) :
    QWidget(parent),users(users),
    ui(new Ui::ItemCreate)
{
    ui->setupUi(this);
    this->setFixedSize(300,360);
    setWindowTitle("新增商品");
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
    connect(this->ui->btnCommit,SIGNAL(clicked(bool)),this,SLOT(commit()));
    connect(this->ui->btnReset,SIGNAL(clicked(bool)),this,SLOT(reload()));
    QStringList userList = this->users.split(",");
    this->ui->cbWorker->addItems(userList);
    this->ui->cbWorker->show();
}

void ItemCreate::commit()
{
    int iType = this->ui->cbType->currentIndex();
    QString type = QString::number(iType + 1);
    QString pname = this->ui->lePname->text();
    QString brand = this->ui->leBrand->text();
    QString origin = this->ui->leOrigin->text();
    QString spec = this->ui->leSpec->text();
    QString inum = this->ui->leInum->text();
    QString barcode = this->ui->leBarcode->text();
    QString price = this->ui->lePrice->text();
    QString oriPrice = this->ui->leOriPrice->text();
    QString worker = this->ui->cbWorker->currentText();
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("12");
    jc->sendmsg(marketname);
    jc->sendmsg(type + "," + pname + "," + brand + "," + origin + "," + spec + "," + inum + "," + barcode + "," + price + "," + oriPrice + "," + worker);
    Success * sc = new Success;
    sc->show();
}

void ItemCreate::reload()
{
    ItemCreate * ic;
    ic = new ItemCreate(users);
    ic->show();
    this->close();
}

void ItemCreate::shutdown()
{
    this->close();
}

ItemCreate::~ItemCreate()
{
    delete ui;
}
