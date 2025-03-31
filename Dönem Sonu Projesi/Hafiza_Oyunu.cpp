#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

int puan, boyut;
int koordinat_x, koordinat_y;
int eski_koordinat_x, eski_koordinat_y;
vector <int> tablo;
vector <int> harfler;
int kontrol;

// Oyundaki tabloyu oluşturan fonk.
void tabloOlusturma()
{
    int satir = 0, sutun = 1, j = 0, harf = 65;;

    for (int i = 0; i < (boyut * boyut); i++)
    {
        if (i % boyut == 0 && i != 0)
            harf++;

        harfler.push_back(harf);
    }

    srand(static_cast<unsigned int>(std::time(0)));
    random_shuffle(harfler.begin(), harfler.end());

    for (int i = 0; i < (boyut + 1) * (boyut + 1); i++)
    {
        if (i < boyut + 1)
        {
            tablo.push_back(satir);;
            satir++;
        }

        else if (i % (boyut + 1) == 0)
        {
            tablo.push_back(sutun);
            sutun++;
        }

        else
        {
            tablo.push_back(harfler[j]);
            j++;
        }
    }
}

// Tabloyu bastıran fonk.
void tabloBastirma()
{
    for (int i = 0; i < (boyut + 1) * (boyut + 1); i++)
    {
        if (i == koordinat_x * (boyut + 1) + koordinat_y || i == eski_koordinat_x * (boyut + 1) + eski_koordinat_y)
            cout << (char)tablo[i] << "\t";

        else if (tablo[i] == 32)
            cout << (char)tablo[i] << "\t";

        else if (i < boyut + 1)
            cout << tablo[i] << "\t";

        else if (i % (boyut + 1) == 0)
        {
            cout << endl << endl;
            cout << tablo[i] << "\t";
        }

        else
        {
            cout << "*" << "\t";
            if ((i + 1) % (boyut + 1) == 0)
                cout << endl;
        }
    }
    cout << endl;
}

// Koordinat alma fonk.
int koordinatAlma()
{
    do
    {
        // X Koordinatı
        do
        {
            cout << "NOT: Ana Menuye Donmek Icin Herhangi Bir Harf Giriniz." << endl;
            cout << "NOT: Girilen Koordinat Degerinin Gecerli Olmasina ve Acik Bir Yerin Korrdinatinin Girilmemesine Dikkat Ediniz." << endl;
            cout << "Satir Koordinati Giriniz: ";
            cin >> koordinat_x;
            cout << endl;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Oyun Kayit Edildi. Ana Menuye Donuluyor..." << endl;
                Sleep(1000);
                system("cls");
                return kontrol = 1;
            }
        } while (koordinat_x > boyut || koordinat_x <= 0);

        // Y Koordinatı
        do
        {
            cout << "NOT: Ana Menuye Donmek Icin Herhangi Bir Harf Giriniz." << endl;
            cout << "NOT: Girilen Koordinat Degerinin Gecerli Olmasina ve Acik Bir Yerin Korrdinatinin Girilmemesine Dikkat Ediniz." << endl;
            cout << "Sutun Koordinati Giriniz: ";
            cin >> koordinat_y;
            cout << endl;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Oyun Kayit Edildi. Ana Menuye Donuluyor..." << endl;
                Sleep(1000);
                system("cls");
                return kontrol = 1;
            }
        } while (koordinat_y > boyut || koordinat_y <= 0);

    } while (tablo[koordinat_x * (boyut + 1) + koordinat_y] == 32);

    return kontrol = 0;
}

// Kayıt Yapan Fonk.
void save()
{
    ofstream file("save.txt");

    file << puan << endl;
    for (int i = 0; i < (boyut + 1) * (boyut + 1); i++)
        file << tablo[i] << " ";

    file.close();
}

// Kayıtı Yükleyen Fonk.
bool load()
{
    ifstream file("save.txt");
    if (file.is_open())
    {
        file >> puan;
        for (int i = 0; i < (boyut + 1) * (boyut + 1); i++)
            file >> tablo[i];

        file.close();
        return true;
    }

    else
        return false;
}

// Oyunun Döngüsü
void Baslat()
{
    if (!load())
    {
        do
        {
            cout << "NOT: boyut en az '4' olamalidir ve bir cift sayi olmalidir." << endl;
            cout << "Oyunun Boyutunu Giriniz: ";
            cin >> boyut;
            system("cls");
        } while (boyut < 4 || boyut % 2 == 1);

        puan = 0;

        tabloOlusturma();
    }

    // Oyun Döngüsü
    for (int i = 1; i < (boyut + 1); i++)
    {
        for (int j = 1; j < (boyut + 1); j++)
        {
            while (tablo[i * (boyut + 1) + j] != 32)
            {
                cout << "Puan: " << puan << endl << endl;
                tabloBastirma();

                koordinatAlma();
                system("cls");

                if (kontrol == 1)
                {
                    save();
                    return;
                }

                cout << "Puan: " << puan << endl << endl;
                tabloBastirma();

                // karşılaştırmak üzere koordinatlar farklı bir değere atandı.
                eski_koordinat_x = koordinat_x;
                eski_koordinat_y = koordinat_y;

                koordinatAlma();
                system("cls");

                if (kontrol == 1)
                {
                    save();
                    return;
                }


                cout << "Puan: " << puan << endl << endl;
                tabloBastirma();

                Sleep(2000);
                system("cls");

                if (tablo[eski_koordinat_x * (boyut + 1) + eski_koordinat_y] == tablo[koordinat_x * (boyut + 1) + koordinat_y])
                {
                    tablo[eski_koordinat_x * (boyut + 1) + eski_koordinat_y] = 32;
                    tablo[koordinat_x * (boyut + 1) + koordinat_y] = 32;
                    puan += 3;
                }

                else
                    puan -= 1;

                koordinat_x = -1;
                koordinat_y = -1;
                eski_koordinat_x = -1;
                eski_koordinat_y = -1;
            }
        }
    }
}

// Menuyu Bastiran Fonk.
void anaMenu()
{
    cout << "1: Yeni Oyuna Basla" << endl;
    cout << "2: Kayitli Oyundan Devam Et" << endl;
    cout << "3: Cikis Yap" << endl << endl;
    cout << "Bir Islem Seciniz: ";
}

int main()
{
    int secim;
    do {
        anaMenu();

        cin >> secim;
        system("cls");

        switch (secim)
        {
        case 1:
            remove("save.txt");
            tablo.clear();
            harfler.clear();
            Baslat();
            break;

        case 2:
            if (!load())
            {
                cout << "Kayitli Oyun Bulunamadi. Yeni Oyun Baslatiliyor...";
                Sleep(1000);
                system("cls");
                Baslat();
            }

            else
            {
                cout << "Kayitli Oyun Baslatiliyor..." << endl;
                Sleep(1000);
                system("cls");
                Baslat();
            }
            break;

        case 3:
            cout << "Kayit Dosyalari Siliniyor. Cikis Yapiliyor...";
            Sleep(1000);
            system("cls");
            remove("save.txt");
            break;

        default:
            cout << "Gecersiz Islem!!!" << endl;
            Sleep(1000);
            system("cls");
            break;
        }
    } while (secim != 3);

    remove("save.txt");
}