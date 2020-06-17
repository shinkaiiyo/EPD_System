#include "javaconnect.h"
#include <QString>
#include <QDebug>


JavaConnect::JavaConnect()
{

}

void JavaConnect::client()
{
    socket = new QTcpSocket();
//    connect(socket,SIGNAL(readyRead()),this,SLOT(getmsg()));
    QString ip = "127.0.0.1";
    int port = 8888;
    socket->connectToHost(ip, port);
    if(!socket->waitForConnected(30000))
    {
        qDebug() << "QT网络通信" <<"连接服务端失败！";
        return;
    }
}

void JavaConnect::sendmsg(QString name)
{
    //获取TextEdit控件中的内容
    char sendMsgChar[1024] = {0};
    auto nameWithSplit = name + "\n";
    qDebug() << "name: " <<nameWithSplit;
    strcpy_s(sendMsgChar,nameWithSplit.toStdString().c_str());
    int sendRe = socket->write(sendMsgChar, strlen(sendMsgChar));
    if(sendRe == -1)
    {
        qDebug() <<  "QT网络通信" << "向服务端发送数据失败！";
        return;
    }
}

QString JavaConnect::getmsg()
{
    //将接收内容存储到字符串中
    char recvMsg[1024] = {0};
    socket->waitForReadyRead(3000);
    int recvRe = socket->readLine(recvMsg, 1023);
    if(recvRe == -1)
    {
        qDebug() << "QT网络通信" << "接收服务端数据失败！";
    }
    QString showQstr = recvMsg;
    qDebug() << "showQstr: " << showQstr;
    return showQstr.split("\r\n")[0];
}
