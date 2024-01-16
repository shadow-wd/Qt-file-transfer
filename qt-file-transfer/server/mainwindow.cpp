#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    printf("ssg\n");
}

MainWindow::~MainWindow()
{
    delete ui;
    printf("exit file-transfer app\n");
}

