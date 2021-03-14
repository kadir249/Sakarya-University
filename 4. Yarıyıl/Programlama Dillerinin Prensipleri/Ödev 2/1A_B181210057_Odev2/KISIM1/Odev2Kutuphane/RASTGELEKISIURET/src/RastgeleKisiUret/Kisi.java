/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin kişi kısmı
* </p>
*/

package RastgeleKisiUret;

//kişimizin verilerini bu sınıfta tutuyoruz.
public class Kisi 
{
    //kimlikno ve telefon türünde bir değişken belirtiyoruz
    private KimlikNo kimlikNo;
    private Telefon telefonNo;
    private String isim;
    private String soyisim;
    private int yas;
   

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }
   
    public KimlikNo getKimlikNo() 
    {
        return kimlikNo;
    }

    public void setKimlikNo(KimlikNo kimlikNo) 
    {
        this.kimlikNo = kimlikNo;
    }

    public String getSoyisim() 
    {
        return soyisim;
    }

    public void setSoyisim(String soyisim) 
    {
        this.soyisim = soyisim;
    }

    public int getYas() {
        return yas;
    }

    public void setYas(int yas) 
    {
        this.yas = yas;
    }

    public Telefon getTelefonNo() 
    {
        return telefonNo;
    }

    public void setTelefonNo(Telefon telefonNo) 
    {
        this.telefonNo = telefonNo;
    }

}