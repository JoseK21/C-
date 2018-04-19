#include "interface.h"
#include <QApplication>

#include <iostream>
#include "unistd.h"

using namespace std;

/**
 * @brief Inicio de la aplicación
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Interface w;
    w.show();
    return a.exec();

}



