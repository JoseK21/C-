/**
  * @file nodos.cpp
  * @version 1.0
  * @date 10/03/2018
  * @author José Núñez
  * @title Tarea Extraclase #1
  * @brief Nodo de tipo simple
  */

#include "iostream"
using namespace std;


/**
* @brief Clase NodoS Molde de un nodo simple, el cual es empleado por la lista simple.
*
*/
class NodoS{
private:
    /**
     * @brief dato Valor numerico.
     */
    int dato;

public:
    /**
     * @brief siguiente Referencia del puntero siguiente.
     */
    NodoS *siguiente;

    /**
     * @brief NodoS Constructor
     * @param dato
     */
    NodoS(int dato){
        this->dato=dato;
        this->siguiente=NULL;
    }
    /**
     * @brief getDato Obtención del valor numerico asignado
     * @return
     */
    int getDato() const {
        return dato;
    }
    /**
     * @brief setDato Asignación del valor numerico
     * @param dato
     */
    void setDato(int dato) {
        NodoS::dato = dato;
    }

    /**
     * @brief getSiguiente Obtención del siguiente puntero
     * @return
     */
    NodoS *getSiguiente() const {
        return siguiente;
    }
    /**
     * @brief setSiguiente Asignación del siguiente puntero
     * @param siguiente
     */
    void setSiguiente(NodoS *siguiente) {
        NodoS::siguiente = siguiente;
    }

};
