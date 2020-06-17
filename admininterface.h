#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QWidget>

namespace Ui {
class admininterface;
}

class AdminInterface : public QWidget
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = 0);
    ~AdminInterface();

private slots:
    void exit();
    void showUser();
    void addUser();

private:
    Ui::admininterface *ui;
};

#endif // ADMININTERFACE_H
