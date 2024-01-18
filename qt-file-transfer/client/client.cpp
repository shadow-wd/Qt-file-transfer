#include "client.h"
#include "ui_client.h"
#include <QDebug>
Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
//    setWindowTitle("file-transfer");
}

Client::~Client()
{
    delete ui;
    sourcefilepath="";
    objectfolderpath="";
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

void Client::on_objectfolder_clicked()
{
    objectfolderpath = QFileDialog::getExistingDirectory(
                                this,
                                tr("选择目标文件夹:"),
                                QDir::homePath()
                                );

    if(!objectfolderpath.isEmpty()){
        ui->objectfilepathdisplay->setText(objectfolderpath);
    }
}

void Client::on_copybutton_clicked()
{
    if(objectfolderpath.isEmpty() || sourcefilepath.isEmpty()){
        ui->message->append("source file path or object folder path is error!");
        return;
    }

    QFile sourceFile(sourcefilepath);
    QFileInfo sourceFileInfo(sourceFile);
    QString reobjectfolderpath = objectfolderpath + "/" + sourceFileInfo.fileName();
    qDebug() << reobjectfolderpath;
    QFile destinationFile(reobjectfolderpath);

    if(sourceFile.open(QIODevice::ReadOnly)){
        if(destinationFile.open(QIODevice::WriteOnly)){
            // 从源文件读取数据并写入目标文件
            QByteArray data = sourceFile.readAll();
            destinationFile.write(data);

            // 关闭文件
            destinationFile.close();
        }else{
            qDebug("object file open fail\n");
            return;
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

void Client::message_display(){
    ui->message->append(sourcefilepath+"  ------>  "+objectfolderpath);
    ui->message->append("copy Successfully!");
}
