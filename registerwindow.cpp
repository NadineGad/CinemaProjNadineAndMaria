#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "loginwindow.h"
RegisterWindow::RegisterWindow(QWidget *parent, const QString &usernames, int ages)
        : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->labelErrorUsername->setVisible(false);
    ui->labelErrorPass->setVisible(false);
    ui->labelErrorAge->setVisible(false);
    ui->labelErrorAllFields->setVisible(false);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_RegisterPushButton_clicked()
{

    QString name = ui->lineEditUsername->text();
    usernames[usersCount-1]=name;
    if (*usernames == name)
    {
        ui->labelErrorUsername->setVisible(true);
        return;
    }


    QString password = ui->lineEditPass->text();
     passwords[usersCount-1]=password;
    QString retype = ui->lineEditRetype->text();
        if (password != retype)
    {
        ui->labelErrorPass->setVisible(true);
        return;
    }

    QString month = ui->comboBoxMonth->currentText();
    int day =ui->lineEditDay->text().toInt();
    int year = ui->lineEditYear->text().toInt();
    if (year > 2024 - 12)
    {
        ui->labelErrorAge->setVisible(true);
        return;
    }

    bool isMaleChecked = ui->radioButtonMale->isChecked();
    bool isFemaleChecked = ui->radioButtonFemale->isChecked();

    bool isUser = ui->radioButtonUser->isChecked();
    bool isAdmin = ui->radioButtonAdmin->isChecked();

    bool isAction =ui->checkBoxAction->isChecked();
    bool isDrama =ui->checkBoxDrama->isChecked();
    bool isComedy =ui->checkBoxComedy->isChecked();
    bool isHorror =ui->checkBoxHorror->isChecked();
    bool isRomance =ui->checkBoxRomance->isChecked();
    bool isOther =ui->checkBoxOther->isChecked();

    if (name.isEmpty() ||
        password.isEmpty() ||
        retype.isEmpty() ||
        (!isMaleChecked && !isFemaleChecked) ||
        (!isUser && !isAdmin) ||
        (!isAction && !isDrama && !isComedy && !isHorror && !isRomance && !isOther) ||
        ui->lineEditDay->text().isEmpty() ||
        ui->lineEditYear->text().isEmpty() ||
        month.isEmpty())
    {
        ui->labelErrorAllFields->setVisible(true);
        return;
    }


    usersCount++;

    hide();
    WelcomeWindow *welcome = new WelcomeWindow(this, name, 2024-year);
    welcome->show();
}



