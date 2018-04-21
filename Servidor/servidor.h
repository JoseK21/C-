#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include "memoria.h"

namespace Ui {
class servidor;
}
/**
 * @brief Constructor de interface del servidor
 *
 */
class servidor : public QMainWindow
{
    Q_OBJECT

public:
    memoria *data= new memoria(); /**< Variable de manajador de memoria */
    /**
     * @brief Comunicador de la creacion de la interface
     *
     * @param parent
     */
    explicit servidor(QWidget *parent = 0);
    /**
     * @brief Método para eliminar la creacion de la interface
     *
     */
    ~servidor();

public slots:
    /**
     * @brief Método para establecer la comunicación con el cliente
     *
     */
    void conexion_nueva();
    /**
     * @brief Método para leer los datos enviado por el cliente
     *
     */
    void leer_socketcliente();

private slots:
    /**
     * @brief Método para establecer la conexió con el cliente
     *
     */
    void on_client1_clicked(const QString da);

private:
    Ui::servidor *ui; /**< Interface */
    QTcpServer *tcpservidor; /**< TCP_Servidor */
    QTcpSocket *tcpcliente[2]; /**< TCP_Cliente */
};

#endif // SERVIDOR_H
