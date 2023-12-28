namespace GSPProje2Kurlar
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

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
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            lblHaberlesme = new Label();
            btnEUR = new Button();
            btnGBP = new Button();
            btnUSD = new Button();
            btnAltin = new Button();
            btnSeriClose = new Button();
            btnSeriOpen = new Button();
            SuspendLayout();
            // 
            // lblHaberlesme
            // 
            lblHaberlesme.AutoSize = true;
            lblHaberlesme.Location = new Point(320, 308);
            lblHaberlesme.Name = "lblHaberlesme";
            lblHaberlesme.Size = new Size(0, 20);
            lblHaberlesme.TabIndex = 0;
            // 
            // btnEUR
            // 
            btnEUR.Location = new Point(12, 259);
            btnEUR.Name = "btnEUR";
            btnEUR.Size = new Size(102, 29);
            btnEUR.TabIndex = 1;
            btnEUR.UseVisualStyleBackColor = true;
            btnEUR.Click += btnEUR_Click;
            // 
            // btnGBP
            // 
            btnGBP.Location = new Point(162, 259);
            btnGBP.Name = "btnGBP";
            btnGBP.Size = new Size(158, 29);
            btnGBP.TabIndex = 2;
            btnGBP.UseVisualStyleBackColor = true;
            btnGBP.Click += btnGBP_Click;
            // 
            // btnUSD
            // 
            btnUSD.Location = new Point(349, 259);
            btnUSD.Name = "btnUSD";
            btnUSD.Size = new Size(178, 29);
            btnUSD.TabIndex = 5;
            btnUSD.UseVisualStyleBackColor = true;
            btnUSD.Click += btnUSD_Click;
            // 
            // btnAltin
            // 
            btnAltin.Location = new Point(566, 259);
            btnAltin.Name = "btnAltin";
            btnAltin.Size = new Size(168, 29);
            btnAltin.TabIndex = 6;
            btnAltin.UseVisualStyleBackColor = true;
            btnAltin.Click += btnAltin_Click;
            // 
            // btnSeriClose
            // 
            btnSeriClose.Location = new Point(566, 365);
            btnSeriClose.Name = "btnSeriClose";
            btnSeriClose.Size = new Size(194, 29);
            btnSeriClose.TabIndex = 7;
            btnSeriClose.UseVisualStyleBackColor = true;
            btnSeriClose.Click += btnSeriClose_Click;
            // 
            // btnSeriOpen
            // 
            btnSeriOpen.Location = new Point(81, 365);
            btnSeriOpen.Name = "btnSeriOpen";
            btnSeriOpen.Size = new Size(156, 29);
            btnSeriOpen.TabIndex = 8;
            btnSeriOpen.UseVisualStyleBackColor = true;
            btnSeriOpen.Click += btnSeriOpen_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(800, 450);
            Controls.Add(btnSeriOpen);
            Controls.Add(btnSeriClose);
            Controls.Add(btnAltin);
            Controls.Add(btnUSD);
            Controls.Add(btnGBP);
            Controls.Add(btnEUR);
            Controls.Add(lblHaberlesme);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblHaberlesme;
        private Button btnEUR;
        private Button btnGBP;
        private Button btnUSD;
        private Button btnAltin;
        private Button btnSeriClose;
        private Button btnSeriOpen;
    }
}