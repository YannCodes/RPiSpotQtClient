#ifndef QT5
    #include <QtGui>
#else 
    #include <QtWidgets>
#endif

#include "RPiSpotQtClient.h"
#include <QtNetwork>
#include <string>

RPiSpotQtClient::RPiSpotQtClient()
{
    setFixedSize(300,265);

    socket = new QTcpSocket(this);

    IP = new QLineEdit(this);
    port = new QSpinBox(this);
    ONEon = new QPushButton("Turn on spot 1",this);
    ONEoff = new QPushButton("Turn off spot 1",this);
    TWOon = new QPushButton("Turn on spot 2",this);
    TWOoff = new QPushButton("Turn off spot 2",this);
    THREEon = new QPushButton("Turn on spot 3",this);
    THREEoff = new QPushButton("Turn off spot 3",this);

    IP->setGeometry(10,10,150,30);
    port->setGeometry(170,10,120,30);
    ONEon->setGeometry(10,45,280,30);
    ONEoff->setGeometry(10,80,280,30);
    TWOon->setGeometry(10,120,280,30);
    TWOoff->setGeometry(10,155,280,30);
    THREEon->setGeometry(10,195,280,30);
    THREEoff->setGeometry(10,230,280,30);

    IP->setInputMask("000.000.000.000");
    port->setRange(0,65535);

    IP->insert("192.168.0.11");
    port->setValue(12345);

    connect(ONEon, SIGNAL(clicked()), this, SLOT(ONEonSlot()));
    connect(ONEoff, SIGNAL(clicked()), this, SLOT(ONEoffSlot()));

    connect(TWOon, SIGNAL(clicked()), this, SLOT(TWOonSlot()));
    connect(TWOoff, SIGNAL(clicked()), this, SLOT(TWOoffSlot()));

    connect(THREEon, SIGNAL(clicked()), this, SLOT(THREEonSlot()));
    connect(THREEoff, SIGNAL(clicked()), this, SLOT(THREEoffSlot()));
}

RPiSpotQtClient::~RPiSpotQtClient()
{}

void RPiSpotQtClient::ONEonSlot()
{
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
    socket->write("1on");
}

void RPiSpotQtClient::ONEoffSlot()
{
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
    socket->write("1of");
}

void RPiSpotQtClient::TWOonSlot()
{
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
    socket->write("2on");
}

void RPiSpotQtClient::TWOoffSlot()
{
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
    socket->write("2of");
}

void RPiSpotQtClient::THREEonSlot()
{
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
    socket->write("3on");
}

void RPiSpotQtClient::THREEoffSlot()
{
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
    socket->write("3of");
}

#include "RPiSpotQtClient.moc" //please comment if not using kdevelop
