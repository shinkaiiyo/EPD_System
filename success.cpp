#include "success.h"
#include "ui_success.h"


Success::Success(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::success)
{
    ui->setupUi(this);
    setFixedSize(95,62);
    setWindowTitle("成功");
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(exit()));
}

void Success::exit()
{
    this->close();
}

Success::~Success()
{
    delete ui;
}
