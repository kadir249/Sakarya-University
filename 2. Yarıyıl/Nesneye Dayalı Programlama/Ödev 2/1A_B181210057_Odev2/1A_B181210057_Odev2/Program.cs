/****************************************************************************
**				SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**			    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**			    2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 2
**				ÖĞRENCİ ADI............: Kadir Çelik
**				ÖĞRENCİ NUMARASI.......: B181210057
**              DERSİN ALINDIĞI GRUP...: 1A
****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1A_B181210057_Odev2
{
    //Futbolcu adında bir sınıf oluşturuluyor.
    class Futbolcu
    {
        //Futbolcu sınıfının değişkenleri tanımlanıyor.
        public string AdSoyad { get; set; }
        public int FormaNo { get; set; }
        public double Hiz { get; set; }
        public double Dayaniklilik { get; set; }
        public double Pas { get; set; }
        public double Sut { get; set; }
        public double Yetenek { get; set; }
        public double Kararlilik { get; set; }
        public double DogalForm { get; set; }
        public double Sans { get; set; }

        //Futbolcu sınıfının değişkenlerine değer ataması yapan DegerAta fonksiyonu tanımlanıyor.
        public void DegerAta()
        {
            //Futbolcu sınıfının değişkenlerine 50-100 arasında random değerler atanıyor.
            Random DegerAtama = new Random();
            Hiz = DegerAtama.Next(50, 100);
            Dayaniklilik = DegerAtama.Next(50, 100);
            Pas = DegerAtama.Next(50, 100);
            Sut = DegerAtama.Next(50, 100);
            Yetenek = DegerAtama.Next(50, 100);
            Kararlilik = DegerAtama.Next(50, 100);
            DogalForm = DegerAtama.Next(50, 100);
            Sans = DegerAtama.Next(50, 100);
        }

        //Futbolcu sınıfının kurucu fonksiyonu tanımlanıyor.
        public Futbolcu(string adSoyad, int formaNo)
        {
            //Futbolcu sınıfının AdSoyad ve FormaNo değişkenlerine kurucu fonksiyonun değişkenleri atanıyor.
            AdSoyad = adSoyad;
            FormaNo = formaNo;
            //Futbolcu sınıfının DegerAta fonksiyonu çağrılıyor.
            DegerAta();
        }

        //Double değer döndüren PasVer metodu tanımlanıyor.
        public virtual double PasVer()
        {
            //PasSkor adlı değişken tanımlanıyor.
            double PasSkor;
            //Futbolcu sınıfının değişkenleri kullanılarak PasSkor değişkeni hesaplanıyor.
            PasSkor = PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklilik * 0.1 + DogalForm * 0.1 + Sans * 0.2;
            //PasVer metodu PasSkoru değer olarak döndürüyor.
            return PasSkor;

        }

        //Double değer döndüren GolVurusu metodu tanımlanıyor.
        public virtual double GolVurusu()
        {
            //GolSkor adlı değişken tanımlanıyor.
            double GolSkor;
            //Futbolcu sınıfının değişkenlerini kullanılarak GolSkor değişkeni hesaplanıyor.
            GolSkor = Yetenek * 0.3 + Sut * 0.2 + Kararlilik * 0.1 + DogalForm * 0.1 + Hiz * 0.1 + Sans * 0.2;
            //GolVurusu metodu GolSkoru değer olarak döndürüyor.
            return GolSkor;
        }
    }

    //Futbolcu sınıfını temel alan Defans sınıfı oluşturuluyor.
    class Defans : Futbolcu
    {
        //Defans sınıfının değişkenleri tanımlanıyor.
        public double PozisyonAlma { get; set; }
        public double Kafa { get; set; }
        public double Sicrama { get; set; }

        //Defans sınıfındaki değişkenlere değer atayan DegerAta fonksiyonu tanımlanıyor.
        public new void DegerAta()
        {
            //Defans sınıfının değişkenlerine 50-90 arasında random değerler atanıyor.
            Random DegerAtama = new Random();
            Hiz = DegerAtama.Next(50, 90);
            Dayaniklilik = DegerAtama.Next(50, 90);
            Pas = DegerAtama.Next(50, 90);
            Sut = DegerAtama.Next(50, 90);
            Yetenek = DegerAtama.Next(50, 90);
            Kararlilik = DegerAtama.Next(50, 90);
            DogalForm = DegerAtama.Next(50, 90);
            Sans = DegerAtama.Next(50, 90);
            PozisyonAlma = DegerAtama.Next(50, 90);
            Kafa = DegerAtama.Next(50, 90);
            Sicrama = DegerAtama.Next(50, 90);
        }

        //Futbolcu sınıfının kurucu fonksiyonunu temel alan Defans sınıfının kurucu fonksiyonu tanımlanıyor.
        public Defans(string DefansAdSoyad, int DefansFormaNo) : base(DefansAdSoyad, DefansFormaNo)
        {
            //Defans sınıfının DegerAta fonksiyonu çağrılıyor.
            DegerAta();
        }

        //Defans sınıfının double değer döndüren PasVer metodu tanımlanıyor.
        public override double PasVer()
        {
            //PasSkor adlı değişken tanımlanıyor.
            double PasSkor;
            //Defans sınıfının değişkenleri kullanılarak PasSkor değişkeni hesaplanıyor.
            PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklilik * 0.1 + DogalForm * 0.1 + PozisyonAlma * 0.1 + Sans * 0.2;
            //PasVer metodu PasSkoru değer olarak döndürüyor.
            return PasSkor;

        }

        //Defans sınıfının double değer döndüren GolVurusu metodu tanımlanıyor.
        public override double GolVurusu()
        {
            //GolSkor adlı değişken tanımlanıyor.
            double GolSkor;
            //Defans sınıfının değişkenlerini kullanılarak GolSkor değişkeni hesaplanıyor.
            GolSkor = Yetenek * 0.3 + Sut * 0.2 + Kararlilik * 0.1 + DogalForm * 0.1 + Kafa * 0.1 + Sicrama * 0.1 + Sans * 0.1;
            //GolVurusu metodu GolSkoru değer olarak döndürüyor.
            return GolSkor;
        }
    }

    //Futbolcu sınıfını temel alan OrtaSaha sınıfı oluşturuluyor.
    class OrtaSaha : Futbolcu
    {
        //OrtaSaha sınıfının değişkenleri tanımlanıyor.
        public double UzunTop { get; set; }
        public double IlkDokunus { get; set; }
        public double Uretkenlik { get; set; }
        public double TopSurme { get; set; }
        public double OzelYetenek { get; set; }


        //OrtaSaha sınıfındaki değişkenlere değer atayan DegerAta fonksiyonu tanımlanıyor.
        public new void DegerAta()
        {
            //OrtaSaha sınıfının değişkenlerine 60-100 arasında random değerler atanıyor.
            Random DegerAtama = new Random();
            Hiz = DegerAtama.Next(60, 100);
            Dayaniklilik = DegerAtama.Next(60, 100);
            Pas = DegerAtama.Next(60, 100);
            Sut = DegerAtama.Next(60, 100);
            Yetenek = DegerAtama.Next(60, 100);
            Kararlilik = DegerAtama.Next(60, 100);
            DogalForm = DegerAtama.Next(60, 100);
            Sans = DegerAtama.Next(60, 100);
            UzunTop = DegerAtama.Next(60, 100);
            IlkDokunus = DegerAtama.Next(60, 100);
            Uretkenlik = DegerAtama.Next(60, 100);
            TopSurme = DegerAtama.Next(60, 100);
            OzelYetenek = DegerAtama.Next(60, 100);
        }

        //Futbolcu sınıfının kurucu fonksiyonunu temel alan OrtaSaha sınıfının kurucu fonksiyonu tanımlanıyor.
        public OrtaSaha(string OrtaSahaAdSoyad, int OrtaSahaFormaNo) : base(OrtaSahaAdSoyad, OrtaSahaFormaNo)
        {
            //DegerAta fonksiyonu çağrılıyor.
            DegerAta();
        }

        //OrtaSaha sınıfının double değer döndüren PasVer metodu tanımlanıyor.
        public override double PasVer()
        {
            //PasSkor adlı değişken tanımlanıyor.
            double PasSkor;
            //OrtaSaha sınıfının değişkenleri kullanılarak PasSkor değişkeni hesaplanıyor.
            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklilik * 0.1 + DogalForm * 0.1 + UzunTop * 0.1
            + TopSurme * 0.1 + Sans * 0.1;
            //PasVer metodu PasSkoru değer olarak döndürüyor.
            return PasSkor;

        }

        //OrtaSaha sınıfının double değer döndüren GolVurusu metodu tanımlanıyor.
        public override double GolVurusu()
        {
            //GolSkor adlı değişken tanımlanıyor.
            double GolSkor;
            //OrtaSaha sınıfının değişkenlerini kullanılarak GolSkor değişkeni hesaplanıyor.
            GolSkor = Yetenek * 0.3 + OzelYetenek * 0.2 + Sut * 0.2 + IlkDokunus * 0.1 + Kararlilik * 0.1 + DogalForm * 0.1
            + Sans * 0.1;
            //GolVurusu metodu GolSkoru değer olarak döndürüyor.
            return GolSkor;
        }
    }

    //Futbolcu sınıfını temel alan Forvet sınıfı oluşturuluyor.
    class Forvet : Futbolcu
    {
        //Forvet sınıfının değişkenleri tanımlanıyor.
        public double Bitiricilik { get; set; }
        public double IlkDokunus { get; set; }
        public double Kafa { get; set; }
        public double OzelYetenek { get; set; }
        public double SogukKanlilik { get; set; }

        //Forvet sınıfındaki değişkenlere değer atayan DegerAta fonksiyonu tanımlanıyor.
        public new void DegerAta()
        {
            //Forvet sınıfının değişkenlerine 70-100 arasında random değerler atanıyor.
            Random DegerAtama = new Random();
            Hiz = DegerAtama.Next(70, 100);
            Dayaniklilik = DegerAtama.Next(70, 100);
            Pas = DegerAtama.Next(70, 100);
            Sut = DegerAtama.Next(70, 100);
            Yetenek = DegerAtama.Next(70, 100);
            Kararlilik = DegerAtama.Next(70, 100);
            DogalForm = DegerAtama.Next(70, 100);
            Sans = DegerAtama.Next(70, 100);
            Bitiricilik = DegerAtama.Next(70, 100);
            IlkDokunus = DegerAtama.Next(70, 100);
            Kafa = DegerAtama.Next(70, 100);
            OzelYetenek = DegerAtama.Next(70, 100);
            SogukKanlilik = DegerAtama.Next(70, 100);
        }

        //Futbolcu sınıfının kurucu fonksiyonunu temel alan Forvet sınıfının kurucu fonksiyonu tanımlanıyor.
        public Forvet(string ForvetAdSoyad, int ForvetFormaNo) : base(ForvetAdSoyad, ForvetFormaNo)
        {
            //DegerAta fonksiyonu çağrılıyor.
            DegerAta();
        }

        //Forvet sınıfının double değer döndüren PasVer metodu tanımlanıyor.
        public override double PasVer()
        {
            //PasSkor adlı değişken tanımlanıyor.
            double PasSkor;
            //Forvet sınıfının değişkenleri kullanılarak PasSkor değişkeni hesaplanıyor.
            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            //PasVer metodu PasSkoru değer olarak döndürüyor.
            return PasSkor;
        }

        //Forvet sınıfının double değer döndüren GolVurusu metodu tanımlanıyor.
        public override double GolVurusu()
        {
            //GolSkor adlı değişken tanımlanıyor.
            double GolSkor;
            //Forvet sınıfının değişkenlerini kullanılarak GolSkor değişkeni hesaplanıyor.
            GolSkor = Yetenek * 0.2 + OzelYetenek * 0.2 + Sut * 0.1 + Kafa * 0.1 + IlkDokunus * 0.1 + Bitiricilik * 0.1
            + SogukKanlilik * 0.1 + Kararlilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            //GolVurusu metodu GolSkoru değer olarak döndürüyor.
            return GolSkor;
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            //takim adlı Futbolcu sınıfını baz alan List oluşturuluyor.
            List<Futbolcu> takim = new List<Futbolcu>();

            //Takıma kaleci ekleniyor.
            takim.Add(new Futbolcu("Rui Patricio", 13));

            //Takıma defans oyuncuları ekleniyor.
            takim.Add(new Defans("Matt Doherty", 2));
            takim.Add(new Defans("Willy Boly", 15));
            takim.Add(new Defans("Conor Coady", 16));
            takim.Add(new Defans("Jonny Castro", 19));

            //Takıma orta saha oyuncuları ekleniyor.
            takim.Add(new OrtaSaha("Leander Dendoncker", 32));
            takim.Add(new OrtaSaha("Ruben Neves", 8));
            takim.Add(new OrtaSaha("Joao Moutinho", 28));
            takim.Add(new OrtaSaha("Romain Saiss", 27));

            //Takıma forvet oyuncuları ekleniyor.
            takim.Add(new Forvet("Raul Jimenez", 9));
            takim.Add(new Forvet("Diogo Jota", 18));

            //oyuncu adlı değişken tanımlanıyor.
            int oyuncu;
            //Rastgele oyuncu seçilmesini sağlayan rastgeleFutbolcu metodu tanımlanıyor.
            Random rastgeleFutbolcu = new Random();
            //pasAlan adlı değişken tanımlanıyor.
            int pasAlan = 100;

            //i 4'ten küçük oluncaya kadar i'yi arttır.
            for (int i = 0; i < 4; i++)
            {
                //Eğer pasAlan oyuncu seçilen oyuncunun forma numarasına eşitse döngüye girilir.
                do
                {
                    //Rastgele oyuncu seçiliyor.
                    oyuncu = rastgeleFutbolcu.Next(1, 11);
                } while (pasAlan == takim[oyuncu].FormaNo);

                //Eğer i 0'a eşitse
                if (i == 0)
                {
                    //Ekrana seçilen oyuncu yazdırılıyor.
                    Console.WriteLine(takim[oyuncu].FormaNo + " => " + takim[oyuncu].AdSoyad + " adlı oyuncu seçildi.");
                }

                //Eğer rastgele seçilen oyuncunun PasVer değeri 60'a küçük eşitse
                if (takim[oyuncu].PasVer() <= 60)
                {
                    //Rastgele seçilen oyuncunun pas veremediği ekrana yazdırılıyor.
                    Console.WriteLine(takim[oyuncu].FormaNo + " => " + takim[oyuncu].AdSoyad + " adlı oyuncu pası veremedi.");
                    break;
                }

                //Eğer rastgele seçilen oyuncunun PasVer değeri 60'a küçük eşit değilse
                else
                {
                    //i 2'ye küçük eşitse
                    if (i <= 2)
                    {
                        //Rastgele seçilen oyuncunun pas verdiği ekrana yazdırılıyor.
                        Console.WriteLine(takim[oyuncu].FormaNo + " => " + takim[oyuncu].AdSoyad + " adlı oyuncu pas verdi.");
                    }
                   
                    //i 2'ye küçük eşit değilse
                    else
                    {
                        //Eğer rastgele seçilen oyuncunun GolVurusu değeri 70'e küçük eşitse
                        if (takim[oyuncu].GolVurusu() <= 70)
                        {
                            //Rastgele seçilen oyuncunun golü atamadığı ekrana yazdırılıyor.
                            Console.WriteLine(takim[oyuncu].FormaNo + " => " + takim[oyuncu].AdSoyad + " adlı oyuncu golü kaçırdı.");
                            break;
                        }

                        //Eğer rastgele seçilen oyuncunun GolVurusu değeri 70'e küçük eşit değilse
                        else
                        {
                            //Rastgele seçilen oyuncunun golü attığı ekrana yazdırılıyor.
                            Console.WriteLine(takim[oyuncu].FormaNo + " => " + takim[oyuncu].AdSoyad + " adlı oyuncu golü attı.");
                            break;
                        }
                    }
                }
                //pasAlan değişkeni oyuncunun FormaNo'suna eşitleniyor.
                pasAlan = takim[oyuncu].FormaNo;
            }
            //Bir tuşa basılıncaya kadar çözümün açık kalmasını sağlayan fonksiyon yazılıyor.
            Console.ReadKey();
        }
    }
}