#include"login.h"
#include<QtGui/QtGui>

SLoginDlg::SLoginDlg(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("登录"));
    QLabel *userLabel = new QLabel(tr("用户名"));
    QLabel *pwdLabel = new QLabel(tr("密码"));
    userLineEdit = new QLineEdit;
    pwdLineEdit = new QLineEdit;
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    userLineEdit->setPlaceholderText(tr("条码号/学号"));
    pwdLineEdit->setPlaceholderText(tr("请输入密码"));

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(userLabel,0,0,1,1);
    gridLayout->addWidget(userLineEdit,0,1,1,3);
    gridLayout->addWidget(pwdLabel,1,0,1,1);
    gridLayout->addWidget(pwdLineEdit,1,1,1,3);

    QPushButton *okButton = new QPushButton(tr("登录"));
    QPushButton *cancelButton = new QPushButton(tr("取消"));

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->setSpacing(60);
    btnLayout->addWidget(okButton);
    btnLayout->addWidget(cancelButton);
    QVBoxLayout *faceLayout = new QVBoxLayout;
    faceLayout->setMargin(40);
    faceLayout->addLayout(gridLayout);
    faceLayout->setMargin(40);
    faceLayout->addLayout(btnLayout);
    setLayout(faceLayout);

    connect(okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(reject()));

    //connect(cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    resize(300,150);
    setStyleSheet("background-image:url(:/png/img/login.jpg);");
}
SLoginDlg::~SLoginDlg()
{
    delete userLineEdit;
    delete pwdLineEdit;
}
void SLoginDlg::accept()
{
    if(userLineEdit->text().trimmed()==tr("admin")&&
            pwdLineEdit->text()==tr("admin"))         //trimmed()是过滤其中的非法字符
    {
        QDialog::accept();
    }
    else
    {
        QMessageBox::warning(this,tr("错误"),tr("用户名或密码错误，请检查大小写是否规范"),QMessageBox::Yes);
        userLineEdit->clear();
        pwdLineEdit->clear();
        userLineEdit->setFocus();
    }
}

