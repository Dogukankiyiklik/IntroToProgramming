#include <iostream>
#include <string>
#include<ios>
#include<limits>
using namespace std;

#define N 4

struct Ogrenci
{
	string Ad_Soyad;
	int Ogrenci_No = 0;
	float Not_Ort = 0;
};

int main()
{
	Ogrenci arr[N];
	int degisken;

	// 1. Ýþlem
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << "." << " Ogrencinin Adini ve Soyadini Giriniz: ";
		getline(cin, arr[i].Ad_Soyad);

		cout << i + 1 << "." << " Ogrencinin Ogrenci Numarasini Giriniz: ";
		cin >> arr[i].Ogrenci_No;

		cout << i + 1 << "." << " Ogrencinin Not Ortalamasini Giriniz: ";
		cin >> arr[i].Not_Ort;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	}
	cout << "-------------------------------" << endl;

	// 2. Ýþlem
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++) {
			if (arr[i].Ogrenci_No > arr[j].Ogrenci_No)
			{
				string temp1 = arr[i].Ad_Soyad;
				int temp2 = arr[i].Ogrenci_No;
				float temp3 = arr[i].Not_Ort;
				arr[i].Ad_Soyad = arr[j].Ad_Soyad;
				arr[i].Ogrenci_No = arr[j].Ogrenci_No;
				arr[i].Not_Ort = arr[j].Not_Ort;
				arr[j].Ad_Soyad = temp1;
				arr[j].Ogrenci_No = temp2;
				arr[j].Not_Ort = temp3;
			}
		}
	}	
	for (int i = 0; i < N; i++) 
	{
		cout << arr[i].Ad_Soyad << endl;
		cout << arr[i].Ogrenci_No << endl;
		cout << arr[i].Not_Ort << endl;
	}
	cout << "-------------------------------" << endl;

	// 3. Ýþlem
	float temp = arr[0].Not_Ort;
	degisken = 0;
	for (int i = 1; i < N; i++)
	{
		if (temp > arr[i].Not_Ort) 
		{
			temp = arr[i].Not_Ort;
			degisken = i;
		}
	}
	cout << arr[degisken].Ad_Soyad << endl;
	cout << arr[degisken].Ogrenci_No << endl;
	cout << arr[degisken].Not_Ort << endl;
	cout << "-------------------------------" << endl;

	// 4. Ýþlem
	temp = arr[0].Not_Ort;
	degisken = 0;
	for (int i = 1; i < N; i++)
	{
		if (temp < arr[i].Not_Ort) 
		{
			temp = arr[i].Not_Ort;
			degisken = i;
		}
	}
	cout << arr[degisken].Ad_Soyad << endl;
	cout << arr[degisken].Ogrenci_No << endl;
	cout << arr[degisken].Not_Ort << endl;
}