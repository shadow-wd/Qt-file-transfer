#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>

class Server : public QMainWindow
{
    Q_OBJECT
public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void showMessage();

private:
    QAction *showMessageAction;
};

#endif // SERVER_H
