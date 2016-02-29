#ifndef QT5
    #include <QtGui/QApplication>
#else
    #include <QApplication>
#endif

#include "RPiSpotQtClient.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    RPiSpotQtClient rpispot;
    rpispot.setWindowTitle("RPiSpotQtClient");
    rpispot.show();
    return app.exec();
}
