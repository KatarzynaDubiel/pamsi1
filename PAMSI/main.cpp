#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

#include "inc/stosLista.hh"
#include "inc/stosTablica.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main( int argc, char *argv[] ) {

    /*   *   *   *   *   *   *   *   *   *   */
        
    if( argc < 2 ) {
        throw logic_error( "Not enough data!" );
    }

    unsigned int size = atoi( argv[1] );
    string fileName = argv[2];
    bool print = argv[3];

    cout << print << endl;

    stosLista<int> stos_1( size );
    stosTablica<int> stos_2( size );

    clock_t start, stop, time_1, time_2;

    /*   *   *   *   *   *   *   *   *   *   */
    /*
        Zestaw pomiarowy 1
    */

    start = clock();

    for( unsigned int i = 0; i < stos_1.maxSize(); i++ ) {
        stos_1.pushBack( pow(i, 2) );
    }

    if(print) { stos_1.print(); }
    stos_1.clear();
    if(print) { stos_1.print(); }

    for( unsigned int i = 0; i < stos_1.maxSize() / 2; i++ ) {
        stos_1.pushBack( pow(i, 3) );
    }

    while( stos_1.curSize() > 0 ) {

        if(print) {
            cout << stos_1.popBack() << endl;
        } else {
            stos_1.popBack();
        }
    }

    stop = clock();
    time_1 = 1000000 * ( stop - start ) / (float)CLOCKS_PER_SEC;

    /*   *   *   *   *   *   *   *   *   *   */

    /*   *   *   *   *   *   *   *   *   *   */
    /*
        Zestaw pomiarowy 2
    */

    start = clock();

    for( unsigned int i = 0; i < stos_2.maxSize(); i++ ) {
        stos_2.pushBack( pow(i, 2) );
    }

    if(print) { stos_2.print(); }
    stos_2.clear();
    if(print) { stos_2.print(); }

    for( unsigned int i = 0; i < stos_2.maxSize() / 2; i++ ) {
        stos_2.pushBack( pow(i, 3) );
    }

    while( stos_2.curSize() > 0 ) {
        if(print) {
            cout << stos_2.popBack() << endl;
        } else {
            stos_2.popBack();
        }
    }

    stop = clock();
    time_2 = 1000000 * ( stop - start ) / (float)CLOCKS_PER_SEC;

    /*   *   *   *   *   *   *   *   *   *   */
    fstream file( fileName, fstream::out );

    file << "Czas zestawu 1: " << time_1 << " us" << endl;
    file << "Czas zestawu 2: " << time_2 << " us" << endl;

    file.close();
}