#ifndef EXISTINGSALEUSER_H
#define EXISTINGSALEUSER_H

#include <QWidget>

namespace Ui {
class ExistingSaleUser;
}

class ExistingSaleUser : public QWidget
{
    Q_OBJECT

public:
    explicit ExistingSaleUser(const QString& users, QWidget *parent = 0);
    ~ExistingSaleUser();
    QString marketname;

private slots:
    void shutdown();
    void del();

private:
    QString users;
    Ui::ExistingSaleUser *ui;
};

#endif // EXISTINGSALEUSER_H
