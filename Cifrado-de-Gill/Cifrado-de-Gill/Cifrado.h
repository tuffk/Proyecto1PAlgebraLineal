#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Cifrado
{

public:
	Cifrado();
	Cifrado(string m, vector<vector<int>> ll);
	//cosntructores

	void setMensaje(string m);//permite cambiar el mensaje a encriptar/ des encriptar
	string getMensaje();// si tienes altz heimer y nesesitas recordar que escribiste

	void setLlave(vector<vector<int>> ll); // permite cambiar a matriz de encriptacion
	vector<vector<int>> getLlave();//para ver la amtriz

	void dividir();//para poder hacer la multiplicacion de 3*3 de la matriz los vectores deben ser 3*1. con esta funcion "empaquetamos" el mensaje en vectores de 3*1

	int posicion(char);//devuelve la posicion (numero) del character en nuestro ABC

	void cifrar();//aqui es dodne susede al magia

	int determinante(vector<vector<int>>);// para obtener el determinante 

	void desencriptar();// la magia inversa 

	vector<vector<int>> cofactor(vector<vector<int>>);// da la matriz de cofactores 

	int cofactoreo(int, vector<vector<int>>);//da el cofactor NO LA MTRIZ

	vector<vector<int>> transpuesta(vector<vector<int>>); // transpone la mtriz 

	void imprime_mensaje();// permite imprimir el mensaje previo/post a la encriptacion/desencriptacion

private:
	string abc;
	string mensaje;
	vector<vector<int>> palabras_divididas;
	vector<vector<int>> llave;
};