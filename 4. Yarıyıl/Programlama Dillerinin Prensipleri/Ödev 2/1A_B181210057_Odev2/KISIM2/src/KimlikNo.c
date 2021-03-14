/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın kimlik kısmının kaynak dosyası
* </p>
*/


#include "KimlikNo.h"

//KimlikNo yapısını oluşturacak fonksiyon yazılıyor.
KimlikNo KimlikNoOlustur(int i)
{
	KimlikNo this;
	//KimlikNo için bellekte gerekli yer ayrılıyor
	this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->r2 = RastgeleOlustur();
	
	this->teklerinToplami = 0;
	this->ciftlerinToplami = 0;
	this->kimlikDegiskeni = i;
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->kimlikNoUret = &_KimlikNoUret;
	this->kimlikNoKontrolEt = &_KimlikNoKontrolEt;
	this->kyoket = &KimlikYokEt;
	
	return this;
}

//Rastgele kimlik numarası üreten fonksiyon yazılıyor
char* _KimlikNoUret(const KimlikNo this)
{
	//Programın çalıştığı andaki zaman hesaplanıyor
	clock_t current_time = time(NULL);
	
	//Hesaplanan zaman bir değişkenle çarpılarak r2'nin kullanacağı sayı değerine atanıyor
	this->r2->sayi = (int)(current_time * (this->kimlikDegiskeni + 9));
	int i;
	//İlk 9 haneyi oluşturacak for döngüsü yazılıyor
	for(i = 0; i < 9; i++)
    {
        this->tcNoTemp[i] = this->r2->rastgeleUret(this->r2,0,9);    
        if(i == 0)
		{
			while(this->tcNoTemp[i] == 0)
            {
                this->tcNoTemp[i] = this->r2->rastgeleUret(this->r2,0,9);   
            } 
        }
    }
	//10. haneyi bulmak için gerekli hesaplamalar yapılıyor	
	int j;		
    for(j = 0; j < 10; j+=2)
    {
        this->teklerinToplami += this->tcNoTemp[j];        
    }
    
	int k;
    for(k = 1; k < 9; k+=2)
    {
        this->ciftlerinToplami += this->tcNoTemp[k];      
    }
        
    this->tcNoTemp[9]  = ((this->teklerinToplami*7) - this->ciftlerinToplami)%10;
    //11. haneyi bulmak için gerekli hesaplamalar yapılıyor
    int tempSayi = 0;
	int l;
    for(l = 0; l < 10; l++)
    {
        tempSayi += this->tcNoTemp[l];
    }
     
    this->tcNoTemp[10] = tempSayi%10;
    
	int m;    
    for(int m = 0; m < 11; m++)
    {
        this->temp[m] = this->tcNoTemp[m] + '0';
    }
	this->temp[11] = '\0';
	//Kimlik numarasına kimlik tempte tutulan veriler char'a çevrilerek atılıyor	
	this->tcNo = &(this->temp[0]);
    return this->tcNo; 	
}

//Kimlik numaralarının doğruluğunu kontrol eden fonksiyon oluşturuluyor
bool _KimlikNoKontrolEt(char* tc)
{
	//Boş bir değer gelirse false döndürüyor
    if (tc == NULL)return false;
	//Kimlik uzunluğu 11'den farklıysa false döndürüyor
    if (strlen(tc) != 11) return false;
    
	int tcNoKontrol[11];
	
	int i;
    for(i=0; i<11; i++) 
    {
        tcNoKontrol[i] = tc[i] - '0';
    }
	//İlk basamak 0 ise false döndürüyor
    if(tcNoKontrol[0] == 0) return false;
	//Son basamak tek sayıysa false döndürüyor
    if(tcNoKontrol[10] % 2 == 1) return false;
	//Sondan bir önceki basamak yanlışsa false döndürüyor
    if((((tcNoKontrol[0] + tcNoKontrol[2] + tcNoKontrol[4] + tcNoKontrol[6] + tcNoKontrol[8]) * 7) - (tcNoKontrol[1] + tcNoKontrol[3] + tcNoKontrol[5] + tcNoKontrol[7])) % 10 != tcNoKontrol[9]) return false;
	//Son basamak yanlışsa false döndürüyor
    if((tcNoKontrol[0] + tcNoKontrol[1] + tcNoKontrol[2] + tcNoKontrol[3] + tcNoKontrol[4] + tcNoKontrol[5] + tcNoKontrol[6] + tcNoKontrol[7] + tcNoKontrol[8] + tcNoKontrol[9]) % 10 != tcNoKontrol[10]) return false;
    
	//Yukarıdakilerden hiçbiri olmadıysa true döndürüyor
    return true;     
} 

//KimlikNo yapısını yok eden metod yazılıyor
void KimlikYokEt(KimlikNo this)
{
	if(this == NULL) return;
	this->r2->yoket(this->r2);
	free(this);	
}


