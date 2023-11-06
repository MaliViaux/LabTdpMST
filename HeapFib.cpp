#include "HeapFib.h"

/**
 * @brief Constructor de la clase HeapFib.
 *
 * Inicializa un nuevo heap de Fibonacci. Establece el nodo mínimo y la cabeza de la lista de raíces
 * a `nullptr`, y el contador de nodos a 0. Este estado inicial indica que el heap está vacío.
 */
HeapFib::HeapFib(){
    this->min = nullptr;
    this->rootsListHead = nullptr;
    this->numNodos = 0;
}

/**
 * @brief Destructor de la clase HeapFib.
 *
 * Libera la memoria de todos los nodos en el heap de Fibonacci. Extrae y elimina cada nodo
 * comenzando por el nodo mínimo hasta que el heap esté completamente vacío.
 */
HeapFib::~HeapFib() {
    while (min != nullptr) {
        NodoHeapFib* current = extractMin();
        delete current;
    }
}

/**
 * @brief Obtiene el nodo mínimo del heap de Fibonacci.
 *
 * Retorna el nodo que actualmente tiene el valor mínimo en el heap. Si el heap está vacío,
 * retorna `nullptr`.
 *
 * @return NodoHeapFib* El nodo mínimo del heap o `nullptr` si el heap está vacío.
 */
NodoHeapFib* HeapFib::getMin(){
    return this->min;
}


/**
    * @brief Inserta un nuevo nodo con un valor dado en el heap de Fibonacci y actualiza el nodo mínimo si es necesario.
    * @param key El valor del nuevo nodo a insertar en el heap.
    * @return NodoHeapFib* Retorna un puntero al nodo recién insertado en el heap.
*/
NodoHeapFib* HeapFib::insert(int key){
    NodoHeapFib* nodo = new NodoHeapFib(key);
    // Configuración del nuevo nodo como un ciclo.
    nodo->setLeft(nodo);
    nodo->setRight(nodo);
    this->insertRootList(nodo);
    // Actualización del nodo mínimo si es necesario.
    if (this->min == nullptr || nodo->getKey() < this->min->getKey()){
        this->min = nodo;
    }
    this->numNodos += 1;
    return nodo;
}
 

/**
 * @brief Inserta un nodo en la lista de raíces del heap de Fibonacci.
 * @param nodo El puntero al nodo que se insertará en la lista de raíces
 * @return void
 */
void HeapFib::insertRootList(NodoHeapFib* nodo){
    // Verificación si la lista de raíces está vacía.
    if (this->rootsListHead == nullptr){
        // Inicialización de la lista de raíces con el nuevo nodo.
        this->rootsListHead = nodo;
        nodo->setLeft(nodo);
        nodo->setRight(nodo);
    }
    else{
        // Inserción del nodo en la lista doblemente enlazada de raíces.
        nodo->setRight(this->rootsListHead);
        nodo->setLeft(this->rootsListHead->getLeft());
        this->rootsListHead->getLeft()->setRight(nodo);
        this->rootsListHead->setLeft(nodo);
    }
}
 
/**
 * @brief Extrae el nodo con el valor mínimo del heap de Fibonacci.
 * Elimina y devuelve el nodo mínimo. Si es el único elemento y no tiene hijos, el heap se queda
 * vacío. Si tiene hijos, estos se insertan en la lista de raíces. Después de la extracción, 
 * se realiza un proceso de consolidación para reestructurar el heap y encontrar el nuevo mínimo.
 * 
 * @return NodoHeapFib* El puntero al nodo con el valor mínimo que se ha extraído
 */
NodoHeapFib* HeapFib::extractMin(){
    NodoHeapFib* aux = this->min;
    // si el minimo es el ultimo nodo en el heap
    if (aux->getRight() == aux && aux->getChild() == nullptr){
        this->min = nullptr;
        this->rootsListHead = nullptr;
        return aux;
    }
    if (aux == nullptr){
        return aux;
    }
    NodoHeapFib* child = aux->getChild();
    NodoHeapFib* nextChild;
    if (child != nullptr){
        NodoHeapFib* ptr = child;
        do { // Mover los hijos del nodo mínimo a la lista de raíces.
            nextChild = child->getRight();
            insertRootList(child);
            child->setParent(nullptr);
            child = nextChild;
        } while (child != ptr);
    }
    if (aux->getRight() == aux) {
        this->min = nullptr;
    } else {
        removeRoot(aux);
        this->min = aux->getRight();
    }
    consolidate();
    this->numNodos -= 1;
    return aux;
}

