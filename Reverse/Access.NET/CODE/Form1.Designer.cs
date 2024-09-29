namespace LoginApp
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.TextBox txtUsername;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.Label lblMessage;
        private System.Windows.Forms.Label lblWelcome;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
void InitializeComponent()
{
    this.components = new System.ComponentModel.Container();
    this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
    this.ClientSize = new System.Drawing.Size(400, 200); // Adjusted for more space
    this.Text = "Login App";

    // Set background color to light pink
    this.BackColor = System.Drawing.Color.Pink;

    // Add a big welcome label
    this.lblWelcome = new System.Windows.Forms.Label();
    this.lblWelcome.AutoSize = true;
    this.lblWelcome.Location = new System.Drawing.Point(10, 10);
    this.lblWelcome.Font = new System.Drawing.Font("Poppins", 20, System.Drawing.FontStyle.Bold); // Poppins font, bold, size 20
    this.lblWelcome.Text = "Hi Friend!";
    this.lblWelcome.ForeColor = System.Drawing.Color.DarkMagenta; // Make it stand out with a cute color

    // txtUsername
    this.txtUsername = new System.Windows.Forms.TextBox();
    this.txtUsername.Location = new System.Drawing.Point(120, 70); // Adjusted to fit the welcome message
    this.txtUsername.Name = "txtUsername";
    this.txtUsername.Size = new System.Drawing.Size(150, 20);
    this.txtUsername.Font = new System.Drawing.Font("Poppins", 10); // Poppins font

    // txtPassword
    this.txtPassword = new System.Windows.Forms.TextBox();
    this.txtPassword.Location = new System.Drawing.Point(120, 100);
    this.txtPassword.Name = "txtPassword";
    this.txtPassword.Size = new System.Drawing.Size(150, 20);
    this.txtPassword.UseSystemPasswordChar = true;
    this.txtPassword.Font = new System.Drawing.Font("Poppins", 10); // Poppins font

    // btnLogin
    this.btnLogin = new System.Windows.Forms.Button();
    this.btnLogin.Location = new System.Drawing.Point(120, 130);
    this.btnLogin.Name = "btnLogin";
    this.btnLogin.Size = new System.Drawing.Size(70, 30);
    this.btnLogin.Text = "Login";
    this.btnLogin.BackColor = System.Drawing.Color.LightPink;
    this.btnLogin.Font = new System.Drawing.Font("Poppins", 9); // Poppins font
    this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);

    // lblMessage
    this.lblMessage = new System.Windows.Forms.Label();
    this.lblMessage.AutoSize = true;
    this.lblMessage.Location = new System.Drawing.Point(10, 170);
    this.lblMessage.Font = new System.Drawing.Font("Poppins", 9); // Poppins font

    // Labels for Username and Password
    this.label1 = new System.Windows.Forms.Label();
    this.label1.AutoSize = true;
    this.label1.Location = new System.Drawing.Point(10, 73);
    this.label1.Text = "Username:";
    this.label1.Font = new System.Drawing.Font("Poppins", 10); // Poppins font

    this.label2 = new System.Windows.Forms.Label();
    this.label2.AutoSize = true;
    this.label2.Location = new System.Drawing.Point(10, 103);
    this.label2.Text = "Password:";
    this.label2.Font = new System.Drawing.Font("Poppins", 10); // Poppins font

    // Form1
    this.Controls.Add(this.lblWelcome);
    this.Controls.Add(this.txtUsername);
    this.Controls.Add(this.txtPassword);
    this.Controls.Add(this.btnLogin);
    this.Controls.Add(this.lblMessage);
    this.Controls.Add(this.label1);
    this.Controls.Add(this.label2);
    this.ResumeLayout(false);
    this.PerformLayout();
}

        #endregion
    }
}