#include "existingsaleuser.h"
#include "ui_existingsaleuser.h"
#include <QStandardItemModel>
#include <QDebug>
#include "javaconnect.h"
#include "success.h"

ExistingSaleUser::ExistingSaleUser(const QString& users,QWidget *parent) :
    QWidget(parent),users(users),
    ui(new Ui::ExistingSaleUser)
{
    ui->setupUi(this);
    setWindowTitle("显示用户");
    setFixedSize(380,380);
    auto const& userList = this->users.split(",");
    this->ui->cbUsers->addItems(userList);
    this->ui->cbUsers->show();
    auto standItemModel = new QStandardItemModel();
    //添加表头
    standItemModel->setColumnCount(1);
    standItemModel->setHeaderData(0,Qt::Horizontal,QStringLiteral("用户名"));
    for (int i = 0; i < userList.length(); i++) {
        QStandardItem *standItem1 = new QStandardItem(userList[i]);
        standItemModel->setItem(i,0,standItem1);                                //表格第i行，第0列添加一项内容
        standItemModel->item(i,0)->setForeground(QBrush(QColor(0,0,0)));      //设置字符颜色
        standItemModel->item(i,0)->setTextAlignment(Qt::AlignCenter);
    }
    ui->tableView->setModel(standItemModel);
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
    connect(this->ui->btnDelete,SIGNAL(clicked(bool)),this,SLOT(del()));
}

void ExistingSaleUser::del()
{
    QString userToDelete = this->ui->cbUsers->currentText();
    JavaConnect * jc = new JavaConnect;
    jc->client();
    jc->sendmsg("13");
    jc->sendmsg(userToDelete);
    jc->sendmsg(marketname);
    Success * sc = new Success;
    sc->show();
}

void ExistingSaleUser::shutdown()
{
    this->close();
}

ExistingSaleUser::~ExistingSaleUser()
{
    delete ui;
}

