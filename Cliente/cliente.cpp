#include "cliente.h"
#include "ui_cliente.h"
#include "observer.cpp"

#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

QString fname,nameF,xP;

enum colu{
    Mem_Adr ,Val , Tag , Ref
  //  0       1     2     3
};

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




void Cliente::on_actionExit_triggered()
{
    close();
}

void Cliente::on_actionNew_File_triggered()
{
    ui->tableWidget->setRowCount(0);
    ui->stdOut->clear();
    ui->Application_Log->clear();
    ui->ptd_CodeEdit->clear();
}

void Cliente::on_actionOpen_File_triggered()
{
    ui->ptd_CodeEdit->clear();

    fname = QFileDialog::getOpenFileName(this);

    QString F_Adress = "->>File Open: " +fname;

    ui->Application_Log->addItem(F_Adress);

    nameF = fname;
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream textStream(&file);
    QString line = textStream.readAll();

    ui->ptd_CodeEdit->appendPlainText(line);

    file.close();

}

void Cliente::on_run_clicked()
{
    QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
    QStringList lines = plainTextEditContents.split("\n");

    int sizeLines = lines.length();

        ui->Application_Log->addItem("Starting Execute..");
        for(int ind;ind<sizeLines;ind++){

            xP = ind+1;
            ui->label_Analyzed_Line->setText(xP);

            //TIMER

                QJsonObject out1 = writeLines(lines[ind].toStdString(),ind);    //Observer

                if (out1.value(F_EVENT).toString() == "Line_break"){
                    //Nada solo es para visualizar el salto de linea
                }
                else if (out1.value(F_EVENT).toString() == "json->Server"){

                    // enviarlo
                    xP = "Sending-data-to-the-server...";
                    ui->Application_Log->addItem(xP);

     // AQUI ENVIAR Y RECIVIR JSON SERVER-CLIENTE--------------------------------------

                    //---- prueba de tabla
                    int fila = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

                    QString pV = out1.value(F_VALUE).toString();
                    QString pN = out1.value(F_NAME).toString();
                    QString pT = out1.value(F_TYPE).toString();

                    ui->tableWidget->setItem(fila,Val,new QTableWidgetItem(pV));
                    ui->tableWidget->setItem(fila,Tag,new QTableWidgetItem(pN));
                    ui->tableWidget->setItem(fila,Ref,new QTableWidgetItem(pT));

                    //Mem_Adr ,Val , Tag , Ref

                    //0        1     2     3

                }
                else if (out1.value(F_EVENT).toString() == "syntax error"){
                    xP = "\t\t_Syntax_Error_ >> Line # "+out1.value(F_VALUE).toString();

                    ui->Application_Log->addItem(xP);
                    break;//Finaliza la ejecucion
                }
                else if (out1.value(F_EVENT).toString() == "Interface"){
                    if (out1.value(F_NAME).toString()=="Stdout"){
                        xP = out1.value(F_VALUE).toString();
                        ui->stdOut->addItem(xP);
                    }else if(out1.value(F_NAME).toString()=="ApplicationLog"){
                        xP = "Error>> Line # "+out1.value(F_VALUE).toString();
                        ui->Application_Log->addItem(xP);
                        break;          //Finaliza la ejecucion
                    }
                }
                else{
                    xP = "Patron sin analisis....!! Line( "+QString(ind)+" ).";
                    ui->Application_Log->addItem(xP);
                }
            }
            xP = "\n>>> Finished Execution.\n\n";

            ui->Application_Log->addItem(xP);
            ui->stop->setEnabled(0);


}

void Cliente::on_stop_clicked()
{

}

void Cliente::on_go_on_clicked()
{

}

void Cliente::on_clear_clicked()
{
    ui->Application_Log->clear();
}
