#include "itemchange.h"
#include "ui_itemchange.h"
#include "javaconnect.h"
#include "success.h"

ItemChange::ItemChange(const QString& items ,QWidget *parent) :
    QWidget(parent),items(items),
    ui(new Ui::ItemChange)
{
    ui->setupUi(this);
    setWindowTitle("修改商品信息");
    QStringList itemsList = this->items.split(",");
    this->ui->cbItems->addItems(itemsList);
    this->ui->cbItems->show();
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
    connect(this->ui->btnCommit,SIGNAL(clicked(bool)),this,SLOT(commit()));
}

void ItemChange::commit()
{
    QString item = this->ui->cbItems->currentText();
    QString price = this->ui->leNewPrice->text();
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("11");
    jc->sendmsg(item);
    jc->sendmsg(price);
    Success * sc = new Success;
    sc->show();
}

void ItemChange::shutdown()
{
    this->close();
}

ItemChange::~ItemChange()
{
    delete ui;
}
