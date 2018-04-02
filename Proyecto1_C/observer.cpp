#include "string"
#include "iostream"
#include <QTextStream>

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
        static void writeLines(string,int);
};


    /**
     * @brief Método para leer las lineas del code edit
     *
     * @param lines Linea a analizar
     * @param nL Numero actual de linea analizada
     */
    static void writeLines(string lines,int nL){
       cout<<"Line "<<(nL+1)<<": "<<lines<<endl;
       //falta enviarlo a la intefaz

}
