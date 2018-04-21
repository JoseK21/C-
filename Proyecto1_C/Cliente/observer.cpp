#include "string"
#include "iostream"
#include <QTextStream>
#include <regex>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QFile>
#include <unistd.h>

#include <QThread>

#define F_EVENT "event"
#define F_TYPE "type"
#define F_NAME "name"
#define F_VALUE "value"
#define F_ADRESS_MEMORY "adress_memory"

QThread workerThread; /**< Hilo/Thread */
using namespace std;

/**
 * @brief Clase Observer : Patron de diseño : Observador
 *
 */
class Observer{
    public:
        static QJsonObject writeLines(string,int);

   };
    /**
     * @brief Método para leer las lineas del code_edit
     *
     * @param line linea
     * @param nL numero de lineas
     * @return QJsonObject Objeto en formato Json
     */
    static QJsonObject writeLines(string line,int nL){
    QJsonObject json{{F_EVENT,""},{F_TYPE,""},{F_NAME,""},{F_VALUE,""},{F_ADRESS_MEMORY, "empty"}} ;


/* <<<<<<<<<<<<<<<< Patrones de todas las verificaciones posibles realizadas >>>>>>>>>>>>>>>>>>>>> */
//Patrones de cout<<_________
        smatch mSpace;
        regex patronSpace("[[:s:]]*");                    //cout<<"...."        (Sin ;)
        bool foundSpace= regex_match(line,mSpace,patronSpace);

//Patrones de Variables_____

        smatch mInt;                                                                //Asignacion de variable SIN valor"
        regex patronInt("([[:s:]]*)([[:w:]]+)([[:s:]]+)([[:print:]]+)[[:s:]]*\;");              //int a; long b; char c; float d; double e;
        bool foundV_Int = regex_match(line,mInt,patronInt);

        smatch m1;                                                                //Asignacion de variable SIN valor"
        regex patronV_1("([[:s:]]*)([[:w:]]+)([[:s:]]+)([[:w:]]+)[[:s:]]*\;");              //int a; long b; char c; float d; double e;
        bool foundV_1 = regex_match(line,m1,patronV_1);

        smatch m2;                                                                //Asignacion de variable CON valor"
        regex patronV_2("([[:s:]]*)([[:w:]]+)([[:s:]]+)([[:w:]]+)([[:s:]]*)(=)([[:s:]]*)([[:w:]]+)([[:s:]]*)\;");   //int a = 4;
        bool foundV_2 = regex_match(line,m2,patronV_2);

//Patrones de cout<<_________
        smatch m3;
        regex patronC_1("cout<<\"([[:print:]]*)([[:s:]]*\";)");                   //cout<<"....";
        bool foundC_1 = regex_match(line,m3,patronC_1);

        smatch m4;
        regex patronC_2("cout<<\"([[:print:]]*)([[:s:]]*\")");                    //cout<<"...."        (Sin ;)
        bool foundC_2= regex_match(line,m4,patronC_2);

//Patrones de struct & reference<tipo>______
        smatch mS;
        regex patronV_S("(struct)([[:s:]]*)[\{]");                                //struct{
        bool foundV_S = regex_match(line,mS,patronV_S);

        smatch mR;
        regex patronV_R("(reference<)([[:s:]]*)([[:print:]]+)([[:s:]]*)[\>]");    //reference<...>;
        bool foundV_R = regex_match(line,mR,patronV_R);

/* <<<<<<<<<<<<<<<<<< <<<<<<<<<<<<<<<<<<<<<<<  >>>>>>>>>>>>>>>>>>>>>>>>> >>>>>>>>>>>>>>>>>>>>>>>> */

        if (foundSpace){
            string eve="Line_break";
            json.insert(F_EVENT,eve.c_str());
        }
        else if (foundV_1){
            workerThread.msleep(3000);
           string type=m1[2].str();
           string name=m1[4].str();
           string eve="json->Server";

           json.insert(F_EVENT,eve.c_str());
           json.insert(F_TYPE,type.c_str());
           json.insert(F_NAME,name.c_str());
        }
        else if (foundV_2){
            workerThread.msleep(3000);
            string type=m2[2].str();
            string name=m2[4].str();
            string value=m2[8].str();
            string eve="json->Server";

            json.insert(F_EVENT,eve.c_str());
            json.insert(F_TYPE,type.c_str());
            json.insert(F_NAME,name.c_str());
            json.insert(F_VALUE,value.c_str());
        }

        else if (foundV_Int){
           string type=m1[2].str();
           string name=m1[4].str();
           string eve="json->Server";

           json.insert(F_EVENT,eve.c_str());
           json.insert(F_TYPE,type.c_str());
           json.insert(F_NAME,name.c_str());
           json.insert(F_VALUE,"");
        }

       else if (foundC_1){
           string eve="Interface";
           string seccion="Stdout";
           string value_Cout=m3[1].str();

           json.insert(F_EVENT,eve.c_str());
           json.insert(F_NAME,seccion.c_str());
           json.insert(F_VALUE,value_Cout.c_str());
           qDebug() <<"Seccion > "<< json.value(F_NAME).toString();     //Forma de obtener los datos del json
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

        return json;
    }
