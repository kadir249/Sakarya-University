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
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1A_B181210057_Proje
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //Değişkenler tanımlanıyor.
        public int toplamKazanc;
        public int gecenSure = 0;

        //Tanımlandıkları sınıfın özelliklerini baz alan elemanlar tanımlanıyor.
        Tavuk tavuk = new Tavuk();
        Ordek ordek = new Ordek();
        Inek inek = new Inek();
        Keci keci = new Keci();

        private void Form1_Load(object sender, EventArgs e)
        {
            //Ekrana pictureBox1'de tavuk resminin çıkması için gerekli komutlar yazılıyor.
            pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.Image = Image.FromFile("Hayvan Ciftligi Dosyalar\\tavuk.png");

            //Ekrana pictureBox2'de ördek resminin çıkması için gerekli komutlar yazılıyor.
            pictureBox2.SizeMode = PictureBoxSizeMode.AutoSize;
            pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox2.Image = Image.FromFile("Hayvan Ciftligi Dosyalar\\ordek.png");

            //Ekrana pictureBox3'te inek resminin çıkması için gerekli komutlar yazılıyor.
            pictureBox3.SizeMode = PictureBoxSizeMode.AutoSize;
            pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.Image = Image.FromFile("Hayvan Ciftligi Dosyalar\\inek.png");

            //Ekrana pictureBox4'te keçi resminin çıkması için gerekli komutlar yazılıyor.
            pictureBox4.SizeMode = PictureBoxSizeMode.AutoSize;
            pictureBox4.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox4.Image = Image.FromFile("Hayvan Ciftligi Dosyalar\\keci.png");

            //timer1'in sayacı tanımlanıyor ve timer1 başlatılıyor.
            timer1.Interval = 1000;
            timer1.Enabled = true;
            timer1.Start();

            //timer2'nin sayacı tanımlanıyor ve timer2 başlatılıyor.
            timer2.Interval = 3000;
            timer2.Enabled = true;
            timer2.Start();

            //timer3'ün sayacı tanımlanıyor ve timer3 başlatılıyor.
            timer3.Interval = 5000;
            timer3.Enabled = true;
            timer3.Start();

            //timer4'ün sayacı tanımlanıyor ve timer4 başlatılıyor.
            timer4.Interval = 8000;
            timer4.Enabled = true;
            timer4.Start();

            //timer5'in sayacı tanımlanıyor ve timer5 başlatılıyor.
            timer5.Interval = 7000;
            timer5.Enabled = true;
            timer5.Start();

            //tavuk elemanın değişkenlerine ilk değer ataması yapılıyor.
            tavuk.TavukSaniye = 0;
            tavuk.BirimFiyat = 1;
            tavuk.Enerji = 100;
            //progressBar1'in değeri tavuk.Enerji'ye eşitleniyor.
            progressBar1.Value = tavuk.Enerji;

            //ordek elemanın değişkenlerine ilk değer ataması yapılıyor.
            ordek.OrdekSaniye = 0;
            ordek.BirimFiyat = 3;
            ordek.Enerji = 100;
            //progressBar2'nin değeri ordek.Enerji'ye eşitleniyor.
            progressBar2.Value = ordek.Enerji;

            //inek elemanın değişkenlerine ilk değer ataması yapılıyor.
            inek.InekSaniye = 0;
            inek.BirimFiyat = 5;
            inek.Enerji = 100;
            //progressBar3'ün değeri inek.Enerji'ye eşitleniyor.
            progressBar3.Value = inek.Enerji;

            //keci elemanın değişkenlerine ilk değer ataması yapılıyor.
            keci.KeciSaniye = 0;
            keci.BirimFiyat = 8;
            keci.Enerji = 100;
            //progressBar4'ün değeri keci.Enerji'ye eşitleniyor.
            progressBar4.Value = keci.Enerji;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //Elemanların azalma miktarları atanıyor.
            tavuk.AzalmaMiktari = 2;
            ordek.AzalmaMiktari = 3;
            inek.AzalmaMiktari = 8;
            keci.AzalmaMiktari = 6;

            //gecenSure birer birer arttırılıyor.
            gecenSure++;
            //label29'un textinde gecenSure yazdırılıyor.
            label29.Text = Convert.ToString(gecenSure);

            //Eğer progressBar1'in değeri 2'den büyükse
            if (progressBar1.Value > 2)
            {
                //progressBar1'in değeri tavuk.EnerjiAzalt'a eşitleniyor.
                progressBar1.Value = tavuk.EnerjiAzalt();
                
                //Eğer progressBar1'in değeri 2'ye küçük eşitse
                if (progressBar1.Value <= 2)
                {
                    //progressBar1'in değeri 0'a eşitleniyor.
                    progressBar1.Value = 0;
                    //progressBar1'e erişilebilirlik kapatılıyor.
                    progressBar1.Enabled = false;
                    //label17'nin textinde "ÖLDÜ" yazıyor.
                    label17.Text = "ÖLDÜ";
                    //timer2 durduruluyor.
                    timer2.Stop();

                    //Tavuk ölünce tavuk sesinin çıkmasını sağlayan komutlar yazılıyor.
                    SoundPlayer ses = new SoundPlayer();
                    tavuk.TavukSesi = "Hayvan Ciftligi Dosyalar\\tavuk.wav";
                    ses.SoundLocation = tavuk.TavukSesi;
                    ses.Play();
                }
            }

            //Eğer progressBar2'nin değeri 3'e büyük eşitse
            if (progressBar2.Value >= 3)
            {
                //progressBar2'nin değeri ordek.EnerjiAzalt'a eşitleniyor.
                progressBar2.Value = ordek.EnerjiAzalt();

                //Eğer progressBar1'in değeri 3'ten küçükse
                if (progressBar2.Value < 3)
                {
                    //progressBar2'nin değeri 0'a eşitleniyor.
                    progressBar2.Value = 0;
                    //progressBar2'ye erişilebilirlik kapatılıyor.
                    progressBar2.Enabled = false;
                    //label18'in textinde "ÖLDÜ" yazıyor.
                    label18.Text = "ÖLDÜ";
                    //timer3 durduruluyor.
                    timer3.Stop();

                    //Ördek ölünce ördek sesinin çıkmasını sağlayan komutlar yazılıyor.
                    SoundPlayer ses = new SoundPlayer();
                    ordek.OrdekSesi = "Hayvan Ciftligi Dosyalar\\ordek.wav";
                    ses.SoundLocation = ordek.OrdekSesi;
                    ses.Play();
                }
            }

            //Eğer progressBar3'ün değeri 8'e büyük eşitse
            if (progressBar3.Value >= 8)
            {
                //progressBar3'ün değeri inek.EnerjiAzalt'a eşitleniyor.
                progressBar3.Value = inek.EnerjiAzalt();

                //Eğer progressBar3'ün değeri 8'den küçükse
                if (progressBar3.Value < 8)
                {
                    //progressBar3'ün değeri 0'a eşitleniyor.
                    progressBar3.Value = 0;
                    //progressBar3'e erişilebilirlik kapatılıyor.
                    progressBar3.Enabled = false;
                    //label19'un textinde "ÖLDÜ" yazıyor.
                    label19.Text = "ÖLDÜ";
                    //timer4 durduruluyor.
                    timer4.Stop();

                    //İnek ölünce inek sesinin çıkmasını sağlayan komutlar yazılıyor.
                    SoundPlayer ses = new SoundPlayer();
                    inek.InekSesi = "Hayvan Ciftligi Dosyalar\\inek.wav";
                    ses.SoundLocation = inek.InekSesi;
                    ses.Play();
                }
            }

            //Eğer progressBar4'ün değeri 6'ya büyük eşitse
            if (progressBar4.Value >= 6)
            {
                //progressBar4'ün değeri inek.EnerjiAzalt'a eşitleniyor.
                progressBar4.Value = keci.EnerjiAzalt();

                //Eğer progressBar4'ün değeri 6'dan küçükse
                if (progressBar4.Value < 6)
                {
                    //progressBar4'ün değeri 0'a eşitleniyor.
                    progressBar4.Value = 0;
                    //progressBar4'e erişilebilirlik kapatılıyor.
                    progressBar4.Enabled = false;
                    //label20'nin textinde "ÖLDÜ" yazıyor.
                    label20.Text = "ÖLDÜ";
                    //timer5 durduruluyor.
                    timer5.Stop();

                    //Keçi ölünce keçi sesinin çıkmasını sağlayan komutlar yazılıyor.
                    SoundPlayer ses = new SoundPlayer();
                    keci.KeciSesi = "Hayvan Ciftligi Dosyalar\\keci.wav";
                    ses.SoundLocation = keci.KeciSesi;
                    ses.Play();
                }
            }

            //Eğer label17, label18, label19 ve label20'nin textlerinde "ÖLDÜ" yazıyorsa
            if (label17.Text == "ÖLDÜ" && label18.Text == "ÖLDÜ" && label19.Text == "ÖLDÜ" && label20.Text == "ÖLDÜ")
            {
                //timer1 durduruluyor.
                timer1.Stop();
            }
        }

        private void label22_Click(object sender, EventArgs e)
        {

        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            //tavuk.TavukSaniye birer birer arttırılıyor.
            tavuk.TavukSaniye++;
            //label21'in textine tavuk.TavukSaniyenin değeri yazdırılıyor.
            label21.Text = Convert.ToString(tavuk.TavukSaniye);
        }

        private void timer3_Tick(object sender, EventArgs e)
        {
            //ordek.OrdekSaniye birer birer arttırılıyor.
            ordek.OrdekSaniye++;
            //label25'in textine ordek.OrdekSaniyenin değeri yazdırılıyor.
            label25.Text = Convert.ToString(ordek.OrdekSaniye);

        }

        private void timer4_Tick(object sender, EventArgs e)
        {
            //inek.InekSaniye birer birer arttırılıyor.
            inek.InekSaniye++;
            //label23'ün textine inek.InekSaniyenin değeri yazdırılıyor.
            label23.Text = Convert.ToString(inek.InekSaniye);
        }

        private void timer5_Tick(object sender, EventArgs e)
        {
            //keci.KeciSaniye birer birer arttırılıyor.
            keci.KeciSaniye++;
            //label28'in textine keci.KeciSaniyenin değeri yazdırılıyor.
            label28.Text = Convert.ToString(keci.KeciSaniye);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //tavuk.Adet'in değeri label21.text'in değerine eşitleniyor.
            tavuk.Adet = Convert.ToInt32(label21.Text);
            //tavuk.KazancHesapla fonksiyonu çağırılıyor.
            tavuk.KazancHesapla();
            //toplamKazanc toplanarak tavuk.KazancHesapla'ya eşitleniyor.
            toplamKazanc += tavuk.KazancHesapla();
            //label31'in textine toplamKazanc yazdırılıyor.
            label31.Text = Convert.ToString(toplamKazanc);
            //tavuk.TavukSaniye 0'a eşitleniyor.
            tavuk.TavukSaniye = 0;
            //tavuk.Adet 0'a eşitleniyor.
            tavuk.Adet = 0;
            //label21'in textine tavuk.Adet'in değeri yazdırılıyor.
            label21.Text = Convert.ToString(tavuk.Adet);

            //Eğer label17'nin texti "ÖLDÜ"yse
            if (label17.Text == "ÖLDÜ")
            {
                //label21'in textine "0" yazdırılıyor.
                label21.Text = "0";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //ordek.Adet'in değeri label25.text'in değerine eşitleniyor.
            ordek.Adet = Convert.ToInt32(label25.Text);
            //ordek.KazancHesapla fonksiyonu çağırılıyor.
            ordek.KazancHesapla();
            //toplamKazanc toplanarak ordek.KazancHesapla'ya eşitleniyor.
            toplamKazanc += ordek.KazancHesapla();
            //label31'in textine toplamKazanc yazdırılıyor.
            label31.Text = Convert.ToString(toplamKazanc);
            //ordek.OrdekSaniye 0'a eşitleniyor.
            ordek.OrdekSaniye = 0;
            //ordek.Adet 0'a eşitleniyor.
            ordek.Adet = 0;
            //label25'in textine ordek.Adet'in değeri yazdırılıyor.
            label25.Text = Convert.ToString(ordek.Adet);

            //Eğer label18'in texti "ÖLDÜ"yse
            if (label18.Text == "ÖLDÜ")
            {
                //label25'in textine "0" yazdırılıyor.
                label25.Text = "0";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //inek.Kilogram'ın değeri label23.text'in değerine eşitleniyor.
            inek.Kilogram = Convert.ToInt32(label23.Text);
            //inek.KazancHesapla fonksiyonu çağırılıyor.
            inek.KazancHesapla();
            //toplamKazanc toplanarak inek.KazancHesapla'ya eşitleniyor.
            toplamKazanc += inek.KazancHesapla();
            //label31'in textine toplamKazanc yazdırılıyor.
            label31.Text = Convert.ToString(toplamKazanc);
            //inek.InekSaniye 0'a eşitleniyor.
            inek.InekSaniye = 0;
            //inek.Kilogram 0'a eşitleniyor.
            inek.Kilogram = 0;
            //label23'ün textine inek.Kilogram'ın değeri yazdırılıyor.
            label23.Text = Convert.ToString(inek.Kilogram);

            //Eğer label19'un texti "ÖLDÜ"yse
            if (label19.Text == "ÖLDÜ")
            {
                //label23'ün textine "0" yazdırılıyor.
                label23.Text = "0";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //keci.Kilogram'ın değeri label28.text'in değerine eşitleniyor.
            keci.Kilogram = Convert.ToInt32(label28.Text);
            //keci.KazancHesapla fonksiyonu çağırılıyor.
            keci.KazancHesapla();
            //toplamKazanc toplanarak keci.KazancHesapla'ya eşitleniyor.
            toplamKazanc += keci.KazancHesapla();
            //label31'in textine toplamKazanc yazdırılıyor.
            label31.Text = Convert.ToString(toplamKazanc);
            //keci.KeciSaniye 0'a eşitleniyor.
            keci.KeciSaniye = 0;
            //keci.Kilogram 0'a eşitleniyor.
            keci.Kilogram = 0;
            //label28'in textine keci.Kilogram'ın değeri yazdırılıyor.
            label28.Text = Convert.ToString(keci.Kilogram);

            //Eğer label20'nin texti "ÖLDÜ"yse
            if (label20.Text == "ÖLDÜ")
            {
                //label28'in textine "0" yazdırılıyor.
                label28.Text = "0";
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //Eğer label17'nin texti "CANLI"ysa
            if (label17.Text == "CANLI")
            {
                //tavuk.Enerji 100'e eşitleniyor.
                tavuk.Enerji = 100;
                //progressBar1'in değeri tavuk.Enerji'ye eşitleniyor.
                progressBar1.Value = tavuk.Enerji;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            //Eğer label18'in texti "CANLI"ysa
            if (label18.Text == "CANLI")
            {
                //ordek.Enerji 100'e eşitleniyor.
                ordek.Enerji = 100;
                //progressBar2'nin değeri ordek.Enerji'ye eşitleniyor.
                progressBar2.Value = ordek.Enerji;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            //Eğer label19'un texti "CANLI"ysa
            if (label19.Text == "CANLI")
            {
                //inek.Enerji 100'e eşitleniyor.
                inek.Enerji = 100;
                //progressBar3'ün değeri inek.Enerji'ye eşitleniyor.
                progressBar3.Value = inek.Enerji;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            //Eğer label20'nin texti "CANLI"ysa
            if (label20.Text == "CANLI")
            {
                //keci.Enerji 100'e eşitleniyor.
                keci.Enerji = 100;
                //progressBar4'ün değeri keci.Enerji'ye eşitleniyor.
                progressBar4.Value = keci.Enerji;
            }
        }
    }
}