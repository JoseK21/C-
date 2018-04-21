#ifndef CLIENTE_H
#define CLIENTE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>

namespace Ui {
class Cliente;
}

/**
 * @brief
 *
 */
class Cliente : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit Cliente(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~Cliente();

public slots:

    /**
     * @brief
     *
     */
    void leer_socketservidor();

private slots:

    /**
     * @brief
     *
     * @param da
     */
    void on_Escribiralservidor_clicked(const QString da);

    /**
     * @brief
     *
     */
    void on_actionExit_triggered();

    /**
     * @brief
     *
     */
    void on_actionNew_File_triggered();

    /**
     * @brief
     *
     */
    void on_actionOpen_File_triggered();

    /**
     * @brief
     *
     */
    void on_run_clicked();

    /**
     * @brief
     *
     */
    void on_stop_clicked();

    /**
     * @brief
     *
     */
    void on_go_on_clicked();

    /**
     * @brief
     *
     */
    void on_clear_clicked();

private:
    Ui::Cliente *ui; /**< TODO: describe */
    QTcpSocket *tcpcliente; /**< TODO: describe */
};

#endif // CLIENTE_H
