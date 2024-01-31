#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QAbstractSocket>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT



public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    QTcpSocket *p_socket;

    QString sourcefilepath;
    void message_display();

    QString getlocaladdr();

    bool isConnected();

private slots:

    void ondisconnect();

    void receiveData();

    void socketstatechange(QAbstractSocket::SocketState state);

    void on_selectFile_clicked();

    void on_copybutton_clicked();

    void on_clearmessage_clicked();

    void on_connect_clicked();

    void on_disconnect_clicked();

private:
    Ui::Client *ui;

};

#endif // CLIENT_H
