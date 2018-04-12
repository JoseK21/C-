#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>

#include "observer.cpp"
#include "listasimple.cpp"

using namespace std;

namespace Ui {
class Interface;
}



/**
 * @brief Clase Interface
 *
 */
class Interface : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Interfaz
     *
     * @param parent
     */
    explicit Interface(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~Interface();

private slots:
    /**
     * @brief Ejecutador del codigo
     *
     */
    void on_Run_clicked();

    /**
     * @brief Limpiador de Application Log
     *
     */
    void on_ButtonClear_clicked();
    /**
     * @brief inicializador un nuevo codigo
     *
     */
    void on_NewFile_triggered();

    /**
     * @brief Apertura de codigo desde PC
     *
     */
    void on_Open_File_triggered();

    void on_Stop_clicked();

    void on_GoOn_clicked();

private:
        Ui::Interface *ui; /**< TODO: describe */
    };

    #endif // INTERFACE_H

