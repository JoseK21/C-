#include "nodos.cpp"
#include <string>

/**
 * @brief Clase ListaSimple Molde de una Lista Simple
 */
class ListaSimple{
private:
    /**
     * @brief primero Puntero inicial
     */
    NodoS *primero;
    /**
     * @brief ultimo Puntero final
     */
    NodoS *ultimo;
    /**
     * @brief size Tamaño
     */
    int size =0;
public:
    /**
     * @brief ListaSimple Constructor
     */
    ListaSimple(){
        primero=ultimo=NULL;
    }
    /**
     * @brief getSize Obtención del tamaño
     * @return
     */
    int getSize() const {
          return size;
     }
    /**
     * @brief setSize Asignación del tamaño
     * @param size
     */
    void setSize(int size) {
          this->size = size;
     }
    /**
     * @brief vacio Método para validar la existencia de la lista
     * @return
     */
    bool vacio(){
        return (primero==NULL);
    }
    /**
     * @brief ingresarAlInicio Método para insertar un elemento al inicio de la lista
     * @param d
     */
    void ingresarAlInicio(int d){
        NodoS *temp = new NodoS(d);
        if(vacio()== true){
            primero=ultimo=temp;
        }
        else{
            temp->setSiguiente(primero);
            primero=temp;
        }
        setSize(getSize()+1);
    }
    /**
     * @brief ingresarAlFinal Método para insertar un elemento al final de la lista
     * @param d
     */
    void ingresarAlFinal(int d){
        NodoS *temp = new NodoS(d);
        if(vacio()== true){
            primero=ultimo=temp;
        }
        else{
            ultimo->setSiguiente(temp);
            ultimo=temp;
        }
        setSize(getSize()+1);
    }
    /**
     * @brief ingresarPorPosicion Método para insertar un elemento por posición a la lista
     * @param d
     * @param pos
     */
    void ingresarPorPosicion(int d,int pos){
        NodoS *aux=primero;
        for (int ind=1;ind<pos;ind++){
            aux=aux->siguiente;
            if (aux==NULL){
                break;
            }
        }
        NodoS *tempN =new NodoS(d);
        tempN->siguiente=aux->siguiente;
        aux->siguiente=tempN;
        setSize(getSize()+1);

    }

    /**
     * @brief obtenerPorPosicion Método para obtener el valor de un elemento por su posición
     * @param pos
     * @return
     */
    string obtenerPorPosicion(int pos){
        string Ob;
        if(vacio()==true){
            cout<<"Lista vacia"<<endl;
        }
        else {

            NodoS *aux=primero;
            for (int ind = 0; ind <= pos; ind++) {
                if (ind == pos) {
                    cout << "Valor de la posicion " << pos << " = " << aux->getDato() << endl;
                    break;
                }else if (aux->siguiente == NULL) {
                    cout << "La posición " << pos << " esta fuera del rango de la lista" << endl;
                    cout << "Dato no agregado...!" << endl;
                    break;
                }
                aux = aux->siguiente;
            }
             Ob=to_string(aux->getDato());
        }
        return Ob;
    }
    /**
     * @brief editarPosicion Método para editar el valor numerico de un elemento por su posición
     * @param dc
     * @param pos
     */
    void editarPosicion(int dc,int pos){
        NodoS *aux=primero;
        for (int ind=1;ind<=pos;ind++){
            aux=aux->siguiente;
        }
        aux->setDato(dc);

    }
    /**
     * @brief eliminarPrimero Método para eliminar el primer elemento en la lista
     */
    void eliminarPrimero(){
        NodoS *temp=primero;
        primero=primero->siguiente;
        delete(temp);
        setSize(getSize()-1);

    }
    /**
     * @brief eliminarUltimo Método para eliminar el ultimo elemento en la lista
     */
    void eliminarUltimo(){

        if(primero==ultimo){
            primero=ultimo=NULL;
        }
        else{
            NodoS *aux=primero;
            while (aux!=NULL){
                if(primero==ultimo){
                    primero=ultimo=NULL;
                }
                else if(aux->siguiente==ultimo){
                    NodoS *temp=ultimo;
                    ultimo=aux;
                    ultimo->siguiente=NULL;
                    delete(temp);
                }
                aux=aux->siguiente;
            }
        }
        setSize(getSize()-1);

    }
    /**
     * @brief eliminarPorPosicion Método para eliminar un elemento en la lista por su posición
     * @param pos
     */
    void eliminarPorPosicion(int pos) {
        NodoS *aux = primero;
        NodoS *aux1 = aux->siguiente;

        for (int ind = 1; ind <= pos; ind++) {
            if(ind == pos) {
                aux->siguiente = aux1->siguiente;
                break;
            }
            aux=aux->siguiente;
            aux1=aux1->siguiente;

        }
        setSize(getSize()-1);
        delete(aux1);
        }
    /**
     * @brief mostrarLista Método para imprimir y brindar un resultado del proceso al usuario
     * @return
     */
    string mostrarLista(){
        string R="";
        if (vacio()== true){
            R="Lista Vacia";
        }
        else{
            NodoS *aux=primero;
            int i= 0;
            R="Head-> ";
            while(aux!=NULL){
                R=R+"|"+to_string(aux->getDato())+"|-> ";
                aux=aux->siguiente;
                i++;
            }
            R=R+" End";
            delete(aux);
        }
        return R;
    }
};
