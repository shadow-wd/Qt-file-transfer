#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTcpServer>
#include <QTcpSocket>


namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

    QTcpSocket *p_socket;

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    QString sourcefilepath;
    void message_display();

private slots:
    void on_selectFile_clicked();

    void on_copybutton_clicked();

    void on_clearmessage_clicked();

    void on_connect_clicked();

    void on_disconnect_clicked();

private:
    Ui::Client *ui;

    bool isconnect;
};

#endif // CLIENT_H
