#ifndef ITEMCREATE_H
#define ITEMCREATE_H

#include <QWidget>

namespace Ui {
class ItemCreate;
}

class ItemCreate : public QWidget
{
    Q_OBJECT

public:
    explicit ItemCreate(const QString& users, QWidget *parent = 0);
    QString marketname;
    ~ItemCreate();

private slots:
    void commit();
    void reload();
    void shutdown();

private:
    QString users;
    Ui::ItemCreate *ui;
};

#endif // ITEMCREATE_H
