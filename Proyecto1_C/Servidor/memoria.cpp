#include "memoria.h"
#include "iostream"
using namespace std;

/**
 * @brief Constructor de memoria
 *
 */
memoria::memoria()
{
    ptr=&totalm;
}

/**
 * @brief Método para filtrar los datos
 *
 * @param v
 */
void memoria::filtro(string v) {
    if (v=="int"){
        refInt();
    }
    if(v=="long"){
        refLong();
    }
    if(v=="char"){
        refChar();
    }
    if(v=="float"){
        refFloat();
    }
    if(v=="double"){
        refDouble();
    }
    if(v=="ref"){
        refRef();
    }
    else{
        cout << "tipo desconocido" << endl;
    }
}

/**
 * @brief Método para reservar los bytes correspondientes a un int
 *
 * @return int
 */
int * memoria::refInt() {
    if (totalm < 0){
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[0];
    cout << "int" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr+ref << endl;
    current = ptr + ref ;
    return ptr+ref;

}
/**
 * @brief Método para reservar los bytes correspondientes a un long
 *
 * @return int
 */
int * memoria::refLong() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[1];
    cout << "long" << endl;
    cout << ptr << endl;
    ref=3*ref;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un char
 *
 * @return int
 */
int * memoria::refChar() {
    if (totalm < 0){
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[2];
    cout << "char" << endl;
    cout << ptr << endl;
    char k;

    cout << ptr+k << endl;
    return ptr+ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un float
 *
 * @return int
 */
int * memoria::refFloat() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[3];
    cout << "float" << endl;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un double
 *
 * @return int
 */
int * memoria::refDouble() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[0];
    cout << "double" << endl;
    cout << ptr << endl;
    ref= 1.5* ref;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}
/**
 * @brief Método para reservar los bytes correspondientes a un referencia
 *
 * @return int
 */
int * memoria::refRef() {
    if (totalm < 0) {
        cout << "No memory available" << endl;
        ;
    }
    totalm = totalm - param[0];
    cout << "ref" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr + ref << endl;
    current = ptr + ref ;
    return ptr + ref;
}

//filtro para borrar referencias

/**
 * @brief Método para borrar los bytes de las referencia
 *
 * @param v
 */
void memoria::eraser(string v)
{
    if (v=="int"){
        delInt();
    }
    if(v=="long"){
        delLong();
    }
    if(v=="char"){
        delChar();
    }
    if(v=="float"){
        delFloat();
    }
    if(v=="double"){
        delDouble();
    }
    if(v=="ref"){
        delRef();
    }
    else{
        cout << "tipo desconocido" << endl;
    }
}


/**
 * @brief Método para borrar los bytes correspondientes a un int
 *
 * @return int
 */
int * memoria::delInt() {
    if (totalm >= 10024){
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[0];
    cout << "int" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr-ref << endl;
    current = ptr - ref ;
    return ptr-ref;

}
/**
 * @brief Método para borrar los bytes correspondientes a un long
 *
 * @return int
 */
int * memoria::delLong() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[1];
    cout << "long" << endl;
    cout << ptr << endl;
    ref=3*ref;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
/**
 * @brief Método para borrar los bytes correspondientes a un char
 *
 * @return int
 */
int * memoria::delChar() {
    if (totalm >= 10024){
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm - param[2];
    cout << "char" << endl;
    cout << ptr << endl;
    char k;

    cout << ptr-k << endl;
    current = ptr - k ;
    return ptr-k;
}
/**
 * @brief Método para borrar los bytes correspondientes a un float
 *
 * @return int
 */
int * memoria::delFloat() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[3];
    cout << "float" << endl;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
/**
 * @brief Método para borrar los bytes correspondientes a un double
 *
 * @return int
 */
int * memoria::delDouble() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[0];
    cout << "double" << endl;
    cout << ptr << endl;
    ref= 1.5* ref;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
/**
 * @brief Método para borrar los bytes correspondientes a una referencia
 *
 * @return int
 */
int * memoria::delRef() {
    if (totalm >= 10024) {
        cout << "Full memory ready" << endl;
        ;
    }
    totalm = totalm + param[0];
    cout << "ref" << endl;
    cout << ptr << endl;
    ref++;
    cout << ptr - ref << endl;
    current = ptr - ref ;
    return ptr - ref;
}
