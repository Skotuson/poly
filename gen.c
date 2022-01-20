#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main ( void ) {

    srand(time(NULL));  
    int polyLength = 0, maxPow = 0, pow = 0, cnt = 0;
    
    int a[30] = {};
    int b[30] = {};
    int c[30] = {};

    for ( int i = 0; i < 50; i++ ) {
        polyLength = rand() % 30 + 1;
        maxPow = pow = rand() % 99;
        cnt = 0;

        for ( int j = 0; j < polyLength; j++ ) {
            cnt++;
            a[j] = rand() % 1500;
            b[j] = rand() % 1500;
            c[j] = a[j] + b[j];
            pow -= rand() % 3 + 1;
        }

        printf( "testPolyAdd ( " );
        int val = 0;
        for ( int j = 0; j < 3; j++ ) {
            printf("\"");
            for ( int k = 0; k < cnt; k++ ) {
                switch ( j ) {
                   case 0: 
                    val = a[k];
                    break; 
                   case 1: 
                    val = b[k];
                    break; 
                   case 2: 
                    val = c[k];
                    break; 
                }
                if ( k ) printf(" ");
                printf("%d^%d", val, maxPow - k);
            }
            printf("\"");
            if ( j < 2 ) printf(", ");
        }
        printf ( " );\n" );
    }
    return 0;
}