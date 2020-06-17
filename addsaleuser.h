#ifndef ADDSALEUSER_H
#define ADDSALEUSER_H

#include <QWidget>

namespace Ui {
class AddSaleUser;
}

class AddSaleUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddSaleUser(QWidget *parent = 0);
    QString spName;
    ~AddSaleUser();

private slots:
    void shutdown();
    void signin();
    void reload();

private:
    Ui::AddSaleUser *ui;
};

#endif // ADDSALEUSER_H
