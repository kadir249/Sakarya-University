/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin kimlik kısmı
* </p>
*/

package RastgeleKisiUret;

public class KimlikNo  
{   
    private final int []tcNoTemp;
    private String tcNo;
  
    private int teklerinToplami = 0;
    private int ciftlerinToplami = 0;
    
    private final int artisMiktari = 2;
    private final int tcNoUzunluk = 11;
    
    //rastgele sayı üretmek için
    private Rastgele rastgeleSayi = new Rastgele(10);

    public KimlikNo()
    {
        tcNoTemp = new int [tcNoUzunluk];
        tcNo = new String();
    }

    public String kimlikNoUret ()
    {  
        //ilk 9 haneyi rastgele sayı atıyoruz
        for(int i = 0; i < 9; i++)
        {
            tcNoTemp[i] = rastgeleSayi.rastgeleUret();       
            if(i == 0)
            {
                while(tcNoTemp[i] == 0)
                {
                    tcNoTemp[i] = rastgeleSayi.rastgeleUret();
                } 
            }
        }
        
        //tek hanelerdeki sayilarin toplamini buluyoruz
        for(int i = 0; i < 10; i+=artisMiktari)
        {
            teklerinToplami += tcNoTemp[i];        
        }
        
        //çift hanelerdeki sayilarin toplamini buluyoruz
        for(int i = 1; i < 9; i += artisMiktari)
        {
            ciftlerinToplami += tcNoTemp[i];      
        }
        
        //10. haneyi kurala göre buluyoruz.
        tcNoTemp[9]  = ((teklerinToplami*7) - ciftlerinToplami)%10;
        
        int tempSayi = 0;
        
        //11. haneyi bulmak için bütün elemanları topluyoruz
        for(int i = 0; i < 10; i++)
        {
            tempSayi += tcNoTemp[i];
        }
     
        //11. haneyi buluyoruz       
        tcNoTemp[10] = tempSayi%10;
        
        for(int i = 0; i < 11; i++)
        {
            tcNo+=tcNoTemp[i];
        }        
        return tcNo;        
    }
    
    public boolean kimlikNoKontrolEt(String tc)
    {
        if (tc == null)return false;

        if (tc.length() != 11) return false;
         
        //gelen veriyi karakterlerine parçalıyoruz
        char[] chars = tc.toCharArray();
        int[] tcNo = new int[11];
        
        //verideki her bir haneyi bir int arraye atıyoruz.
        for(int i=0; i<11; i++) 
        {
            tcNo[i] = chars[i]-'0';
        }
        //ilk hane 0 olamaz
        if(tcNo[0] == 0) return false;
        
        //son hane tek olamaz
        if(tcNo[10] % 2 == 1) return false;
      
        //10. haneyi bulmak için aranan koşul sağlanıyor mu
        if((((tcNo[0] + tcNo[2] + tcNo[4] + tcNo[6] + tcNo[8]) * 7) - (tcNo[1] + tcNo[3] + tcNo[5] + tcNo[7])) % 10 != tcNo[9]) return false;

         //11. haneyi bulmak için aranan koşul sağlanıyor mu
        if((tcNo[0] + tcNo[1] + tcNo[2] + tcNo[3] + tcNo[4] + tcNo[5] + tcNo[6] + tcNo[7] + tcNo[8] + tcNo[9]) % 10 != tcNo[10]) return false;
        
        return true;     
    } 
  
    @Override
    public String toString()
    {
        return tcNo;
    }
}
