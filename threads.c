#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct objetos {
    int prosid;
    int cantidad;
};

void *myThread(void *vargp) {
    //parsear puntero
    struct objetos *argus = (struct objetos *)vargp;
    int cantidad = argus->cantidad;
	//int *myid = (int *)vargp;
	sleep(1);
	printf("TID: %d\n", argus->prosid);
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
            printf("Thread #%d: Los numeros primos son: %d \n",argus->prosid,n);
            primos++;
        } 
        n++;
    }
	return NULL; 
} 
  
int main(int argc , char * argv [])
{
    //declaración de threads
    pthread_t tid;
    pthread_t tid2;
    char* tmp = (char*)malloc(10 * sizeof(char));
    printf("Ingrese cantidad que desea: ");
	scanf("%s", tmp);
    printf("Thanks: %s\n", tmp);
    int cant = atoi(tmp);
	free(tmp);
    //thread 1
    struct objetos par1;
    par1.prosid = tid;
    par1.cantidad = cant;

    //thread 2
    struct objetos par2;
    par2.prosid = tid2;
    par2.cantidad = cant;

    pthread_create(&tid, NULL, myThread, (void *)&par1);
    pthread_create(&tid2, NULL, myThread, (void *)&par2); 

	pthread_join(tid, NULL); 
	pthread_join(tid2, NULL);

    return 0;
}