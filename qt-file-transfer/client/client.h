#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>


namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    QString sourcefilepath;
    QString objectfolderpath;
    void message_display();

private slots:
    void on_selectFile_clicked();

    void on_objectfolder_clicked();

    void on_copybutton_clicked();

    void on_clearmessage_clicked();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
