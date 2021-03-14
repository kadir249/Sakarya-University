/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: �dev 3
**				��RENC� ADI...............: Kadir �elik
**				��RENC� NUMARASI.: B181210057
**				DERS GRUBU����: 1C Grubu
****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//Dizide kullan�lacak de�i�kenler belirleniyor
struct Islem
{
	int giris[5][5] = { 3, 2, 5, 1, 4,
						6, 2, 1, 0, 7,
						3, 0, 0, 2, 0,
						1, 1, 3, 2, 2,
						0, 3, 1, 0, 0 };
	int boyut;
	int kaydirmaSayisi;
	int cikisSatir;
	int cikisSutun;
	int sonucMatris[100][100];
	int cekirdekMatris[100][100];
};

//Sonu� matrisini bulmak i�in kullan�lacak �arpma i�lemi tan�mlan�yor
int carpma_fonksiyonu(int a, int b)
{
	return a * b;
}

int main()
{
	struct Islem yapilacakIslem;

	//T�rk�e karakterlerin ekranda g�z�kmesi i�in
	setlocale(LC_ALL, "Turkish");

	//De�i�kenler
	int eleman = (sizeof(yapilacakIslem.giris) / sizeof(int));//Matrisin boyutu belirleniyor
	int maxSatir = sqrt(eleman);//Matriste kullan�lan sat�r say�s� belirleniyor
	int maxSutun = sqrt(eleman);//Matriste kullan�lan sutun say�s� belirleniyor

	int carp = 0;
	int topla = 0;

	cout << "�ekirdek Matrisin Boyutunu Giriniz: "; cin >> yapilacakIslem.boyut;//Kullan�c�dan �ekirdek matrisin boyutu isteniyor
	cout << "\n";
	cout << "Kayd�rma Miktar�n� Giriniz: "; cin >> yapilacakIslem.kaydirmaSayisi;//Kullan�c�dan kayd�rma say�s� isteniyor

	//E�er kayd�rma say�s� 0 ise ve �ekirdek matrisin boyutu giri� matrisinin boyutuna b�y�k e�itse i�lem yap�lmaz
	if (yapilacakIslem.kaydirmaSayisi == 0 || yapilacakIslem.boyut >= maxSatir)
	{
		cout << "��lem Yap�lamaz!!!" << endl;
	}

	//Ko�ullar sa�lanm�yorsa i�lem yap�l�yor
	else
	{
		//E�er �ekirdek matrisi giri� matrisinde tam olarak kayma i�lemini yapam�yorsa i�lem yap�lmaz
		if ((maxSatir - yapilacakIslem.boyut) % yapilacakIslem.kaydirmaSayisi != 0)
		{
			cout << "�slem Yap�lamaz!!!" << endl;
		}

		//Ko�ullar sa�lanm�yorsa i�lem yap�l�yor
		else
		{
			yapilacakIslem.cikisSatir = ((maxSatir - yapilacakIslem.boyut) / yapilacakIslem.kaydirmaSayisi) + 1;//��k�� matrisinin sat�r say�s� hesaplan�yor

			yapilacakIslem.cikisSutun = ((maxSutun - yapilacakIslem.boyut) / yapilacakIslem.kaydirmaSayisi) + 1;//��k�� matrisinin s�tun say�s� hesaplan�yor
			cout << endl;

			cout << "--�ekirdek Matrisi--" << endl;
			//�ekirdek matrisinin sat�rlar�n� kullan�c� taraf�ndan boyuta kadar yazd�rmak i�in
			for (int cekirdekx = 0; cekirdekx < yapilacakIslem.boyut; cekirdekx++)
			{
				//�ekirdek matrisinin s�tunlar�n� kullan�c� taraf�ndan boyuta kadar yazd�rmak i�in
				for (int cekirdeky = 0; cekirdeky < yapilacakIslem.boyut; cekirdeky++)
				{
					cout << "�ekirdek[" << cekirdekx << "] [" << cekirdeky << "] Giriniz: "; cin >> yapilacakIslem.cekirdekMatris[cekirdekx][cekirdeky];//Kullan�c�dan matrisin elemanlar� isteniyor
					cout << endl;
				}
			}
			cout << endl;
			cout << "--Sonu� Matrisi--" << endl;
			//0'dan sonu� matrisinin boyutu kadar cikisz'yi artt�r�r
			for (int cikisz = 0; cikisz < yapilacakIslem.cikisSatir; cikisz++)
			{
				//0'dan sonu� matrisinin boyutu kadar cikist'yi artt�r�r
				for (int cikist = 0; cikist < yapilacakIslem.cikisSutun; cikist++)
				{
					//0'dan �ekirdek matrisin boyutu kadar cekirdekx'i artt�r�r
					for (int cekirdekx = 0; cekirdekx < yapilacakIslem.boyut; cekirdekx++)
					{
						//0'dan �ekirdek matrisin boyutu kadar cekirdeky'yi artt�r�r
						for (int cekirdeky = 0; cekirdeky < yapilacakIslem.boyut; cekirdeky++)
						{
							//��lemler yap�l�yor
							carp = carpma_fonksiyonu(yapilacakIslem.giris[cekirdekx + carpma_fonksiyonu(cikisz,yapilacakIslem.kaydirmaSayisi)][cekirdeky + carpma_fonksiyonu(cikist,yapilacakIslem.kaydirmaSayisi)], 
							yapilacakIslem.cekirdekMatris[cekirdekx][cekirdeky]);
							topla = topla + carp;
						}
					}
					//Sonu� matrisi ekrana yazd�r�l�yor
					yapilacakIslem.sonucMatris[cikisz][cikist] = topla;
					cout << setw(5) << topla;
					topla = 0;
				}
				cout << endl;
			}
		}
	}
	system("pause");
	return 0;
}