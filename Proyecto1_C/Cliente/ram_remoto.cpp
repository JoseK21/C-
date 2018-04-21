//
// Created by josek on 4/20/18.
//

#ifndef UNTITLED_RAM_REMOTO_H
#define UNTITLED_RAM_REMOTO_H

#include "node_rr.cpp"
#include <string>


/**
 * @brief Clase RAM_remoto : Estructura de datos : Lista simple
 */
class RAM_remoto
{
private:
    /**
        * @brief Puntero inicial
        */
    Node_Rr *primero;
    /**
     * @brief Puntero final
     */
    Node_Rr *ultimo;
    /**
     * @brief Tamaño
     */
    int size =0;

public:
    /**
     * @brief Constructor
     */
    RAM_remoto(){
        primero=ultimo=NULL;
    }
    /**
     * @brief Obtención del tamaño de la lisa
     * @return
     */
    int getSize() const {
        return size;
    }
    /**
     * @brief Asignación del tamaño
     * @param size
     */
    void setSize(int size) {
        this->size = size;
    }
    /**
     * @brief Método para validar la existencia de la lista
     * @return
     */
    bool vacio(){
        return (primero==NULL);
    }

    /**
     * @brief Método para insertar un elemento al final de la lista
     * @param d
     */
    void ingresarAlFinal(string m, string n ,string v ,string t ){
        Node_Rr *temp = new Node_Rr(m,n,v,t);
        if(vacio()== true){
            primero=ultimo=temp;
        }
        else{
            ultimo->setSiguiente(temp);
            ultimo=temp;
        }
        size++;
    }
    /**
     * @brief Método para obtener el valor de un elemento por su posición
     * @param pos
     * @return
     */
    Node_Rr* obtenerPorNombre(string name_variable){
        string Ob;
        if(vacio()==true){
            std::cout<<"Lista vacia"<<std::endl;
        }
        else {
            Node_Rr *aux=primero;
            for (int ind = 0; ind <= getSize(); ind++) {
                if (name_variable == aux->getName()){
                    return aux;
                }
                aux = aux->siguiente;
            }
        }
    }
    /**
     * @brief Método para editar el valor numerico de un elemento por su posición
     * @param dc
     * @param pos
     */
    void editarPorNombre(string name){
        Node_Rr *aux=primero;

        for (int ind=1;ind<=size;ind++){
            aux=aux->siguiente;
        }
    }
    /**
     * @brief Método para imprimir y brindar un resultado del proceso al usuario
     * @return
     */
    string mostrarLista(){
        string R="";
        if (vacio()== true){
            R="Lista Vacia";
        }
        else{
            Node_Rr *aux=primero;
            int i= 0;
            R="Head-> ";
            while(aux!=NULL){
                R=R+"| "+(aux->getMemory_address())+" |-> ";
                aux=aux->siguiente;
                i++;
            }
            R=R+" End";
            delete(aux);
        }
        return R;
    }
};
#endif //UNTITLED_RAM_REMOTO_H
