/**
* @file b181210057_1A_Odev2
* @description Bir text dosyasýna atýlan verilerin okunmasý ve tekrar eden verilerin ekrana yazdýrýlmayarak elde edilen kazancýn hesaplanmasý.
* @course 1. Öðretim A Grubu
* @assignment 2. Ödev
* @date 27.11.2019
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr, Duhan Uzun duhan.uzun@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Dugum.h"
#include "CiftYonluBagliListe.h"

CiftYonluBagliListe::CiftYonluBagliListe()
{
	boyut = 0;
	bas = NULL;
	kuyruk = NULL;
}

void CiftYonluBagliListe::elemanEkleme(string& veri)
{
	Dugum *yeni = new Dugum(veri);

	if (bas == NULL)
	{
		bas = yeni;
		kuyruk = yeni;
	}
	
	else
	{
		kuyruk->sonraki = yeni;
		yeni->onceki = kuyruk;
		kuyruk = yeni;
	}
	
	Dugum *temp1 = bas;
	Dugum *temp2;

	while (temp1->sonraki != NULL)
	{
		temp2 = temp1->sonraki;
		while(temp2 != NULL)
		{
			if (temp2->veri == temp1->veri)
			{
				if (temp2->veri != "")
				{
					kazanc =kazanc + (temp2->veri).length();
					temp2->veri = "";
					temp2->sayi = i;
									
					if (i < 10)
					{
						basamakSayisi = 1;
					}
					else
					{
						do
						{
							i = i / 10;
							basamakSayisi++;	
						}while (i >= 10);
					}  
					
					kazanc = kazanc - basamakSayisi;
				}
			}
			temp2 = temp2->sonraki;
			i++;
		}
		temp1 = temp1->sonraki;
		i = 1;
	}
}

void CiftYonluBagliListe::yazdir()
{
	Dugum *iter = bas;
	while (iter != NULL)
	{
		if (iter == bas)
		{
			cout << "NULL<-:";
			cout << iter->veri << " - " << iter->sayi << ":<->:";
			iter = iter->sonraki;
		}

		cout << iter->veri << " - " << iter->sayi << ":<->:";
		iter = iter->sonraki;

		if (iter->sonraki == NULL)
		{
			cout << iter->veri << " - " << iter->sayi << ":->NULL";
			iter = iter->sonraki;
		}
	}
	cout << endl << "Toplam Kazanc: " << kazanc << " Byte";
}