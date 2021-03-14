/****************************************************************************
**				SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**			    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**			    2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 1
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
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace _1A_B181210057_Odev1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //Değişkenler tanımlanıyor.
        public string tc;
        public string ad;
        public string soyad;
        public string yas;
        public string calismaSuresi;
        public string evlilikDurumu;
        public string esiCalisiyorMu;
        public string cocukSayisi;
        public string tabanMaas;
        public string makamTazminati;
        public string idariGorevTazminati;
        public string fazlaMesaiSaati;
        public string fazlaMesaiSaatiUcreti;
        public string vergiMatrahi;
        public string personelFotografi;

        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            //Eğer klavyeden sayılar girilirse textBox1'e girilen veriler yazdırılır. 
            if ((int)e.KeyChar >= 48 && (int)e.KeyChar <= 57 || (int)e.KeyChar == 8 || (int)e.KeyChar == 022)
            {
                e.Handled = false;
            }

            //Değilse ekrana MessageBox çıkar.
            else
            {
                e.Handled = true;
                MessageBox.Show("Uyarı! Sadece Sayı Giriniz!");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Dizi oluşturuluyor.
            string[] satirlar;
            
            //veriler.Text'deki bilgiler bir değişkene atılıyor.
            string hepsi = veriler.Text;
           
            //Dosya satırlara ayrılıyor.
            satirlar = hepsi.Split('\n');
            
            //Veriler satırlara ayrıştırılıyor.
            foreach (string s in satirlar) 
            {
                //Dizi tanımlanıyor ve bu dizinin içine verilerin satırlarındaki elemanlar atanıyor.
                string[] bilgiler = s.Split(' ');

                //Eğer bilgiler dizisinin ilk elemanı textBox1.Text'e eşitse veriler bilgiler dizisinin elemanlarına aktarılıyor.
                if (bilgiler[0] == textBox1.Text)
                {
                    tc = bilgiler[0];
                    ad = bilgiler[1];
                    soyad = bilgiler[2];
                    yas = bilgiler[3];
                    calismaSuresi = bilgiler[4];
                    evlilikDurumu = bilgiler[5];
                    esiCalisiyorMu = bilgiler[6];
                    cocukSayisi = bilgiler[7];
                    tabanMaas = bilgiler[8];
                    makamTazminati = bilgiler[9];
                    idariGorevTazminati = bilgiler[10];
                    fazlaMesaiSaati = bilgiler[11];
                    fazlaMesaiSaatiUcreti = bilgiler[12];
                    vergiMatrahi = bilgiler[13];
                    personelFotografi = bilgiler[14];
                }
            }

            //veriler.Text'ten alınan bilgiler label'lara aktarılıyor.
            label20.Text = tc;
            label21.Text = ad;
            label22.Text = soyad;
            label23.Text = yas;
            label24.Text = calismaSuresi;
            label25.Text = evlilikDurumu;
            label26.Text = esiCalisiyorMu;
            label27.Text = cocukSayisi;
            label28.Text = tabanMaas;
            label29.Text = makamTazminati;
            label30.Text = idariGorevTazminati;
            label31.Text = fazlaMesaiSaati;
            label32.Text = fazlaMesaiSaatiUcreti;
            label33.Text = vergiMatrahi;

            //Değişkenler tanımlanıyor.
            int cocuks = Convert.ToInt32(label27.Text);
            double taban = Convert.ToDouble(label28.Text);
            double makam = Convert.ToDouble(label29.Text);
            double idari = Convert.ToDouble(label30.Text);
            double mesai = Convert.ToDouble(label31.Text);
            double mesaiucreti = Convert.ToDouble(label32.Text);
            double burutMaas;

            //Eğer kişi bekarsa gerekli bürüt maaş hesaplama yöntemi kullanılır.
            if (label25.Text == "B")
            {
                burutMaas = taban + makam + idari + (cocuks * 30) + (mesai * mesaiucreti);
                label34.Text = Convert.ToString(burutMaas);
            }

            //Eğer kişi evli ve eşi çalışıyorsa gerekli bürüt maaş hesaplama yöntemi kullanılır. 
            else if (label25.Text == "E" && label26.Text == "E")
            {
                burutMaas = taban + makam + idari + (cocuks * 30) + (mesai * mesaiucreti);
                label34.Text = Convert.ToString(burutMaas);
            }

            //Eğer kişi evli ve eşi çalışmıyorsa gerekli bürüt maaş hesaplama yöntemi kullanılır.
            else if (label25.Text == "E" && label26.Text == "H")
            {
                burutMaas = taban + makam + idari + 200 + (cocuks * 30) + (mesai * mesaiucreti);
                label34.Text = Convert.ToString(burutMaas);
            }

            //Bulunan bürüt maaş bir değişkene atanıyor.
            double burutMaasi = Convert.ToDouble(label34.Text);

            //Damga vergisi hesaplanıyor ve label'a yazdırılıyor.
            double damgaVergisi = (burutMaasi * 10) / 100;
            label35.Text = Convert.ToString(damgaVergisi);

            //Değişkenler tanımlanıyor.
            double vergiMatrah = Convert.ToDouble(label33.Text);
            double gelirVergisi;
            
            //Eğer vergiMatrahı 10000'den küçükse gerekli gelir vergisi hesaplama yöntemi kullanılır.
            if (vergiMatrah < 10000)
            {
                gelirVergisi = (burutMaasi * 15) / 100;
                label36.Text = Convert.ToString(gelirVergisi);
            }

            //Eğer vergi matrahı 10000'den büyük ve 20000'den küçükse gerekli gelir vergisi hesaplama yöntemi kullanılır.
            else if (vergiMatrah >= 10000 && vergiMatrah < 20000)
            {
                gelirVergisi = (burutMaasi * 20) / 100;
                label36.Text = Convert.ToString(gelirVergisi);
            }

            //Eğer vergi matrahı 20000'den büyük ve 30000'den küçükse gerekli gelir vergisi hesaplama yöntemi kullanılır.
            else if (vergiMatrah >= 20000 && vergiMatrah < 30000)
            {
                gelirVergisi = (burutMaasi * 25) / 100;
                label36.Text = Convert.ToString(gelirVergisi);
            }

            //Eğer vergiMatrahı 30000'den büyükse gerekli gelir vergisi hesaplama yöntemi kullanılır.
            else if (vergiMatrah >= 30000)
            {
                gelirVergisi = (burutMaasi * 30) / 100;
                label36.Text = Convert.ToString(gelirVergisi);
            }

            //Emekli kesintisi hesaplanıyor ve label'a yazdırılıyor.
            double emekliKesintisi = (burutMaasi * 15) / 100;
            label37.Text = Convert.ToString(emekliKesintisi);

            //Hesaplanan gelir vergisi bir değişkene atanıyor.
            double gelirVergi = Convert.ToDouble(label36.Text);

            //Net maaş hesaplanıyor ve label'a yazdırılıyor.
            double netMaas = burutMaasi - (emekliKesintisi + gelirVergi + damgaVergisi);
            label38.Text = Convert.ToString(netMaas);

            //Ekrana fotoğrafın çıkması için gerekli komutlar yazılıyor.
            pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.Image = Image.FromFile(personelFotografi);
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            //button3 butonuna basıldığında dosyayı açmak için kullanılan komut yazılıyor.
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                veriler.Text = File.ReadAllText(openFileDialog1.FileName, Encoding.GetEncoding("iso-8859-9"));
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //button4 butonuna basıldığında dosyaya veri kaydetmek için kullanılan komut yazılıyor.
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                File.WriteAllText(saveFileDialog1.FileName, veriler.Text, Encoding.GetEncoding("iso-8859-9"));
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
 
        }
    }
}