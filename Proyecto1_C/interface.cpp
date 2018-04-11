#include "interface.h"
#include "ui_interface.h"
#include "string"
#include <iostream>     //Cambios <>
#include <QFileDialog>
#include <fstream>
#include <QFile>
#include <QTextStream>



using namespace std;

ListaSimple *ls = new ListaSimple();

QString fname; /**< TODO: describe */
string nameF; /**< TODO: describe */
string stdOut; /**< TODO: describe */


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
    QString plainTextEditContents = ui->ptd_CodeEdit->toPlainText();
    QStringList lines = plainTextEditContents.split("\n");

    int sizeLines = lines.length();
    cout<<"Size Lines :"<<sizeLines<<endl;

    for(int ind =0;ind<sizeLines;ind++){

        string out1 = writeLines(lines[ind].toStdString(),ind); //Uso de Observer

        if(out1.substr(0,out1.find(" ")) == "p:"){
            string xP = out1.substr(out1.find(" "),out1.length());
            char *a = new char[xP.length() + 1];
            strcpy(a,xP.c_str());
            ui->ptd_Stdout->append(a);
            delete(a);

        }
        if(out1.substr(0,out1.find(" ")) == "e:"){


            string xP = "Error de ; en la linea :"+out1.substr(out1.find(" "),out1.length());
            char *a = new char[xP.length() + 1];
            strcpy(a,xP.c_str());

            ui->ptd_ApplicationLog->append(a);

            delete(a);
            break;//Finaliza la ejecucion

        }

        cout<<"TIMER"<<endl;
    }
    cout<<"^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^\n\n"<<endl;
}

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
    // Borrar todo (Punteros y demas)...
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
    cout<<"->->->->File Open: "<<fname.toStdString()<<endl;
    nameF = fname.toStdString();
    QFile file(fname);
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream textStream(&file);
    QString line = textStream.readAll();

    ui->ptd_CodeEdit->setText(line);
    file.close();
}
