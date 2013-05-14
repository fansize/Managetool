#include "clientSocket.h"
#include "ui_clientSocket.h"
#include <QtNetwork>
#include <QtGui>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost(ui->ipText->text(), ui->portText->text().toInt());
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void Widget::readMessage()
{
    QDataStream in(clientSocket);
    in>>message;
    ui->messageLabel->setText(message);
}

void Widget::on_clientRB_clicked()
{
    ui->ipText->setEnabled(false);
    ui->pushButton->setText(tr("监听"));
}

void Widget::on_serverRB_clicked()
{
    ui->ipText->setEnabled(true);
    ui->pushButton->setText(tr("连接"));
}
