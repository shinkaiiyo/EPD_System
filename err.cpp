#include "err.h"
#include "ui_err.h"

Err::Err(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::err)
{
    ui->setupUi(this);
    setFixedSize(124,62);
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(exit()));
    setWindowTitle("错误");
}
void Err::exit()
{
    this->close();
}

Err::~Err()
{
    delete ui;
}
