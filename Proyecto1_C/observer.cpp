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
    static string writeLines(string lines,int nL){
       cout<<"Line "<<(nL+1)<<": "<<lines<<endl;
       string input = lines;


       smatch m;
       regex e("int [A-z] = [0-9];");

       bool found = regex_search(input, m,e);

       if (found==true){
           cout<<"Encontrado :) "<<endl;
       }
       else{
            cout<<"No encontrado :("<<endl;
       }

       /*__________________________________________ funciona muy bien para veririfacar que el valorer del integer sea un numero
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

}
    static string integerC(string){

    }

