#include "cliente.h"
#include <QApplication>

/**
 * @brief Clase main : Clase inicial : Inicializador del programa
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cliente w;
    w.setWindowTitle("__________ C ! __________");
    w.show();

    return a.exec();
}
