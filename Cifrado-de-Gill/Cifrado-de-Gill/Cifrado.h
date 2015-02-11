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

	void setMensaje(string m);
	string getMensaje();

	void setLlave(vector<vector<int>> ll);
	vector<vector<int>> getLlave();

	void dividir();

	int posicion(char);

	void cifrar();

	int determinante(vector<vector<int>>);

	void desencriptar();

	vector<vector<int>> cofactor(vector<vector<int>>);

	int cofactoreo(int, vector<vector<int>>);

	vector<vector<int>> transpuesta(vector<vector<int>>);

	void imprime_mensaje();

private:
	string abc;
	string mensaje;
	vector<vector<int>> palabras_divididas;
	vector<vector<int>> llave;
};