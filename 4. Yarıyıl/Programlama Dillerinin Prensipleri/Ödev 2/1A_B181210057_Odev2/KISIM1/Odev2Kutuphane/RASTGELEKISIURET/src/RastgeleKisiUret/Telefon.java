/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin telefon kısmı
* </p>
*/

package RastgeleKisiUret;

public class Telefon
{
    private final int []telefonNoTemp;
    private String telefonNo;
    private final int telefonNoUzunluk = 11;
    private Rastgele rastgeleSayi = new Rastgele(10);
    private IMEINo imeiNo;
    public IMEINo oImeiNo = new IMEINo();

    public Telefon()
    {
        telefonNoTemp = new int [telefonNoUzunluk];
        telefonNo = new String();
        
        //telefonun kurucusunda imeino da üretiliyor
        oImeiNo.imeiNoUret();
        
        //imeino set ediliyor
        this.setImeiNo(oImeiNo);
    }
    
    public String telefonNoUret()
    {
        //ilk 2 hane belli sayıları alabilir
        telefonNoTemp[0] = 0;
        telefonNoTemp[1] = 5;
        
        //kalan haneler belli kurala göre atanabiliyor, atanan veri koşulu sağlamıyorsa tekrar atanıyor.
        for(int i = 2; i < 11; i++)
        {
            telefonNoTemp[i] = rastgeleSayi.rastgeleUret();
            
            if(i == 2)
            {
                while(telefonNoTemp[i] == 1 || telefonNoTemp[i] == 2 || telefonNoTemp[i] == 7 || telefonNoTemp[i] == 8 || telefonNoTemp[i] == 9)
                {
                    telefonNoTemp[i] = rastgeleSayi.rastgeleUret();
                }
            }
            if(i == 3)
            {
                if(telefonNoTemp[2] == 0)
                {
                    while(telefonNoTemp[i] == 0 || telefonNoTemp[i] == 2 || telefonNoTemp[i] == 3 || telefonNoTemp[i] == 4 || telefonNoTemp[i] == 8 || telefonNoTemp[i] == 9)
                    {
                        telefonNoTemp[i] = rastgeleSayi.rastgeleUret();
                    } 
                }
                
                else if(telefonNoTemp[2] == 5)
                {
                    while(telefonNoTemp[i] == 0 || telefonNoTemp[i] == 6 || telefonNoTemp[i] == 7 || telefonNoTemp[i] == 8)
                    {
                        telefonNoTemp[i] = rastgeleSayi.rastgeleUret();
                    } 
                }  

                else if(telefonNoTemp[2] == 6)
                {
                    telefonNoTemp[i] = 1;
                }
                else
                {
                    telefonNoTemp[i] = rastgeleSayi.rastgeleUret();
                }
            }
        }
        
        //en son bulunan değerler telefonNo'ya atanıyor
        for(int i = 0; i < 11; i++)
        {
            telefonNo+=String.valueOf(telefonNoTemp[i]);
        }
        return telefonNo;
    }
     
    //dışarıdan imiei no'ya erişmek istediğimizde kullanıyoruz
    public IMEINo getImeiNo() 
    {
        return imeiNo;
    }

    //dışarıdan imiei no'yu değiştirmek istediğimizde kullanıyoruz
    public void setImeiNo(IMEINo imeiNo)
    {
        this.imeiNo = imeiNo;
    }
    
    //objeyi yazdırma şeklini belirtiyoruz çünkü diğer sınıflar objeyi kullanarak veriye erişmek isteyecek. 
    @Override
    public String toString()
    {
        return telefonNo;
    }
}
