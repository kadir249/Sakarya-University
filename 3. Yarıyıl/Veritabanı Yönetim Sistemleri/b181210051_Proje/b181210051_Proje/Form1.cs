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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        NpgsqlConnection baglanti = new NpgsqlConnection("Server=localhost; Port=5432; Database=Proje; User Id=postgres; Password=20006757");

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 fr2 = new Form2();
            fr2.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            baglanti.Open();

            string sql1 = "SELECT * FROM kayitekle('" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "','" + textBox7.Text + "','" + textBox8.Text + "')"; 
            NpgsqlCommand cmd1 = new NpgsqlCommand(sql1, baglanti);
            cmd1.ExecuteNonQuery();

            string sql2 = "SELECT * FROM sepetolustur()";
            NpgsqlCommand cmd2 = new NpgsqlCommand(sql2, baglanti);
            cmd2.ExecuteNonQuery();

            baglanti.Close();
            MessageBox.Show("Kayıt Oldunuz");
        }
    }
}
