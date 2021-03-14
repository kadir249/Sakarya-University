/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: Ödev 2
**				ÖÐRENCÝ ADI...............: Kadir Çelik
**				ÖÐRENCÝ NUMARASI.: B181210057
**				DERS GRUBU…………: C Grubu
****************************************************************************/

#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

//Deðiþkenler
char harf[5][10];
int harfKontrol = 0;
char yeniHarf;

//Random olarak yeni harf üreten fonksiyon
void yeniHarfUret(int i)
{
	//Çift sayýlý sütunlarda büyük harf oluþturmak için
	if (i % 2 == 0)//Çift sayýlý sütunlarda büyük harf oluþturmak için
	{
		yeniHarf = (rand() % 26) + 65;
	}
	//Tek sayýlý sütunlarda küçük harf oluþturmak için
	else
	{
		yeniHarf = (rand() % 26) + 97;
	}
}

int main()
{
	//Türkçe karakterlerin ekranda gözükmesi için
	setlocale(LC_ALL, "Turkish");
	
	//Çözüm her çalýþtýðýnda farklý deðerler atanmasý için
	srand(time(NULL));
	cout << "Tekrarsiz ve Rastgele Dizi" << "\n";

	//Matris deðerlerini atama iþlemi			
	
	//0'dan 5'e kadar satýr oluþturur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun oluþturur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			//Yeni harf Üretir
			yeniHarfUret(sutun);

			while (harfKontrol == 1)
			{
				harfKontrol = 0;
				//0'dan 5'e kadar satýr oluþturur.
				for (int satirX = 0; satirX < 5; satirX++)
				{
					//0'dan 10'a kadar sutun oluþturur.
					for (int sutunY = 0; sutunY < 10; sutunY++)
					{
						if (harf[satirX][sutunY] == yeniHarf)
						{
							//Dizide üretilen harf var ise tekrardan harf üretilir. 
							yeniHarfUret(sutun);
							//While döngüsünün tekrar etmesi için
							harfKontrol = +1;
						}
					}
				}
			}
			//Dizinin içinde böyle harf yok ise dize bu harfi atýyoruz.
			if (harfKontrol == 0)
			{
				harf[satir][sutun] = yeniHarf;
				//Yeni harf Üretiyoruz
				yeniHarfUret(sutun);
				//While döngüsüne girebilmesi için ve yeni harf üretebilmek için
				harfKontrol = +1;
			}
		}
	}

	//Oluþturulan diziyi yazdýrýyoruz.
	
	//0'dan 5'e kadar satýr oluþturur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun oluþturur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			cout << setw(5) << harf[satir][sutun];
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "Sýralý ve Tekrarsýz Dizi" << "\n";
	
	//Dizideki harfleri ASCII kodlarýna göre sýralýyoruz
	
	//0'dan 5'e kadar satýr oluþturur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun oluþturur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			//0'dan 5'e kadar satýr oluþturur.
			for (int satirX = 0; satirX < 5; satirX++)
			{
				//0'dan 10'a kadar sutun oluþturur.
				for (int sutunY = 0; sutunY < 10; sutunY++)
				{
					//Matristeki harfleri ASCII kodlarýna göre karþýlaþtýrarak küçükten büyüðe doðru yazmak için
					if (harf[satir][sutun] < harf[satirX][sutunY])
					{
						char gecici = harf[satir][sutun];
						harf[satir][sutun] = harf[satirX][sutunY];
						harf[satirX][sutunY] = gecici;
					}
				}
			}
		}
	}

	//Düzenlenen diziyi yazdýrýyoruz.
	
	//0'dan 5'e kadar satýr oluþturur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun oluþturur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			cout << setw(5) << harf[satir][sutun];
		}
		cout << "\n";
	}
	cout << "\n";
	system("pause");
	return 0;
}