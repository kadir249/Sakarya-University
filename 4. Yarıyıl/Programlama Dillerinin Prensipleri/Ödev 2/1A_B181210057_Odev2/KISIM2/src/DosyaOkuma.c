/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın dosya okuma kaynak dosyası
* </p>
*/


#include "DosyaOkuma.h"

//Dosya yapısını oluşturacak fonksiyon yazılıyor.
Dosya DosyaOlustur(char* yol)
{
	Dosya this;
	//Dosya için bellekte gerekli yer ayrılıyor
	this = (Dosya)malloc(sizeof(struct DOSYA));
    this->dosyaAdi = yol;
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->oku = &verileriAl;
	this->yoket = &DosyaYoket;
	
	//Okunan dosyanın satır sayısı hesaplanıyor
	FILE *okunacakDosya = fopen(yol,"r");
	int satirSayaci = 0;

    if (okunacakDosya == NULL) 
	{
        printf("%s\n", "Dosya bulunamadi");
		exit(1);
    }
	
    else 
	{
        char ch;
        while(!feof( okunacakDosya ))
        {
			ch = fgetc(okunacakDosya);
	
			if (ch == '\n')
			{		
				satirSayaci++;	
			}
			
        };
	}
	rewind(okunacakDosya);
	fclose(okunacakDosya);
	this->sayac = satirSayaci;
	
	return this;

}

//Dosyadaki verileri alan fonksiyon yazılıyor
char** verileriAl (const Dosya this)
{
	//Gerekli dosya okunuyor ve dosyanın boyutunda iki boyutlu veri dizisi oluşturuluyor
	FILE *isimDosyasi = fopen(this->dosyaAdi,"r");
	char veri [this->sayac + 1][125];	
	
	//İstenilen veriyi almak için gerekli işlemler yapılıyor
	int i = 0;
	while(!feof( isimDosyasi )) 
	{		   
	    fgets(veri[i],sizeof(veri[i]), isimDosyasi);
		i++;			
	};
	int m = 0;
	char* tutucu1[this->sayac + 1];
	tutucu1[0] = malloc(sizeof(char*));
	
	for(m=0; m <= this->sayac; m++)
	{
	      tutucu1[m] = 	(char*)&veri[m] + '\0';
	}
	
	char* tutucu2 = (char*)&tutucu1[0];
	free(veri);
	free(tutucu1);
	fclose(isimDosyasi);
	return (char**)tutucu2;
}

//Dosya yapısını yok eden metod yazılıyor
void DosyaYoket(Dosya this)
{
	if(this == NULL) return;
	free(this);
}