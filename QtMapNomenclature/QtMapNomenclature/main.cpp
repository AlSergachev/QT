#include "QtMapNomenclature.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //���������
    QApplication a(argc, argv);
    QtMapNomenclature w;
    w.show();
    return a.exec();
}
