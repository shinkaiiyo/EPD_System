#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>

namespace Ui {
class changePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = 0);
    QString account;
    ~ChangePassword();

private slots:
    void commit();
    void exit();

private:
    Ui::changePassword *ui;
};

#endif // CHANGEPASSWORD_H
