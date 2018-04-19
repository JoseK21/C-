#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>

//No utilizar <QList>

namespace Ui {
class servidor;
}

class servidor : public QMainWindow
{
    Q_OBJECT

public:
    explicit servidor(QWidget *parent = 0);
    ~servidor();

public slots:
    void conexion_nueva();
    void leer_socketcliente();

private slots:

    void on_client1_clicked();

    void on_client2_clicked();

private:
    Ui::servidor *ui;

    QTcpServer *tcpservidor;
    QTcpSocket *tcpcliente[2];

};

#endif // SERVIDOR_H
