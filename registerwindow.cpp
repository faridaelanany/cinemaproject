#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"


RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_Register_clicked()
{
    QString Username, Password, RePassword, Month, Day, Gender, Acctype;
    QString Genre[6];
    int Year, age;
    bool error = false;
    bool BGenre = false;
    bool BGender = false;
    bool BAccType = false;


    ui->AlreadyExisting->setVisible(false);
    ui->notmatching->setVisible(false);
    ui->ageislessthan12->setVisible(false);
    ui->allfieldsmustbefilled->setVisible(false);

    Username = ui->Username->text();
    Password = ui->Password->text();
    RePassword = ui->Retypepassword->text();
    Month = ui->month_2->currentText();
    Day = ui->day_2->text();
    Year = ui->year->text().toInt();

    if (ui->male->isChecked())
    {
        Gender = "Male";
        BGender = true;
    }
    else
    {
        Gender = "Female";
        BGender = true;
    }

    if (ui->admin->isChecked())
    {
        Acctype = "Admin";
        BAccType = true;
    }
    else
    {
        Acctype = "User";
        BAccType = true;
    }

    int count = -1;
    if (ui->action->isChecked())
    {
        Genre[++count] = "Action";
        BGenre = true;
    }
    if (ui->Comedy->isChecked())
    {
        Genre[++count] = "Comedy";
        BGenre = true;
    }
    if (ui->Drama->isChecked())
    {
        Genre[++count] = "Drama";
        BGenre = true;
    }
    if (ui->Horror->isChecked())
    {
        Genre[++count] = "Horror";
        BGenre = true;
    }
    if (ui->Romance->isChecked())
    {
        Genre[++count] = "Romance";
        BGenre = true;
    }
    if (ui->other->isChecked())
    {
        Genre[++count] = "Other";
        BGenre = true;
    }

    for (int i = 0; i<usersCount; i++)
    {
        if (usernames[i] == Username)
        {
            ui->AlreadyExisting->setVisible(true);
            error = true;
        }
    }

    if (Password != RePassword)
    {
        ui->notmatching->setVisible(true);
        error = true;
    }

    age = 2023-Year;

    if (age < 12)
    {
        ui->ageislessthan12->setVisible(true);
        error = true;
    }

    if ((BGender == false)||(BAccType == false))
    {
        ui->allfieldsmustbefilled->setVisible(true);
        error = true;
    }

    if (BGenre == false)
    {
        ui->allfieldsmustbefilled->setVisible(true);
        error = true;
    }

    if (error == false)
    {
        usernames[usersCount] = Username;
        passwords[usersCount] = Password;
        usersCount++;
        ages[usersCount] = age;
        hide();
        WelcomeWindow* welcomewindow = new WelcomeWindow(Username,age);
        welcomewindow->show();
    }
}


