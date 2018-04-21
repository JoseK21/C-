#include "cliente.h"
#include "ui_cliente.h"
#include "observer.cpp"
#include "ram_remoto.cpp"

#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QThread>

QThread workerThread; /**< Hilo/Thread */
QString fname,nameF,xP; /**< Parametros de la entrada del code_edit*/
bool stop_stop = false; /**< Variable para detener la lectura de code_edit */
QStringList linesGo_on; /**< Lista de las lineas del code_edit */
RAM_remoto * ram_remoto = new RAM_remoto(); /**< Lista Simple para guardar las variables creadas en el code_edit */
int indGO_ON =0; /**< Cantidad de lineas en el code_edit */
int row_ind = 0;  /** < Fila de la tabla  */

/**
 * @brief Columna de variables referenciadas en un orden numerico
 *
 */
enum colu{
    Mem_Adr ,Val , Tag , Ref
  //  0       1     2     3
};

/**
 * @brief Clase Cliente : Usuario : Cliente del sistema
 *
 * @param parent
 */
Cliente::Cliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cliente)
{
    ui->setupUi(this);
    tcpcliente = new QTcpSocket(this);
    tcpcliente->connectToHost(QHostAddress::LocalHost,8888);
    connect(tcpcliente, SIGNAL(readyRead()),this,SLOT(leer_socketservidor()));
}

/**
 * @brief Liberador de memoria de la creacion de la ventana
 *
 */
Cliente::~Cliente()
{
    delete ui;
}

/**
 * @brief Metodó para enviar informacion/json al servidor
 *
 * @param da
 */
void Cliente::on_Escribiralservidor_clicked(const QString da)       //envio de datos al servidor
{
    tcpcliente->write(da.toLatin1().data() , da.toLatin1().size());
}

/**
 * @brief Metodó para leer lo que el servidor reenvio
 *
 */
void Cliente::leer_socketservidor()     //lector de los datos provenientes del servidor
{
    QByteArray buffer;
    buffer.resize(tcpcliente->bytesAvailable() );
    tcpcliente->read(buffer.data(),buffer.size());

    QString dataServer = QString(buffer);

    QJsonDocument docServer = QJsonDocument::fromJson(dataServer.toUtf8());

    QJsonObject jsonObjectServer = docServer.object();

    QString pV = jsonObjectServer.value(F_VALUE).toString();
    QString pN = jsonObjectServer.value(F_NAME).toString();
    QString pT = jsonObjectServer.value(F_TYPE).toString();
    QString pM = jsonObjectServer.value(F_ADRESS_MEMORY).toString();
    QString ref_c = QString::number(1);


    if (pT=="int" ||pT=="float" || pT=="double" || pT=="long"){
        int fila = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(fila,Val,new QTableWidgetItem(pV));
        ui->tableWidget->setItem(fila,Tag,new QTableWidgetItem(pN));
        ui->tableWidget->setItem(fila,Mem_Adr,new QTableWidgetItem(pM));
        ui->tableWidget->setItem(fila,Ref,new QTableWidgetItem(ref_c));

        ram_remoto->ingresarAlFinal(pM.toStdString(),pN.toStdString(),pV.toStdString(),pT.toStdString());
        cout<<ram_remoto->mostrarLista()<<endl;
    }

}

/**
 * @brief Metodó para cerrar la ventana
 *
 */
void Cliente::on_actionExit_triggered()
{
    close();
}

/**
 * @brief Metodó para abrir archivos desde la PC
 *
 */
void Cliente::on_actionNew_File_triggered()
{
    ui->tableWidget->setRowCount(0);
    ui->stdOut->clear();
    ui->Application_Log->clear();
    ui->ptd_CodeEdit->clear();
}

/**
 * @brief Metodó para abrir una ventana emergente de donde se puede seleccionar un archivo
 *
 */
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

/**
 * @brief Metodó para ejecutar C! leyendo linea a linea
 *
 */
void Cliente::on_run_clicked()
{
    QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
    QStringList lines = plainTextEditContents.split("\n");
    int sizeLines = lines.length();
    ui->Application_Log->addItem("Starting Execute..");

    int ind = 0;

    while ( ind < sizeLines){
        on_go_on_clicked();

        workerThread.msleep(3000);
        ind++;
    }
}

/**
 * @brief Metodó para detener la ejecución del lector de C!
 *
 */
void Cliente::on_stop_clicked()
{
    stop_stop = false;
}

/**
 * @brief Metodó para analizar linea a linea el codigo escrito en code_edit
 *
 */
void Cliente::on_go_on_clicked()
{
        QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
        linesGo_on = plainTextEditContents.split("\n");

        if (indGO_ON < linesGo_on.length()){

            xP = QString(indGO_ON);
            ui->label_Analyzed_Line->setText(QString::number(indGO_ON +1));
                QJsonObject out1 = writeLines(linesGo_on[indGO_ON].toStdString(),indGO_ON);    //Observer
                QJsonObject jsonObj = out1;
                QJsonDocument doc(jsonObj);
                const QString strJson(doc.toJson(QJsonDocument::Compact));
                qDebug() << strJson;

                if (out1.value(F_EVENT).toString() == "Line_break"){
                    //Nada solo es para visualizar el salto de linea
                }
                else if (out1.value(F_EVENT).toString() == "json->Server"){
                    on_Escribiralservidor_clicked(strJson);
                    xP = "Sending-data-to-the-server...";
                    ui->Application_Log->addItem(xP);
                    leer_socketservidor();


                }
                else if (out1.value(F_EVENT).toString() == "syntax error"){
                    xP = "\t\t_Syntax_Error_ >> Line # "+out1.value(F_VALUE).toString();
                    ui->Application_Log->addItem(xP);
                }
                else if (out1.value(F_EVENT).toString() == "Interface"){
                    if (out1.value(F_NAME).toString()=="Stdout"){
                        xP = out1.value(F_VALUE).toString();
                        ui->stdOut->addItem(xP);
                    }else if(out1.value(F_NAME).toString()=="ApplicationLog"){
                        xP = "Error>> Line # "+out1.value(F_VALUE).toString();
                        ui->Application_Log->addItem(xP);
                    }
                }
                else{
                    xP = "Patron sin analisis....!! Line( "+QString(indGO_ON)+" ).";
                    ui->Application_Log->addItem(xP);
                }
                indGO_ON++;
            }
        else{
            ui->go_on->setEnabled(0);
            xP = "\n>>> Finished Execution.\n\n";
            ui->Application_Log->addItem(xP);
            ui->stop->setEnabled(0);
        }
}

/**
 * @brief Metodó para limpiar las secciones de la interfaz
 *
 */
void Cliente::on_clear_clicked()
{
    ui->Application_Log->clear();
}
