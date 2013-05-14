#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QtGui>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //使用UTF-8编码，显示中文

    QSplashScreen splash(QPixmap(":/png/img/splash.jpg"));  //添加启动画面
    splash.show();

    /******************延时*******************/
    QMutex mutex;
    QWaitCondition sleep;
    mutex.lock();
    sleep.wait(&mutex, 500);
    mutex.unlock();

    SLoginDlg sLogin;
    MainWindow w;

    splash.finish(&sLogin);
    while(sLogin.exec())
    {
        w.show();
        sLogin.hide();
        break;
    }

    return app.exec();
}
