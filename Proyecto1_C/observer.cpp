#include "string"
#include "iostream"
#include <QTextStream>
#include <regex>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

#include <ctime>

#define F_EVENT "event"
#define F_TYPE "type"
#define F_NAME "name"
#define F_VALUE "value"

using namespace std;

/**
 * @brief Clase Observer
 *
 */
class Observer{
    public:

        /**
         * @brief Lector de codigo
         *
         * @param string Linea leida
         * @param int Numero de linea leida
         */
        static string writeLines(string,int);

   };
    /**
     * @brief Método para leer las lineas del code edit
     *
     * @param lines Linea a analizar
     * @param nL Numero actual de linea analizada
     */
    static QJsonObject writeLines(string line,int nL){

        QFile file1("/home/josek/Escritorio/C-/array");
        Q_ASSERT(file1.open(QFile::WriteOnly));
        QJsonObject json{{F_EVENT,""},{F_TYPE,""},{F_NAME,""},{F_VALUE,""},};


/* <<<<<<<<<<<<<<<< Patrones de todas las verificaciones posibles realizadas >>>>>>>>>>>>>>>>>>>>> */

//Patrones de struct & reference<tipo>______
        smatch mS;
        regex patronV_S("(struct)([[:s:]]*)[\{]");                                //struct{
        bool foundV_S = regex_match(line,mS,patronV_S);

        smatch mR;
        regex patronV_R("(reference<)([[:s:]]*)([[:print:]]+)([[:s:]]*)[\>]");    //reference<...>;
        bool foundV_R = regex_match(line,mR,patronV_R);

//Patrones de Variables_____
        smatch m1;                                                                //Asignacion de variable SIN valor"
        regex patronV_1("([[:w:]]+)([[:s:]]+)([[:w:]]+)[[:s:]]*\;");              //int a; long b; char c; float d; double e;
        bool foundV_1 = regex_match(line,m1,patronV_1);

        smatch m2;                                                                //Asignacion de variable CON valor"
        regex patronV_2("([[:w:]]+)([[:s:]]+)([[:w:]]+)([[:s:]]*)(=)([[:s:]]*)([[:w:]]+)([[:s:]]*)\;");   //int a = 4;
        bool foundV_2 = regex_match(line,m2,patronV_2);

//Patrones de cout<<_________
        smatch m3;
        regex patronC_1("cout<<\"([[:print:]]*)([[:s:]]*\";)");                   //cout<<"....";
        bool foundC_1 = regex_match(line,m3,patronC_1);

        smatch m4;
        regex patronC_2("cout<<\"([[:print:]]*)([[:s:]]*\")");                    //cout<<"...."        (Sin ;)
        bool foundC_2= regex_match(line,m4,patronC_2);

/* <<<<<<<<<<<<<<<<<< <<<<<<<<<<<<<<<<<<<<<<<  >>>>>>>>>>>>>>>>>>>>>>>>> >>>>>>>>>>>>>>>>>>>>>>>> */

        if (line.empty() || line==" "){
            string eve="Line_break";
            json.insert(F_EVENT,eve.c_str());
        }
        else if (foundV_1){
           string name=m1[3].str();
           string type=m1[1].str();
           string eve="json->Server";

           json.insert(F_EVENT,eve.c_str());
           json.insert(F_TYPE,type.c_str());
           json.insert(F_NAME,name.c_str());
           json.insert(F_VALUE,"");

        }
        else if (foundV_2){
            string eve="json->Server";
            string type=m2[1].str();
            string name=m2[3].str();
            string value=m2[7].str();

            json.insert(F_EVENT,eve.c_str());
            json.insert(F_TYPE,type.c_str());
            json.insert(F_NAME,name.c_str());
            json.insert(F_VALUE,value.c_str());

        }

       else if (foundC_1){
           string eve="Interface";
           string seccion="Stdout";
           string value_Cout=m3[1].str();

           json.insert(F_EVENT,eve.c_str());
           json.insert(F_NAME,seccion.c_str());
           json.insert(F_VALUE,value_Cout.c_str());
        }
        else if (foundC_2){
           string eve="Interface";
           string seccion="ApplicationLog";
           string nuLine = to_string(nL+1);

           json.insert(F_EVENT,eve.c_str());
           json.insert(F_NAME,seccion.c_str());
           json.insert(F_VALUE,nuLine.c_str());

       }
       else{
           string eve="syntax error";
           string nuLine = to_string(nL+1);
           json.insert(F_EVENT,eve.c_str());
           json.insert(F_VALUE,nuLine.c_str());
       }

        QJsonArray jsonArray {json};
        QJsonDocument jsonDoc(jsonArray);
        file1.write(jsonDoc.toJson());
        qDebug()<<"Json(LINE) :"<< jsonDoc.array()<<endl;
        return json;
    }


      /*____funciona muy bien para veririfacar que el valorer del integer sea un numero
       regex integer("(\\+|-)?[[:digit:]]+");
       if(regex_match(input,integer)){
            cout<<"integer"<<endl;
            return ">> integer";
       }else{
            cout<<"Invalid input"<<endl;
            return ">> Invalid input";
       }
       */
