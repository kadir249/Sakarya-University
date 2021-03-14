/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: �dev 4
**				��RENC� ADI...............: Kadir �elik
**				��RENC� NUMARASI.: B181210057
**				DERS GRUBU����: 1C Grubu
****************************************************************************/

//strcopyde hata verdi�i i�in projenin �zellikleri penceresindeki c/c++ i�indeki �ni�lemci k�sm�na "_CRT_SECURE_NO_WARNINGS" yazd�m.

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

#define limit 500 //Limit ad�nda 500 de�erinde bir sabit olu�turur

char metin[limit];//metin adl� dizinin uzunlu�u belirtilir
char sifre[limit];//sifre adl� dizinin uzunlu�u belirtilir
int alfabeBoyutu;
int bul(char alfabe[], char arananHarf)//Harflerin alfabedeki konumlar�n� bulur
{
	int i, sayac = -1;

	for (i = 0; i < alfabeBoyutu; i++)//i'yi alfabe boyutu kadar artt�r�r
	{
		if (arananHarf == alfabe[i])//Arad���m�z harfi alfabede bulur
			sayac = i;//sayaca i'yi atar
	}
	return sayac;//sayac� geri d�nd�r�r
}

//�ifre ad�nda bir class tan�mlan�yor
class Sifre
{
public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char* sifrele(char*);
	char* sifreCoz(char*);
	void sifreKelimesiAta(char*);

private:
	char* alfabe;
	char* sifreKelimesi;
};

Sifre::Sifre(char *alfabe, char *sifre)
{
	this->alfabe = alfabe;//private alfabe de�i�keni fonksiyondaki alfabe de�i�kenine ula��r
	this->sifreKelimesi = sifre;//private sifreKelimesi de�i�keni fonksiyondaki sifre de�i�kenine ula��r
}

Sifre::Sifre()
{
	const char* alfabe1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//alfabe1 adl� bir dizi olu�turuluyor
	const char* sifre1 = "BSM";//sifre1 adl� bir dizi olu�turuluyor
	this->alfabe = strcpy(alfabe, alfabe1);//alfabe1 de�i�keni alfabeye kopyalan�yor
	this->sifreKelimesi = strcpy(sifreKelimesi,sifre1);//sifre1 de�i�keni sifreKelimesine kopyalan�yor
}

char* Sifre::sifrele(char*)
{
	//De�i�kenler tan�mlan�yor
	int i, j = 0, metinHarfSirasi, sifreHarfSirasi;
	int metinBoyut = strlen(metin);//Metnin boyutu bir de�i�kene atan�yor
	int sifreBoyut = strlen(sifre);//�ifrenin boyutu bir de�i�kene atan�yor

	for (i = 0; i < metinBoyut; i++, j++)//D�ng�y� metin boyutu kadar d�nd�r�r
	{
		if (j >= sifreBoyut)//j metin boyutuna b�y�k e�it oldu�unda j'yi s�f�rlar
		{
			j = 0;
		}
		metinHarfSirasi = bul(alfabe, metin[i]);//bul fonksiyonundan d�nen de�eri metinHarfSirasina atar
		sifreHarfSirasi = bul(alfabe, sifre[j]);//bul fonksiyonundan d�nen de�eri sifreHarfSirasina atar

		if (metinHarfSirasi != -1 && sifreHarfSirasi != -1)//bul fonksiyonundan d�nen de�erler -1'den farkl�ysa �al���r
		{
			//metinHarfSirasi ve sifreHarfSirasin� toplay�p alfabeBoyutu kadar modunu al�r ve metinHarfsirasi de�i�kenine atar
			metinHarfSirasi = (metinHarfSirasi + sifreHarfSirasi) % alfabeBoyutu;
			metin[i] = alfabe[metinHarfSirasi];//metin dizisinin i. indisine alfabe dizisinin metinHarfSirasina e�it olan indisini atar
		}
	}
	return 0;
}

char* Sifre::sifreCoz(char*)
{
	//De�i�kenler tan�mlan�yor
	int i, j = 0, metinHarfSirasi, sifreHarfSirasi;
	int metinBoyut = strlen(metin);//Metnin boyutu bir de�i�kene atan�yor
	int sifreBoyut = strlen(sifre);//�ifrenin boyutu bir de�i�kene atan�yor

	for (i = 0; i < metinBoyut; i++, j++)//D�ng�y� metin boyutu kadar d�nd�r�r
	{
		if (j >= sifreBoyut)//j metin boyutuna b�y�k e�it oldu�unda j'yi s�f�rlar
		{
			j = 0;
		}

		metinHarfSirasi = bul(alfabe, metin[i]);//bul fonksiyonundan d�nen de�eri metinHarfSirasina atar
		sifreHarfSirasi = bul(alfabe, sifre[j]);//bul fonksiyonundan d�nen de�eri sifreHarfSirasina atar

		if (metinHarfSirasi != -1 && sifreHarfSirasi != -1)//bul fonksiyonundan d�nen de�erler -1'den farkl�ysa �al���r
		{
			//metinHarfSirasi ve sifreHarfSirasin�n fark�n� al�p alfabeBoyutu kadar modunu al�r ve metinHarfsirasi de�i�kenine atar
			metinHarfSirasi = (metinHarfSirasi - sifreHarfSirasi) % alfabeBoyutu;

			if (metinHarfSirasi < 0)//metinHarfSirasi s�f�rdan k���kse �al���r
			{
				metinHarfSirasi += alfabeBoyutu;//metinHarfSirasi de�i�keninin de�erine alfabeBoyutu de�i�keninin de�erini ekler
			}
			metin[i] = alfabe[metinHarfSirasi];//metin dizisinin i. indisine alfabe dizisinin metinHarfSirasina e�it olan indisini atar
		}
	}
	return 0;
}

void Sifre::sifreKelimesiAta(char* kelime)
{
	this->sifreKelimesi = kelime;//private sifrekelimesi fonksiyondaki kelimeye ula��r
}

int main()
{
	char alfabe[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//alfabe adl� bir karakter dizisi olu�turuluyor
	char sifre[] = "SAU";//sifre adl� bir karakter dizisi olu�turuluyor

	alfabeBoyutu = strlen(alfabe);//alfabe dizisinin boyutu hesaplan�r

	//Kullan�c�dan bilgilein girmesi isteniyor
	cout << "ALFABE           :"; cin >> alfabe;
	cout << "SIFRE            :"; cin >> sifre;
	cout << "METIN            :"; cin >> metin;

	//�ifrelenmi� metin ekrana yazd�r�l�yor
	Sifre sifrele(alfabe, sifre);
	cout << "SIFRELENMIS METIN:" << metin;
	cout << endl;

	//De�ifre metin ekrana yazd�r�l�yor
	Sifre sifreCoz(alfabe, sifre);
	cout << "DESIFRE METIN    :" << metin;
	cout << endl;


	system("pause");
	return 0;
}