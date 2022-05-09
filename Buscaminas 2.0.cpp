/*Buscaminas con tablero y bombas a elegir, cambio de colores al perder o ganar y opción a volver a jugar
Creado por Irene Ruiz*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
int main() {
	int juego;
	bool jugar=false;
	do {
		jugar=false;
		bool finJuego=false;
		int tablero, bombas;
		int bombafila, bombacolumna; /*variables para añadir las bombas en posiciones aleatorias*/
		int filau, columnau; /*Variables introducidas por el usuario*/
		std::cout <<"Introduce el tamaño del tablero: ";
		std::cin>> tablero;
		std::cout << "Introduce las bombas: ";
		std::cin >> bombas;
		int cd=tablero*tablero; /*variable que cuenta las casillas descubiertas*/
		char b[tablero+2][tablero+2]; /*Matriz de bombas oculta*/
		int m[tablero+2][tablero+2]; /*Matriz que se mostrará al usuario*/
		for (int fila=0; fila<tablero+2; fila++) { 
			for (int columna=0; columna<tablero+2; columna++) {
				b[fila][columna]='-';
				m[fila][columna]=-1;
				/*Matrices rellenadas*/
			}
		} 
		srand(time(NULL));
		for(int contadorbombas=0 /*variable para añadir bombas*/; contadorbombas<bombas;contadorbombas++){
			bombafila=(rand()%tablero+1);
			bombacolumna=(rand()%tablero+1);
			/*Si la casilla ya tiene una bomba, se resta al contador para poner una mas*/
			if(b[bombafila][bombacolumna]=='-'){ 
				b[bombafila][bombacolumna] ='b';	
			}
			else {
				contadorbombas=contadorbombas-1;
			}	
		}
		do{
			do{
				std::cout << "Dame una fila y una columna válidas:\n";
				std::cin >> filau >> columnau;
			} while (filau<1||filau>tablero||columnau<1||columnau>tablero);
			/*si hay una bomba en esas csilla*/
			if (b[filau][columnau]=='b') {/*imprime el tablero m*/
				system ("color 4");
				for (int ifilam=1; ifilam<=tablero; ifilam++) {
					for (int icolumnam=1; icolumnam<=tablero; icolumnam++) {
						std::cout << b[ifilam] [icolumnam] << "\t";
					}
					std::cout << "\n";
				}
				std::cout << "BOOM\n";
				finJuego=true;
			}
			/*si no hay una bomba en esa casilla*/
			else if (b[filau][columnau]!='b'){
				cd=tablero*tablero;
				int bvecinas=0; /*variable que cuenta las bombas que hay en las casillas vecinas a la introducida por el usuario*/	
				for(int fu=-1/*contador para solo contar bombas en un espacio de 3 filas*/; fu<2; fu++) {
					for (int cu=-1/*contador para solo contar bombas en un espacio de tres columnas*/; cu<2; cu++) {
						if(b[(filau)+fu][(columnau)+cu]=='b') {
							bvecinas=bvecinas+1;
						}
					}
				}
				m[filau][columnau]=bvecinas; /*ahora la casilla descubierta pasa a mostrar el numero de bombas alrededor*/
				/*bucle para imprimir el tablero m con el nuevo número descubierto*/
				for (int fimp=1/*variable para imprimir las filas*/; fimp<=tablero; fimp++) {
					for(int cimp=1/*variable para imprimir las columnas*/; cimp<=tablero ; cimp++) {
						if (m[fimp][cimp]==-1) { /*para imprimir - en vez de un -1*/ 
							std::cout << "-\t";
						}
						else { /*para mostrar las casillas descubiertas */
							std::cout << m[fimp][cimp] << "\t";
						}
					}
					std::cout << "\n";
				}
				/*cuenta las casillas descubiertas en cada turno*/
				for(int filacd=1; filacd<=tablero;filacd++) {
					for(int columnacd=1; columnacd<=tablero; columnacd++) {
						if(m[filacd][columnacd]==-1) {
							cd=cd-1;
						}
					}
				}
				std::cout << cd << " casillas descubiertas.\n";
			}	
		} while((cd<tablero*tablero-bombas)&&(finJuego!=true)); /*bucle para seguir jugando hasta que salga una bomba o se descubran todas las casillas posibles*/
		if(cd==tablero*tablero-bombas) {
			system ("color 6");
			std::cout << "GANA\n";
		}
		/*si el usuario gana:*/
		std::cout << "Introduce 1 para volver a jugar:";
		std::cin >> juego;
		if(juego==1 ){
			system ("color 7");
			jugar=true;
		}
	} while(jugar==true); /*bucle para jugar una nueva partida*/
	std::cout << "Adios";
	return 0;
}

