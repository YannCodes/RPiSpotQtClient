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

#ifndef RPiSpotQtClient_H
#define RPiSpotQtClient_H

#ifndef QT5
    #include <QtGui>
#else 
    #include <QtWidgets>
#endif
#include <QtNetwork>

class RPiSpotQtClient : public QMainWindow
{
    Q_OBJECT

public:
    RPiSpotQtClient();
    virtual ~RPiSpotQtClient();

public slots:
    void ButtonsSlot(int);
    void sliderONESlot(int);
    void sliderTWOSlot(int);
    void sliderTHREESlot(int);
    void sliderFOURSlot(int);
    void sliderFIVESlot(int);
    void sliderSIXSlot(int);
    void writeSocket();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *socket;
    QLineEdit *IP;
    QSpinBox *port;
    QPushButton *sendONE;
    QPushButton *sendTWO;
    QPushButton *sendTHREE;
    QPushButton *sendFOUR;
    QPushButton *sendFIVE;
    QPushButton *sendSIX;
    QSlider *sliderONE;
    QSlider *sliderTWO;
    QSlider *sliderTHREE;
    QSlider *sliderFOUR;
    QSlider *sliderFIVE;
    QSlider *sliderSIX;
    QLabel *labelONE;
    QLabel *labelTWO;
    QLabel *labelTHREE;
    QLabel *labelFOUR;
    QLabel *labelFIVE;
    QLabel *labelSIX;
    QLabel *sliderLabelONE;
    QLabel *sliderLabelTWO;
    QLabel *sliderLabelTHREE;
    QLabel *sliderLabelFOUR;
    QLabel *sliderLabelFIVE;
    QLabel *sliderLabelSIX;
    QString *state;
    QButtonGroup *buttonGroup;
};

#endif // RPiSpotQtClient_H
