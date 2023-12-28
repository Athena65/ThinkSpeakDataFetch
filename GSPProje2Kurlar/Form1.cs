using System.IO.Ports;

namespace GSPProje2Kurlar
{
    public partial class Form1 : Form
    {
        SerialPort seri = new SerialPort();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            seri.BaudRate = 9600;
            seri.PortName = "COM3";
            try
            {
                seri.Open();
                lblHaberlesme.Text = "Arduino ile Baglanti Kuruldu";
                lblHaberlesme.BackColor = Color.Green;
                //Button textleri
                btnSeriClose.Text = "Seri Haberlesmeyi kapat";
                btnSeriOpen.Text = "Seri Haberlesmeyi aç";
                btnEUR.Text = "EUR-TL";
                btnUSD.Text = "Dolar-TL";
                btnAltin.Text = "Gram Altin-TL";
                btnGBP.Text = "Sterlin-TL";
            }
            catch (Exception ex)
            {
                lblHaberlesme.BackColor = Color.Red;
                lblHaberlesme.Text = ex.Message;
                MessageBox.Show(ex.Message);
            }
        }

        private void btnEUR_Click(object sender, EventArgs e)
        {
            btnEUR.Enabled = true;
            seri.Write("A");
        }

        private void btnGBP_Click(object sender, EventArgs e)
        {
            btnGBP.Enabled = true;
            seri.Write("B");
        }
        private void btnUSD_Click(object sender, EventArgs e)
        {
            btnUSD.Enabled = true;
            seri.Write("C");
        }
        private void btnAltin_Click(object sender, EventArgs e)
        {
            btnAltin.Enabled = true;
            seri.Write("D");
        }

        private void btnSeriOpen_Click(object sender, EventArgs e)
        {
            try
            {
                if (seri.IsOpen)
                {
                    lblHaberlesme.Text = "Seri Haberlesme zaten acik";
                }
                else
                {
                    seri.Open();
                    lblHaberlesme.Text = "Arduino ile Baglanti Tekrar Kuruldu";
                    lblHaberlesme.BackColor = Color.Green;
                    btnEUR.Visible = true;
                    btnUSD.Visible = true;
                    btnAltin.Visible = true;
                    btnGBP.Visible = true;
                }
            }
            catch (Exception ex)
            {
                lblHaberlesme.Text = ex.Message;
                MessageBox.Show(ex.Message);
            }

        }

        private void btnSeriClose_Click(object sender, EventArgs e)
        {
            try
            {
                seri.Close();
                lblHaberlesme.Text = "Arduino ile Baglanti Kesildi";
                lblHaberlesme.BackColor = Color.Red;
                //Button gorunurluk
                btnEUR.Visible = false;
                btnUSD.Visible = false;
                btnAltin.Visible = false;
                btnGBP.Visible = false;
            }
            catch (Exception ex)
            {
                lblHaberlesme.Text = ex.Message;
                MessageBox.Show(ex.Message);
            }
        }
    }
}