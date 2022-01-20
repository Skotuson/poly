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
    TITEM * head = NULL, * curr = NULL;
    int mul, pow;
    while ( a && b ) {
        if ( a -> pow == b -> pow ) {
            mul = a -> mul + b -> mul;
            pow = a -> pow;
            a = a -> next;
            b = b -> next;
        }
        else if ( a -> pow < b -> pow ) {   
            mul = a -> mul;
            pow = a -> pow;
            a = a -> next;
        }
        else {
            mul = b -> mul;
            pow = b -> pow;
            b = b -> next;
        }
        if ( !head )
            curr = head = createNode ( mul, pow, NULL );
        else {
            curr -> next = createNode ( mul, pow, NULL );
            curr = curr -> next;
        }
    }
    return head;
}

int main ( void ) {
    
    TITEM * a = parseList ( "9^3 2^1 3^0" );
    TITEM * b = parseList ( "-1^3 4^2 7^0" );
    TITEM * c = addPoly ( a, b );
    
    printList ( a );
    printList ( b );
    printList ( c );
    
    deleteList ( a );
    deleteList ( b );
    deleteList ( c );

    return 0;
}