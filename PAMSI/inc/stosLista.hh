#include <iostream>
#include <list>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
class stosLista {
    private:
        
        unsigned int size;

        list<T> stack;

    public:

        stosLista( unsigned int size );
        ~stosLista();

        bool isEmpty();

        unsigned int curSize();
        unsigned int maxSize();

        T popBack();
        void pushBack( T data );

        void clear();
        void print();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
stosLista<T>::stosLista( unsigned int size ) {

    this->size = size;
}

template <typename T>
stosLista<T>::~stosLista() {

    this->stack.clear();
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
bool stosLista<T>::isEmpty() {
    bool isEmpty = this->stack.empty();
    return isEmpty;
}

template <typename T>
unsigned int stosLista<T>::curSize() {
    return this->stack.size();
}

template <typename T>
unsigned int stosLista<T>::maxSize() {
    return this->size;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
T stosLista<T>::popBack() {
    
    if( this->stack.size() > 0 ) {

        T data = this->stack.back();
        this->stack.pop_back();
        return data;

    } else {
        throw out_of_range("Stack is already empty!");
    }
}

template <typename T>
void stosLista<T>::pushBack( T data ) {

    if( this->stack.size() < this->size ) {

        this->stack.push_back( data );

    } else {
        throw out_of_range("Stack is already full!");
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void stosLista<T>::clear() {
    
    this->stack.clear();
}

template <typename T>
void stosLista<T>::print() {
    

    for( T & i : this->stack ) {
        cout << i << endl;
    }
}