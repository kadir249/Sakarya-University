/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın imei kısmının kaynak dosyası
* </p>
*/


#include "IMEINo.h"

//ImeiNo yapısını oluşturacak fonksiyon yazılıyor.
ImeiNo ImeiNoOlustur()
{
	ImeiNo this;
	//ImeiNo için bellekte gerekli yer ayrılıyor
	this = (ImeiNo)malloc(sizeof(struct IMEINO));
	this->r1 = RastgeleOlustur();
	
	//Fonksiyonlara ilgili göstericiler atanıyor
	this->imeiNoUret = &_ImeiNoUret;
	this->basamaklarinToplami = &_BasamaklarinToplami;
	this->imeiNoKontrolEt = &_ImeiNoKontrolEt;
	this->yoket = &ImeiYokEt;
	
	return this;
}

//Rastgele IMEI numarası üreten fonksiyon yazılıyor
char* _ImeiNoUret(const ImeiNo this, int imeiDegiskeni)
{
	//Programın çalıştığı andaki zaman hesaplanıyor
	clock_t current_time = time(NULL);
	
	//Hesaplanan zaman bir değişkenle çarpılarak r1'in kullanacağı sayı değerine atanıyor
	this->r1->sayi = (int)(current_time * imeiDegiskeni);
	
	int toplam = 0;
        
	int i;
	
	//İlk 14 haneyi üreten for döngüsü açılıyor	
    for(i = 0; i < 14; i++)
    {
        this->imeiNoTemp[i] = this->r1->rastgeleUret(this->r1,0,9);
    }
		
	int j;
	
	//Son haneyi bulmak için kullanılan for döngüsü açılıyor
    for(j = 0;j<14;j++)
    {              
        int basamak = this->imeiNoTemp[j];
            
        if(j%2==0)
        {
            toplam = toplam + basamak;
        }
        else
        {
			toplam = toplam + this->basamaklarinToplami(basamak*2);
        }
    }
        
    toplam = toplam * 9;
    
	//Son hane bulunuyor ve IMEI numarası tutan tempe atanıyor
    this->imeiNoTemp[14] =toplam %10;
	
	int k;
		
    for(k = 0; k < 15; k++)
    {
		this->temp[k] = this->imeiNoTemp[k]+'0';        		   
    }
	this->temp[15] = '\0';
	//IMEI numarasına IMEI tempte tutulan veriler char'a çevrilerek atılıyor	
	this->imeiNo = &(this->temp[0]);
		 
    return this->imeiNo;
}

//Rastgele IMEI numarası üretilirken her bir basamağın basamak değerini hesaplayan fonksiyon oluşturuluyor
int _BasamaklarinToplami(int sayi)
{
    int basamakToplami = 0;
	//Eğer sayı iki basamaklıysa basamaklarını parçalıyor
    while(sayi > 0) 
    {
        basamakToplami += sayi % 10;
        sayi = sayi/10;
    }
    return basamakToplami;
}

//IMEI numaralarının doğruluğunu kontrol eden fonksiyon oluşturuluyor
bool _ImeiNoKontrolEt(char* imei)
{
	//Boş bir değer gelirse false döndürüyor
    if (imei == NULL)return false;
	
	//IMEI uzunluğu 15'ten farklıysa false döndürüyor
    if (strlen(imei) != 15) return false;
        	
    char kontrolEdilenHarf = imei[14];
    
    int kontrolEdilenRakam;
        
    kontrolEdilenRakam = kontrolEdilenHarf - '0';

    int toplam = 0;
        
	int i;
	//Son basamağı kontrol eden döngü yazılıyor
    for(i =0;i<14;i++)
    {
        char sBasamak = imei[i];			
        int basamak = sBasamak -  '0';
      
        if(i%2==0) 
        {
            toplam = toplam + basamak;
        }
        else 
        {
            toplam = toplam + _BasamaklarinToplami(basamak * 2);
        }
    }
    toplam = toplam * 9;
	//Dor döngüsüyle bulunan değer gönderilen IMEI numarasının son hanesinden farklıysa false döndürüyor
    if(kontrolEdilenRakam != toplam %10)  return  false;
    
	//Yukarıdakilerden hiçbiri olmadıysa true döndürüyor
    return true;	
}

//IMEINo yapısını yok eden metod yazılıyor
void ImeiYokEt(ImeiNo this)
{
	if(this == NULL) return;
	this->r1->yoket(this->r1);
	free(this);
}