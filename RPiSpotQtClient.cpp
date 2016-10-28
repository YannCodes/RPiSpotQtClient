/*  RPiSpotQtClient
 *  Copyright (C) 2016  Yann Lochet
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QT5
    #include <QtGui>
#else 
    #include <QtWidgets>
#endif

#include "RPiSpotQtClient.h"
#include <QtNetwork>
#include <string>

#define SIDE 60
#define SQY 390-SIDE
#define SLY 85
#define H 200
#define SLX SIDE/2
//#define SLWIDTH 20

RPiSpotQtClient::RPiSpotQtClient()
{
    setFixedSize(430,400);

    //instantiation of attributes
    
    socket = new QTcpSocket(this);

    state = new QString("on"); //temporary
    
    IP = new QLineEdit(this);
    port = new QSpinBox(this);
    
    labelONE = new QLabel("Spot 1",this);
    labelTWO = new QLabel("Spot 2",this);
    labelTHREE = new QLabel("Spot 3",this);
    labelFOUR = new QLabel("Spot 4",this);
    labelFIVE = new QLabel("Spot 5",this);
    labelSIX = new QLabel("Spot 6",this);
    
    sliderONE = new QSlider(this);
    sliderTWO = new QSlider(this);
    sliderTHREE = new QSlider(this);
    sliderFOUR = new QSlider(this);
    sliderFIVE = new QSlider(this);
    sliderSIX = new QSlider(this);
    
    sliderLabelONE = new QLabel("0",this);
    sliderLabelTWO = new QLabel("0",this);
    sliderLabelTHREE = new QLabel("0",this);
    sliderLabelFOUR = new QLabel("0",this);
    sliderLabelFIVE = new QLabel("0",this);
    sliderLabelSIX = new QLabel("0",this);
    
    sendONE = new QPushButton("Send",this);
    sendTWO = new QPushButton("Send",this);
    sendTHREE = new QPushButton("Send",this);
    sendFOUR = new QPushButton("Send",this);
    sendFIVE = new QPushButton("Send",this);
    sendSIX = new QPushButton("Send",this);
    
    buttonGroup = new QButtonGroup(this);
    
    //adding all buttons to group
    
    buttonGroup->addButton(sendONE,1);
    buttonGroup->addButton(sendTWO,2);
    buttonGroup->addButton(sendTHREE,3);
    buttonGroup->addButton(sendFOUR,4);
    buttonGroup->addButton(sendFIVE,5);
    buttonGroup->addButton(sendSIX,6);
    
    //setting up slider maximum
    
    sliderONE->setMaximum(100);
    sliderTWO->setMaximum(100);
    sliderTHREE->setMaximum(100);
    sliderFOUR->setMaximum(100);
    sliderFIVE->setMaximum(100);
    sliderSIX
    ->setMaximum(100);
    
    //setting up the geometry

    IP->setGeometry(10,10,150,30);
    port->setGeometry(170,10,120,30);
    
    labelONE->setGeometry(10,50,SIDE,30);
    labelTWO->setGeometry((SIDE + 10)+10,50,SIDE,30);
    labelTHREE->setGeometry((SIDE + 10)*2+10,50,SIDE,30);
    labelFOUR->setGeometry((SIDE + 10)*3+10,50,SIDE,30);
    labelFIVE->setGeometry((SIDE + 10)*4+10,50,SIDE,30);
    labelSIX->setGeometry((SIDE + 10)*5+10,50,SIDE,30);
    
    labelONE->setAlignment(Qt::AlignCenter);
    labelTWO->setAlignment(Qt::AlignCenter);
    labelTHREE->setAlignment(Qt::AlignCenter);
    labelFOUR->setAlignment(Qt::AlignCenter);
    labelFIVE->setAlignment(Qt::AlignCenter);
    labelSIX->setAlignment(Qt::AlignCenter);
    
    sliderONE->setGeometry(SLX,SLY,20,H);
    sliderTWO->setGeometry((SLX + SIDE + 10),SLY,20,H);
    sliderTHREE->setGeometry((SIDE + 10)*2+SLX,SLY,20,H);
    sliderFOUR->setGeometry((SIDE + 10)*3+SLX,SLY,20,H);
    sliderFIVE->setGeometry((SIDE + 10)*4+SLX,SLY,20,H);
    sliderSIX->setGeometry((SIDE + 10)*5+SLX,SLY,20,H);
    
    sliderLabelONE->setGeometry(10,290,SIDE,30);
    sliderLabelTWO->setGeometry((SIDE + 10)+10,290,SIDE,30);
    sliderLabelTHREE->setGeometry((SIDE + 10)*2+10,290,SIDE,30);
    sliderLabelFOUR->setGeometry((SIDE + 10)*3+10,290,SIDE,30);
    sliderLabelFIVE->setGeometry((SIDE + 10)*4+10,290,SIDE,30);
    sliderLabelSIX->setGeometry((SIDE + 10)*5+10,290,SIDE,30);
    
    sliderLabelONE->setAlignment(Qt::AlignCenter);
    sliderLabelTWO->setAlignment(Qt::AlignCenter);
    sliderLabelTHREE->setAlignment(Qt::AlignCenter);
    sliderLabelFOUR->setAlignment(Qt::AlignCenter);
    sliderLabelFIVE->setAlignment(Qt::AlignCenter);
    sliderLabelSIX->setAlignment(Qt::AlignCenter);
    
    sendONE->setGeometry(10,SQY,SIDE,SIDE);
    sendTWO->setGeometry((SIDE + 10)+10,SQY,SIDE,SIDE);
    sendTHREE->setGeometry((SIDE + 10)*2+10,SQY,SIDE,SIDE);
    sendFOUR->setGeometry((SIDE + 10)*3+10,SQY,SIDE,SIDE);
    sendFIVE->setGeometry((SIDE + 10)*4+10,SQY,SIDE,SIDE);
    sendSIX->setGeometry((SIDE + 10)*5+10,SQY,SIDE,SIDE);
    
    IP->setInputMask("000.000.000.000");
    port->setRange(0,65535);

    //IP->insert("192.168.0.11");
    IP->insert("127.0.0.1");
    port->setValue(12345);
    
    connect(buttonGroup,SIGNAL(buttonClicked(int)), this, SLOT(ButtonsSlot(int)));
    connect(socket, SIGNAL(connected()), this, SLOT(writeSocket()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));
    
    connect(sliderONE,SIGNAL(valueChanged(int)), this, SLOT(sliderONESlot(int)));
    connect(sliderTWO,SIGNAL(valueChanged(int)), this, SLOT(sliderTWOSlot(int)));
    connect(sliderTHREE,SIGNAL(valueChanged(int)), this, SLOT(sliderTHREESlot(int)));
    connect(sliderFOUR,SIGNAL(valueChanged(int)), this, SLOT(sliderFOURSlot(int)));
    connect(sliderFIVE,SIGNAL(valueChanged(int)), this, SLOT(sliderFIVESlot(int)));
    connect(sliderSIX,SIGNAL(valueChanged(int)), this, SLOT(sliderSIXSlot(int)));
}

RPiSpotQtClient::~RPiSpotQtClient()
{}

void RPiSpotQtClient::ButtonsSlot(int id)
{
    QString color;
    int value = 1;
    state->clear();
    state->append("on");
    
    switch(id)
    {
        case 1:
            color = "Bl1";
            value = sliderONE->value();
            break;
        case 2:
            color = "Bl2";
            value = sliderTWO->value();
            break;
        case 3:
            color = "Gre";
            value = sliderTHREE->value();
            break;
        case 4:
            color = "Yel";
            value = sliderFOUR->value();
            break;
        case 5:
            color = "Ora";
            value = sliderFIVE->value();
            break;
        case 6:
            color = "Red";
            value = sliderSIX->value();
            break;
    }
    
    if(value == 0)
    {
        state->clear();
        state->append("of");
    }
    
    state->append(color); //temporary
    
    socket->abort();
    socket->connectToHost(IP->text(), port->value());
}

void RPiSpotQtClient::writeSocket()
{
    socket->write(state->toLocal8Bit());
}

void RPiSpotQtClient::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, "Error","The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, "Error","The connection was refused by the peer. Make sure the server is running, and check that the host name and port settings are correct.");
        break;
    default:
        QMessageBox::critical(this, "Error",tr("The following error occurred: %1.").arg(socket->errorString()));
    }
}

void RPiSpotQtClient::sliderONESlot(int value)
{
    sliderLabelONE->setText(QString::number(value));
}

void RPiSpotQtClient::sliderTWOSlot(int value)
{
    sliderLabelTWO->setText(QString::number(value));
}

void RPiSpotQtClient::sliderTHREESlot(int value)
{
    sliderLabelTHREE->setText(QString::number(value));
}

void RPiSpotQtClient::sliderFOURSlot(int value)
{
    sliderLabelFOUR->setText(QString::number(value));
}

void RPiSpotQtClient::sliderFIVESlot(int value)
{
    sliderLabelFIVE->setText(QString::number(value));
}

void RPiSpotQtClient::sliderSIXSlot(int value)
{
    sliderLabelSIX->setText(QString::number(value));
}

//#include "RPiSpotQtClient.moc" //please comment if not using kdevelop
