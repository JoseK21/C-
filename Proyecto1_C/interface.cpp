#include "interface.h"
#include "ui_interface.h"
#include "string"
#include <iostream>     //Cambios <>
#include <QFileDialog>
#include <fstream>
#include <QFile>
#include <QTextStream>

QFile file_jSon("/home/josek/Escritorio/C-/Proyecto1_C/array.json");
using namespace std;

//ListaSimple *ls = new ListaSimple();
QString fname; /**< TODO: describe */
string nameF; /**< TODO: describe */
string stdOut; /**< TODO: describe */
bool stop=false;
string xP;
char *a;
int ind =0; // indice de linea analizada
QStringList lines;

/**
 * @brief Inicio de ventana
 *
 * @param parent
 */
Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
}


/**
 * @brief Eliminación de la ventana
 *
 */
Interface::~Interface()
{
    delete ui;
}



/**
 * @brief Boton para ejecutar codigo
 *
 */
void Interface::on_Run_clicked()
{
    //ui->Run->setEnabled(0);
    xP = "Starting Compilation....";
    a = new char[xP.length() + 1];
    strcpy(a,xP.c_str());
    ui->ptd_ApplicationLog->append(a);


    QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
    lines = plainTextEditContents.split("\n");

    int sizeLines = lines.length();

    for(int ind;ind<sizeLines;ind++){

        xP = to_string(ind+1);
        a = new char[xP.length() + 1];
        strcpy(a,xP.c_str());
        ui->label_Analyzed_Line->setText(a);
        delete(a);

        //TIMER

            QJsonObject out1 = writeLines(lines[ind].toStdString(),ind);    //Observer

            if (out1.value(F_EVENT).toString() == "Line_break"){
                //Nada solo es para visualizar el salto de linea
            }
            else if (out1.value(F_EVENT).toString() == "json->Server"){

                // enviarlo
                xP = "Sending-data-to-the-server...";
                a = new char[xP.length() + 1];
                strcpy(a,xP.c_str());
                ui->ptd_ApplicationLog->append(a);
                delete(a);

                //---- prueba de tabla
                int fila = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QString p = out1.value(F_EVENT).toString();
                ui->tableWidget->setItem(fila,0,new QTableWidgetItem(p));

                //-----

            }
            else if (out1.value(F_EVENT).toString() == "syntax error"){
                xP = "\t\t_Syntax_Error_ >> Line # "+out1.value(F_VALUE).toString().toStdString();
                a = new char[xP.length() + 1];
                strcpy(a,xP.c_str());
                ui->ptd_ApplicationLog->append(a);
                delete(a);
                break;//Finaliza la ejecucion
            }
            else if (out1.value(F_EVENT).toString() == "Interface"){
                if (out1.value(F_NAME).toString()=="Stdout"){
                    xP = out1.value(F_VALUE).toString().toStdString();
                    a = new char[xP.length() + 1];
                    strcpy(a,xP.c_str());
                    ui->ptd_Stdout->append(a);
                    delete(a);
                }else if(out1.value(F_NAME).toString()=="ApplicationLog"){
                    xP = "Error>> Line # "+out1.value(F_VALUE).toString().toStdString();
                    a = new char[xP.length() + 1];
                    strcpy(a,xP.c_str());
                    ui->ptd_ApplicationLog->append(a);

                    delete(a);
                    break;          //Finaliza la ejecucion
                }
            }
            else{
                xP = "Patron sin analisis....!! Line( "+to_string(ind)+" ).";
                a = new char[xP.length() + 1];
                strcpy(a,xP.c_str());
                ui->ptd_ApplicationLog->append(a);
                delete(a);
            }
        }
        xP = "\n>>> Finished Execution.\n\n";
        a = new char[xP.length() + 1];
        strcpy(a,xP.c_str());
        ui->ptd_ApplicationLog->append(a);
        ui->Stop->setEnabled(0);
        delete(a);
    }
//}

/**
 * @brief Boton para borrar información del Apllication Log
 *
 */
void Interface::on_ButtonClear_clicked()
{
    ui->ptd_ApplicationLog->clear();
}