/**
 * @brief Consolida el heap de Fibonacci para mantener sus propiedades.
 * 
 * se después de extraer el nodo mínimo. Recorre los nodos en la lista de raíces y los consolida, 
 * asegurando que cada grado esté representado una vez. Utiliza un arreglo de punteros para almacenar los nodos con 
 * grados distintos y combina aquellos con el mismo grado. Después de la consolidación, se actualiza el nodo mínimo del heap.
 * 
 * No hay retorno ya que la función modifica el estado interno del heap directamente.
 */
void HeapFib::consolidate() {
    float f = (log(this->numNodos)) / (log(2)); // grado maximo esperado segun la cantidad de nodos
    int maxDegree = static_cast<int>(std::floor(f)) + 1;
    std::vector<NodoHeapFib*> A(maxDegree, nullptr);
    NodoHeapFib *x = this->min;
    NodoHeapFib *y;
    int d;
    do { // Iterar sobre la lista de raíces y unir nodos del mismo grado.
        d = x->getDegree();
        while (A[d] != nullptr) {
            y = A[d];
            if (x->getKey() > y->getKey()) {
                std::swap(x, y);
            }
            mergeHeap(x, y);
            A[d] = nullptr;
            d += 1;
        }
        A[d] = x;
        x = x->getRight();
    } while (x != this->min);
    this->min = nullptr;
    if (!this->rootsListHead) {
        return;
    }
    NodoHeapFib* current = this->rootsListHead;
    NodoHeapFib* start = current;
    NodoHeapFib* minNode = current;
    do { // itera la lista de raices buscando el nuevo minimo
        if (current->getKey() < minNode->getKey()) {
            minNode = current;
        }
        current = current->getRight();
    } while (current != start);
    this->min = minNode;
}

/**
 * @brief Remueve un nodo de la lista de raíces del heap de Fibonacci.
 * 
 * Este método desconecta el nodo proporcionado de la lista de raíces del heap. Si el nodo a eliminar
 * es el único nodo en la lista de raíces, el puntero a la cabeza de la lista de raíces se establece
 * en nullptr. Si el nodo a eliminar es el nodo cabeza de la lista, se actualiza la cabeza a su nodo
 * hermano derecho.
 * 
 * @param nodo El nodo a ser removido de la lista de raíces.
 */
void HeapFib::removeRoot(NodoHeapFib* nodo){
    if(nodo->getRight() == nodo && nodo->getLeft() == nodo){
        // si se esta eliminando la ultima raiz
        this->rootsListHead = nullptr;
    } else {
        // enlazar los hermanos de nodo entre si
        nodo->getLeft()->setRight(nodo->getRight());
        nodo->getRight()->setLeft(nodo->getLeft());
        if (this->rootsListHead == nodo){
            this->rootsListHead = nodo->getRight();
        }
    }
    // Configuración del nuevo nodo como un ciclo.
    nodo->setLeft(nodo);
    nodo->setRight(nodo);
}

/**
 * @brief Fusiona dos árboles en el heap de Fibonacci, haciendo de uno el hijo del otro.
 * 
 * Este método quita el nodo y de la lista de raíces y lo hace hijo del nodo x, incrementando
 * el grado de x. Si los nodos son iguales, se reporta un error y la función retorna prematuramente.
 * 
 * @param y El nodo que se convertirá en hijo.
 * @param x El nodo que se convertirá en padre.
 */
void HeapFib::mergeHeap(NodoHeapFib* y, NodoHeapFib* x){
    if (x == y) {
        std::cerr << "Error: Intento de mergeHeap con el mismo nodo." << std::endl;
        return;
    }
    this->removeRoot(y);
    y->setLeft(y);
    y->setRight(y);
    this->insertChildList(x, y);
    x->setDegree(x->getDegree() + 1);
    y->setParent(x);
    y->setMark(false);
}

/**
 * @brief Inserta un nodo en la lista de hijos de un nodo padre en el heap de Fibonacci.
 * 
 * agrega el nodo dado a la lista circular de hijos del nodo padre. Si el
 * padre no tiene hijos, el nodo se convierte en el único hijo. Si el padre 
 * ya tiene hijos, el nuevo nodo se inserta en la lista circular.
 * 
 * @param parent El nodo que será el padre.
 * @param nodo El nodo que se insertará como hijo.
 */
