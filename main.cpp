#include "loginwindow.h"
#include "welcomewindow.h"
#include <QApplication>
#include "users.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LoginWindow w;
    WelcomeWindow w("admin", 33);
    w.show();
    return a.exec();
}
