#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>

//#define ABC { 'a', 'b','c','d','e','f', 'g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z', ' '}

using namespace std;

vector<char> ABC{ 'a', 'b','c','d','e','f', 'g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z', ' '};
//char ABC[28] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ' };
/*
	28 caracteres en el ABC
	con char de ascii son a = 97 - z= 122
	25 letras
	con ascii seria mod 128
*/


void multKcolum(vector<vector<double>> mat, vector<double>&col)
{
	vector<double> temp{ 0, 0, 0 };
	for (int i = 0; i < 3; i++) // i recorre la matriz en y
	{
		for (int j = 0; j < 3; j++)//j recorre la matriz en x 
		{
			temp[i] += (mat[i][j]*col[j]);
		}
	}

	col = temp;
	return;
}

void empaquetamela(vector<vector<double>>& p, vector<char> vagina)
{
	int x = 0;
	vector<double> temp;
	int tam = ceil(vagina.size()/3);
	for (int i = 0; i <= tam; i++)
	{
		temp.clear();
		for (int j = 0; j < 3; j++)
		{
			//p[i][j] = vagina[j + i];
			if (!vagina.empty())
			{
				x = vagina[0];
				vagina.erase(vagina.begin());
			}
			else
			{
				x = 0;
			}
			

			temp.push_back(x);
			
		}
		p.push_back(temp);
	}
	/*char kk;
	for (int i = 0; i < p.size();i++)
	{
		for (int j = 0; j < 3; j++)
		{
			kk = p[i][j];
			cout << kk;
		}
	}*/
	return;
}


int main()
{
	vector<vector<char>> llave; //matriz que se utiliza para encriptar y des encriptar 
	/*
	c++ tiene una convercion implicata de char a int !! :D
	*/
	vector<vector<double>> test = { { 5, 17, 20 }, { 9, 23, 3 }, { 2, 11, 13 } };
	vector<double> test2 = { 1, 2, 3 };
	multKcolum(test, test2);
	test2;

	vector<char> mila;
	string tujefa;
	getline(cin,tujefa);
	for each (char var in tujefa)
	{
		mila.push_back(var);
	}
	mila;
	vector<vector<double>> pito;

	empaquetamela(pito, mila);
	//pito;

	/*for each (vector<int> var in pito)
	{
		multKcolum(test, var);
	}*/
	for (int i = 0; i < pito.size(); i++)
	{
		multKcolum(test, pito[i]);
	}
	pito; // la multiplicacion para encriptar funge falta modulear
	//moduleamos
	for (int i = 0; i < pito.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pito[i][j] = ((int)pito[i][j]) % 128;
		}
	}
	pito;
	vector<vector<double>> inversa = { { 0.5288270, -0.0019881, -0.8131213 }, { -0.2206759, 0.0497018, 0.3280318 }, { 0.1053678, -0.0417495, -0.0755467 } };
	
	system("PAUSE");
	return 0;
}