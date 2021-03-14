/**
*
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr
* @since 08.03.2020
* <p>
* Bir dosyadan alınan Türkçe karakterli verinin içinde bulunan sesli harflerin, kelimelerin, cümlelerin, mail adreslerinin ve web sitelerinin sayısını belirli kurallar 
* çerçevesinde bulan program.
* </p>
*/

package b181210057_1a_odev1;

//Program için gerekli olan dosya okuma kütüphanelerinin tanımlandığı kısım.
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
//Dosya okuma sırasında oluşabilecek istisnalar için gerekli olan kütüphanelerin tanımlandığı kısım.
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
//Regex için gerekli olan pattern(düzen) ve matcher(eşleştirme) kütüphanelerinin tanımlandığı kısım.
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class B181210057_1A_Odev1 
{    
    //Mail adresi kontrolünde kullanılacak olan sabit ve değiştirilemez karakter düzeninin tanımlandığı kısım. 
    private static final String mailKontrol = "^[\\w-\\+]+(\\.[\\w]+)*@[\\w-]+(\\.[\\w]+)*(\\.[a-z]{2,}+)[.]*$";
    //Web sitesi kontrolünde kullanılacak olan sabit ve değiştirilemez karakter düzeninin tanımlandığı kısım. 
    private static final String webSitesiKontrol = "^[\\w-\\+]+(\\.[\\w]+)*.(com|edu|net|org|com.tr|edu.tr|net.tr|org.tr+)[.]*$";
    //Mail adresi kontrolü için gerekli pattern(düzen)in tanımlandığı kısım.
    private static Pattern patternMail;
    //Mail adresi kontrolü için gerekli olan matcher(eşletirme)ın tanımlandığı kısım.
    private static Matcher matcherMail;
    //Web sitesi kontrolü için gerekli pattern(düzen)in tanımlandığı kısım.
    private static Pattern patternWeb;
    //Web sitesi kontrolü için gerekli olan matcher(eşletirme)ın tanımlandığı kısım.
    private static Matcher matcherWeb;

    //Mail adresi kontrolü için gerekli olan, boolean değer döndüren fonksiyonun tanımlandığı kısım.
    public static final boolean mailKontrolu(String email) 
    {
        //Mail adresi için verilen düzenin derleme alanı.
        patternMail = Pattern.compile(mailKontrol, Pattern.CASE_INSENSITIVE);
        //Mail adresi için verilen düzenin eşleştirildiği alan.
        matcherMail = patternMail.matcher(email);
        //Fonksiyonun eşleştirme sonucunu true ya da false olarak döndürdüğü alan.
        return matcherMail.matches();
    }
    
    //Web sitesi kontrolü için gerekli olan, boolean değer döndüren fonksiyonun tanımlandığı kısım.
    public static final boolean webKontrolu(String web) 
    {
        //Web sitesi için verilen düzenin derleme alanı.
        patternWeb = Pattern.compile(webSitesiKontrol, Pattern.CASE_INSENSITIVE);
        //Web sitesi için verilen düzenin eşleştirildiği alan.
        matcherWeb = patternWeb.matcher(web);
        //Fonksiyonun eşleştirme sonucunu true ya da false olarak döndürdüğü alan.
        return matcherWeb.matches();
    }
       
    public static void main(String[] args) 
    {
        //Text dosyasının konumunun bir değişkene atandığı kısım.
        String dosyaYolu = ".//doc//icerik.txt";
        //Text dosyasındaki verileri aktaracağımız değişken.
        String metin = null;
        //Dosyayı okumak içiin gerekli olan try-catch bloğu.
        try
        {
            //Dosyanın tanımlandığı kısım.
            File dosya = new File(dosyaYolu);
            //Dosya okumaya yarayan sınıfların kullanıldığı ve tanımlandığı kısım.
            BufferedReader oku = new BufferedReader(
            new InputStreamReader(
            new FileInputStream(dosya), "UTF8"));
            
            //dizi değişkeninin tanımlandığı kısım.
            String dizi;
            //Dosyadaki verilerin okunarak "metin" değişkenine aktarıldığı while döngüsü.
            while((dizi = oku.readLine()) != null)
            {
                //Dosyadaki bir verinin "metin" değişkenine atandığı kısım.
                metin = dizi;
            }
            //Dosya okumanın bitirildiği kısım.
            oku.close();
        }
        //Desteklenmeyen kodlamalarda verilecek hatanın tanımlandığı kısım.
        catch (UnsupportedEncodingException e)
        {
            System.out.println("Desteklenmeyen Kodlama İstisnası: " + e.getMessage());
        }
        //IO ile ilgili istisnalarda verilecek hatanın tanımlandığı kısım.
        catch (IOException e) 
        {
            System.out.println("IO İstisnası: " + e.getMessage());
        }
        //İstisnalarda verilecek hatanın tanımlandığı kısım.
        catch (Exception e)
        {
            System.out.println("İstisna: " + e.getMessage());
        }
        
        //Dosyadaki sesli harflerin sayısını tutacak değişkenin tanımlandığı kısım.
        int sesliHarfSayaci = 0;
        //Dosyadaki kelimelerin sayısını tutacak değişkenin tanımlandığı kısım.
        int kelimeSayaci = 0;
        //Dosyadaki cümlelerin sayısını tutacak değişkenin tanımlandığı kısım.
        int cumleSayaci = 0;
        //Dosyadaki mail adreslerinin sayısını tutacak değişkenin tanımlandığı kısım.
        int mailSayaci = 0;
        //Dosyadaki web sitelerinin sayısını tutacak değişkenin tanımlandığı kısım.
        int webSitesiSayaci = 0;

        //Sesli harf okumada kullanılacak olan değişkenin tanımlandığı kısım.
        String sesliHarfler = "AEIİOÖUÜaeıioöuü";
        
        //"metin" değişkenindeki verilerin boşluğa göre parçalanarak "kelimeler" adlı bir String dizisine aktarıldığı kısım.
        String[] kelimeler = metin.split(" ");
        
        //"metin" değişkeninin uzunluğu kadar dönen bir for döngüsü.
        for(int i = 0; i < metin.length() - 1; i++)
        {
             //"sesliHarfler" değişkeninin uzunluğu kadar dönen bir for döngüsü.
            for(int j = 0; j <= 15; j++)
            {
                //Eğer "sesliHarfler" değişkeninde bulunan bir verinin "metin" değişkeninde bulunuyorsa if'in bloğunun içerisine girilir.
                if(metin.charAt(i) == sesliHarfler.charAt(j))
                {
                    //Sesli harf sayacının arttırıldığı kısım.
                    sesliHarfSayaci++;
                }
            }
        }
        
        //Kelime sayacının, kelimeler dizisinin uzunluğuna eşitlendiği kısım.
        kelimeSayaci = kelimeler.length;
        
        //"kelimeler" dizisinin uzunluğu kadar dönen bir for döngüsü.
        for(int i = 0; i < kelimeler.length; i++)
        {
            //"kelimeler" dizisinde bulunan bir elemanın uzunluğu kadar dönen bir for döngüsü.
            for(int j = 0; j < kelimeler[i].length(); j++)
            {   
                //Eğer "kelimeler" dizisinin bir elemanının son karakterinde "." varsa if'in içine girilir. 
                if (j == kelimeler[i].length() - 1 && kelimeler[i].charAt(j) == '.') 
                {
                    //Cümle sayacının arttırıldığı kısım.
                    cumleSayaci++;
                }
            }
        }
        
        //"mailGecici" adlı String bir değişkene sırasıyla "kelimeler" adlı dizinin elemanlarının atandığı for döngüsü.
        for (String mailGecici : kelimeler) 
        {
            //Eğer "mailKontrolu" fonksiyonu true döndürürse if'in içine girilir.
            if(mailKontrolu(mailGecici) == true)
            {
                //Mail adresi sayacının arttırıldığı kısım.
                mailSayaci++;
            }
	}
        
         //"webGecici" adlı String bir değişkene sırasıyla "kelimeler" adlı dizinin elemanlarının atandığı for döngüsü.
        for (String webGecici : kelimeler) 
        {   
            //Eğer "webKontrolu" fonksiyonu true döndürürse if'in içine girilir.
            if(webKontrolu(webGecici) == true)
            {
                 //Web sitesi sayacının arttırıldığı kısım.
                webSitesiSayaci++;
            } 
        }
        
        //Dosyadaki sesli harf sayısının ekrana yazdırıldığı kısım.
        System.out.println("Toplam Sesli Harf Sayısı: " + sesliHarfSayaci);
        //Dosyadaki kelime sayısının ekrana yazdırıldığı kısım.
        System.out.println("Toplam Kelime Sayısı    : " + kelimeSayaci);
        //Dosyadaki cümle sayısının ekrana yazdırıldığı kısım.
        System.out.println("Toplam Cümle Sayısı     : " + cumleSayaci);
        //Dosyadaki mail adresi sayısının ekrana yazdırıldığı kısım.
        System.out.println("Toplam Mail Sayısı      : " + mailSayaci);
        //Dosyadaki web sitesi sayısının ekrana yazdırıldığı kısım.
        System.out.println("Toplam Web Sitesi Sayısı: " + webSitesiSayaci);
    }  
}