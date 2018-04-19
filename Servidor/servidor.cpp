#include "servidor.h"
#include "ui_servidor.h"

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

    tcpservidor->listen(QHostAddress::LocalHost , 1234 );

    connect(tcpservidor,SIGNAL(newConnection()),this, SLOT(conexion_nueva()));
}

servidor::~servidor()
{
    delete ui;
}

void servidor::conexion_nueva()
{
    static int j=0;
    tcpcliente[j] = tcpservidor->nextPendingConnection();

    connect(tcpcliente[j],SIGNAL(readyRead()),this, SLOT(leer_socketcliente()));
    j++;

}


void servidor::leer_socketcliente()
{
    if(tcpcliente[0]->bytesAvailable() > 0){
        QByteArray buffer;
        buffer.resize( tcpcliente[0]->bytesAvailable());
        tcpcliente[0]->read( buffer.data(),buffer.size() );
        ui->plainTextEdit->setReadOnly(true);
        ui->plainTextEdit->appendPlainText( QString (buffer));
    }
    else if(tcpcliente[1]->bytesAvailable() >0)
    {
        QByteArray buffer;
        buffer.resize( tcpcliente[1]->bytesAvailable());
        tcpcliente[1]->read( buffer.data(),buffer.size() );
        ui->plainTextEdit->setReadOnly(true);
        ui->plainTextEdit->appendPlainText( QString (buffer));
    }
    else
    {
        ui->plainTextEdit->appendPlainText("No se puedo realizar la comunicacion de ningun sockets cliente");
    }

}


void servidor::on_client1_clicked()
{
    tcpcliente[0]->write( ui->lineEdit->text().toLatin1().data() , ui->lineEdit->text().size());
    ui->lineEdit->clear();
}

void servidor::on_client2_clicked()
{
    tcpcliente[1]->write( ui->lineEdit->text().toLatin1().data() , ui->lineEdit->text().size());        //Envio de dato al cliente
    ui->lineEdit->clear();
}
