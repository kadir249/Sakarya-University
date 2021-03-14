/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin rastgele kişi üreten kısmı
* </p>
*/

package RastgeleKisiUret;

public class RastgeleKisi extends Kisi
{    
    private String rastgele_ad = new String();
    private String rastgele_soyisim = new String();
    private int rastgele_yas;
    
    public KimlikNo oTcNo = new KimlikNo();
    public Telefon oTelefonNo = new Telefon();

    //kurucuda gerekli atamaları yapıyoruz.
    public RastgeleKisi(String dosyaAdi)
    {
        oTcNo.kimlikNoUret();
        oTelefonNo.telefonNoUret();  
        rastgeleIsimUret(dosyaAdi);      
        super.setKimlikNo(oTcNo);
        super.setTelefonNo(oTelefonNo);
        super.setIsim(this.rastgele_ad);
        super.setSoyisim(this.rastgele_soyisim);
        super.setYas(rastgeleYasUret());
    }
    
    public void rastgeleIsimUret(String dosyaAdi)
    {
        //dosyadan gerekli verileri çekiyoruz
        DosyaOkuma dosya = new DosyaOkuma(dosyaAdi);
        Rastgele random = new Rastgele(dosya.getSayac());      
        int rastgeleSayi =  random.rastgeleUret();
        
        //dosyadan gerekli verileri çekiyoruz
        String isim = dosya.VerileriAl()[rastgeleSayi];
        
        //veriyi isim ve soyisim diye iki parçaya ayırıyoruz, fazla boşluklar varsa da sıkıntı olmayacak şekilde ayarladık.
        String isim2[] =  isim.split("\\s+");
        
        rastgele_ad=isim2[0];
        rastgele_soyisim = isim2[1];
    }
    
    public int rastgeleYasUret()
    {
        rastgele_yas = 0;
        
        Rastgele rastgeleYas = new Rastgele(100);
        rastgele_yas = rastgeleYas.rastgeleUret();
        
        return rastgele_yas;
    }
}