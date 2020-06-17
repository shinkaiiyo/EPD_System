#ifndef SPADMININTERFACE_H
#define SPADMININTERFACE_H

#include <QWidget>

namespace Ui {
class spadmininterface;
}

class SpAdminInterface : public QWidget
{
    Q_OBJECT

public:
    explicit SpAdminInterface(QWidget *parent = 0);
    QString spname;
    ~SpAdminInterface();

private slots:
    void changePwd();
    void exit();
    void showSaleUser();
    void addSaleUser();
    void showItems();
    void createItems();

private:
    Ui::spadmininterface *ui;
};

#endif // SPADMININTERFACE_H
