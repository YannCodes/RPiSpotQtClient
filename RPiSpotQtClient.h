#ifndef RPiSpotQtClient_H
#define RPiSpotQtClient_H

#include <QtGui>
#include <QtNetwork>

class RPiSpotQtClient : public QMainWindow
{
    Q_OBJECT

public:
    RPiSpotQtClient();
    virtual ~RPiSpotQtClient();

public slots:
    void ONEonSlot();
    void ONEoffSlot();
    void TWOonSlot();
    void TWOoffSlot();
    void THREEonSlot();
    void THREEoffSlot();

private:
    QTcpSocket *socket;
    QLineEdit *IP;
    QPushButton *ONEon;
    QPushButton *ONEoff;
    QPushButton *TWOon;
    QPushButton *TWOoff;
    QPushButton *THREEon;
    QPushButton *THREEoff;
    QSpinBox *port;
};

#endif // RPiSpotQtClient_H
