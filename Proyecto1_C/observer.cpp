#include "string"
#include "iostream"
#include <QTextStream>
#include <regex>

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
        cout<<"x1: "<<x1<<endl;
        if (x1 =="int" || x1 =="long" || x1 =="char" || x1 =="float" || x1 =="double"){  //int long char float double

            smatch m;
            regex patronVariable("([[:w:]]+)[[:s:]]*([[:w:]])+\;");
            string R;

            bool found = regex_match(line,m,patronVariable);

            if (found==true){
               for(int n=0; n<m.size();n++){
                   cout<<R<<endl;
                   R= R+m[n+1].str()+" ";
               }
               cout<<"COUT: "<<R<<endl;
               return R;

            }
            else{
                //Otro patron
               cout<<"No encontrado :("<<endl;
               return R;
            }




            cout<<"VAriable............!!..........1!"<<endl;
            return "variable___SII";
        }
        else{
            //Aqui buscar los printf();
            return "hola_:Nada";
        }





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

