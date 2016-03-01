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
    QButtonGroup *buttonGroup;
};

#endif // RPiSpotQtClient_H
