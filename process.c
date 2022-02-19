#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



int calculo(int cantidad, int nump) {
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
            printf("Proceso #%d: Los numeros primos son: %d \n",nump,n);
            primos++;
        } 
        n++;
    }
}

void calculate()
{
    char* tmp = (char*)malloc(10 * sizeof(char));
	printf("Ingrese cantidad que desea: ");
	scanf("%s", tmp);
	printf("Thanks: %s\n", tmp);
    int cant = atoi(tmp);
	free(tmp);
    //convert string to int
	// child process because return value zero
	if (fork() == 0)
        calculo(cant,1);
		//printf("Hello from Child!\n");

	// parent process because return value non-zero.
	else
        calculo(cant,2);
		//printf("Hello from Parent!\n");
}
int main()
{
	calculate();
	return 0;
}
