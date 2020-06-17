#ifndef EXISTINGUSERS_H
#define EXISTINGUSERS_H

#include <QWidget>

namespace Ui {
class existingUsers;
}

class ExistingUsers : public QWidget
{
    Q_OBJECT

public:
    explicit ExistingUsers(const QString& users,QWidget *parent = 0);
    ~ExistingUsers();

private slots:
    void shutdown();

private:
    QString users;
    Ui::existingUsers *ui;
};

#endif // EXISTINGUSERS_H
