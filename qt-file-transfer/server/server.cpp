#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    p_socket = nullptr;
    server::p_server = new QTcpServer(this);

    this->p_server->listen(QHostAddress::Any,6666);
    connect(this->p_server,SIGNAL(newConnection()),this,SLOT(acceptconnect()));

    QString localipaddr = getlocaladdr();
    setWindowTitle("Qtserver                      local host ipaddr: " + localipaddr);
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
    connect(p_socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(socketstatechange(QAbstractSocket::SocketState)));
    socketstatechange(p_socket->state());


    ui->message->append("socket connect!");

}


void server::ondisconnect(){
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



void server::socketstatechange(QAbstractSocket::SocketState state){

    switch (state) {
        case QAbstractSocket::UnconnectedState:
            ui->socketstate->setText("UnconnectedState");
            break;
        case QAbstractSocket::HostLookupState:
        ui->socketstate->setText("HostLookupState");
        break;
        case QAbstractSocket::ConnectingState:
            ui->socketstate->setText("ConnectingState");
            break;
        case QAbstractSocket::ConnectedState:
        ui->socketstate->setText("ConnectedState");
        break;
        case QAbstractSocket::BoundState:
            ui->socketstate->setText("BoundState");
            break;
        case QAbstractSocket::ClosingState:
        ui->socketstate->setText("ClosingState");
        break;
        case QAbstractSocket::ListeningState:
            ui->socketstate->setText("ListeningState");
            break;
    }

}


void server::on_clearmessage_clicked()
{
    ui->message->clear();
}

//------------------------------------------------------------------------------------------------
// 获取本地ip地址显示在标题
QString server::getlocaladdr(){
    QList<QHostAddress> ipAddrList = QNetworkInterface::allAddresses();
    QString localIpAddress;
    foreach (QHostAddress address, ipAddrList) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && !address.isLoopback()) {
            localIpAddress = address.toString();
            break;
        }
    }

    if (!localIpAddress.isEmpty()) {
        qDebug() << "本地主机的IPv4地址：" << localIpAddress;
    } else {
        qDebug() << "未找到本地主机的IPv4地址";
    }

    return localIpAddress;

}

//socket建立且已连接就返回true ，否则返回false
bool server::isConnected(){

    if(!p_socket){
        return false;
    }
    if(p_socket->state() != QAbstractSocket::ConnectedState){
        return false;
    }
    return true;
}
