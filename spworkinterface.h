#ifndef SPWORKINTERFACE_H
#define SPWORKINTERFACE_H

#include <QWidget>

namespace Ui {
class spworkinterface;
}

class SPWorkInterface : public QWidget
{
    Q_OBJECT

public:
    explicit SPWorkInterface(QWidget *parent = 0);
    ~SPWorkInterface();
    QString name;

private slots:
    void changePwd();
    void exit();
    void showItems();
    void changeItems();

private:
    Ui::spworkinterface *ui;
};

#endif // SPWORKINTERFACE_H
