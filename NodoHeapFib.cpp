#include "NodoHeapFib.h"

/**
 * @brief Constructor de la clase NodoHeapFib.
 *
 * Inicializa un nuevo nodo para el heap de Fibonacci con una clave dada y valores predeterminados
 * para el resto de los miembros.
 *
 * @param key La clave que representa el valor o prioridad del nodo en el heap.
 */
NodoHeapFib::NodoHeapFib(int key){
    this->key = key;
    this->degree = 0;
    this->mark = false;
    this->parent = nullptr;
    this->child = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

/**
 * @brief Obtiene la clave del nodo.
 *
 * @return int La clave actual del nodo.
 */
int NodoHeapFib::getKey() const {
    return this->key;
}

/**
 * @brief Establece una nueva clave para el nodo.
 *
 * @param newKey La nueva clave que se asignará al nodo.
 */
void NodoHeapFib::setKey(int newKey) {
    this->key = newKey;
}

/**
 * @brief Obtiene el grado del nodo.
 *
 * @return int El grado actual del nodo, que es el número de hijos que tiene.
 */
int NodoHeapFib::getDegree() const {
    return this->degree;
}

/**
 * @brief Establece un nuevo grado para el nodo.
 *
 * @param newDegree El nuevo grado que se asignará al nodo.
 */
void NodoHeapFib::setDegree(int newDegree) {
    this->degree = newDegree;
}

/**
 * @brief Comprueba si el nodo está marcado.
 *
 * Este marcador se utiliza en operaciones de heap de Fibonacci para indicar que un nodo ha perdido un hijo.
 *
 * @return true Si el nodo está marcado.
 * @return false Si el nodo no está marcado.
 */
bool NodoHeapFib::isMarked() const {
    return this->mark;
}

/**
 * @brief Establece el marcador del nodo.
 *
 * @param newMark El nuevo valor del marcador, verdadero o falso.
 */
void NodoHeapFib::setMark(bool newMark) {
    this->mark = newMark;
}

/**
 * @brief Obtiene el dato almacenado en el nodo.
 *
 * @return int El dato del nodo.
 */
int NodoHeapFib::getData() const {
    return this->data;
}

/**
 * @brief Establece el dato del nodo.
 *
 * @param newData El nuevo dato que se almacenará en el nodo.
 */
void NodoHeapFib::setData(int newData) {
    this->data = newData;
}

/**
 * @brief Obtiene el padre del nodo actual.
 *
 * @return NodoHeapFib* Puntero al nodo padre.
 */
NodoHeapFib* NodoHeapFib::getParent() const {
    return this->parent;
}

/**
 * @brief Establece el padre del nodo.
 *
 * @param newParent Puntero al nuevo nodo padre.
 */
void NodoHeapFib::setParent(NodoHeapFib* newParent) {
    this->parent = newParent;
}

/**
 * @brief Obtiene el hijo del nodo actual.
 *
 * @return NodoHeapFib* Puntero al primer hijo del nodo.
 */
NodoHeapFib* NodoHeapFib::getChild() const {
    return this->child;
}

/**
 * @brief Establece el primer hijo del nodo.
 *
 * @param newChild Puntero al nuevo primer hijo del nodo.
 */
void NodoHeapFib::setChild(NodoHeapFib* newChild) {
    this->child = newChild;
}

/**
 * @brief Obtiene el nodo hermano izquierdo del nodo actual.
 *
 * @return NodoHeapFib* Puntero al nodo hermano izquierdo.
 */
NodoHeapFib* NodoHeapFib::getLeft() const {
    return this->left;
}

/**
 * @brief Establece el nodo hermano izquierdo del nodo.
 *
 * @param newLeft Puntero al nuevo nodo hermano izquierdo.
 */
void NodoHeapFib::setLeft(NodoHeapFib* newLeft) {
    this->left = newLeft;
}

/**
 * @brief Obtiene el nodo hermano derecho del nodo actual.
 *
 * @return NodoHeapFib* Puntero al nodo hermano derecho.
 */
NodoHeapFib* NodoHeapFib::getRight() const {
    return this->right;
}

/**
 * @brief Establece el nodo hermano derecho del nodo.
 *
 * @param newRight Puntero al nuevo nodo hermano derecho.
 */
void NodoHeapFib::setRight(NodoHeapFib* newRight) {
    this->right = newRight;
}