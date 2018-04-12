#include "interface.h"
#include <QApplication>
#include "client.h"

/**
 * @brief Inicio de la aplicación
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{

    /*
    QApplication a(argc, argv);
    Interface w;
    w.setWindowTitle("C! - IDE");
    w.show();

    return a.exec();*/

    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Client::tr("C! Client"));
    Client client;
    client.show();
    return app.exec();


}



