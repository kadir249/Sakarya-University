/**
*
* @author Duhan UZUN, duhan.uzun@ogr.sakarya.edu.tr - Kadir ÇELİK, kadir.celik6@ogr.sakarya.edu.tr
* @since 20.04.2020
* <p>
* Rastgele kişi üreten ve ürettiği kişilerin kimlik numaralarını ve IMEI numaralarını kontrol eden kütüphaneyi test ettiğimiz programın main kısmı
* </p>
*/

package rastgelekisideneme;

import RastgeleKisiUret.RastgeleKisi;
import RastgeleKisiUret.DosyaOkuma;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class RastgeleKisiDeneme 
{
    public static void main(String[] args)   throws IOException 
    {
        int cikis = 0;

        do
        {  
            System.out.println("1- Rastgele Kisi Uret");
            System.out.println("2- Uretilmis Dosya Kontrol Et");
            System.out.println("3- Cikis");
            
            //kullanıcıdan işlem seçmesi için giriş alıyoruz.
            Scanner oku = new Scanner(System.in);
            String islem = oku.nextLine();

            String tcNo1;
            String telefonNo1;
            String imeiNo1;
            String imeiNoTemp1;

            String tcNo2;
            String imeiNo2;
            String imeiNoTemp2;

            switch(islem)
            {
                case "1":  
                    
                System.out.println("Kac adet kisi ureteceksiniz?");
                Scanner oku2 = new Scanner(System.in);
                int kisiSayisi = Integer.parseInt(oku2.nextLine());
                
                //dosyaya yazmak için kullanıyoruz, üstüne yazmamak için false yapıyoruz. 
                BufferedWriter writer = new BufferedWriter(new FileWriter("Kisiler.txt", false));

                //girilen kisi sayısı kadar kisi olusturuyoruz.
                for(int i = 0; i < kisiSayisi; i++)
                {
                    RastgeleKisi rk = new RastgeleKisi("random_isimler.txt");
                    
                    //Tc, telefon ve IMEI numaralarının tekrarlanmamasını sağlayan kısım. Programı yavaşlattığı için açıklama satırına çevirdik. İsterseniz deneyebilirsiniz.
                    /*DosyaOkuma dosya = new DosyaOkuma("Kisiler.txt");

                    for(int j = 0; j < dosya.getSayac(); j++)
                    {
                       //ürettiğimiz veriyi dosyay yazmadan önce dosyada var mı yok mu kontrol etmek için array'e atıyoruz. 
                      String veriler = dosya.VerileriAl()[j];
                      String []kelimeler = veriler.split("\\s+");
                    
                      //dosyada 6 kelimeden farlı sayıda kelime varsa kontrol etmiyoruz.
                        if(kelimeler.length == 6)
                        {
                            tcNo1 = kelimeler[0];
                            telefonNo1 = kelimeler[4];
                            imeiNoTemp1 = kelimeler[5];      
                            imeiNo1= imeiNoTemp1.replaceAll("([(-)])", "");

                            //tc no kontrolu
                            if(tcNo1.equals(rk.getKimlikNo().toString()))
                            {
                             RastgeleKisi rk2 = new RastgeleKisi("random_isimler.txt");
                             rk.setKimlikNo(rk2.oTcNo);
                             j=0; 
                            }

                            //telefon no kontrolu
                            if(telefonNo1.equals(rk.getTelefonNo().toString()))
                            {
                                RastgeleKisi rk3 = new RastgeleKisi("random_isimler.txt");
                                rk.setTelefonNo(rk3.oTelefonNo);
                                j=0; 
                            }

                            //imei no kontrolu
                            if(imeiNo1.equals(rk.oTelefonNo.getImeiNo().toString()))
                            {
                                 RastgeleKisi rk4 = new RastgeleKisi("random_isimler.txt");
                                 rk.oTelefonNo.setImeiNo(rk4.oTelefonNo.oImeiNo);
                                 j=0; 
                            } 
                        }
                    }*/
                    
                    //verileri dosyaya yazıyoruz.
                    writer.write(rk.getKimlikNo()+" "+rk.getIsim()  +" "+ rk.getSoyisim() + " " + rk.getYas() + " " + rk.getTelefonNo() + " (" + rk.oTelefonNo.getImeiNo() + ")" );
                    writer.write('\n');   
                }
                
                writer.close();
                System.out.println("kisiler oluşturuldu");
                break;

                case "2":    
                    
                RastgeleKisi rk = new RastgeleKisi("random_isimler.txt");     
                DosyaOkuma dosya = new DosyaOkuma("Kisiler.txt");   
                
                System.out.println("T.C. Kimlik Kontrol");

                int gecerliTcSayisi = 0;
                int gecersizTcSayisi = 0;
                
                for(int k = 0; k < dosya.getSayac(); k++)
                {
                    
                    String veriler1 = dosya.VerileriAl()[k];   
                    String []kelimeler1 = veriler1.split("\\s+");   
                     
                    //dosyada 6 kelimeden farlı sayıda kelime varsa kontrol etmiyoruz.
                    if(kelimeler1.length == 6)
                    {
                        tcNo2 = kelimeler1[0];

                        if(rk.oTcNo.kimlikNoKontrolEt(tcNo2)==true)
                        {
                            gecerliTcSayisi++;
                        }

                        else 
                        {
                            gecersizTcSayisi++;
                        }      
                    }
                }
                
                System.out.println("Gecerli : " + gecerliTcSayisi + "\nGecersiz: " + gecersizTcSayisi + "\n");
                
                System.out.println("IMEI Kontrol");
                
                int gecerliImeiSayisi = 0;
                int gecersizImeiSayisi = 0;
                
                for(int l = 0; l < dosya.getSayac(); l++)
                {
                    String veriler2 = dosya.VerileriAl()[l];
                    String []kelimeler2 = veriler2.split("\\s+");
                    
                    //dosyada 6 kelimeden farlı sayıda kelime varsa kontrol etmiyoruz.
                    if(kelimeler2.length == 6)
                    {
                        imeiNoTemp2 = kelimeler2[5];
                        
                        //imeino daki parantezleri kaldırıyoruz.
                        imeiNo2= imeiNoTemp2.replaceAll("([(-)])", "");
                        
                        if(rk.oTelefonNo.oImeiNo.imeiNoKontrolEt(imeiNo2)==true)
                        {
                            gecerliImeiSayisi++;
                        }

                        else 
                        {
                            gecersizImeiSayisi++;
                        }
                    }
                }
                
                System.out.println("Gecerli : " + gecerliImeiSayisi + "\nGecersiz: " + gecersizImeiSayisi + "\n");
                
                break;
                
                case "3":
                    
                cikis = 1;  
                break;
            }
        }while(cikis != 1);
    }  
}