#ifndef LOGIN_H
#define LOGIN_H

#include<QtGui/QDialog>

class QLineEdit;
class SLoginDlg : public QDialog
{
    Q_OBJECT
public:
    SLoginDlg(QWidget *parent = 0);
    virtual ~SLoginDlg();
public slots:
    virtual void accept();
private:
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
};
#endif // LOGIN_H
