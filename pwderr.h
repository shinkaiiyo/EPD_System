#ifndef PWDERR_H
#define PWDERR_H

#include <QWidget>

namespace Ui {
class pwderr;
}

class PwdErr : public QWidget
{
    Q_OBJECT

public:
    explicit PwdErr(QWidget *parent = 0);
    ~PwdErr();

private slots:
    void exit();

private:
    Ui::pwderr *ui;
};

#endif // PWDERR_H
