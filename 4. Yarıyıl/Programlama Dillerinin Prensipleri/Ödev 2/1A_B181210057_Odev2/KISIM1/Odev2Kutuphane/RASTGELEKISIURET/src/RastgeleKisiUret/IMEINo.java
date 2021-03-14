/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin dosya imei kısmı
* </p>
*/

package RastgeleKisiUret;

public class IMEINo 
{ 
    private int [] imeiNoTemp;
    private String imeiNo;
    private String islemYapilanImeiParcasi;
    private final int imeiNoUzunluk = 15;  
    private Rastgele rastgeleSayi = new Rastgele(10);
    
    public IMEINo()
    {    
        imeiNo = new String();
        imeiNoTemp = new int[imeiNoUzunluk];
        islemYapilanImeiParcasi = new String();
    }
        
    public String imeiNoUret()
    {
        int toplam = 0;

        //ilk 14 haneye rastgele sayı atıyoruz.
        for(int i = 0; i < 14; i++)
        {
           imeiNoTemp[i] = rastgeleSayi.rastgeleUret();
        }

        for(int i = 0;i<14;i++)
        {    
           //her bir haneyi kontrol etmek için sırayla değikene atıyoruz
           int basamak = imeiNoTemp[i];
            
           //hane numarası tekse direk toplama ekliyoruz 
            if(i%2==0)
            {
                toplam = toplam + basamak;
            }
            
            //değilse ve tek basamakdan fazlaysa sayıyı parçalayıp öyle topluyoruz.  
            else
            {
                toplam = toplam + basamaklarinToplami(basamak*2);
            }
        }
        
        toplam = toplam * 9;
        
        //son haneyi buluyoruz
        imeiNoTemp[14] =toplam %10;
       
        //bulduğumuz verileri asıl değişkenimize atıyoruz
        for(int i = 0; i < 15; i++)
        {
            imeiNo+=String.valueOf(imeiNoTemp[i]);
        }
        
        return imeiNo;     
    }
   
    //gelen veriyi basamaklarına ayırmak için kullanıyoruz
    public int basamaklarinToplami(int sayi)
    {  
        int toplam=0;
        while(sayi > 0) 
        {
            toplam += sayi%10;
            sayi = sayi/10;
        }
        return toplam;
    }
    
    public boolean imeiNoKontrolEt(String imei)
    {
        if (imei == null)return false;

        if (imei.length() != 15) return false;
        
        //imeino'nun son hanesini kontrol etmek için değişkene atıyoruz
        char kontrolEdilenHarf = imei.charAt(imeiNoUzunluk-1);
        
        int kontrolEdilenRakam;
        
        //çekilen haneyi int'e dönüştürüyoruz
        kontrolEdilenRakam = kontrolEdilenHarf - '0';

        int toplam = 0;
        
        //ilk 14 haneye gerekli işlemleri yapıyoruz.
        for(int i =0;i<14;i++)
        {    
            String sBasamak = imei.substring(i,i+1);
            int basamak = Integer.valueOf(sBasamak);
            
            if(i%2==0) 
            {
                toplam = toplam + basamak;
            }
            else 
            {
                toplam = toplam + basamaklarinToplami(basamak * 2);
            }
        }
        toplam = toplam * 9;
        
        //son haneyi kurala göre kontrol ediyoruz
        if(kontrolEdilenRakam != toplam %10)  return  false;
        
        return true;
    }
    
    //objeyi yazdırma şeklini belirtiyoruz çünkü diğer sınıflar objeyi kullanarak veriye erişmek isteyecek.
    @Override
    public String toString()
    {
        return imeiNo;
    }
}
