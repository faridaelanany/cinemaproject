#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->error->setVisible(true);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_login_clicked()
{
    bool SuccessfulLogin = false;
    for (int i=0; i<usersCount; i++)
    {
        if ((usernames[i] == ui->Username->text()) && (passwords[i] == ui->Password->text()))
        {
            hide();
            WelcomeWindow* welcomewindow = new WelcomeWindow(usernames[i], ages[i]);
            welcomewindow->show();

            SuccessfulLogin = true;
        }
    }

    if (SuccessfulLogin == false)
        ui->error->setVisible(true);
}


void LoginWindow::on_Register_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}


