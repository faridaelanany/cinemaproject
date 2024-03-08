#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"
#include "users.h"



WelcomeWindow::WelcomeWindow(QString username, int age,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString str = QString::number(age);
    ui->hello->setText("Hello "+username+" "+str);
    QPixmap pix("C:\\Users\\HP\\Downloads\\welcome2.jpg");
    int w = ui->picture->width();
    int h = ui->picture->height();
    ui->picture->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logout_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();
}

