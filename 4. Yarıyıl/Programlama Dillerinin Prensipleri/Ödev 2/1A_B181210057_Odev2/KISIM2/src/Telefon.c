/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın telefon kısmının kaynak dosyası
* </p>
*/


#include "Telefon.h"

//Telefon yapısını oluşturacak fonksiyon yazılıyor.
Telefon TelefonNoOlustur(int i)
{	
	Telefon this;
	//Telefon için bellekte gerekli yer ayrılıyor
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->r3 = RastgeleOlustur();
	this->oImeiNo = ImeiNoOlustur();
	
	this->telefonDegiskeni = i;
	this->oImeiNo->imeiNoUret(this->oImeiNo, i);
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->telefonNoUret = &_telefonNoUret;
	this->yoket = &telefonYoket;
	return this;
}

//Rastgele telefon numarası üreten fonksiyon yazılıyor
char* _telefonNoUret(const Telefon this)
{
	this->telefonNoTemp[0] = 0;
    this->telefonNoTemp[1] = 5;
	//Programın çalıştığı andaki zaman hesaplanıyor
	clock_t current_time = time(NULL);
	
	//Hesaplanan zaman bir değişkenle çarpılarak r3'ün kullanacağı sayı değerine atanıyor
	this->r3->sayi = (int)(current_time * (this->telefonDegiskeni + 5));
	int i;
	
	//Türkiye'de kullanılan telefon numaralarına göre rastgele telefon numaraları oluşturuluyor.
    for(i = 2; i < 11; i++)
    {
        this->telefonNoTemp[i] = this->r3->rastgeleUret(this->r3,0,9);
			
        if(i == 2)
        {
            while(this->telefonNoTemp[i] == 1 || this->telefonNoTemp[i] == 2 || this->telefonNoTemp[i] == 7 || this->telefonNoTemp[i] == 8 || this->telefonNoTemp[i] == 9)
            {
				this->telefonNoTemp[i] = this->r3->rastgeleUret(this->r3,0,9);
            }
        }
        if(i == 3)
        {
            if(this->telefonNoTemp[2] == 0)
            {
                while(this->telefonNoTemp[i] == 0 || this->telefonNoTemp[i] == 2 || this->telefonNoTemp[i] == 3 || this->telefonNoTemp[i] == 4 || this->telefonNoTemp[i] == 8 || this->telefonNoTemp[i] == 9)
                {
                   this->telefonNoTemp[i] = this->r3->rastgeleUret(this->r3,0,9);
                } 
            }
                
            else if(this->telefonNoTemp[2] == 5)
            {
                while(this->telefonNoTemp[i] == 0 || this->telefonNoTemp[i] == 6 || this->telefonNoTemp[i] == 7 || this->telefonNoTemp[i] == 8)
                {
                    this->telefonNoTemp[i] = this->r3->rastgeleUret(this->r3,0,9);
                } 
            }  

            else if(this->telefonNoTemp[2] == 6)
            {
                this->telefonNoTemp[i] = 1;
            }
            else
            {
                this->telefonNoTemp[i] = this->r3->rastgeleUret(this->r3,0,9);
            }
        }
    }
		
    int j;
	//Telefon numarasına telefon tempte tutulan veriler char'a çevrilerek atılıyor	
    for(j = 0; j < 11; j++)
    {
		this->telefonNo[j] = this->telefonNoTemp[j]+'0';     		   
    }
    this->telefonNo[11] = '\0';
		
    return this->telefonNo;
}

//Telefon yapısını yok eden metod yazılıyor
void telefonYoket(Telefon this)
{	
	if(this == NULL) return;
	this->r3->yoket(this->r3);
	this->oImeiNo->yoket(this->oImeiNo);
	free(this);
}