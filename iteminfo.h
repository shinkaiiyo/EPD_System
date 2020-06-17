#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <QWidget>

namespace Ui {
class iteminfo;
}

class ItemInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ItemInfo(const QString& items,QWidget *parent = 0);
    ~ItemInfo();
    QString spname;

private slots:
    void shutdown();

private:
    Ui::iteminfo *ui;
    QString items;
};

#endif // ITEMINFO_H
