#include "servidor.h"
#include <QApplication>

/**
 * @brief Clase main
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    servidor w;
    w.show();
    return a.exec();
}
