#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>

namespace Ui {
class AddUser;
}

class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = 0);
    ~AddUser();

private slots:
    void signin();
    void reload();
    void shutdown();

private:
    Ui::AddUser *ui;
};

#endif // ADDUSER_H
