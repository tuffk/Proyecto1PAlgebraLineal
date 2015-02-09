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

*/

void multKcolum(vector<vector<int>> mat, vector<int>&col)
{
	vector<int> temp{ 0, 0, 0 };
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

void empaquetamela(vector<vector<int>>& p, vector<char> vagina)
{
	int x = 0;
	vector<int> temp;
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
				continue;
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
	vector<vector<int>> test = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<int> test2 = { 1, 2, 3 };
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
	vector<vector<int>> pito;

	empaquetamela(pito, mila);
	pito;

	system("PAUSE");
	return 0;
}