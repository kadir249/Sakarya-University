/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

import java.util.Random;
import java.util.Scanner;

public class AkilliCihaz 
{
    private static AkilliCihaz akilliCihaz;
    private boolean kontrol1;
    private boolean kontrol2;
    private boolean kontrol3;
    private boolean kontrol4;
    private boolean kontrol5;
    private int kontrol6;
    
    private AkilliCihaz()
    {
        
    }
        
    public static synchronized AkilliCihaz getAkilliCihaz()
    {
        if(akilliCihaz == null)
        {
            akilliCihaz = new AkilliCihaz();
        }
        return akilliCihaz;
    }
        
    public void basla() throws InterruptedException
    {
        Scanner veri = new Scanner(System.in);
        Random random = new Random(); 
        this.kontrol1 = true;
        this.kontrol2 = true;
        this.kontrol3 = random.nextBoolean();
        this.kontrol4 = random.nextBoolean();
        this.kontrol5 = random.nextBoolean();
        this.kontrol6 = 0;
        
        if(this.kontrol1 == true)
        {
            String kullaniciAdi = null;
            String kullaniciSifresi = null; 

            System.out.println("Giris Ekrani");
            System.out.print("Kullanici Adi: ");
            kullaniciAdi = veri.next();
            System.out.print("Sifre: ");
            kullaniciSifresi = veri.next();
            
            Kullanici kullanici = new Kullanici(kullaniciAdi, kullaniciSifresi);

            SogutucuVeritabaniServisi svs = new SogutucuVeritabaniServisi();

            if(svs.kullaniciDogrula(kullanici.getAdi(), kullanici.getSifresi())== true)
            {
                System.out.println("Giris Basarili! Lutfen Yapmak Istediginiz Islemi Seciniz.");
                AgArayuzu.getAgArayuzu().ekle(kullanici);
            int cevap;
            int cikis = 0;
            do
            {
                System.out.println("----------------------");
                System.out.println("1-Sicakligi Goruntule ");
                System.out.println("2-Sogutucuyu Ac");
                System.out.println("3-Sogutucuyu Kapat ");
                System.out.println("4-Sistemi Kapat ");
                System.out.println("----------------------");
                System.out.print("Seciminiz: ");
                Scanner secim1 = new Scanner(System.in);
                cevap = secim1.nextInt();
                System.out.println("----------------------");
                switch(cevap)
                {
                    case 1:
                        if(this.kontrol6 != 2)
                        {
                            AgArayuzu.getAgArayuzu().sicaklikGoruntule(this.kontrol3, this.kontrol4);
                        }
                        else
                        {
                            System.out.println("Su anda bu islem yapilamamaktadir.");
                        }
                        
                        if(this.kontrol3 == false || this.kontrol4 == false)
                        {
                            this.kontrol6 = 2;
                        }
                        break;
                    case 2:
                        int derece;
                        if(this.kontrol6 == 0)
                        {
                            Scanner secim2 = new Scanner(System.in);
                            System.out.print("Istediginiz oda sicakligi degeri: ");
                            derece = secim2.nextInt();
                            AgArayuzu.getAgArayuzu().sogutucuAc(derece, this.kontrol3, this.kontrol4, this.kontrol5, this.kontrol6);
                        }
                        else if(this.kontrol6 == 1)
                        {
                            System.out.println("Sogutucunuz zaten acik. Lutfen baska bir islem seciniz.");
                        }
                        else
                        {
                            System.out.println("Su anda bu islem yapilamamaktadir.");
                        }
                        
                        if(this.kontrol3 == true && this.kontrol4 == true && this.kontrol5 == true)
                        {
                            this.kontrol6 = 1;
                        }
                        else
                        {
                            this.kontrol6 = 2;
                        }
                        break;
                    case 3:
                        if(this.kontrol6 == 1)
                        {
                            AgArayuzu.getAgArayuzu().sogutucuKapat(this.kontrol3, this.kontrol5, this.kontrol6);
                        }
                        else if (this.kontrol6 == 0)
                        {
                            System.out.println("Sogutucunuz zaten kapali. Lutfen baska bir islem seciniz.");
                        }
                        else
                        {
                            System.out.println("Su anda bu islem yapilamamaktadir.");
                        }
                        
                        if(this.kontrol3 == true && this.kontrol4 == true && this.kontrol5 == true)
                        {
                            this.kontrol6 = 0;
                        }
                        else
                        {
                            this.kontrol6 = 2;
                        }   
                        break;
                    case 4:
                        System.out.println("Sistemden cikis yapildi.");
                        cikis = 1;
                        break;
                    default :
                        System.out.println("Hatali secim! 1, 2, 3 ya da 4'e basiniz.");
                        break;
                }
            }while(cikis != 1);
            }
            else
            {
                System.out.println("Giris Basarisiz! Lutfen Bilgilerinizi Kontrol Ediniz.");
            }        
        }
        else
        {
            if(this.kontrol2 == true)
            {
                System.out.println("Sistem su anda kullanılamamaktadır.");
            }
            else
            {
                System.out.println("Lutfen ag baglantinizi kontrol ediniz.");
            }
        }
    }
}
