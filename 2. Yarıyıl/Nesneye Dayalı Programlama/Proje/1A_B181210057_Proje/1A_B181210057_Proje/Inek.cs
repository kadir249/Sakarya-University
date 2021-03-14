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
    //Inek isimli Hayvan abstract sınıfını ve IHayvan arayüzünü kalıtım alan sınıf tanımlanıyor.
    class Inek : Hayvan, IHayvan
    {
        //Inek sınıfının değişkenleri tanımlanıyor.
        public int Kilogram { get; set; }
        public int InekSaniye { get; set; }
        public string InekSesi { get; set; }

        //KazancHesapla adlı integer değer döndüren override fonksiyon oluşturuluyor.
        public override int KazancHesapla()
        {
            //kazanc adlı integer bir değişken tanımlanıyor. Bu değişkenin değeri Kilogram ve BirimFiyat'ın çarpımıyla hesaplanıyor.
            int kazanc = Kilogram * BirimFiyat;
            //Fonksiyon kazanc adlı değişkenin değerini döndürüyor.
            return kazanc;
        }

        //Integer değer döndüren EnerjiAzalt fonksiyonu tanımlanıyor.
        public int EnerjiAzalt()
        {
            //Enerjinin değeri Enerji'den AzalmaMiktari çıkartılarak hesaplanıyor.
            Enerji = Enerji - AzalmaMiktari;
            //Fonksiyon Enerji adlı değişkenin değerini döndürüyor.
            return Enerji;
        }
    }
}
