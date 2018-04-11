#include "string"
#include "iostream"
#include <QTextStream>
#include <regex>

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
        cout<<"Text: "<<x1<<endl;
        smatch m;
        string R;
        if (x1 =="int" || x1 =="long" || x1 =="char" || x1 =="float" || x1 =="double"){

            regex patronV_1("([[:w:]]+)([[:s:]]+)([[:w:]]+)[[:s:]]*\;");
            bool found1 = regex_match(line,m,patronV_1);

            if (found1==true){
               cout<<"\nAsignacion de variable sin valor"<<endl;
               for(int n=1; n<m.size();n++){
                   cout<<m[n]<<endl;
                   R= R+m[n].str()+"";
               }
               cout<<"COUT: "<<R<<endl;
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
                   R= "e: "+to_string(nL);      //Error
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

