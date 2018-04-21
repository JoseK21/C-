#include "iostream"
using namespace std;


/**
* @brief Clase Node_Rr : Estructura de datos : Nodo Simpre
*
*/
class Node_Rr{
private:
    string memory_address; /**< dirección de memoria */
    string name; /**< nombre */
    string value; /**< valor*/
    string type; /**< tipo */

public:
    Node_Rr *siguiente; /**< Nodo siguiente*/

    /**
     * @brief Metodó para obtener la dirección de memoria de un nodo
     *
     * @return const string
     */
    const string &getMemory_address() const {
        return memory_address;
    }

    /**
     * @brief Metodó para asignar la direccion de memoria
     *
     * @param memory_address
     */
    void setMemory_address(const string &memory_address) {
        Node_Rr::memory_address = memory_address;
    }

    /**
     * @brief Metodó para obtener la direccion de memoria
     *
     * @return const string
     */
    const string &getName() const {
        return name;
    }

    /**
     * @brief Metodó para asignar el nombre
     *
     * @param name
     */
    void setName(const string &name) {
        Node_Rr::name = name;
    }

    /**
     * @brief Metodó para obtener el valor de un nodo
     *
     * @return const string
     */
    const string &getValue() const {
        return value;
    }

    /**
     * @brief Metodó para asignar el valor de un nodo
     *
     * @param value
     */
    void setValue(const string &value) {
        Node_Rr::value = value;
    }

    /**
     * @brief Metodó para obtener el tipo de dato del nodo
     *
     * @return const string
     */
    const string &getType() const {
        return type;
    }

    /**
     * @brief Metodó para asignar el tipo de un nodo
     *
     * @param type
     */
    void setType(const string &type) {
        Node_Rr::type = type;
    }

    /**
     * @brief Metodó para obtener el nodo siguiente
     *
     * @return Node_Rr
     */
    Node_Rr *getSiguiente() const {
        return siguiente;
    }

    /**
     * @brief Metodó para asignar el nodo siguiente
     *
     * @param siguiente
     */
    void setSiguiente(Node_Rr *siguiente) {
        Node_Rr::siguiente = siguiente;
    }

    /**
     * @brief Metodó para crear un nodo con su informacion respectiva
     *
     * @param m direccion de memoria
     * @param n nombre
     * @param v valor
     * @param t tipo
     */
    Node_Rr(string m, string n ,string v ,string t){
        this->siguiente=NULL;
        this->memory_address=m;
        this->name=n;
        this->value=v;
        this->type=t;
    }

};