void HeapFib::insertChildList(NodoHeapFib* parent, NodoHeapFib* nodo){
    if (parent->getChild() == nullptr) {
        // si el padre no tiene hijos 
        parent->setChild(nodo);
        nodo->setRight(nodo); 
        nodo->setLeft(nodo);
    } else {
        // enlazar el nodo en la lista de hijos
        NodoHeapFib* firstChild = parent->getChild();
        NodoHeapFib* lastChild = firstChild->getLeft();
        nodo->setRight(firstChild);
        nodo->setLeft(lastChild);
        firstChild->setLeft(nodo);
        lastChild->setRight(nodo);
    }
}

/**
 * @brief Disminuye el valor de la clave de un nodo y reestructura el heap si es necesario.
 * 
 * Si el nuevo valor es mayor que el actual, la función retorna sin hacer cambios. caso contrario,
 * actualiza la clave del nodo y si tiene una clave menor que la de su padre, se realiza un corte del
 * nodo y posiblemente un corte en cascada. También actualiza el nodo mínimo del heap si es necesario.
 * 
 * @param nodo El nodo cuya clave se disminuirá.
 * @param nuevoValor El nuevo valor de la clave para el nodo.
 */
void HeapFib::decreaseKey(NodoHeapFib* nodo, int nuevoValor){
    if (nuevoValor > nodo->getKey()) {
        return;
    }

    nodo->setKey(nuevoValor);
    NodoHeapFib* parent = nodo->getParent();

    if (parent != nullptr && nodo->getKey() < parent->getKey()) {
        cut(nodo, parent);
        cascadingCut(parent);
    }

    if (nodo->getKey() < this->min->getKey()){
        this->min = nodo;
    }
}

/**
 * @brief Corta la conexión entre un nodo hijo y su padre, moviendo el hijo a la lista de raíces.
 * 
 * Remueve el nodo hijo de la lista de hijos del padre, disminuye el grado del padre, añade el hijo
 * a la lista de raíces del heap, y establece su marca en falso.
 * 
 * @param child El nodo hijo que será cortado.
 * @param parent El nodo padre del hijo.
 */
void HeapFib::cut(NodoHeapFib* child,  NodoHeapFib* parent){
    this->removeChild(child, parent);
    parent->setDegree(parent->getDegree() - 1);
    this->insertRootList(child);
    child->setParent(nullptr);
    child->setMark(false);
}

/**
 * @brief Realiza cortes en cascada hacia arriba en el árbol.
 * 
 * Si el nodo está marcado, se corta la conexión con su padre y se procede recursivamente. Si el nodo
 * no está marcado, se marca. Continúa hasta llegar a un nodo que no está marcado o a la raíz del árbol.
 * 
 * @param nodo El nodo donde comienza el corte en cascada.
 */
void HeapFib::cascadingCut(NodoHeapFib* nodo){
    NodoHeapFib* aux = nodo->getParent();
    if (aux != nullptr){
        if (!nodo->isMarked()){
            nodo->setMark(true);
        }
        else{
            this->cut(nodo, aux);
            this->cascadingCut(aux);
        }
    }
}

/**
 * @brief Remueve un nodo de la lista de hijos de su padre.
 * 
 * Si el nodo es el único hijo, el puntero al hijo del padre se establece en nullptr. De lo contrario,
 * actualiza las conexiones entre los hermanos del nodo removido y actualiza el
 * puntero del hijo del padre al siguiente hermano.
 * 
 * @param child El nodo hijo a ser removido.
 * @param parent El nodo padre del hijo.
 */
void HeapFib::removeChild(NodoHeapFib* child, NodoHeapFib* parent){
    if (parent->getChild() == child && child->getRight() == child) {
        parent->setChild(nullptr);
    } else {
        if (parent->getChild() == child) {
            parent->setChild(child->getRight());
            child->getRight()->setParent(parent);
        }
        child->getLeft()->setRight(child->getRight());
        child->getRight()->setLeft(child->getLeft());
    }
    child->setLeft(child);
    child->setRight(child);
}

/**
 * @brief Comprueba si el heap de Fibonacci está vacío.
 *
 * Determina si el heap de Fibonacci no contiene ningún elemento. Esto es útil para
 * saber si aún hay elementos a ser procesados en algoritmos como el de Prim.
 *
 * @return true si el heap está vacío, false si contiene al menos un elemento.
 */
bool HeapFib::isEmpty() const {
    return this->min == nullptr;
}

/**
 * @brief Imprime la clave del nodo mínimo en el heap de Fibonacci.
 * param: none
 * return: void
 */
void HeapFib::printHeapMinimum() {
    if (!this->isEmpty()) {
        std::cout << "El minimo actual del heap es: " << this->getMin()->getKey() << std::endl;
    } else {
        std::cout << "El heap está vacío." << std::endl;
    }
}