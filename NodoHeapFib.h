#ifndef NODOHEAPFIB_H
#define NODOHEAPFIB_H

/*
    * Representa un nodo de un heap de fibonacci
    * puede tener padre, hijo, y hermanos
*/
class NodoHeapFib {
private:
    // Valor del nodo
    int key;
    // Número de hijos
    int degree;
    // Indica si el nodo ha perdido un hijo desde la última vez que fue el resultado de una operación extractMin
    bool mark;
    // almacena el id de un NodoGrafo
    int data;
    NodoHeapFib* parent;
    NodoHeapFib* child;
    NodoHeapFib* left;
    NodoHeapFib* right;
public:
    //constructor
    NodoHeapFib(int key);

    // getters
    int getKey() const;
    int getDegree() const;
    int getData() const;
    NodoHeapFib* getParent() const;
    NodoHeapFib* getChild() const;
    NodoHeapFib* getLeft() const;
    NodoHeapFib* getRight() const;

    // setters
    void setKey(int newKey);
    void setDegree(int newDegree);
    void setMark(bool newMark);
    void setData(int newData);
    void setParent(NodoHeapFib* newParent);
    void setChild(NodoHeapFib* newChild);
    void setLeft(NodoHeapFib* newLeft);
    void setRight(NodoHeapFib* newRight);
    
    // otros metodos
    bool isMarked() const;
};

#endif // NODOHEAPFIB_H