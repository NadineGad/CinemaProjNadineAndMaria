#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWIndow;
}
QT_END_NAMESPACE

class LoginWIndow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWIndow(QWidget *parent = nullptr);
    ~LoginWIndow();

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButtonRegister_clicked();

private:
    Ui::LoginWIndow *ui;
};
#endif // LOGINWINDOW_H
