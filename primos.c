#include <stdio.h>

int calculo(int cantidad){
    int primos=0;
    int n = 2;
    while(primos<cantidad) {
        int buchhalter=0;
        int m;
        for(m=2;m<n;m++) {
            if(n%m==0){
                buchhalter++;
                break;
            }
        }
        
        if(buchhalter==0) {
            printf("%d-",n);
            primos++;
        } 
        n++;
    }
}

int main() {
    calculo(100);
}