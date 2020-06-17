#include "pwderr.h"
#include "ui_pwderr.h"

PwdErr::PwdErr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pwderr)
{
    ui->setupUi(this);
    setFixedSize(137,62);
    setWindowTitle("修改密码失败");
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(exit()));
}

void PwdErr::exit()
{
    this->close();
}

PwdErr::~PwdErr()
{
    delete ui;
}
