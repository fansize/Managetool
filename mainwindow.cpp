#include "mainwindow.h"
//#include "userfunction.h"

#include <QtGui>
#include <QtWebKit/QWebView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/png/img/windowIcon.png"));    //设置窗口左上角的图标
    setWindowTitle(tr("管理中心"));         //设置窗口名称
    resize(700, 400);       //固定窗体大小

    timeLabel = new QLabel();

    createTable();
    createAction();
    createMenu();
    createToolBar();
    createStatusBar();
}



void MainWindow::createTable()     //创建主题列表
{
    mainTable = new QTableWidget(5,4);
    setCentralWidget(mainTable);          //设置Table为主题中心窗体
    mainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    //设置表格不可编辑
    mainTable->verticalHeader()->setVisible(false);       //隐藏列表头
    mainTable->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    mainTable->setColumnWidth(0,200);
    mainTable->setShowGrid(false);
    QStringList list;
    list<<tr("序号")<<tr("名称")<<tr("IP")<<tr("版本");
    mainTable->setHorizontalHeaderLabels(list);     //更改列表头名称

    mainTable->setItem(0, 1, new QTableWidgetItem(tr("dfd")));
}


void MainWindow::createAction()   //创建菜单栏和工具栏中的选项
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/png/img/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip("Create");       //传递消息给状态栏

    editAction = new QAction(tr("复制"), this);

    searchAction = new QAction(tr("搜索"), this);
    searchAction->setIcon(QIcon(":/png/img/seach.png"));
    searchAction->setStatusTip(tr("搜索设备"));

    configAction = new QAction(tr("配置"), this);
    configAction->setIcon(QIcon(":/png/img/config.png"));
    configAction->setStatusTip(tr("用浏览器打开配置界面"));
    connect(configAction, SIGNAL(triggered()), this, SLOT(shuchu()));

    debugAction = new QAction(tr("调试"), this);
    debugAction->setIcon(QIcon(":/png/img/debug.png"));
    connect(debugAction, SIGNAL(triggered()), this, SLOT(debug()));


    aboutQtAction = new QAction(tr("About Qt"), this);
    aboutQtAction->setIcon(QIcon(":/png/img/qtlogo.png"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));  //qApp是一个QApplication的全局指针

    aboutAppAction = new QAction(tr("About App"), this);
    aboutAppAction->setIcon(QIcon(":/png/img/about.png"));
    connect(aboutAppAction, SIGNAL(triggered()), this, SLOT(aboutApp()));

}


void MainWindow::createMenu()    //创建菜单栏
{
    fileMenu = menuBar()->addMenu(tr("&文件"));
    fileMenu->addAction(newAction);

    fileMenu = menuBar()->addMenu(tr("&编辑"));
    fileMenu->addAction(editAction);
    fileMenu->addAction(searchAction);
    fileMenu->addAction(configAction);

    //fileMenu->addSeparator();        //添加分割条
    fileMenu = menuBar()->addMenu(tr("&关于"));
    fileMenu->addAction(aboutQtAction);
    fileMenu->addAction(aboutAppAction);

}


void MainWindow::createToolBar()    //创建工具栏
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(searchAction);
    fileToolBar->addAction(configAction);
    fileToolBar->addAction(debugAction);

    fileToolBar = addToolBar(tr("&about"));
    fileToolBar->addAction(aboutQtAction);
    fileToolBar->addAction(aboutAppAction);

}


void MainWindow::createStatusBar()     //创建状态栏
{


    QProgressBar *progressBar = new QProgressBar();

    /*定时器，每隔1s更新状态栏的时间*/
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);


    statusBar()->addWidget(timeLabel);       //状态栏添加系统时间
    statusBar()->addWidget(progressBar);        //状态栏添加进度条


}




MainWindow::~MainWindow()
{
    
}



/***********自定义槽函数*****************/

void MainWindow::aboutApp()
{

    QMessageBox::about(this, tr("About"),              //调用自带的about界面
                       tr("<h2>管理中心 1.0</h2>"
                          "<p>用<b>Qt</b>做的一个demo,纯属娱乐!"
                          "<h2><b>Perfect is Shit!!!</b></h2>"
                          "<p>Copyright &copy; 2013 Software Inc."));

}

void MainWindow::shuchu()
{
    //timeLabel = new QLabel();
    //time = QString(QDateTime::currentDateTime().toString());
    qDebug()<<"OK";


}


void MainWindow::updateTime()      //更新label上显示的系统时间
{
    time = QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));      //获得系统当前时间并转换为字符串(格式化)
    timeLabel->setText(time);

}

void MainWindow::debug()
{
    clientWidget = new Widget;
    clientWidget->setAttribute(Qt::WA_QuitOnClose,false);  //主窗口关闭触发关闭其他窗口
    clientWidget->show();

}


