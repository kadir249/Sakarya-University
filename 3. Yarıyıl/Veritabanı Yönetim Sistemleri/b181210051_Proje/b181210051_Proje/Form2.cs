using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Npgsql;

namespace b181210051_Proje
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        NpgsqlConnection baglanti = new NpgsqlConnection("Server=localhost; Port=5432; Database=Proje; User Id=postgres; Password=20006757");
        DataSet veriDuzenleme = new DataSet();
        int sira = 0;
        int toplamFiyat = 0;

        private void Form2_Load(object sender, EventArgs e)
        {
            baglanti.Open();
            string sql = "SELECT \"oyunID\", \"adi\", \"cikisTarihi\", \"fiyati\", \"adedi\", \"aciklamasi\", \"resmi\" FROM public.\"Oyun\"";
            NpgsqlDataAdapter ekle = new NpgsqlDataAdapter(sql, baglanti);
            ekle.Fill(veriDuzenleme);
            dataGridView1.DataSource = veriDuzenleme.Tables[0];
            baglanti.Close();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            int secilen = dataGridView1.SelectedCells[0].RowIndex;
            string oyunId = dataGridView1.SelectedCells[0].Value.ToString();
            string oyunAdi = dataGridView1.Rows[secilen].Cells[1].Value.ToString();
            string cikisTarihi = dataGridView1.Rows[secilen].Cells[2].Value.ToString();
            string fiyat = dataGridView1.Rows[secilen].Cells[3].Value.ToString();
            string adedi = dataGridView1.Rows[secilen].Cells[4].Value.ToString();
            string aciklamasi = dataGridView1.Rows[secilen].Cells[5].Value.ToString();
            string resim = dataGridView1.Rows[secilen].Cells[6].Value.ToString();

            textBox1.Text = oyunAdi;
            textBox2.Text = cikisTarihi;
            textBox3.Text = fiyat;
            textBox4.Text = adedi;
            richTextBox1.Text = aciklamasi;
            pictureBox1.ImageLocation = resim;
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            sira++;
            string[] elemanDizisi = new string[3];
            ListViewItem item;
            elemanDizisi[0] = Convert.ToString(sira);
            elemanDizisi[1] = textBox1.Text;
            elemanDizisi[2] = textBox3.Text;
            toplamFiyat += Convert.ToInt32(elemanDizisi[2]);
            item = new ListViewItem(elemanDizisi);
            listView1.Items.Add(item);
            label4.Text = Convert.ToString(sira);
            label10.Text = Convert.ToString(toplamFiyat);
        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            foreach(ListViewItem seciliKayit in listView1.CheckedItems)
            {
                seciliKayit.Remove();
                sira--;
                toplamFiyat -= Convert.ToInt32(seciliKayit.SubItems[2].Text);
                label4.Text = Convert.ToString(sira);
                label10.Text = Convert.ToString(toplamFiyat);
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
            MessageBox.Show("Oyun satın alma işleminiz başarıyla gerçekleşmiştir. Lütfen e-posta gelen kutunuzu kontrol ediniz.");
            sira = 0;
            label4.Text = Convert.ToString(sira);
            toplamFiyat = 0;
            label10.Text = Convert.ToString(toplamFiyat);
        }
    }
}
