/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphanenin dosya okuma kısmı
* </p>
*/

package RastgeleKisiUret;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DosyaOkuma 
{   
    private String[] veri;
    private int sayac;
    private String dosyaAdi;
   
    public DosyaOkuma(String dosya)
    {
      //dosya okuma ilk çalıştığı zaman dosyayı satır satır gezerek toplam satır sayısını tespit ediyoruz.         
        try
        {          
            BufferedReader reader = null;
            reader = new BufferedReader(new FileReader(dosya));
            String secilen = reader.readLine();
       
            while(secilen != null)
            {
                sayac++;
                secilen = reader.readLine();                
            }         
        }
        catch(final IOException e)
        {
            System.out.println("Dosya bulunamadı!");
        }
         
        veri = new String[sayac];
        dosyaAdi = dosya;   
    }
   
    //bulunan satır sayısını döndürüyoruz
    public int getSayac() 
    {
        return sayac;
    }
    
    public String []VerileriAl()
    {
        try
        {      
            BufferedReader reader = null;
            reader = new BufferedReader(new FileReader(dosyaAdi));
            String secilen = reader.readLine();
            
            //okunan verileri array'e atıyoruz.
            for(int i = 0; i < sayac; i++)
            {
                veri[i] = secilen;
                secilen = reader.readLine();                
            }        
        }
        catch(final IOException e)
        {
            System.out.println("Dosya bulunamadı!");
        }
        return veri; 
    }               
}