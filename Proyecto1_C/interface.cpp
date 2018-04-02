#include "interface.h"
#include "ui_interface.h"
#include "QTimer"
#include "string"
#include "iostream"
#include <QFileDialog>
#include <fstream>
#include <QFile>
#include <QTextStream>


using namespace std;

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

    int currentIndex=0;
    int sizeLines = lines.length();
    cout<<"Size Lines :"<<sizeLines<<endl;

    while(currentIndex < sizeLines){
        writeLines(lines[currentIndex].toStdString(),currentIndex); //Uso de Observer
        currentIndex++;
    }
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
