#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <pthread.h>
#include <stdlib.h>



#define limite 50



FILE *nuevo;


sem_t semaforo;
sem_t semaforo2;
sem_t semaforo3;
int i=1;
int terminado1=2;
int terminado2=2;
int terminado3=2;
int acabo;

void lectura() {
int c;
	FILE * archivo = fopen("receta.txt","rb");				//Abre el archivo
	while ((c=fgetc(archivo)) != EOF){					//recorre todo el archivo
	putchar(c);								//muestra por la terminal el contenido del archivo
}
}



void *cortar (int p) {
	if (acabo==0){								//se fija si ya alguien termino las 2 hamburguesas 

	printf ("el competidor %i , esta lavando cortando y mezclando \n",p);
	fprintf(nuevo,"el competidor %i , esta lavando cortando y mezclando \n",p);  //los fprintf se utilizan para escribir en el archivo.txt
	
	usleep(2000000);
	}
}

void *salando (int p) {
	if (acabo==0){								//se fija si ya alguien termino las 2 hamburguesas 

	sem_wait(&semaforo);							//pone el semaforo en 0 y se ejecuta, o espera que el semaforo este en 1 

	printf ("el competidor %i , esta salando la comida \n",p);
	fprintf(nuevo,"el competidor %i , esta salando la comida \n",p);        //los fprintf se utilizan para escribir en el archivo.txt
	
	usleep(2000000);

	sem_post(&semaforo);							//termina y pone el semaforo en 1 para que otro pueda entrar

}}

void *planchando (int p) {
	if (acabo==0){								//se fija si ya alguien termino las 2 hamburguesas 

	sem_wait(&semaforo2);							//pone el semaforo en 0 y se ejecuta, o espera que el semaforo este en 1 

	printf ("el competidor %i , esta planchando la hamburguesa \n",p);
	fprintf(nuevo,"el competidor %i , esta planchando la hamburguesa \n",p); //los fprintf se utilizan para escribir en el archivo.txt
	usleep(2000000);

	sem_post(&semaforo2);							//termina y pone el semaforo en 1 para que otro pueda entrar

	}
}

void *horneando (int p) {
	if (acabo==0){								//se fija si ya alguien termino las 2 hamburguesas 
	
	sem_wait(&semaforo3);							//pone el semaforo en 0 y se ejecuta, o espera que el semaforo este en 1 

	printf ("el competidor %i , esta horneando la hamburguesa \n",p);
	fprintf(nuevo,"el competidor %i , esta horneando la hamburguesa \n",p);	//los fprintf se utilizan para escribir en el archivo.txt
	usleep(2000000);							//los sleeps son para simular que los competidores cocinan
	
	sem_post(&semaforo3);							//termina y pone el semaforo en 1 para que otro pueda entrar
	
	}
}



void *cocinandoando () {
	while(terminado1>0){		
	
	cortar(1);	
		
	
		
	salando(1);
	
	
	
	
	planchando(1);

	
	

	horneando(1);

	
	
			
	if (terminado1==2){
		
		printf("\n EL EQUIPO  %i ACABA DE TERMINAR LA PRIMER HAMBURGUESA \n \n", 1);
		fprintf(nuevo,"\n EL EQUIPO  %i ACABA DE TERMINAR LA PRIMER HAMBURGUESA \n \n", 1);
		
		
	terminado1--;}
	else{
		if (terminado1==1 && acabo==0){
		
		printf("\n ¡¡¡¡¡ACABA DE GANAR EL EQUIPO %i!!!!!! \n \n", 1);
		fprintf(nuevo,"\n ¡¡¡¡¡ACABA DE GANAR EL EQUIPO %i!!!!!! \n \n", 1);
		terminado1--;
		
		acabo=1;
	}
	else {
	terminado1--;	
}

}
	
	

}}
void *cocinandoando2 () {
	while(terminado2>0){		
	
	cortar(2);	
		
	
		
	salando(2);
	
	
	
	planchando(2);

	

	horneando(2);

	
	
			
	if (terminado2==2){
		
		printf("\n EL EQUIPO  %i ACABA DE TERMINAR LA PRIMER HAMBURGUESA \n \n", 2);
		fprintf(nuevo,"\n EL EQUIPO  %i ACABA DE TERMINAR LA PRIMER HAMBURGUESA \n \n", 2);
		
	terminado2--;}
	else{
		if (terminado2==1 && acabo==0){
		

		printf("\n ¡¡¡¡¡ACABA DE GANAR EL EQUIPO %i!!!!!! \n \n", 2);
		fprintf(nuevo,"\n ¡¡¡¡¡ACABA DE GANAR EL EQUIPO %i!!!!!! \n \n", 2);
		
		terminado2--;
		acabo=1;
	}
	else {
	terminado2--;	
}
}
terminado2==-1;
}}
void *cocinandoando3 () {
	while(terminado3>0){		
	
	cortar(3);	
		
	
		
	salando(3);
	
	
	
	planchando(3);

	
	horneando(3);

	
			
	if (terminado3==2){

		fprintf(nuevo,"\n EL EQUIPO  %i ACABA DE TERMINAR LA PRIMER HAMBURGUESA \n \n",3);
		printf("\n EL EQUIPO  %i ACABA DE TERMINAR LA PRIMER HAMBURGUESA \n \n",3);
		
	terminado3--;}
	else{
		if (terminado3==1 && acabo==0){								//se fija si nadie acabo y si ya termino la primera
													// hamburguesa 
		fprintf(nuevo,"\n ¡¡¡¡¡ACABA DE GANAR EL EQUIPO %i!!!!!! \n \n",3);
		printf("\n ¡¡¡¡¡ACABA DE GANAR EL EQUIPO %i!!!!!! \n \n", 3);
		acabo=1;

		terminado3--;
		terminado1--;
		terminado2--;
		
	
	}
	else {
	
	terminado3--;	
}
}

}}

int main(){
	
	nuevo= fopen("comp.txt","w");
	lectura();
	
	printf("\n¡COMIENZA LA COMPETENCIAAAA! \n \n");
	fprintf(nuevo,"\n ¡COMIENZA LA COMPETENCIAAAA! \n \n");			//los fprintf se utilizan para escribir en el archivo.txt

	
	
	

	acabo=0;
	int tiempo=200000;
	int value=1;
	int sem1 = sem_init(&semaforo,0,1);					//
	int sem2 = sem_init(&semaforo2,0,1);					//Los semaforos comienzan inicializados en 1
	int sem3 = sem_init(&semaforo3,0,1);					//


	
	pthread_t competidor2;						
	pthread_t competidor3;
	pthread_t competidor1;

	
	pthread_create(&competidor1,NULL,cocinandoando,&value);			//	
	pthread_create(&competidor2,NULL,cocinandoando2,&value);		//se crean los 3 competidores
	pthread_create(&competidor3,NULL,cocinandoando3,&value);		//
	
	pthread_join(competidor1,NULL);
	pthread_join(competidor2,NULL);
	pthread_join(competidor3,NULL);
	
	
	fclose(nuevo);								//se cierra el archivo de texto
	
	

return 0;
}
