using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace leito_de_caotao_de_asseso
{

    public partial class Form1 : Form
    {


        public Form1()
        {
            InitializeComponent();
        }


        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

            if (serialPort2.IsOpen == false)
            {
                try
                {
                    serialPort2.PortName = comboBox1.Items[comboBox1.SelectedIndex].ToString();
                    serialPort2.Open();

                }
                catch
                {
                    return;

                }
                if (serialPort2.IsOpen)
                {
                    button2.Text = "Desconectar";
                    comboBox1.Enabled = false;

                }
            }
            else
            {

                try
                {
                    serialPort2.Close();
                    comboBox1.Enabled = true;
                    button2.Text = "Conectar";
                }
                catch
                {
                    return;
                }

            }



        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {


        }
        int ftd = 0;
        int fff = 0;

        private void timer1_Tick(object sender, EventArgs e)
        {
            atualizarCOMS();


            if (serialPort2.IsOpen && fff == 1)
            {
                serialPort2.Write("g");
                textBox8.Text = serialPort2.ReadLine();
                textBox8.Enabled = false;
                textBox8.BackColor = Color.White;

                
                    ftd = 1;
                    fff = 0;
                

            }

             if (serialPort2.IsOpen && ftd == 1)
                {



                    serialPort2.Write("p");
                    textBox3.Text = serialPort2.ReadLine();
                    textBox3.Enabled = false;
                    textBox3.BackColor = Color.White;
                    serialPort2.Write("q");
                    textBox4.Text = serialPort2.ReadLine();
                    textBox4.Enabled= false;
                    textBox4.BackColor = Color.White;
                    serialPort2.Write("w");
                    textBox5.Text = serialPort2.ReadLine();
                    textBox5.Enabled = false;
                    textBox5.BackColor = Color.White;
                    serialPort2.Write("e");
                    textBox6.Text = serialPort2.ReadLine();
                    textBox6.Enabled = false;
                    textBox6.BackColor = Color.White;
                    serialPort2.Write("r");
                    textBox7.Text = serialPort2.ReadLine();
                    textBox7.Enabled = false;
                    textBox7.BackColor = Color.White;
                    ftd = 0;

                }







        }

    


           

        
        void atualizarCOMS()
        {

            int i;
            bool quantDiferente;    //flag para sinalizar que a quantidade de portas mudou

            i = 0;
            quantDiferente = false;

            //se a quantidade de portas mudou
            if (comboBox1.Items.Count == SerialPort.GetPortNames().Length)
            {
                foreach (string s in SerialPort.GetPortNames())
                {
                    if (comboBox1.Items[i++].Equals(s) == false)
                    {
                        quantDiferente = true;
                    }
                }
            }
            else
            {
                quantDiferente = true;
            }

            //Se não foi detectado diferença
            if (quantDiferente == false)
            {
                return;                     //retorna
            }

            //limpa comboBox
            comboBox1.Items.Clear();

            //adiciona todas as COM diponíveis na lista
            foreach (string s in SerialPort.GetPortNames())
            {
                comboBox1.Items.Add(s);
            }
            //seleciona a primeira posição da lista
            comboBox1.SelectedIndex = 0;

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            

            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";

            textBox6.Text = "";

            textBox7.Text = "";
            
          
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // ftd = 1;
          
            fff = 1;
          
          

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }
    }
    
}