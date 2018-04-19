#ifndef CLIENTE_H
#define CLIENTE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>

namespace Ui {
class Cliente;
}

class Cliente : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cliente(QWidget *parent = 0);
    ~Cliente();

public slots:

    void leer_socketservidor();

private slots:
    void on_Escribiralservidor_clicked();

private:
    Ui::Cliente *ui;
    QTcpSocket *tcpcliente;
};

#endif // CLIENTE_H
