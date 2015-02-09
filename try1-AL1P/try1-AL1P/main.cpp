#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>

//#define ABC { 'a', 'b','c','d','e','f', 'g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z', ' '}
//TODA VARIABLE CON NOMBRE VULGAR ES HECHO POR JAIME

using namespace std;

vector<char> ABC{ 'a', 'b','c','d','e','f', 'g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z', ' '};
//char ABC[28] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ' };
/*
	28 caracteres en el ABC
	con char de ascii son a = 97 - z= 122
	25 letras
	con ascii seria mod 128
*/

int pos(char caracter);
vector<vector<double>> invertir(vector<vector<int>>);

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

void empaquetamela(vector<vector<double>>& p, vector<char> kuz)
{
	int x = 0;
	vector<double> temp;
	int tam = ceil(kuz.size()/3);
	for (int i = 0; i <= tam; i++)
	{
		temp.clear();
		for (int j = 0; j < 3; j++)
		{
			//p[i][j] = kuz[j + i];
			if (!kuz.empty())
			{
				/*x = kuz[0];
				kuz.erase(kuz.begin());*/
				x = pos(kuz[0]);
				kuz.erase(kuz.begin());
			}
			else
			{
				x = 27;
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


vector<char> aletreame(vector<vector<double>> tutzke)
{
	vector<char> sharmuta;
	for each (vector<double> modishne in tutzke)
	{

		for (int i = 0; i < 3; i++)
		{

			sharmuta.push_back(ABC[modishne[i]]);

		}

	}
	return sharmuta;
}


int main()
{
	vector<vector<char>> llave; //matriz que se utiliza para encriptar y des encriptar 
	/*
	c++ tiene una convercion implicata de char a int !! :D
	*/
	vector<vector<double>> test = { { 5, 17, 20 }, { 9, 23, 3 }, { 2, 11, 13 } };
	vector<double> test2 = { 1, 2, 3 };
/*	multKcolum(test, test2);
	test2;*/

	vector<char> mila;
	string tujefa;
	getline(cin,tujefa);
	for each (char var in tujefa)
	{
		mila.push_back(var);
	}
	mila;
	vector<vector<double>> zain;

	empaquetamela(zain, mila);
	//zain;

	/*for each (vector<int> var in zain)
	{
		multKcolum(test, var);
	}*/
	for (int i = 0; i < zain.size(); i++)
	{
		multKcolum(test, zain[i]);
	}
	zain; // la multiplicacion para encriptar funge falta modulear
	//moduleamos
	for (int i = 0; i < zain.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			zain[i][j] = ((int)zain[i][j]) % 28;
		}
	}
	zain;
	vector<vector<double>> inversa = { { 0.5288270, -0.0019881, -0.8131213 }, { -0.2206759, 0.0497018, 0.3280318 }, { 0.1053678, -0.0417495, -0.0755467 } };
	
	mila= aletreame(zain);
	for each (char var in mila)
	{
		cout << var;
	}
	system("PAUSE");
	return 0;
}

int pos(char caracter)
{

	for (int i = 0; i < ABC.size(); i++)
	{
		if (caracter == ABC[i])
			return i;
	}

	return -1;

}

//vector<vector<double>> invertir(vector<vector<double>> mat)
//{
//
//	vector<vector<double>> inv;
//
//	for (int i = 0; i < 3; i++)
//	{
//		vector<double> temp;
//		for (int j = 0; j < 3; j++)
//		{
//			for (int k = 0; k < 3; k++)
//			{
//
//			}
//		}
//	}
//
//}