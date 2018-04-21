#ifndef MEMORIA_H
#define MEMORIA_H
#include "iostream"
using namespace std;

/**
 * @brief Clase Memoria
 *
 */
class memoria
{
public:
    char *total = (char *) malloc(10024 * sizeof(int)); /** Memoria local*/
    int param[6] = {4, 8, 1, 4, 8, 4}; /**< Parametro de bites de cada tipo de dato*/
    int ref= 0; /**< Valor de referecnia para operar sobre los valores de memoria*/
    int *ptr; /**< puntero null que va a apuntar a regiiones moviles de memoria */
    int totalm = 10024; /**< Variable de control  */
    int *current; /**< Variable de control para mantener el flujo de los punteros */
    /**
     * @brief Constructurar de memoria
     *
     */
    memoria();

    /**
     * @brief Método de referencias de enteros (4Bytes)
     *
     * @return int
     */
    int * refInt();
    /**
     * @briefMétodo de referencias de long (8Bytes)
     *
     * @return int
     */
    int* refLong();
    /**
     * @brief Método de referencias de caracter (1Bytes)
     *
     * @return int
     */
    int* refChar();
    /**
     * @brief Método de referencias de float (4Bytes)
     *
     * @return int
     */
    int* refFloat();
    /**
     * @brief Método de referencias de double (4Bytes)
     *
     * @return int
     */
    int* refDouble();
    /**
     * @brief Método de referencias de referencia (4Bytes)
     *
     * @return int
     */
    int* refRef();
    /**
     * @brief Método para dividir el trabajo de asignacion de memoria (4Bytes)
     *
     * @param v
     */
    void filtro(string v);
    /**
     * @brief Método para eliminar la referencia de enteros
     *
     * @return int
     */
    int* delInt();
    /**
     * @brief Método para eliminar la referencia de long
     *
     * @return int
     */
    int* delLong();
    /**
     * @brief Método para eliminar la referencia de caracter
     *
     * @return int
     */
    int* delChar();
    /**
     * @brief Método para eliminar la referencia de float
     *
     * @return int
     */
    int* delFloat();
    /**
     * @brief Método para eliminar la referencia de double
     *
     * @return int
     */
    int* delDouble();
    /**
     * @brief Método para eliminar la referencia de referencia
     *
     * @return int
     */
    int* delRef();
    /**
     * @brief Método para eliminar total
     *
     * @param v
     */
    void eraser(string v);
};

#endif // MEMORIA_H
