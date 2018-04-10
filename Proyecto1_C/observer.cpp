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
        static string integerC(string);

};
    /**
     * @brief Método para leer las lineas del code edit
     *
     * @param lines Linea a analizar
     * @param nL Numero actual de linea analizada
     */
    static string writeLines(string line,int nL){
        string x1 = line.substr(0,line.find(" "));
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

