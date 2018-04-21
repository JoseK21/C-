#include "servidor.h"
#include "ui_servidor.h"
#include "memoria.h"

#include <QJsonObject>
#include <QJsonDocument>

/**
 * @brief Método crear la ventana del servidor
 *
 * @param parent
 */
servidor::servidor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::servidor)
{
    ui->setupUi(this);
    tcpservidor = new QTcpServer(this);
    tcpservidor->setMaxPendingConnections(2);

    for(int i = 0; i< tcpservidor->maxPendingConnections();i++){
        tcpcliente[i] = new QTcpSocket(this);
    }
    tcpservidor->listen(QHostAddress::LocalHost,8888);
    connect(tcpservidor,SIGNAL(newConnection()),this, SLOT(conexion_nueva()));

}

/**
 * @brief Método para borrar la llamada de la creación de la ventana
 *
 */
servidor::~servidor()
{
    delete ui;
}

/**
 * @brief Método para crear una nueva conexión
 *
 */
void servidor::conexion_nueva(){
    static int j=0;
    tcpcliente[j] = tcpservidor->nextPendingConnection();
    connect(tcpcliente[j],SIGNAL(readyRead()),this, SLOT(leer_socketcliente()));
    j++;
    ui->lineEdit->setText("Connected Client...10MB saved");
}


/**
 * @brief Método para leer los msj del cliente
 *
 */
void servidor::leer_socketcliente() {       //Recibe los datos del cliente

    if(tcpcliente[0]->bytesAvailable() > 0){
        data->filtro("int");
        QByteArray buffer;
        buffer.resize( tcpcliente[0]->bytesAvailable());

        tcpcliente[0]->read( buffer.data(),buffer.size() );

        ui->plainTextEdit->setReadOnly(true);
        ui->plainTextEdit->appendPlainText( QString (buffer));

        qDebug() << "Buffer : "<<QString (buffer);



        QString dataInto = QString(buffer);
        QJsonDocument doc = QJsonDocument::fromJson(dataInto.toUtf8());
        QJsonObject jsonObject = doc.object();


         int value = *data->filtro("int");

         qDebug() << "Yes "<< QString::number(value);

        jsonObject.insert("adress_memory", QString::number(value));
        QJsonDocument docX(jsonObject);
        const QString strJson(docX.toJson(QJsonDocument::Compact));


        on_client1_clicked(strJson);



    }
    else{
        ui->plainTextEdit->appendPlainText("No se puedo realizar la comunicacion de ningun sockets cliente");
    }
}

/**
 * @brief Método para establecer una conexión con el cliente 1
 *
 */
void servidor::on_client1_clicked(const QString dato)
{

    tcpcliente[0]->write( dato.toLatin1().data() , dato.toLatin1().size()); //envio datos al cliente
   // ui->lineEdit->clear();
}
