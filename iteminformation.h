#ifndef ITEMINFORMATION_H
#define ITEMINFORMATION_H

#include <QWidget>

namespace Ui {
class itemInformation;
}

class ItemInformation : public QWidget
{
    Q_OBJECT

public:
    explicit ItemInformation(const QString& items,QWidget *parent = 0);
    ~ItemInformation();
    QString spname;

private slots:
    void shutdown();
    void del();

private:
    Ui::itemInformation *ui;
    QString items;
};

#endif // ITEMINFORMATION_H
