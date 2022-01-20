#include <stdio.h>
#include <stdlib.h>

typedef struct TItem {
    struct TItem * next;
    int pow;
    int mul; 
} TITEM;

TITEM * createNode ( int mul, int pow, TITEM * next ) {
    TITEM * node = ( TITEM* ) malloc ( sizeof ( TITEM ) );
    node -> mul = mul;
    node -> pow = pow;
    node -> next = next;
    return node;
}

void deleteList ( TITEM * l ) {
    while ( l ) {
        TITEM * tmp = l -> next;
        free ( l );
        l = tmp;
    }
}

void printList ( TITEM * l ) {
    while ( l ) {
        printf( "%d^%d -> ", l -> mul, l -> pow );
        l = l -> next;
    }
    printf("\n");
}

void printPoly ( TITEM * l ) {
    
}

TITEM * parseList ( const char * str ) {
    TITEM * head = NULL;
    int a = 0, b = 0, c = 0;
    while ( sscanf( str, " %d^%d%n", &a, &b, &c ) == 2 ) {
        head = createNode ( a, b, head );
        str += c;
    }
    return head;
}

TITEM * addPoly ( TITEM * a, TITEM * b ) {

}

int main ( void ) {
    
    TITEM * a = parseList ( "9^3 2^1 3^0" );
    printList ( a );
    deleteList ( a );

    TITEM * b = parseList ( "8^3 4^2 2^1 10^0" );
    printList ( b );
    deleteList ( b );

    return 0;
}