/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: �dev 1
**				��RENC� ADI...............: Kadir �elik
**				��RENC� NUMARASI.: B181210057
**				DERS GRUBU����: C Grubu
****************************************************************************/

#include <iostream>
#include <locale.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string cumle = " ";
	cout << "Cumle Giriniz: ";
	getline(cin, cumle);
	int aAdedi = 0, eAdedi = 0, iAdedi = 0, oAdedi = 0, uAdedi = 0;

	for (int i = 0; i < cumle.length(); i++)
		//C�mledeki sesli harflerin say�s�n�n bulunmas� i�in
	{
		//C�mledeki a say�s�n�n bulunmas� i�in
		if (cumle[i] == 'a' || cumle[i] == 'A')//"A,a" ise a adedini artt�r
		{
			aAdedi += 1;
		}

		//C�mledeki e say�s�n�n bulunmas� i�in//"E,e" ise e adedini artt�r
		else if (cumle[i] == 'e' || cumle[i] == 'E')
		{
			eAdedi += 1;
		}

		//C�mledeki i say�s�n�n bulunmas� i�in//"I,i" ise i adedini artt�r
		else if (cumle[i] == 'i' || cumle[i] == 'I')
		{
			iAdedi += 1;
		}

		//C�mledeki o say�s�n�n bulunmas� i�in
		else if (cumle[i] == 'o' || cumle[i] == 'O')//"O,o" ise o adedini artt�r
		{
			oAdedi += 1;
		}

		//C�mledeki u say�s�n�n bulunmas� i�in
		else if (cumle[i] == 'u' || cumle[i] == 'U')//"U,u" ise u adedini artt�r
		{
			uAdedi += 1;
		}
	}

	//C�mlede en fazla bulunan harfi bulmak i�in bir dizi olu�turuluyor	
	int enbuyuksayi = 0;

	int sayilar[5];

	sayilar[0] = aAdedi;
	sayilar[1] = eAdedi;
	sayilar[2] = iAdedi;
	sayilar[3] = oAdedi;
	sayilar[4] = uAdedi;

	int gecici = 0;

	cout << "\n";

	//En fazla kullan�lan harf kadar tablonun uzat�lmas� i�in kabarc�k se�imi y�ntemi uygulan�yor
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1; j++)
		{
			if (sayilar[j] > sayilar[j + 1])
			{
				gecici = sayilar[j];
				sayilar[j] = sayilar[j + 1];
				sayilar[j + 1] = gecici;
			}
		}
	}

	enbuyuksayi = sayilar[4];

	//Tablo olu�turuluyor
	cout << "H" << setw(6) << "TS" << setw(5);

	for (int sayac = 1; sayac < enbuyuksayi + 1; sayac++)
	{
		cout << sayac << setw(5);
	}

	cout << "\n";

	//C�mlede ge�en a say�s� kadar "a" harfinin tabloda yaz�lmas� i�in "if" blo�u a��l�yor
	if (aAdedi >= 0)//aAdedi >= 0 ise ekrana a'n�n tekrar say�s� kadar a yaz
	{
		cout << "a" << setw(6) << aAdedi << setw(5);
		for (int sayac = 0; sayac < aAdedi; sayac++)
		{
			cout << "a" << setw(5);
		}
	}
	cout << "\n";

	//C�mlede ge�en e say�s� kadar "e" harfinin tabloda yaz�lmas� i�in "if" blo�u a��l�yor
	if (eAdedi >= 0)//eAdedi >= 0 ise ekrana e'nin tekrar say�s� kadar e yaz
	{
		cout << "e" << setw(6) << eAdedi << setw(5);
		for (int sayac = 0; sayac < eAdedi; sayac++)
		{
			cout << "e" << setw(5);
		}
	}
	cout << "\n";

	//C�mlede ge�en i say�s� kadar "i" harfinin tabloda yaz�lmas� i�in "if" blo�u a��l�yor
	if (iAdedi >= 0)//iAdedi >= 0 ise ekrana i'nin tekrar say�s� kadar i yaz
	{
		cout << "i" << setw(6) << iAdedi << setw(5);
		for (int sayac = 0; sayac < iAdedi; sayac++)
		{
			cout << "i" << setw(5);
		}
	}
	cout << "\n";

	//C�mlede ge�en o say�s� kadar "o" harfinin tabloda yaz�lmas� i�in "if" blo�u a��l�yor
	if (oAdedi >= 0)//oAdedi >= 0 ise ekrana o'nun tekrar say�s� kadar o yaz
	{
		cout << "o" << setw(6) << oAdedi << setw(5);
		for (int sayac = 0; sayac < oAdedi; sayac++)
		{
			cout << "o" << setw(5);
		}
	}
	cout << "\n";

	//C�mlede ge�en u say�s� kadar "u" harfinin tabloda yaz�lmas� i�in "if" blo�u a��l�yor
	if (uAdedi >= 0)//uAdedi >= 0 ise ekrana u'nun tekrar say�s� kadar u yaz
	{
		cout << "u" << setw(6) << uAdedi << setw(5);
		for (int sayac = 0; sayac < uAdedi; sayac++)
		{
			cout << "u" << setw(5);
		}
	}
	cout << "\n" << "\n";

	system("pause");
	return 0;
}