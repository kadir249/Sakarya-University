/*
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden programın test kısmı
* </p>
*/

//Gerekli kütüphaneler ekleniyor
#include "RastgeleKisi.h"

int main()
{
	//Kullanıcı çıkış seçeneğini tuşlayıncaya kadar çalışan do-while döngüsü yazılıyor
	int cikis = 0;
    do
    {  
        printf("%s\n","1- Rastgele Kisi Uret");
        printf("%s\n","2- Uretilmis Dosya Kontrol Et");
        printf("%s\n","3- Cikis");
		
		//Kullanıcının seçtiği seçenek alınıyor
        int islem;
        scanf("%d", &islem);
		
		//Gerekli değişkenler tanımlanıyor
        char*  tcNo1;
        char*  telefonNo1;
        char*  imeiNo1;
        char*  imeiNoTemp1;

        char*  tcNo2;
        char*  imeiNo2;
        char*  imeiNoTemp2;
		
		//İlgili işlemleri yapan switch-case oluşturuluyor
        switch(islem)
        {
            case 1:
			//Kullanıcıdan kaç adet kişi üretmek istediği alınıyor
            printf("%s\n","Kac adet kisi ureteceksiniz?");              
            int kisiSayisi;
			scanf("%d", &kisiSayisi);
			
			//Oluşturulan kişilerin yazılacağı dosya açılıyor
			FILE * yazilacakDosya;

			yazilacakDosya = fopen ("Kisiler.txt","w");
				 
			int i;
			//Kişi sayısı kadar rastgele kişi oluşturuluyor ve dosyaya yazılıyor
            for(i = 0; i < kisiSayisi; i++)
            {
                RastgeleKisi rk = RastgeleKisiOlustur(i + 1);
				fprintf(yazilacakDosya,"%s %s %s %d %s %s%s%s",rk->kisi->kimlikNo->tcNo, rk->kisi->isim, rk->kisi->soyisim, rk->kisi->yas, rk->kisi->telefon->telefonNo ,"(",rk->kisi->telefon->oImeiNo->imeiNo,")");
				fprintf(yazilacakDosya,"\n");
				rk->yoket(rk);
            }
            printf("%s\n","Kisiler olusturuldu.");
            fclose(yazilacakDosya);  
            break;

			case 2:;
			//Dosyadaki TC ve IMEIleri kontrol etmek için gerekli değişkenler tanımlanıyor
            RastgeleKisi rk2 = RastgeleKisiOlustur();
			RastgeleKisi rk3 = RastgeleKisiOlustur(); 			
            Dosya dosya2 = DosyaOlustur("Kisiler.txt");
			Dosya dosya3 = DosyaOlustur("Kisiler.txt");
			
            printf("%s","T.C. Kimlik Kontrol\n");
			int k;
			int gecerliTcSayisi = 0;
			int gecersizTcSayisi = 0;
			//Geçerli ve geçersiz TC kimlik numaralarının sayısını bulan kısım yazılıyor
            for(k = 0; k < dosya2->sayac; k++)
            {        
                char* veriler1 = dosya2->oku(dosya2)[k];           
                char* temp1 =  strtok(veriler1," ");
				int sayac2=0;
						
				while(temp1!=NULL)
				{
					sayac2++;
					temp1=strtok(NULL," ");
				} 
                        
                if(sayac2 == 6)
                {
					char* tcNo2 =  strtok(veriler1," ");   
					
                    if(rk2->kisi->kimlikNo->kimlikNoKontrolEt(tcNo2)==true)
                    {
                        gecerliTcSayisi++;
                    }

                    else 
                    {
                        gecersizTcSayisi++;
                    }
                        
                }							
            } 
			//Geçerli ve geçersiz TC kimlik numaralarının sayısı ekrana yazdırılıyor
            printf("%d   %s\n", gecerliTcSayisi, "Gecerli");
			printf("%d   %s\n\n", gecersizTcSayisi, "Gecersiz");
			dosya2->yoket(dosya2);
			rk2->yoket(rk2);
			
            printf("%s","IMEI Kontrol\n");				
			int l;
			int gecerliImeiSayisi = 0;
			int gecersizImeiSayisi = 0;
			//Geçerli ve geçersiz IMEI numaralarının sayısını bulan kısım yazılıyor
            for(l = 0; l < dosya3->sayac; l++)
            {
                char* veriler2 = dosya3->oku(dosya3)[l];
                char* temp2 =  strtok(veriler2," ");
				int sayac3=0;
						
				while(temp2!=NULL)
				{
					sayac3++;
					temp2=strtok(NULL," ");
							
					if(sayac3 == 5)
					{
						imeiNoTemp2= temp2;
							
					}
				} 

                if(sayac3 == 6)
                {
					char* imeiNo2 = strtok(imeiNoTemp2,"()");

                    if(rk3->kisi->telefon->oImeiNo->imeiNoKontrolEt(imeiNo2)==true)
                    {
                        gecerliImeiSayisi++;
                    }

                    else 
                    {
                        gecersizImeiSayisi++;
                    }
                }			
            }
			//Geçerli ve geçersiz IMEI numaralarının sayısı ekrana yazdırılıyor
			printf("%d   %s\n", gecerliImeiSayisi, "Gecerli");
			printf("%d   %s\n\n", gecersizImeiSayisi, "Gecersiz");	
			dosya3->yoket(dosya3);
			rk3->yoket(rk3);
            break;
			
            case 3:
			//Programdan çıkış yapılıyor
            cikis = 1;  
            break;
			default:
			//Hatalı sayının tuşlanması durumunda ekrana hata mesajı yollanıyor
			printf("%s\n","Hatali secim! Menudeki sayilardan birine basiniz.");
			break;
        }
    }while(cikis != 1);	
	return 0;
}