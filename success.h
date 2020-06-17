#ifndef SUCCESS_H
#define SUCCESS_H

#include <QWidget>

namespace Ui {
class success;
}

class Success : public QWidget
{
    Q_OBJECT

public:
    explicit Success(QWidget *parent = 0);
    ~Success();

private slots:
    void exit();

private:
    Ui::success *ui;
};

#endif // SUCCESS_H
