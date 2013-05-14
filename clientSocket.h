#ifndef WIDGET_H
#define WIDGET_H

#include <QtNetwork>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_clicked();
    void readMessage();

    void on_clientRB_clicked();

    void on_serverRB_clicked();

private:
    Ui::Widget *ui;

    QTcpSocket *clientSocket;
    QString message;
    quint16 blockSize;

};

#endif // WIDGET_H
