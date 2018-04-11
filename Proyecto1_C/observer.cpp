#include "string"
#include "iostream"
#include <QTextStream>
#include <regex>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include "QThread"


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
    static string writeLines(string line,int nL){
        string x1 = line.substr(0,line.find(" "));
        smatch m;
        string R;
        QJsonObject json{};
        if (x1 =="int" || x1 =="long" || x1 =="char" || x1 =="float" || x1 =="double"){     //CAso de encontrar una Variable

            regex patronV_1("([[:w:]]+)([[:s:]]+)([[:w:]]+)[[:s:]]*\;");                    //Patron: int x;
            bool found1 = regex_match(line,m,patronV_1);
            if (found1==true){  //Asignacion de variable sin valor"
               int n=1;
               //QString data = to_string(x1); // assume this holds the json string

               string name=m[3].str();
               json.insert("Type",x1.c_str());
               json.insert("Name",name.c_str());
               json.insert("Value","null");

               QJsonArray jsonArray {json};
               QJsonDocument jsonDoc(jsonArray);

               qDebug()<< jsonDoc.array()<<endl;
              // cout<<  <<endl;
               QFile file1("/home/josek/Escritorio/C-/array");
               Q_ASSERT(file1.open(QFile::WriteOnly));
               file1.write(jsonDoc.toJson());

               return R;
            }
            else{
                regex patronV_2("([[:w:]]+)([[:s:]]+)([[:w:]]+)([[:s:]]*)(=)([[:s:]]*)([[:w:]]+)([[:s:]]*)\;");
                bool found2 = regex_match(line,m,patronV_2);

                if (found2==true){
                   cout<<"\nAsignacion de variable con valor"<<endl;
                   for(int n=1; n<m.size();n++){
                       cout<<m[n]<<endl;
                       R= R+m[n].str()+" ";
                   }
                   cout<<"COUT: "<<R<<endl;
                   return R;

                }

                //Otro patron
               cout<<"No encontrado :("<<endl;
               return R;
            }

            return "variable___SII";
        }
        else{
            regex patronV_P("cout<<\"([[:print:]]*)([[:s:]]*\");");     //regex patronV_P("cout<<([[:w:]]*)([[:s:]]*);"); -> para variables
            bool foundP3 = regex_match(line,m,patronV_P);

            cout<<"printf(.........);"<<endl;
            if (foundP3==true){

               cout<<m[1].str()<<endl;
               R= "p: "+m[1].str();
               cout<<"COUT: "<<R<<endl;
               return R;

            }

            regex patronV_P1("cout<<\"([[:print:]]*)([[:s:]]*\")");
            bool foundP4= regex_match(line,m,patronV_P1);
            cout<<"printf(....ERRORPunto_coma.....)"<<endl;

            if(foundP4==true){//Error de ;
               R= "e: "+to_string(nL+1);      //Error
               cout<<"COUT: "<<R<<endl;
               return R;

                }
            }

            //Otro patron
           cout<<"----> No encontrado :("<<endl;
           return R;

            //Aqui buscar los printf();
            return "hola_:Nada";






        /*


        string R = "";

        cout<<"First word: "<<x1<<endl;

        smatch m;
        regex e ("([[:w:]]+)[[:s:]]*([[:w:]])+\;");

        bool found = regex_search(line,m,e);

        if (found==true){
           for(int n=0; n<m.size();n++){
               R= R+m[n].str()+" ";
           }
           return R;

        }
        else{
           cout<<"No encontrado :("<<endl;
           return R;
        }

        */

        cout<<"-------------FIN---------------"<<endl;
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


       //falta enviarlo a la intefaz
       // TIPOS EXISTENTES : int long char float double struct reference<tipo>

