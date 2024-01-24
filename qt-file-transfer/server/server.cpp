#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    isConnect = false;

    server::p_server = new QTcpServer(this);

    this->p_server->listen(QHostAddress::Any,6666);
    connect(this->p_server,SIGNAL(newConnection()),this,SLOT(acceptconnect()));

}


server::~server()
{
    delete ui;
}


void server::on_openfile_clicked()
{

}



void server::on_closeconnect_clicked()
{
    if(p_socket->isOpen()){
        p_socket->close();
        p_socket->deleteLater();  // 删除套接字
        ui->message->append("close socket!");
        isConnect = false;
    }
}


void server::acceptconnect(){

    this->p_socket = this->p_server->nextPendingConnection();

    connect(p_socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
    connect(this->p_socket,SIGNAL(disconnected()),this,SLOT(ondisconnect()));


    isConnect = true;
    ui->message->append("socket connect!");

}


void server::ondisconnect(){
    isConnect = false;
    ui->message->append("socket disconnect!");

}



void server::receiveData(){
    QFile file("C:/Users/dong.wang/Desktop/file.txt");


    if (file.open(QIODevice::WriteOnly)) {
        // 从套接字接收数据并写入文件
        while (p_socket->bytesAvailable() > 0) {

            QByteArray data = p_socket->read(1024);  // 读取数据
            file.write(data);                      // 写入文件
        }
        file.close();
        ui->message->append("receive file successfully!");
    }
}


void server::on_clearmessage_clicked()
{
    ui->message->clear();
}

