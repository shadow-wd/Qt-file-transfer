#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QAbstractSocket>
#include <QNetworkInterface>

namespace Ui {
class server;
}

class server : public QMainWindow
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

    QTcpServer *p_server;
    QTcpSocket *p_socket;
    QString sourcefilepath;


private slots:

    void on_closeconnect_clicked();

    void acceptconnect();

    void ondisconnect();

    void receiveData();

    void on_clearmessage_clicked();

    bool isConnected();

    void socketstatechange(QAbstractSocket::SocketState state);

    void on_selectfile_clicked();

    void on_sendfile_clicked();

private:
    Ui::server *ui;

    bool isConnect;


    QString getlocaladdr();
};

#endif // SERVER_H
