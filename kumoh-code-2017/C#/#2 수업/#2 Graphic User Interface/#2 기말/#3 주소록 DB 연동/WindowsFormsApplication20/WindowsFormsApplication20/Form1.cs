using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace WindowsFormsApplication20
{
    public partial class Form1 : Form
    {
        MySqlConnection conn;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            string strConn = "Server=202.31.202.151;Port=3306;Database=address_book;Uid=root;Pwd=root;";
            //string strConn = "Server=localhost;Port=3306;Database=address_book;Uid=root;Pwd=****";

            conn = new MySqlConnection(strConn);
            conn.Open();

            MySqlCommand selectCommand = new MySqlCommand();
            selectCommand.Connection = conn;
            selectCommand.CommandText = "Select * from address";

            MySqlDataReader rdr = selectCommand.ExecuteReader();
            while (rdr.Read())
            {
                listBox1.Items.Add(rdr[0].ToString() + "" + rdr[1].ToString() + "" + rdr[2].ToString() + "" + rdr[3].ToString());
            }
            rdr.Close();

            MessageBox.Show("DB 연결 성공");
        }

        private void disconnectButton_Click(object sender, EventArgs e)
        {
            conn.Close();
            MessageBox.Show("DB 해제 성공");
        }

        private void sendButton_Click(object sender, EventArgs e)
        {
            MySqlCommand insertCommand = new MySqlCommand();

            insertCommand.Connection = conn;
            insertCommand.CommandText = comboBox1.Text;
            insertCommand.ExecuteNonQuery();
        }

        private void clearButton_Click(object sender, EventArgs e)
        {

            listBox1.Items.Clear();
            comboBox1.Items.Add(comboBox1.Text);

            if (comboBox1.Text[0] == 'S' || comboBox1.Text[0] == 's')
            {
                MySqlCommand selectCommand = new MySqlCommand();
                selectCommand.Connection = conn;
                selectCommand.CommandText = comboBox1.Text;

                MySqlDataReader rdr = selectCommand.ExecuteReader();
                while (rdr.Read())
                {
                    listBox1.Items.Add(rdr[0].ToString() + "" + rdr[1].ToString() + "" + rdr[2].ToString() + "" + rdr[3].ToString());
                }
                rdr.Close();
            }
            else
            {
                MySqlCommand insertCommand = new MySqlCommand();

                insertCommand.Connection = conn;
                insertCommand.CommandText = comboBox1.Text;
                insertCommand.ExecuteNonQuery();

                MySqlCommand selectCommand = new MySqlCommand();
                selectCommand.Connection = conn;
                selectCommand.CommandText = "Select * from address";

                MySqlDataReader rdr = selectCommand.ExecuteReader();

                while (rdr.Read())
                {
                    listBox1.Items.Add(rdr[0].ToString() + "" + rdr[1].ToString() + "" + rdr[2].ToString() + "" + rdr[3].ToString());
                }
                rdr.Close();
            }
        }

        private void datasetButton_Click(object sender, EventArgs e)
        {
            string sql = "SELECT * FROM address ORDER BY Name";

            MySqlDataAdapter DBAdapter = new MySqlDataAdapter(sql, conn);

            DataSet DS = new DataSet();
            DBAdapter.Fill(DS, "address");

            dataGridView1.DataSource = DS.Tables["address"].DefaultView;
        }
    }
}
