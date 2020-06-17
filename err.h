#ifndef ERR_H
#define ERR_H

#include <QWidget>

namespace Ui {
class err;
}

class Err : public QWidget
{
    Q_OBJECT

public:
    explicit Err(QWidget *parent = 0);
    ~Err();

private slots:
    void exit();
private:
    Ui::err *ui;
};

#endif // ERR_H
