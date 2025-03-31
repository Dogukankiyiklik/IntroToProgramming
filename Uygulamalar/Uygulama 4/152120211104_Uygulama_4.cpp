#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	float matrisA[2][2], temp, det;

	// Dosyaya matrisin elemanlarýný yazma iþlemi
	ofstream MatrisA;
	MatrisA.open("matrixA.txt");
	MatrisA << "1 2 3 4";
	MatrisA.close();

	// 1. Ýþlem
	ifstream fin;
	fin.open("matrixA.txt");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			fin >> matrisA[i][j];
	}
	fin.close();

	cout << "A MATRISI" << endl;
	cout << "---------" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrisA[i][j] << "\t";
		}
		cout << endl;
	}

	// Matrisin tersinin var olup olmadýðýnýn determinant ile kontrolü
	det = (matrisA[0][0] * matrisA[1][1]) - (matrisA[0][1] * matrisA[1][0]);

	if (det == 0)
	{
		ofstream MatrisB;
		MatrisB.open("matrixB.txt");
		MatrisB << "A matrisinin tersi yoktur" << endl;
		MatrisB.close();
	}

	else
	{
		// 2x2 matrisin tersinin alýnmasý
		temp = matrisA[0][0];
		matrisA[0][0] = matrisA[1][1];
		matrisA[1][1] = temp;
		matrisA[0][1] = -(matrisA[0][1]);
		matrisA[1][0] = -(matrisA[1][0]);

		ofstream MatrisB;
		MatrisB.open("matrixB.txt");

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				MatrisB << matrisA[i][j] / det << " ";
		}
		MatrisB.close();
	}
}