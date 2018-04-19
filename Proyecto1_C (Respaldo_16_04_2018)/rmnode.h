#ifndef RMNODE_H
#define RMNODE_H

template<class J,class T>
class RMnode {
public:
    RMnode<J,T>* next;
    T data;
    J key;
    bool operator==(const RMnode<J,T>& node); //compara si el data de dos nodos es igual
    void operator=(const RMnode<J,T> &node);//copia el data de un nodo a otro ej. nodo1=nodo2 le da el data de nodo2 al nodo1
    bool operator!=(const RMnode<J,T> &node);// verifica si el data de dos nodos es diferente
    static std::string toJsonStr(RMnode<J,T> node);
    static RMnode<J,T> strToNode(std::string str);

    static RMnode<J,T> nodeFromJsonObject (std::string objStr);
};


#endif // RMNODE_H
