#include "client.h"
#include "ui_client.h"
#include <QDebug>
Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);


    Client::p_socket = new QTcpSocket(this);

    // default config
    ui->ipaddr->setPlainText("172.16.151.129");
    ui->portnumber->setPlainText("6666");

    isconnect = false;

}

Client::~Client()
{
    delete ui;
    sourcefilepath="";
}


void Client::on_selectFile_clicked()
{

    sourcefilepath = QFileDialog::getOpenFileName(
                                this,
                                tr("选择源文件:"),
                                QDir::homePath(),
                                tr("文本文件 (*.txt);;所有文件 (*)")
                                );

    if(!sourcefilepath.isEmpty()){
        ui->sourcefilepathdisplay->setText(sourcefilepath);
    }

}


void Client::on_copybutton_clicked()
{
    if(sourcefilepath.isEmpty()){
        ui->message->append("source file path is error!");
        return;
    }

    QFile sourceFile(sourcefilepath);

    if(sourceFile.open(QIODevice::ReadOnly)){

        while (!sourceFile.atEnd()) {
            QByteArray data = sourceFile.read(1024);  // 读取数据块
            p_socket->write(data);          // 发送数据
        }

        sourceFile.close();
    }else{
        qDebug("source file open fail\n");
        return;
    }
    message_display();
}



void Client::on_clearmessage_clicked()
{
    ui->message->clear();
}


void Client::on_connect_clicked()
{
    QString userInput = ui->ipaddr->toPlainText();
    QString userport = ui->portnumber->toPlainText();



    QRegExp ipRegex("\\b(?:\\d{1,3}\\.){3}\\d{1,3}\\b");
    if (!ipRegex.exactMatch(userInput)) {
        // IP 地址格式不正确
        ui->message->append("Invalid IP Address "+userInput);
    }

    quint16 port = userport.toUInt();
    if(isconnect ==true){
        ui->message->append("client has connected to server!");
        return;
    }

    p_socket->connectToHost(userInput,port,QIODevice::ReadWrite);


    if(p_socket->waitForConnected()){
        ui->message->append("connect server successfully!");
        isconnect = true;
    }else{
        ui->message->append("connect server fail,timeout!");
        isconnect = false;
    }
}






void Client::on_disconnect_clicked()
{
    if(p_socket->isOpen()){
        p_socket->close();
        ui->message->append("close socket!");
        isconnect = false;
    }

}


//------------------------------------------------------------------------------
void Client::message_display(){
    ui->message->append(sourcefilepath+"  ------>  ");
    ui->message->append("copy Successfully!");
}
