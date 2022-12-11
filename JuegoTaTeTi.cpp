#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//ARRAY PARA EL TABLERO Y DECLARACION DE LAS VARIABLES
char tablero[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}, turno = 'O';

int elec,fila,columna;

bool fin = false;

//ORDENAR EL TABLERO EN FORMA DE OCTOHORPE (#), CADA CUADRO ES ASIGNADO UN NUMERO

void tablero_m(){
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);	//CODIGO PARA MANIPULAR COLOR DE LA CONSOLA
	
	SetConsoleTextAttribute(h,4); //CAMBIA EL COLOR DE LAS SIGUIENTES LINEAS
    cout<<"\n\tJUGADOR 1 [O] |\t JUGADOR 2 [X]" << endl << endl;
    SetConsoleTextAttribute(h,7);
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<tablero[0][0]<<"  |  "<<tablero[0][1]<<"  |  "<<tablero[0][2]<< endl;
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<tablero[1][0]<<"  |  "<<tablero[1][1]<<"  |  "<<tablero[1][2]<< endl;
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<tablero[2][0]<<"  |  "<<tablero[2][1]<<"  |  "<<tablero[2][2]<< endl;
    cout<<"\t\t     |     |     \n";
}


//ACTUALIZA EL TABLERO E INTRODUCE LA ELECCION DEL JUGADOR
void jugada(){
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	
    if(turno == 'O'){
    	SetConsoleTextAttribute(h,10);
        cout<<"\n\tTurno del jugador 1 [O]: ";
    }
    else if(turno == 'X'){
		SetConsoleTextAttribute(h,12);
        cout<<"\n\tTurno del jugador 2 [X]: ";
    }
    //ENTRADA PARA EL USUARIO
    
    //ACTUALIZAR EL TABLERO SEGUN LA ELECCION Y REASIGNA EL TURNO

    cin>> elec;

    //SENTENCIA SWITCH PARA ENCONTRAR LA FILA Y COLUMNA PARA ACTUALIZAR. EN EL CASO DE DIFERIR, INDICA QUE NO SE PERMITE DICHO MOVIMIENTO

    switch(elec){
        case 1: fila=0; columna=0; break;
        case 2: fila=0; columna=1; break;
        case 3: fila=0; columna=2; break;
        case 4: fila=1; columna=0; break;
        case 5: fila=1; columna=1; break;
        case 6: fila=1; columna=2; break;
        case 7: fila=2; columna=0; break;
        case 8: fila=2; columna=1; break;
        case 9: fila=2; columna=2; break;
        default:
            cout<<"MOVIMIENTO NO VALIDOS";
    }

    if(turno == 'O' && tablero[fila][columna] != 'O' && tablero[fila][columna] != 'X'){
        //ACTUALIZA LA POSICION DE 'O' EN EL CASO DE NO ESTAR OCUPADO
    	SetConsoleTextAttribute(h,12); 
        tablero[fila][columna] = 'O';
        turno = 'X';
    }else if(turno == 'X' && tablero[fila][columna] != 'O' && tablero[fila][columna] != 'X'){
        //ACTUALIZA LA POSICION DE 'X' EN EL CASO DE NO ESTAR OCUPADO
    	SetConsoleTextAttribute(h,10);          
		tablero[fila][columna] = 'X';
        turno = 'O';
    }else {
        //EN EL CASO DE QUE LA CASILLA ESTE OCUPADA
        cout << "CASILLERO OCUPADO. ELIJA OTRO \n\n";
        jugada();
    }
    /* AL FINALIZAR */
    tablero_m();
}

//BOOL QUE COMPRUEBA EL ESTADO DEL JUEGO

bool finaliza(){
    //COMPRUEBA LAS FILAS Y COLUMNAS
    for(int i=0; i<3; i++)
    if(tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2] || tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i])
    return false;

    //COMPRUEBA LAS DIAGONALES

    if(tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2] || tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
    return false;

    //COMPRUEBA EL ESTADO DEL JUEGO (CONTINUO/FINALIZADO)
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(tablero[i][j] != 'O' && tablero[i][j] != 'X')
    return true;

    //COMPRUEBA EL EMPATE/FINALIZADO
    fin = true;
    return false;
}

//PROGRAMA

int main()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,11);
    cout<<"\t\t\tTA";
	SetConsoleTextAttribute(h,15);
	cout<<" - ";
	SetConsoleTextAttribute(h,13);
	cout<<"TE";
	SetConsoleTextAttribute(h,15);
	cout<<" - ";
	SetConsoleTextAttribute(h,14);
	cout<<"TI\t\t\t";
	
    while(finaliza()){
        tablero_m();
        jugada();
        finaliza();
    }
    
    if(turno == 'X' && fin == false){
        cout<<"FELICIDADES! EL JUGADOR 1 GANO LA PARTIDA";
    }
    else if(turno == 'O' && fin == false){
        cout<<"FELICIDADES! EL JUGADOR 2 GANO LA PARTIDA";
    }
    else
    cout<<"EMPATE!";
} 
