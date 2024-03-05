#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, const QString &username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString greetingText = "Hello " + username + " " + QString::number(age);
    ui->helloLabel->setText(greetingText);
    QPixmap pix ("C:\\Users\\Nadine\\Desktop\\AUC\\Semester 4\\CS2 Lab\\CinemaProject\\istockphoto-1191001701-612x612.jpg");
    int w = ui->labelWelcomePic->width();
    int h = ui->labelWelcomePic->height();
    ui->labelWelcomePic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButtonLogout_clicked()
{
    hide();
    LoginWIndow *login = new LoginWIndow(this);
    login->show();
}

