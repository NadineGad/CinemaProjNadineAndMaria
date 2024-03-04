#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent, const QString &usernames, int ages)
        : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_RegisterPushButton_clicked()
{
    hide();
    RegisterWindow *registerwindow = new RegisterWindow();
    registerwindow->show();
}

