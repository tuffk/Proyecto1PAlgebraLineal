#include "Cifrado.h"

bool valido(vector<vector<int>>);

int main()
{

	string texto;
	vector<vector<int>> llave; // nos gustan los vectores decidimos ahcer una matriz asi. eso se ahce con un vector que contiene vectores.

	//cout << "Inserta el mensaje a cifrar \n";
	//getline(cin, texto);

	cout << "inserta numeros del 0 al 27 para crear una llave de cifrado\n";

	
		for (int i = 0; i < 3; i++)
		{
			vector<int> tempo;
			int temp;
			for (int j = 0; j < 3; j++)
			{
				
					cin >> temp;
					if (27 >= temp && temp >= 0)
					{
						tempo.push_back(temp); //llenamos el vector que despeus ira a la matriz
					}
					else
					{
						cout << "escribe otro numero\n7";
						j--;
					}
					//cout << temp << endl;
				
			}
			llave.push_back(tempo);//dado que una amtriz es un arreglo de arreglos, esto aplica para vectores. llenamos nuestra matriz que es un vector que contiene vectores
		}
	

	if (valido(llave))
	{
		/*Cifrado * encriptador = new Cifrado(texto, llave);
		encriptador->dividir();
		encriptador->imprime_mensaje();
		encriptador->cifrar();
		encriptador->imprime_mensaje();
		encriptador->desencriptar();
		encriptador->imprime_mensaje();*/

		Cifrado * encriptador = new Cifrado("", llave);//creamos nuestro objeto para encritpar y des encriptar

		int choice = -1;
		string tutzke;
		while (choice!=0)
		{
			cout << "elige opcion\n1)cifrar mensaje\n2)desifrar mensaje" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: //caso 1 encriptar un mensaje
				cout << "inserte mensaje a cifrar" << endl;
				cin >> tutzke;
				encriptador->setMensaje(tutzke);
				encriptador->dividir();
				//encriptador->imprime_mensaje();
				encriptador->cifrar();
				encriptador->imprime_mensaje();

				break;

			case 2:// csao 2 des encriptar un mensaje
				
				cout << "isnerte el mensaje encriptado para desencriptarlo" << endl;
				cin >> tutzke;

				encriptador->setMensaje(tutzke);
				encriptador->desencriptar();
				encriptador->imprime_mensaje();


				break;
			default:
				break;
			}

		}


	}
	else
		cout << "Metiste una matriz invalida\n";// "lindo" mensaje de error cuando la matriz no es invertible

	system("pause");
	return 0;
}

bool valido(vector<vector<int>> m) //funcion que valida la matriz mediante el determinante
{
	Cifrado * validator = new Cifrado();
	int det = validator->determinante(m);
	int modulado = 28;
	int mult;
	for (int i = 1; i < 28; i++)
	{
		if (det >= 0)
		{
			if ((det*i)%28==1)
			{
				return true; // la amtriz si es invertible
			}
		}
		else
		{
			if (((det*i) % 28) + 28 == 1)
			{
				return true; // la matriz no es invertible
			}
		}
	}
	return false;
}