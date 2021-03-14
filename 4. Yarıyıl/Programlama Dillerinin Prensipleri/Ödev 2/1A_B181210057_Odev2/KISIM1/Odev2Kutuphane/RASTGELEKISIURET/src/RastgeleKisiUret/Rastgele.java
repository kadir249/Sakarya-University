/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin rastgeleliği sağlayan kısmı
* </p>
*/

package RastgeleKisiUret;

public class Rastgele
{
    private int sayi;
    private long son;

    //kurucuda bağımsız değişken olarak zaman fonksiyonu kullandık.
    Rastgele(int sayi)
    {
        this.sayi = sayi;   
        son = System.nanoTime();
    }

    //her çağrıldığında farklı sayı üreten fonksiyon
    int rastgeleUret()
    {    
        son = (((son * 214013L + 2531011L) >> 16) & 32767);
        return (int)((son % sayi));   
    }
}