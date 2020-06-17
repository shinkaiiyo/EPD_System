#ifndef ITEMCHANGE_H
#define ITEMCHANGE_H

#include <QWidget>

namespace Ui {
class ItemChange;
}

class ItemChange : public QWidget
{
    Q_OBJECT

public:
    explicit ItemChange(const QString& items, QWidget *parent = 0);
    ~ItemChange();


private slots:
    void commit();
    void shutdown();

private:
    QString items;
    Ui::ItemChange *ui;
};

#endif // ITEMCHANGE_H
