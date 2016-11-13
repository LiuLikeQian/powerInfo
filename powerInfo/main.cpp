#include "powertable.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    powerTable w;

    w.show();

    return a.exec();
}
