/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: Ödev 3
**				ÖÐRENCÝ ADI...............: Kadir Çelik
**				ÖÐRENCÝ NUMARASI.: B181210057
**				DERS GRUBU…………: 1C Grubu
****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//Dizide kullanýlacak deðiþkenler belirleniyor
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

//Sonuç matrisini bulmak için kullanýlacak çarpma iþlemi tanýmlanýyor
int carpma_fonksiyonu(int a, int b)
{
	return a * b;
}

int main()
{
	struct Islem yapilacakIslem;

	//Türkçe karakterlerin ekranda gözükmesi için
	setlocale(LC_ALL, "Turkish");

	//Deðiþkenler
	int eleman = (sizeof(yapilacakIslem.giris) / sizeof(int));//Matrisin boyutu belirleniyor
	int maxSatir = sqrt(eleman);//Matriste kullanýlan satýr sayýsý belirleniyor
	int maxSutun = sqrt(eleman);//Matriste kullanýlan sutun sayýsý belirleniyor

	int carp = 0;
	int topla = 0;

	cout << "Çekirdek Matrisin Boyutunu Giriniz: "; cin >> yapilacakIslem.boyut;//Kullanýcýdan çekirdek matrisin boyutu isteniyor
	cout << "\n";
	cout << "Kaydýrma Miktarýný Giriniz: "; cin >> yapilacakIslem.kaydirmaSayisi;//Kullanýcýdan kaydýrma sayýsý isteniyor

	//Eðer kaydýrma sayýsý 0 ise ve çekirdek matrisin boyutu giriþ matrisinin boyutuna büyük eþitse iþlem yapýlmaz
	if (yapilacakIslem.kaydirmaSayisi == 0 || yapilacakIslem.boyut >= maxSatir)
	{
		cout << "Ýþlem Yapýlamaz!!!" << endl;
	}

	//Koþullar saðlanmýyorsa iþlem yapýlýyor
	else
	{
		//Eðer çekirdek matrisi giriþ matrisinde tam olarak kayma iþlemini yapamýyorsa iþlem yapýlmaz
		if ((maxSatir - yapilacakIslem.boyut) % yapilacakIslem.kaydirmaSayisi != 0)
		{
			cout << "Ýslem Yapýlamaz!!!" << endl;
		}

		//Koþullar saðlanmýyorsa iþlem yapýlýyor
		else
		{
			yapilacakIslem.cikisSatir = ((maxSatir - yapilacakIslem.boyut) / yapilacakIslem.kaydirmaSayisi) + 1;//Çýkýþ matrisinin satýr sayýsý hesaplanýyor

			yapilacakIslem.cikisSutun = ((maxSutun - yapilacakIslem.boyut) / yapilacakIslem.kaydirmaSayisi) + 1;//Çýkýþ matrisinin sütun sayýsý hesaplanýyor
			cout << endl;

			cout << "--Çekirdek Matrisi--" << endl;
			//Çekirdek matrisinin satýrlarýný kullanýcý tarafýndan boyuta kadar yazdýrmak için
			for (int cekirdekx = 0; cekirdekx < yapilacakIslem.boyut; cekirdekx++)
			{
				//Çekirdek matrisinin sütunlarýný kullanýcý tarafýndan boyuta kadar yazdýrmak için
				for (int cekirdeky = 0; cekirdeky < yapilacakIslem.boyut; cekirdeky++)
				{
					cout << "Çekirdek[" << cekirdekx << "] [" << cekirdeky << "] Giriniz: "; cin >> yapilacakIslem.cekirdekMatris[cekirdekx][cekirdeky];//Kullanýcýdan matrisin elemanlarý isteniyor
					cout << endl;
				}
			}
			cout << endl;
			cout << "--Sonuç Matrisi--" << endl;
			//0'dan sonuç matrisinin boyutu kadar cikisz'yi arttýrýr
			for (int cikisz = 0; cikisz < yapilacakIslem.cikisSatir; cikisz++)
			{
				//0'dan sonuç matrisinin boyutu kadar cikist'yi arttýrýr
				for (int cikist = 0; cikist < yapilacakIslem.cikisSutun; cikist++)
				{
					//0'dan çekirdek matrisin boyutu kadar cekirdekx'i arttýrýr
					for (int cekirdekx = 0; cekirdekx < yapilacakIslem.boyut; cekirdekx++)
					{
						//0'dan çekirdek matrisin boyutu kadar cekirdeky'yi arttýrýr
						for (int cekirdeky = 0; cekirdeky < yapilacakIslem.boyut; cekirdeky++)
						{
							//Ýþlemler yapýlýyor
							carp = carpma_fonksiyonu(yapilacakIslem.giris[cekirdekx + carpma_fonksiyonu(cikisz,yapilacakIslem.kaydirmaSayisi)][cekirdeky + carpma_fonksiyonu(cikist,yapilacakIslem.kaydirmaSayisi)], 
							yapilacakIslem.cekirdekMatris[cekirdekx][cekirdeky]);
							topla = topla + carp;
						}
					}
					//Sonuç matrisi ekrana yazdýrýlýyor
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