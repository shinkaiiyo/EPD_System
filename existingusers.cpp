#include "existingusers.h"
#include "ui_existingusers.h"
#include <QStandardItemModel>

ExistingUsers::ExistingUsers(const QString& users,QWidget *parent) :
    QWidget(parent),users(users),
    ui(new Ui::existingUsers)
{
    ui->setupUi(this);
    setWindowTitle("显示用户");
    QStringList usersList = this->users.split(",");
    auto standItemModel = new QStandardItemModel();
    //添加表头
    standItemModel->setColumnCount(2);
    standItemModel->setHeaderData(0,Qt::Horizontal,QStringLiteral("用户名"));
    standItemModel->setHeaderData(1,Qt::Horizontal,QStringLiteral("用户超市"));
    for (int i = 0; i < usersList.length(); i++) {
        QStringList userList = usersList[i].split("\u0001");
        for(int j = 0;j < userList.length();j++)
        {
            QStandardItem *standItem1 = new QStandardItem(userList[j]);
            standItemModel->setItem(i,j,standItem1);                                //表格第i行，第j列添加一项内容
            standItemModel->item(i,j)->setForeground(QBrush(QColor(0,0,0)));      //设置字符颜色
            standItemModel->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->tableView->setModel(standItemModel);
    connect(this->ui->btnExit,SIGNAL(clicked(bool)),this,SLOT(shutdown()));
}

void ExistingUsers::shutdown()
{
    this->close();
}

ExistingUsers::~ExistingUsers()
{
    delete ui;
}
