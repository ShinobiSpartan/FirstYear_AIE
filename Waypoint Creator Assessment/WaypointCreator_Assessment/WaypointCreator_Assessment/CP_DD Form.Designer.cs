namespace WaypointCreator_Assessment
{
    partial class CP_DD_Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tb_DD = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // tb_DD
            // 
            this.tb_DD.AllowDrop = true;
            this.tb_DD.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tb_DD.Location = new System.Drawing.Point(0, 0);
            this.tb_DD.Multiline = true;
            this.tb_DD.Name = "tb_DD";
            this.tb_DD.Size = new System.Drawing.Size(284, 268);
            this.tb_DD.TabIndex = 2;
            this.tb_DD.DragDrop += new System.Windows.Forms.DragEventHandler(this.tb_DD_DragDrop);
            this.tb_DD.DragEnter += new System.Windows.Forms.DragEventHandler(this.tb_DD_DragEnter);
            this.tb_DD.MouseDown += new System.Windows.Forms.MouseEventHandler(this.tb_DD_MouseDown);
            // 
            // CP_DD_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 268);
            this.Controls.Add(this.tb_DD);
            this.Name = "CP_DD_Form";
            this.Text = "CP_DD_Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox tb_DD;
    }
}