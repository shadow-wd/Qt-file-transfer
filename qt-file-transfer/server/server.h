#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>


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





private slots:

    void on_openfile_clicked();

    void on_closeconnect_clicked();

    void acceptconnect();

    void ondisconnect();

    void receiveData();

    void on_clearmessage_clicked();

private:
    Ui::server *ui;

    bool isConnect;
};

#endif // SERVER_H
