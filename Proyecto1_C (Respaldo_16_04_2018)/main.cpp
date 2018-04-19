#include "interface.h"
#include <QApplication>

#include <iostream>
#include "rmlib.h"
#include "unistd.h"

/**
 * @brief Inicio de la aplicación
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[])
{
    char *x = "2";
    RMLib::rm_init("172.18.42.143",8888);
    RMLib::rm_new(x);

    RMnode<int,string> node = RMLib::rm_get(4321);
    cout<<node.key;
    RMLib::rm_delete(4321);




    QApplication a(argc, argv);
    Interface w;
    w.setWindowTitle("C! - IDE");
    w.show();

    return a.exec();
/*
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Client::tr("C! Client"));
    Client client;
    client.show();
    return app.exec();

*/
}



