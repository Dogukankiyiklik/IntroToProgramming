#include <iostream>
#include <string>

using namespace std;

int main()
{
	string cumle;
	cout << "cumleyi giriniz" << endl;
	getline(cin, cumle);

	// 1. İşlem
	int i = 0;
	size_t right = cumle.length();

	while (i < cumle.length()) {

		if (cumle[i] > 64 && cumle[i] < 91) {

			cumle.resize(right + 1);

			while (right > i) {

				cumle[right] = cumle[right - 1];
				right--;
			}
			i++;
		}

		i++;
		right = cumle.length();
	}

	cout << "1.Islemin Sonucu :" << cumle << endl;
	cout << "uzunluk:" << cumle.length() << endl;

	
	// 2. İşlem
	int bosluk_sayisi = 0;
	int harf_baslangici = 0;
	int a = 0;
	int yeni_index = 0;
	int sinir = 0;

	for (a; a < cumle.length(); a++) {
		
		if (cumle[a] == ' ') {

			if (cumle[a + 1] != ' ') {
				continue;
			}

			else {

				harf_baslangici = a;
				while (cumle[harf_baslangici] == ' ') {

					bosluk_sayisi++;
					harf_baslangici++;
				}

				yeni_index = a + 1;
				sinir = harf_baslangici;
				for (int m = 0; m < cumle.length() - sinir; m++) {

					cumle[yeni_index] = cumle[harf_baslangici];
					yeni_index++;
					harf_baslangici++;
				}

				cumle.resize(yeni_index);
			}
		}
	}


	cout << "2.Islemin Sonucu :" << cumle << endl;
	cout << "uzunluk:" << cumle.length() << endl;


	// 3. İşlem
	int index_1 = 0;
	
	if (cumle[index_1] > 96 && cumle[index_1] < 123) {
		cumle[index_1] = cumle[index_1] - 32;
	}

	for (int i = 0; i < cumle.length(); i++) {

		if (cumle[i] == ' ') {

			if (cumle[i + 1] > 96 && cumle[i + 1] < 123) {
				cumle[i + 1] = cumle[i + 1] - 32;
			}

		}
	}

	cout << "3.Islemin Sonucu :" << cumle << endl;
	cout << "uzunluk:" << cumle.length() << endl;


	// 4. İşlem
	int gecici;
	size_t uzunluk = cumle.length();

	for (int i = 0; i < uzunluk / 2; i++) {

		gecici = cumle[i];
		cumle[i] = cumle[uzunluk - i - 1];
		cumle[uzunluk - i - 1] = gecici;
	}

	cout << "4.Islemin Sonucu :" << cumle << endl;
	cout << "uzunluk:" << cumle.length() << endl;

	return 0;
}