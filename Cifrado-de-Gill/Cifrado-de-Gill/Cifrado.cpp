#include "Cifrado.h"

Cifrado::Cifrado() 
{
	mensaje = "";
	abc = "abcdefghijklmnñopqrstuvwxyz ";
}

Cifrado::Cifrado(string m, vector<vector<int>> ll)
{
	mensaje = m;
	llave = ll;
	abc = "abcdefghijklmnñopqrstuvwxyz ";
}

void Cifrado::setMensaje(string m)
{
	mensaje = m;
}

string Cifrado::getMensaje()
{
	return mensaje;
}

void Cifrado::setLlave(vector<vector<int>> ll)
{
	llave = ll;
}
vector<vector<int>> Cifrado::getLlave()
{
	return llave;
}

void Cifrado::dividir()
{

	palabras_divididas.clear();

	for (int i = 0; i < mensaje.length(); i = i)
	{
		vector<int> temp;
		for (int j = 0; j < 3; j++)
		{
			if (i >= mensaje.length())
				temp.push_back(27);//el ultimo vector 3*1 no siempre es exacto y se llena con el mensjae, asi que si queda espacio en blanco l o llenamos con espacios para que no afecte el mensaje
			else
				temp.push_back(posicion(mensaje.at(i)));

			i++;
		}
		palabras_divididas.push_back(temp);
	}

}

void Cifrado::cifrar()
{
	for (int i = 0; i < palabras_divididas.size(); i++)
	{
		vector<int> temporal;
		for (int j = 0; j < 3; j++)
		{
			int temp = 0;
			for (int k = 0; k < 3; k++)
			{
				temp += llave[j][k] * palabras_divididas[i][k];//se multiplica la llave por el vector
			}
			temporal.push_back(temp%28); // aqui es la aritmetica modualr
		}
		palabras_divididas[i] = temporal;
	}
}

void Cifrado::desencriptar()
{
	int det = determinante(llave);
	int mult;
	for (int i = 1; i < 28; i++)
	{
		if (det >= 0)
		{
			if ((det*i) % 28 == 1)
			{
				mult = i;
				break;
			}
		}
		else
		{
			if (((det*i) % 28)+28 == 1)
			{
				mult = i;
				break;
			}
		}
	}//sacamos el numero magico para multiplciar la matriz y desencriptar
	vector<vector<int>> cofito = cofactor(llave);
	vector<vector<int>>cofactorial = transpuesta(cofito);


	for (int i = 0; i < cofactorial.size(); i++)
	{
		for (int j = 0; j < cofactorial.size(); j++)
		{
			cofactorial[i][j] = ((cofactorial[i][j] * mult));
		}
	}


	vector<vector<int>> inversa;

	for (int i = 0; i < cofactorial.size(); i++)
	{
		vector<int> temporalidad;
		for (int j = 0; j < cofactorial.size(); j++)
		{
			if (cofactorial[i][j] >= 0)
				temporalidad.push_back(cofactorial[i][j] % 28);
			else
				temporalidad.push_back((cofactorial[i][j] % 28)+28);
		}
		inversa.push_back(temporalidad);// hacemos la mtriz de cofactores
	}

	llave = inversa;
	cifrar();//se aplcia el algoritmo de manera inversa

}

vector<vector<int>> Cifrado::cofactor(vector<vector<int>> m)
{
	//funcion que da la matriz de cofactores
	if (m.size() != 2)
	{
		vector<vector<int>> cofactorial;
		for (int i = 0; i < m.size(); i++)
		{
			vector<int> temp;
			for (int j = 0; j < m.size(); j++)
			{
				
				int cofa = m[i][j];
				vector<vector<int>> mat_temp;
				for (int k = 0; k < m.size(); k++)
				{
					
					if (i != k)
					{
						vector<int> fila_temp;
						for (int l = 0; l < m.size(); l++)
						{
							if (j != l)
								fila_temp.push_back(m[k][l]);
							else
								continue;
						}
						mat_temp.push_back(fila_temp);
					}
					else
						continue;
				}

				temp.push_back(cofactoreo(cofa, mat_temp)*pow(-1,(i+j)%2));
			}
			cofactorial.push_back(temp);
		}
		return cofactorial;
	}
	else
		return m;

}

int Cifrado::cofactoreo(int cof, vector<vector<int>> m)
{
	// seria mas bien sacar el determinante de cuando ya es 2*2
	if (m.size() == 2)
	{
		return 1*(m[0][0] * m[1][1] - m[1][0] * m[0][1]);
	}
	else
	{
		for (int i = 0; i < m.size(); i++)
		{
			vector<int> temp;
			for (int j = 0; j < m.size(); j++)
			{

				int cofa = m[i][j];
				vector<vector<int>> mat_temp;
				for (int k = 0; k < m.size(); k++)
				{
					vector<int> fila_temp;
					if (i != k)
					{
						for (int l = 0; l < m.size(); l++)
						{
							if (j != l)
								fila_temp.push_back(m[k][l]);
							else
								continue;
						}
					}
					else
						continue;
				}

				temp.push_back(cofactoreo(cofa, mat_temp));
			}
		}
	}


}

int Cifrado::determinante(vector<vector<int>> m)
{
	int m1 = m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
	int m2 = m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2]);
	int m3 = m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]);

	return m1 - m2 + m3;
	//devuelve el determinante
}

vector<vector<int>> Cifrado::transpuesta(vector<vector<int>> m)
{
	//funcion que transpone la matriz 
	vector<vector<int>> trans;

	for (int i = 0; i < m.size(); i++)
	{
		vector<int> temp;
		for (int j = 0; j < m.size(); j++)
		{
			temp.push_back(0);
		}
		trans.push_back(temp);
	}

	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			trans[j][i] = m[i][j];
		}
	}

	return trans;

}

int Cifrado::posicion(char p)
{
	//para poder convertir el mensjae en numero
	for (int i = 0; i < abc.size(); i++)
	{
		if (abc[i] == p)
			return i;
	}

	return -1;
}

void Cifrado::imprime_mensaje()
{

	string impresion = "";

	for (int i = 0; i < palabras_divididas.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (palabras_divididas[i][j] != -1)
				impresion += abc[palabras_divididas[i][j]];
			else
				impresion += " ";
		}
	}

	cout << impresion << endl;

}