/****************************************************************************
**				SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**			    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**			    2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: Proje
**				ÖĞRENCİ ADI............: Kadir Çelik
**				ÖĞRENCİ NUMARASI.......: B181210057
**              DERSİN ALINDIĞI GRUP...: 1A
****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1A_B181210057_Proje
{
    //Hayvan isimli bir abstract sınıf tanımlanıyor.
    abstract class Hayvan
    {
        //Hayvan sınıfının değişkenleri tanımlanıyor.
        public int Enerji { get; set; }
        public int BirimFiyat { get; set; }
        public int Adet { get; set; }
        public int AzalmaMiktari { get; set; }

        //KazancHesapla adlı integer değer döndüren virtual fonksiyon oluşturuluyor.
        public virtual int KazancHesapla()
        {
            //kazanc adlı integer bir değişken tanımlanıyor. Bu değişkenin değeri Adet ve BirimFiyat'ın çarpımıyla hesaplanıyor.
            int kazanc = Adet * BirimFiyat;
            //Fonksiyon kazanc adlı değişkenin değerini döndürüyor.
            return kazanc;
        }
    }

    //IHayvan adlı interface(arayüz) tanımlanıyor.
    public interface IHayvan
    {
        //IHayvan arayüzünün integer değer döndüren EnerjiAzalt fonksiyonu tanımlanıyor.
        int EnerjiAzalt();
    }
}
