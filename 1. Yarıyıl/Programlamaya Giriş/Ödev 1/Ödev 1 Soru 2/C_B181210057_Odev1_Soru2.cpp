/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: Ödev 1
**				ÖÐRENCÝ ADI...............: Kadir Çelik
**				ÖÐRENCÝ NUMARASI.: B181210057
**				DERS GRUBU…………: C Grubu
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
		//Cümledeki sesli harflerin sayýsýnýn bulunmasý için
	{
		//Cümledeki a sayýsýnýn bulunmasý için
		if (cumle[i] == 'a' || cumle[i] == 'A')//"A,a" ise a adedini arttýr
		{
			aAdedi += 1;
		}

		//Cümledeki e sayýsýnýn bulunmasý için//"E,e" ise e adedini arttýr
		else if (cumle[i] == 'e' || cumle[i] == 'E')
		{
			eAdedi += 1;
		}

		//Cümledeki i sayýsýnýn bulunmasý için//"I,i" ise i adedini arttýr
		else if (cumle[i] == 'i' || cumle[i] == 'I')
		{
			iAdedi += 1;
		}

		//Cümledeki o sayýsýnýn bulunmasý için
		else if (cumle[i] == 'o' || cumle[i] == 'O')//"O,o" ise o adedini arttýr
		{
			oAdedi += 1;
		}

		//Cümledeki u sayýsýnýn bulunmasý için
		else if (cumle[i] == 'u' || cumle[i] == 'U')//"U,u" ise u adedini arttýr
		{
			uAdedi += 1;
		}
	}

	//Cümlede en fazla bulunan harfi bulmak için bir dizi oluþturuluyor	
	int enbuyuksayi = 0;

	int sayilar[5];

	sayilar[0] = aAdedi;
	sayilar[1] = eAdedi;
	sayilar[2] = iAdedi;
	sayilar[3] = oAdedi;
	sayilar[4] = uAdedi;

	int gecici = 0;

	cout << "\n";

	//En fazla kullanýlan harf kadar tablonun uzatýlmasý için kabarcýk seçimi yöntemi uygulanýyor
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

	//Tablo oluþturuluyor
	cout << "H" << setw(6) << "TS" << setw(5);

	for (int sayac = 1; sayac < enbuyuksayi + 1; sayac++)
	{
		cout << sayac << setw(5);
	}

	cout << "\n";

	//Cümlede geçen a sayýsý kadar "a" harfinin tabloda yazýlmasý için "if" bloðu açýlýyor
	if (aAdedi >= 0)//aAdedi >= 0 ise ekrana a'nýn tekrar sayýsý kadar a yaz
	{
		cout << "a" << setw(6) << aAdedi << setw(5);
		for (int sayac = 0; sayac < aAdedi; sayac++)
		{
			cout << "a" << setw(5);
		}
	}
	cout << "\n";

	//Cümlede geçen e sayýsý kadar "e" harfinin tabloda yazýlmasý için "if" bloðu açýlýyor
	if (eAdedi >= 0)//eAdedi >= 0 ise ekrana e'nin tekrar sayýsý kadar e yaz
	{
		cout << "e" << setw(6) << eAdedi << setw(5);
		for (int sayac = 0; sayac < eAdedi; sayac++)
		{
			cout << "e" << setw(5);
		}
	}
	cout << "\n";

	//Cümlede geçen i sayýsý kadar "i" harfinin tabloda yazýlmasý için "if" bloðu açýlýyor
	if (iAdedi >= 0)//iAdedi >= 0 ise ekrana i'nin tekrar sayýsý kadar i yaz
	{
		cout << "i" << setw(6) << iAdedi << setw(5);
		for (int sayac = 0; sayac < iAdedi; sayac++)
		{
			cout << "i" << setw(5);
		}
	}
	cout << "\n";

	//Cümlede geçen o sayýsý kadar "o" harfinin tabloda yazýlmasý için "if" bloðu açýlýyor
	if (oAdedi >= 0)//oAdedi >= 0 ise ekrana o'nun tekrar sayýsý kadar o yaz
	{
		cout << "o" << setw(6) << oAdedi << setw(5);
		for (int sayac = 0; sayac < oAdedi; sayac++)
		{
			cout << "o" << setw(5);
		}
	}
	cout << "\n";

	//Cümlede geçen u sayýsý kadar "u" harfinin tabloda yazýlmasý için "if" bloðu açýlýyor
	if (uAdedi >= 0)//uAdedi >= 0 ise ekrana u'nun tekrar sayýsý kadar u yaz
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