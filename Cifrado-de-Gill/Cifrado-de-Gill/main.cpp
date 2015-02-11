#include "Cifrado.h"

bool valido(vector<vector<int>>);

int main()
{

	string texto;
	vector<vector<int>> llave;

	cout << "Inserta el mensaje a cifrar \n";
	getline(cin, texto);

	cout << "inserta numeros del 0 al 27 para crear una llave de cifrado\n";

	do
	{
		for (int i = 0; i < 3; i++)
		{
			vector<int> tempo;
			int temp;
			for (int j = 0; j < 3; j++)
			{
				do
				{
					cin >> temp;
					if (27 >= temp && temp >= 0)
					{
						tempo.push_back(temp);
					}
					else
						cout << "escribe otro numero\n7";

					cout << temp << endl;
				} while (27 < temp && temp < 0);
			}
			llave.push_back(tempo);
		}
	}
	while (!valido(llave)); // este do while esta raro, el de arriba tambien, no se si esten jalando

	if (valido(llave))
	{
		Cifrado * encriptador = new Cifrado(texto, llave);
		encriptador->dividir();
		encriptador->imprime_mensaje();
		encriptador->cifrar();
		encriptador->imprime_mensaje();
		encriptador->desencriptar();
		encriptador->imprime_mensaje();
	}
	else
		cout << "La cagaste, metiste una matriz invalida\n";

	system("pause");
	return 0;
}

bool valido(vector<vector<int>> m)
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
				return true;
			}
		}
		else
		{
			if (((det*i) % 28) + 28 == 1)
			{
				return true;
			}
		}
	}
	return false;
}