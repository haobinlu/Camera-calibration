#include "pic_hard_sync.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pic_hard_sync w;
    w.show();
    return a.exec();
}
