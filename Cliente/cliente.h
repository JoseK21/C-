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

    void on_actionExit_triggered();

    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_run_clicked();

    void on_stop_clicked();

    void on_go_on_clicked();

    void on_clear_clicked();

private:
    Ui::Cliente *ui;
    QTcpSocket *tcpcliente;
};

#endif // CLIENTE_H
