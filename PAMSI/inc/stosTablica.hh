#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
class stosTablica {
    private:
        
        unsigned int index;
        unsigned int size;

        T * stack;

    public:

        stosTablica( unsigned int size );
        ~stosTablica();

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
stosTablica<T>::stosTablica( unsigned int size ) {

    this->index = 0;
    this->size = size;

    this->stack = new T [size];
}

template <typename T>
stosTablica<T>::~stosTablica() {

    delete [] this->stack;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
bool stosTablica<T>::isEmpty() {

    bool isEmpty = (this->index > 0) ? false : true;
    return isEmpty;
}

template <typename T>
unsigned int stosTablica<T>::curSize() {
    return this->index;
}

template <typename T>
unsigned int stosTablica<T>::maxSize() {
    return this->size;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
T stosTablica<T>::popBack() {
    
    if( this->index > 0 ) {

        T data = this->stack[ --this->index ];
        return data;

    } else {
        throw out_of_range("Stack is already empty!");
    }
}

template <typename T>
void stosTablica<T>::pushBack( T data ) {

    if( this->index < this->size ) {

        this->stack[ this->index++ ] = data;

    } else {
        throw out_of_range("Stack is already full!");
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void stosTablica<T>::clear() {
    
    this->index = 0;
}

template <typename T>
void stosTablica<T>::print() {
    
    for( unsigned int i = 0; i < this->index; i++ ) {
        cout << this->stack[i] << endl;
    }
}