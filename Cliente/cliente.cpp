#include "cliente.h"
#include "ui_cliente.h"

Cliente::Cliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cliente)
{
    ui->setupUi(this);

    tcpcliente = new QTcpSocket(this);

    tcpcliente->connectToHost(QHostAddress::LocalHost , 1234);

    connect(tcpcliente, SIGNAL(readyRead()),this,SLOT(leer_socketservidor()));
}

Cliente::~Cliente()
{
    delete ui;
}

void Cliente::on_Escribiralservidor_clicked()
{
    tcpcliente->write(ui->lineEdit->text().toLatin1().data() , ui->lineEdit->text().size());
    ui->lineEdit->clear();
}

void Cliente::leer_socketservidor()
{
    QByteArray buffer;
    buffer.resize(tcpcliente->bytesAvailable() );
    tcpcliente->read(buffer.data(),buffer.size());
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->appendPlainText(QString(buffer));
}



