#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userfunction.h"
#include "clientSocket.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    void createTable();
    void createAction();
    void createMenu();
    void createToolBar();
    void createStatusBar();

    Widget *clientWidget;

    QTableWidget *mainTable;
    QAction *newAction;
    QAction *editAction;
    QAction *searchAction;
    QAction *configAction;
    QAction *debugAction;
    QAction *aboutQtAction;
    QAction *aboutAppAction;

    QLabel *timeLabel;
    QString time;

    QMenu *fileMenu;
    QToolBar *fileToolBar;

public slots:
    void shuchu();
    void updateTime();
//    void peizhi();
    void aboutApp();
    void debug();

};






#endif // MAINWINDOW_H
