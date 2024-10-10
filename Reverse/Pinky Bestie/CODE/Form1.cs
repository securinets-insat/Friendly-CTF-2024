using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Numerics;

namespace LoginApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            string username = txtUsername.Text;
            string password = txtPassword.Text;
            lblMessage.Text = "";

            if (check_username(username) && check_password(password)  )
            {
                string flag = "Securinets{" + username + '_' + password + "}";
                lblMessage.Text = "You have logged in successfully! Use the flag: " + flag + "}";
            }
            else
            {
                // lblMessage.Text = "Invalid username or password.";
            }
        }

        private List<string> GetHexa(string flag)
        {
            List<string> hexa = new List<string>();
            foreach (char c in flag)
            {
                BigInteger bigValue = new BigInteger(c);
                hexa.Add(bigValue.ToString("X")); 
            }
            return hexa;
        }

        private bool check_username(string username)
        {
            if(string.IsNullOrEmpty(username))
            {
                return false;
            }
            List<string> hexa = GetHexa(username);

            string validUsername = "Y0u_Th0uGhT_1t_Th3_U5eRn4m3";

            for (int i = 0; i < hexa.Count; i++)
            {
                int num = int.Parse(hexa[i], System.Globalization.NumberStyles.HexNumber);  
                BigInteger fibValue = GetFibonacci(num);
                hexa[i] = fibValue.ToString(); 
            }
            
            hexa = BigIntegerHelper.IntToHex(hexa.ConvertAll(BigInteger.Parse));

            for(int i = 0; i < hexa.Count; i++)
            {
                lblMessage.Text += hexa[i] + "\n";
            }

            List<string> value = new List<string> 
                { 
                    "1C5575E509F60", 
                    "11E8D0A40", 
                    "10BDC5FB88F7A983179C2", 
                    "755B0BDD8FA9946C1", 
                    "7AC0CA1E3" 
                };

            List<bool> boolList = transform(hexa, value);

            if (boolList.TrueForAll(x => x == true))
            {
                return true;
            }

            return false;
        }

        private bool check_password(string password)
        {
            if(string.IsNullOrEmpty(password))
            {
                return false;
            }
            List<string> hexa = GetHexa(password);

            string validPassword = "Y0u_Th0uGhT_1t_Wa5_Th3_Pa55w0rD";

            for (int i = 0; i < hexa.Count / 2; i++)
            {
                int numStart = int.Parse(hexa[i], System.Globalization.NumberStyles.HexNumber);  
                int numEnd = int.Parse(hexa[hexa.Count - i - 1], System.Globalization.NumberStyles.HexNumber);  
                BigInteger fibValueStart = GetFibonacci(numStart);
                BigInteger fibValueEnd = GetFibonacci(numEnd);
                hexa[i] = fibValueEnd.ToString();
                hexa[hexa.Count - i - 1] = fibValueStart.ToString();
            }

            hexa = BigIntegerHelper.IntToHex(hexa.ConvertAll(BigInteger.Parse));
            for(int i = 0; i < hexa.Count; i++)
            {
                lblMessage.Text += hexa[i] + "\n";
            }
            List<string> value = new List<string> 
                { 
                    "48879FAF5D0623241", 
                    "19438B44A658", 
                    "10BDC5FB88F7A983179C2", 
                    "0EED684CFE43B518EF62", 
                    "1CFA62F21", 
                    "1C5575E509F60", 
                    "7AC0CA1E3", 
                    "3861CA6EB3EE4626510" 
                };
            List<bool> boolList = transform(hexa, value);

            if (boolList.TrueForAll(x => x == true))
            {
                return true;
            }
           
            return false;
        }

        private BigInteger GetFibonacci(int n)
        {
            if (n < 0)
                return 0;
            if (n == 0) return 0;
            if (n == 1) return 1;
            BigInteger a = 0, b = 1;
            for (int j = 2; j <= n; j++)
            {
                BigInteger temp = a + b;
                a = b;
                b = temp;
            }
            return b ;  
        }

        private List<bool> transform(List<string> hexa, List<string> value)
        {
            List<bool> boolList = new List<bool>();
            try{
                for (int i = 0; i < hexa.Count; i++)
                {
                    BigInteger hexaValue = BigInteger.Parse(hexa[i], System.Globalization.NumberStyles.HexNumber);
                    BigInteger valueValue = BigInteger.Parse(value[i], System.Globalization.NumberStyles.HexNumber);
                    boolList.Add((hexaValue ^ valueValue) == 0);
                }
            }
            catch(Exception ex){
                lblMessage.Text += ex.Message;
                return new List<bool>() { false };
            }
            return boolList;
        }

    }
    public static class BigIntegerHelper
    {
        public static List<string> IntToHex(List<BigInteger> bigIntegers)
        {
            List<string> hexList = new List<string>();
            
            foreach (BigInteger number in bigIntegers)
            {
                string hexValue = number.ToString("X");
                hexList.Add(hexValue);
            }
            
            return hexList;
        }
    }


}
