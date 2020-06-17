#ifndef JAVACONNECT_H
#define JAVACONNECT_H
#include <QtNetwork>
#include <QObject>
class JavaConnect: public QObject
{
    Q_OBJECT
public:
    JavaConnect();
    ~JavaConnect() = default;
    void client();
    void sendmsg(QString name);

public slots:

    QString getmsg();

private:

    QTcpSocket *socket;

};

#endif // JAVACONNECT_H
