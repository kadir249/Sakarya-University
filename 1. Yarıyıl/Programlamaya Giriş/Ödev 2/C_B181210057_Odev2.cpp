/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: �dev 2
**				��RENC� ADI...............: Kadir �elik
**				��RENC� NUMARASI.: B181210057
**				DERS GRUBU����: C Grubu
****************************************************************************/

#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

//De�i�kenler
char harf[5][10];
int harfKontrol = 0;
char yeniHarf;

//Random olarak yeni harf �reten fonksiyon
void yeniHarfUret(int i)
{
	//�ift say�l� s�tunlarda b�y�k harf olu�turmak i�in
	if (i % 2 == 0)//�ift say�l� s�tunlarda b�y�k harf olu�turmak i�in
	{
		yeniHarf = (rand() % 26) + 65;
	}
	//Tek say�l� s�tunlarda k���k harf olu�turmak i�in
	else
	{
		yeniHarf = (rand() % 26) + 97;
	}
}

int main()
{
	//T�rk�e karakterlerin ekranda g�z�kmesi i�in
	setlocale(LC_ALL, "Turkish");
	
	//��z�m her �al��t���nda farkl� de�erler atanmas� i�in
	srand(time(NULL));
	cout << "Tekrarsiz ve Rastgele Dizi" << "\n";

	//Matris de�erlerini atama i�lemi			
	
	//0'dan 5'e kadar sat�r olu�turur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun olu�turur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			//Yeni harf �retir
			yeniHarfUret(sutun);

			while (harfKontrol == 1)
			{
				harfKontrol = 0;
				//0'dan 5'e kadar sat�r olu�turur.
				for (int satirX = 0; satirX < 5; satirX++)
				{
					//0'dan 10'a kadar sutun olu�turur.
					for (int sutunY = 0; sutunY < 10; sutunY++)
					{
						if (harf[satirX][sutunY] == yeniHarf)
						{
							//Dizide �retilen harf var ise tekrardan harf �retilir. 
							yeniHarfUret(sutun);
							//While d�ng�s�n�n tekrar etmesi i�in
							harfKontrol = +1;
						}
					}
				}
			}
			//Dizinin i�inde b�yle harf yok ise dize bu harfi at�yoruz.
			if (harfKontrol == 0)
			{
				harf[satir][sutun] = yeniHarf;
				//Yeni harf �retiyoruz
				yeniHarfUret(sutun);
				//While d�ng�s�ne girebilmesi i�in ve yeni harf �retebilmek i�in
				harfKontrol = +1;
			}
		}
	}

	//Olu�turulan diziyi yazd�r�yoruz.
	
	//0'dan 5'e kadar sat�r olu�turur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun olu�turur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			cout << setw(5) << harf[satir][sutun];
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "S�ral� ve Tekrars�z Dizi" << "\n";
	
	//Dizideki harfleri ASCII kodlar�na g�re s�ral�yoruz
	
	//0'dan 5'e kadar sat�r olu�turur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun olu�turur.
		for (int sutun = 0; sutun < 10; sutun++)
		{
			//0'dan 5'e kadar sat�r olu�turur.
			for (int satirX = 0; satirX < 5; satirX++)
			{
				//0'dan 10'a kadar sutun olu�turur.
				for (int sutunY = 0; sutunY < 10; sutunY++)
				{
					//Matristeki harfleri ASCII kodlar�na g�re kar��la�t�rarak k���kten b�y��e do�ru yazmak i�in
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

	//D�zenlenen diziyi yazd�r�yoruz.
	
	//0'dan 5'e kadar sat�r olu�turur.
	for (int satir = 0; satir < 5; satir++)
	{
		//0'dan 10'a kadar sutun olu�turur.
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