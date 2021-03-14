/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

import java.util.Random;
import java.util.Scanner;

public class AgArayuzu implements ISubject
{
    private IObserver kullanici;
    private static AgArayuzu agArayuzu;
    private AgArayuzu()
    {
        
    }
        
    public static synchronized AgArayuzu getAgArayuzu()
    {
        if(agArayuzu == null)
        {
            agArayuzu = new AgArayuzu();
        }
        return agArayuzu;
    }
        
    public void sicaklikGoruntule(boolean kontrol3, boolean kontrol4) throws InterruptedException
    {
        if(kontrol3 == true)
        {
            if(kontrol4 == true)
            {
                Thread.sleep(1000);
                AgArayuzu.getAgArayuzu().mesaj3(kontrol4);
            }
            else 
            {
                Thread.sleep(1000);
                System.out.println("Sorun ag arayuzune bildiriliyor.");
                Thread.sleep(1000);
                AgArayuzu.getAgArayuzu().mesaj2();
            }
        }
        else
        {
            Thread.sleep(1000);
            AgArayuzu.getAgArayuzu().mesaj2();
        }      
    }
    
    public void sogutucuAc(int derece, boolean kontrol3, boolean kontrol4, boolean kontrol5, int kontrol6) throws InterruptedException
    {
        Thread.sleep(1000);
        System.out.println("Isteginiz merkezi islem birimine iletiliyor.");
        if(kontrol3 == true)
        {
            if(kontrol4 == true)
            {
                Thread.sleep(1000);
                MerkeziIslemBirimi.getMerkeziIslemBirimi().sogutucuAc(derece, kontrol4, kontrol5);
                if(derece < MerkeziIslemBirimi.getMerkeziIslemBirimi().sicaklikGonder(kontrol4))
                {
                    if(kontrol5 == true)
                    {
                        Thread.sleep(1000);
                        Eyleyici.getEyleyici().sogutucuAc();
                        Thread.sleep(1000);
                        AgArayuzu.getAgArayuzu().mesaj1(kontrol6);
                    }
                    else
                    {
                        Thread.sleep(1000);
                        AgArayuzu.getAgArayuzu().mesaj2();
                    }
                }
                else
                {
                    Thread.sleep(1000);
                    System.out.println("Lutfen daha dusuk bir sicaklik degeri giriniz.");
                }
            }
            else
            {
                Thread.sleep(1000);
                System.out.println("Sorun ag arayuzune bildiriliyor.");
                Thread.sleep(1000);
                AgArayuzu.getAgArayuzu().mesaj2();
            }
        }
        else
        {
            Thread.sleep(1000);
            AgArayuzu.getAgArayuzu().mesaj2();
        }
    }
    
    public void sogutucuKapat(boolean kontrol3, boolean kontrol5, int kontrol6) throws InterruptedException
    {
        Thread.sleep(1000);
        System.out.println("Isteginiz merkezi islem birimine iletiliyor.");
        if(kontrol3 == true)
        {
            Thread.sleep(1000);
            MerkeziIslemBirimi.getMerkeziIslemBirimi().sogutucuKapat(kontrol5);
            {
                if(kontrol5 == true)
                {
                    Thread.sleep(1000);
                    Eyleyici.getEyleyici().sogutucuKapat();
                    Thread.sleep(1000);
                    AgArayuzu.getAgArayuzu().mesaj1(kontrol6);
                }
                else
                {
                    Thread.sleep(1000);
                    AgArayuzu.getAgArayuzu().mesaj2();
                }
            }
        }
        else
        {
            Thread.sleep(1000);
            AgArayuzu.getAgArayuzu().mesaj2();
        }       
    }
    
    @Override
    public void ekle(IObserver kullanici) 
    {
        this.kullanici = kullanici;
    }

    @Override
    public void sil(IObserver kullanici) 
    {
        this.kullanici = null;
    }

    @Override
    public void mesaj1(int kontrol6) 
    {
        if(kontrol6 == 0)
        {
            kullanici.guncelleme("Sogutucunuz acildi.");
        }
        else
        {
            kullanici.guncelleme("Sogutucunuz kapatildi.");
        }
    }
    
    @Override
    public void mesaj2() 
    {
        kullanici.guncelleme("Lutfen teknik servise basvurunuz.");
    }
    
    @Override
    public void mesaj3(boolean kontrol4) 
    {
        kullanici.guncelleme("Odanizin mevcut sicaklik degeri " + MerkeziIslemBirimi.getMerkeziIslemBirimi().sicaklikGonder(kontrol4) + " derece.");
    }
}
    