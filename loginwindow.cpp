#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "ui_welcomewindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

LoginWIndow::LoginWIndow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWIndow)
{
    ui->setupUi(this);
    ui->labelError->setVisible(false);

}

LoginWIndow::~LoginWIndow()
{
    delete ui;
}

void LoginWIndow::on_pushButtonLogin_clicked()
{
    QString enteredUsername = ui->lineEditUsername->text();
    QString enteredPassword = ui->lineEditPass->text();

    int userIndex = -1;

    for (int i = 0; i < usersCount; ++i) {
        if (usernames[i] == enteredUsername && passwords[i] == enteredPassword) {
            userIndex = i;
            break;
        }
    }

    if (userIndex != -1) {
        hide();
        QString username = usernames[userIndex];
        int age = ages[userIndex];

        WelcomeWindow *welcome = new WelcomeWindow(this, username, age);
        welcome->show();
    } else {
        ui->labelError->setVisible(true);
    }
}

void LoginWIndow::on_pushButtonRegister_clicked(){
    hide();
    connect(ui->pushButtonRegister, SIGNAL(clicked()), this, SLOT(on_pushButtonRegister_clicked()));
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

