#include <QApplication>
#include "opengllibrary/openglwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenglWidget openglWidget;
    openglWidget.show();

    return a.exec();
}
