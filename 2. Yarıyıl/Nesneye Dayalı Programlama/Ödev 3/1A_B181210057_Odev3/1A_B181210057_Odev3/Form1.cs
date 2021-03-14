/****************************************************************************
**				SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**			    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**			    2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 3
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
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1A_B181210057_Odev3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //Değişkenler tanımlamıyor.
        public int Konum = -1;
        public bool Devam;
        public string GirilenMetin;
        public string carpi = "*";
        public string bol = "/";
        public string cikar = "-";
        public string topla = "+";

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Girilen metin textBox1'in textine eşitleniyor.
            GirilenMetin = textBox1.Text;
            //Eğer işaretçiler -1. indekstelerse
            if (GirilenMetin.IndexOf(bol) == -1 && GirilenMetin.IndexOf(cikar) == -1 && GirilenMetin.IndexOf(topla) == -1 &&
                GirilenMetin.IndexOf(carpi) == -1)
            {
                //Konum -1'e eşitleniyor.
                Konum = -1;
            }
            //Değilse
            else
            {
                //Konum 1'e eşitleniyor.
                Konum = 1;
            }


            if (Konum != -1)
            {
                for (int i = 0; i < GirilenMetin.Length; i++) //Çarpma ve Bölme işlemleri
                {
                    //Eğer girilen metnin indeksinde çarpı -1'den farklıysa
                    if (GirilenMetin.IndexOf(carpi) != -1)
                    {
                        //Eğer i. konumdan 1 ileriye kadar "*" varsa
                        if (GirilenMetin.Substring(i, 1) == "*")
                        {
                            //Değişkenler tanımlanıyor ve değer ataması yapılıyor.
                            int a = Convert.ToInt32(GirilenMetin.Substring(i - 1, 1));
                            int b = Convert.ToInt32(GirilenMetin.Substring(i + 1, 1));
                            string ReplaceMetin = (GirilenMetin.Substring(i - 1, 1) + GirilenMetin.Substring(i, 1)) + GirilenMetin.Substring(i + 1, 1);
                            int carpmaislemi = a * b;
                            GirilenMetin = GirilenMetin.Replace(ReplaceMetin, Convert.ToString(carpmaislemi));
                        }
                    }
                    //Eğer girilen metnin indeksinde bölü -1'den farklıysa
                    if (GirilenMetin.IndexOf(bol) != -1)
                    {
                        //Eğer i. konumdan 1 ileriye kadar "/" varsa
                        if (GirilenMetin.Substring(i, 1) == "/")
                        {
                            //Değişkenler tanımlanıyor ve değer ataması yapılıyor.
                            int a = Convert.ToInt32(GirilenMetin.Substring(i - 1, 1));
                            int b = Convert.ToInt32(GirilenMetin.Substring(i + 1, 1));
                            string ReplaceMetin = (GirilenMetin.Substring(i - 1, 1) + GirilenMetin.Substring(i, 1)) + GirilenMetin.Substring(i + 1, 1);
                            int bolmeislemi = a / b;
                            GirilenMetin = GirilenMetin.Replace(ReplaceMetin, Convert.ToString(bolmeislemi));
                        }
                    }
                }


                for (int i = 0; i < GirilenMetin.Length; i++)//Toplama ve Çıkarma işlemleri
                {
                    //Eğer girilen metnin indeksinde topla -1'den farklıysa
                    if (GirilenMetin.IndexOf(topla) != -1)
                    {
                        //Eğer i. konumdan 1 ileriye kadar "+" varsa
                        if (GirilenMetin.Substring(i, 1) == "+")
                        {
                            //Değişkenler tanımlanıyor ve değer ataması yapılıyor.
                            int a = Convert.ToInt32(GirilenMetin.Substring(i - 1, 1));
                            int b = Convert.ToInt32(GirilenMetin.Substring(i + 1, 1));
                            string ReplaceMetin = (GirilenMetin.Substring(i - 1, 1) + GirilenMetin.Substring(i, 1)) + GirilenMetin.Substring(i + 1, 1);
                            int toplamaislemi = a + b;
                            GirilenMetin = GirilenMetin.Replace(ReplaceMetin, Convert.ToString(toplamaislemi));
                        }
                    }
                    //Eğer girilen metnin indeksinde çıkar -1'den farklıysa
                    if (GirilenMetin.IndexOf(cikar) != -1)
                    {
                        //Eğer i. konumdan 1 ileriye kadar "-" varsa
                        if (GirilenMetin.Substring(i, 1) == "-")
                        {
                            //Değişkenler tanımlanıyor ve değer ataması yapılıyor.
                            int a = Convert.ToInt32(GirilenMetin.Substring(i - 1, 1));
                            int b = Convert.ToInt32(GirilenMetin.Substring(i + 1, 1));
                            string ReplaceMetin = (GirilenMetin.Substring(i - 1, 1) + GirilenMetin.Substring(i, 1)) + GirilenMetin.Substring(i + 1, 1);
                            int cikarmaislemi = a - b;
                            GirilenMetin = GirilenMetin.Replace(ReplaceMetin, Convert.ToString(cikarmaislemi));
                        }
                    }
                }
                //textBox2'nin texti girilen metne eşitleniyor.
                textBox2.Text = GirilenMetin;
            }
            //Değilse
            else
            {
                MessageBox.Show("4 işlem yapılacak bir ifade girmediniz.");
                textBox2.Text = GirilenMetin.ToString();
            }
        }
    }
}