/**
 * @brief Boton para iniciar un nuevo codigo(Borra la información anterio)
 *
 */
void Interface::on_NewFile_triggered()
{
    ui->Run->setEnabled(1);
    ui->Stop->setEnabled(1);
    ui->GoOn->setEnabled(0);

    ui->label_Analyzed_Line->setText("");
    ui->ptd_ApplicationLog->clear();
    ui->ptd_CodeEdit->clear();
    ui->ptd_Stdout->clear();
    ui->tableWidget->setRowCount(0);
}

/**
 * @brief Boton para importar codigo de PC
 *
 */
void Interface::on_Open_File_triggered()
{
    ui->ptd_CodeEdit->clear();

    fname = QFileDialog::getOpenFileName(this);
    nameF = fname.toStdString();
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream textStream(&file);
    QString line = textStream.readAll();


    xP = "Open file address:  "+fname.toStdString();
    a= new char[xP.length() + 1];
    strcpy(a,xP.c_str());

    ui->ptd_ApplicationLog->append(a);
    ui->ptd_CodeEdit->setText(line);
    delete(a);
    file.close();
}

void Interface::on_Stop_clicked()
{
    stop=true;
    xP = "Pause<< Stopped processes";
    a = new char[xP.length() + 1];
    strcpy(a,xP.c_str());
    ui->ptd_ApplicationLog->append(a);
    delete(a);
    ui->Run->setEnabled(0);
    ui->Stop->setEnabled(0);
    ui->GoOn->setEnabled(1);

}

void Interface::on_GoOn_clicked()
{
    xP = "Line_Break.. ";
    a= new char[xP.length() + 1];
    strcpy(a,xP.c_str());
    ui->ptd_ApplicationLog->append(a);
    delete(a);

    QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
    lines = plainTextEditContents.split("\n");

    if (ind < lines.length()){

        xP = to_string(ind+1);
        a= new char[xP.length() + 1];
        strcpy(a,xP.c_str());
        ui->label_Analyzed_Line->setText(a);
        delete(a);

        QJsonObject out1 = writeLines(lines[ind].toStdString(),ind); //Observer

        if (out1.value(F_EVENT).toString() == "Line_break"){
            // NAda solo visualiza que sea un salto de linea
        }
        else if (out1.value(F_EVENT).toString() == "json->Server"){
            xP = "Sending-data-to-the-server...";
            a= new char[xP.length() + 1];
            strcpy(a,xP.c_str());
            ui->ptd_ApplicationLog->append(a);
            delete(a);
        }
        else if (out1.value(F_EVENT).toString() == "syntax error"){
            xP = "\t\t_Syntax_Error_ >> Line # "+out1.value(F_VALUE).toString().toStdString();
            a= new char[xP.length() + 1];
            strcpy(a,xP.c_str());
            ui->ptd_ApplicationLog->append(a);
            delete(a);
        }
        else if (out1.value(F_EVENT).toString() == "Interface"){
            if (out1.value(F_NAME).toString()=="Stdout"){
                xP = out1.value(F_VALUE).toString().toStdString();
                a= new char[xP.length() + 1];
                strcpy(a,xP.c_str());
                ui->ptd_Stdout->append(a);
                delete(a);

            }else if(out1.value(F_NAME).toString()=="ApplicationLog"){
                xP = "Error>> Line # "+out1.value(F_VALUE).toString().toStdString();
                a= new char[xP.length() + 1];
                strcpy(a,xP.c_str());
                ui->ptd_ApplicationLog->append(a);
                delete(a);
            }
        }
        else{
            xP = "Patron sin analisis....!! Line( "+to_string(ind)+" ).";
            a= new char[xP.length() + 1];
            strcpy(a,xP.c_str());
            ui->ptd_ApplicationLog->append(a);
            delete(a);
        }
        ind++;
    }else{
        xP = "\n>>> Finished Execution.\n\n";
        a= new char[xP.length() + 1];
        strcpy(a,xP.c_str());
        ui->ptd_ApplicationLog->append(a);
        delete(a);

        ui->GoOn->setEnabled(0);
        ui->Stop->setEnabled(0);
    }
}



