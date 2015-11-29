#include <QtGui/QApplication>
#include "RPiSpotQtClient.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    RPiSpotQtClient rpispot;
    rpispot.setWindowTitle("RPiSpotQtClient");
    rpispot.show();
    return app.exec();
}
