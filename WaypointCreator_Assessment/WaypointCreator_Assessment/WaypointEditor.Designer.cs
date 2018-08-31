namespace WaypointCreator_Assessment
{
    partial class WaypointEditor
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
            this.components = new System.ComponentModel.Container();
            this.pb_Map = new System.Windows.Forms.PictureBox();
            this.btn_MapImport = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txt_GridWidth = new System.Windows.Forms.TextBox();
            this.txt_GridHeight = new System.Windows.Forms.TextBox();
            this.btn_GenGrid = new System.Windows.Forms.Button();
            this.gb_Waypoints = new System.Windows.Forms.GroupBox();
            this.dgv_Waypoints = new System.Windows.Forms.DataGridView();
            this.lbl_currentX = new System.Windows.Forms.Label();
            this.lbl_currentY = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btn_AddWaypoint = new System.Windows.Forms.Button();
            this.gb_GridSettings = new System.Windows.Forms.GroupBox();
            this.btn_RemGrid = new System.Windows.Forms.Button();
            this.gb_MapSettings = new System.Windows.Forms.GroupBox();
            this.btn_MapRemove = new System.Windows.Forms.Button();
            this.gb_Save = new System.Windows.Forms.GroupBox();
            this.rb_BinaryS = new System.Windows.Forms.RadioButton();
            this.rb_xmlS = new System.Windows.Forms.RadioButton();
            this.btn_SaveWaypoints = new System.Windows.Forms.Button();
            this.btn_LoadWaypoints = new System.Windows.Forms.Button();
            this.gb_Load = new System.Windows.Forms.GroupBox();
            this.rb_BinaryL = new System.Windows.Forms.RadioButton();
            this.rb_xmlL = new System.Windows.Forms.RadioButton();
            this.wayPointLocationBindingSource = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pb_Map)).BeginInit();
            this.gb_Waypoints.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgv_Waypoints)).BeginInit();
            this.gb_GridSettings.SuspendLayout();
            this.gb_MapSettings.SuspendLayout();
            this.gb_Save.SuspendLayout();
            this.gb_Load.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.wayPointLocationBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // pb_Map
            // 
            this.pb_Map.BackColor = System.Drawing.Color.White;
            this.pb_Map.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pb_Map.Cursor = System.Windows.Forms.Cursors.Default;
            this.pb_Map.Enabled = false;
            this.pb_Map.Location = new System.Drawing.Point(12, 12);
            this.pb_Map.Name = "pb_Map";
            this.pb_Map.Size = new System.Drawing.Size(849, 481);
            this.pb_Map.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb_Map.TabIndex = 0;
            this.pb_Map.TabStop = false;
            this.pb_Map.Click += new System.EventHandler(this.pb_Map_Click);
            // 
            // btn_MapImport
            // 
            this.btn_MapImport.Location = new System.Drawing.Point(5, 19);
            this.btn_MapImport.Name = "btn_MapImport";
            this.btn_MapImport.Size = new System.Drawing.Size(114, 32);
            this.btn_MapImport.TabIndex = 1;
            this.btn_MapImport.Text = "Import Map";
            this.btn_MapImport.UseVisualStyleBackColor = true;
            this.btn_MapImport.Click += new System.EventHandler(this.btn_ImageImport_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Width:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 52);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Height:";
            // 
            // txt_GridWidth
            // 
            this.txt_GridWidth.Location = new System.Drawing.Point(62, 23);
            this.txt_GridWidth.Name = "txt_GridWidth";
            this.txt_GridWidth.Size = new System.Drawing.Size(45, 20);
            this.txt_GridWidth.TabIndex = 4;
            this.txt_GridWidth.Text = "16";
            this.txt_GridWidth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txt_GridWidth.TextChanged += new System.EventHandler(this.txt_GridWidth_TextChanged);
            // 
            // txt_GridHeight
            // 
            this.txt_GridHeight.Location = new System.Drawing.Point(62, 49);
            this.txt_GridHeight.Name = "txt_GridHeight";
            this.txt_GridHeight.Size = new System.Drawing.Size(45, 20);
            this.txt_GridHeight.TabIndex = 5;
            this.txt_GridHeight.Text = "16";
            this.txt_GridHeight.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txt_GridHeight.TextChanged += new System.EventHandler(this.txt_GridHeight_TextChanged);
            // 
            // btn_GenGrid
            // 
            this.btn_GenGrid.Location = new System.Drawing.Point(136, 19);
            this.btn_GenGrid.Name = "btn_GenGrid";
            this.btn_GenGrid.Size = new System.Drawing.Size(101, 45);
            this.btn_GenGrid.TabIndex = 6;
            this.btn_GenGrid.Text = "Generate Grid";
            this.btn_GenGrid.UseVisualStyleBackColor = true;
            this.btn_GenGrid.Click += new System.EventHandler(this.btn_GenGrid_Click);
            // 
            // gb_Waypoints
            // 
            this.gb_Waypoints.Controls.Add(this.dgv_Waypoints);
            this.gb_Waypoints.Controls.Add(this.lbl_currentX);
            this.gb_Waypoints.Controls.Add(this.lbl_currentY);
            this.gb_Waypoints.Controls.Add(this.label5);
            this.gb_Waypoints.Controls.Add(this.label4);
            this.gb_Waypoints.Controls.Add(this.label3);
            this.gb_Waypoints.Controls.Add(this.btn_AddWaypoint);
            this.gb_Waypoints.Location = new System.Drawing.Point(866, 12);
            this.gb_Waypoints.Name = "gb_Waypoints";
            this.gb_Waypoints.Size = new System.Drawing.Size(296, 481);
            this.gb_Waypoints.TabIndex = 8;
            this.gb_Waypoints.TabStop = false;
            this.gb_Waypoints.Text = "Waypoints";
            // 
            // dgv_Waypoints
            // 
            this.dgv_Waypoints.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv_Waypoints.Location = new System.Drawing.Point(6, 86);
            this.dgv_Waypoints.Name = "dgv_Waypoints";
            this.dgv_Waypoints.Size = new System.Drawing.Size(284, 389);
            this.dgv_Waypoints.TabIndex = 10;
            // 
            // lbl_currentX
            // 
            this.lbl_currentX.AutoSize = true;
            this.lbl_currentX.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_currentX.Location = new System.Drawing.Point(35, 47);
            this.lbl_currentX.Name = "lbl_currentX";
            this.lbl_currentX.Size = new System.Drawing.Size(16, 18);
            this.lbl_currentX.TabIndex = 9;
            this.lbl_currentX.Text = "0";
            this.lbl_currentX.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // lbl_currentY
            // 
            this.lbl_currentY.AutoSize = true;
            this.lbl_currentY.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_currentY.Location = new System.Drawing.Point(35, 65);
            this.lbl_currentY.Name = "lbl_currentY";
            this.lbl_currentY.Size = new System.Drawing.Size(16, 18);
            this.lbl_currentY.TabIndex = 8;
            this.lbl_currentY.Text = "0";
            this.lbl_currentY.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(7, 65);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(21, 18);
            this.label5.TabIndex = 7;
            this.label5.Text = "Y:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(7, 47);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(22, 18);
            this.label4.TabIndex = 6;
            this.label4.Text = "X:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(7, 20);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(99, 18);
            this.label3.TabIndex = 5;
            this.label3.Text = "Current Point:";
            // 
            // btn_AddWaypoint
            // 
            this.btn_AddWaypoint.Enabled = false;
            this.btn_AddWaypoint.Location = new System.Drawing.Point(176, 19);
            this.btn_AddWaypoint.Name = "btn_AddWaypoint";
            this.btn_AddWaypoint.Size = new System.Drawing.Size(114, 32);
            this.btn_AddWaypoint.TabIndex = 3;
            this.btn_AddWaypoint.Text = "Add Waypoint";
            this.btn_AddWaypoint.UseVisualStyleBackColor = true;
            this.btn_AddWaypoint.Click += new System.EventHandler(this.btn_AddWaypoint_Click);
            // 
            // gb_GridSettings
            // 
            this.gb_GridSettings.Controls.Add(this.btn_RemGrid);
            this.gb_GridSettings.Controls.Add(this.label1);
            this.gb_GridSettings.Controls.Add(this.txt_GridWidth);
            this.gb_GridSettings.Controls.Add(this.label2);
            this.gb_GridSettings.Controls.Add(this.txt_GridHeight);
            this.gb_GridSettings.Controls.Add(this.btn_GenGrid);
            this.gb_GridSettings.Enabled = false;
            this.gb_GridSettings.Location = new System.Drawing.Point(146, 506);
            this.gb_GridSettings.Name = "gb_GridSettings";
            this.gb_GridSettings.Size = new System.Drawing.Size(254, 116);
            this.gb_GridSettings.TabIndex = 9;
            this.gb_GridSettings.TabStop = false;
            this.gb_GridSettings.Text = "Grid Settings";
            // 
            // btn_RemGrid
            // 
            this.btn_RemGrid.Location = new System.Drawing.Point(136, 70);
            this.btn_RemGrid.Name = "btn_RemGrid";
            this.btn_RemGrid.Size = new System.Drawing.Size(101, 34);
            this.btn_RemGrid.TabIndex = 7;
            this.btn_RemGrid.Text = "Remove Grid";
            this.btn_RemGrid.UseVisualStyleBackColor = true;
            this.btn_RemGrid.Click += new System.EventHandler(this.btn_RemGrid_Click);
            // 
            // gb_MapSettings
            // 
            this.gb_MapSettings.Controls.Add(this.btn_MapRemove);
            this.gb_MapSettings.Controls.Add(this.btn_MapImport);
            this.gb_MapSettings.Location = new System.Drawing.Point(12, 506);
            this.gb_MapSettings.Name = "gb_MapSettings";
            this.gb_MapSettings.Size = new System.Drawing.Size(128, 109);
            this.gb_MapSettings.TabIndex = 10;
            this.gb_MapSettings.TabStop = false;
            this.gb_MapSettings.Text = "Map Settings";
            // 
            // btn_MapRemove
            // 
            this.btn_MapRemove.Location = new System.Drawing.Point(5, 62);
            this.btn_MapRemove.Name = "btn_MapRemove";
            this.btn_MapRemove.Size = new System.Drawing.Size(114, 32);
            this.btn_MapRemove.TabIndex = 2;
            this.btn_MapRemove.Text = "Remove Map";
            this.btn_MapRemove.UseVisualStyleBackColor = true;
            this.btn_MapRemove.Click += new System.EventHandler(this.btn_MapRemove_Click);
            // 
            // gb_Save
            // 
            this.gb_Save.Controls.Add(this.rb_BinaryS);
            this.gb_Save.Controls.Add(this.rb_xmlS);
            this.gb_Save.Location = new System.Drawing.Point(629, 506);
            this.gb_Save.Name = "gb_Save";
            this.gb_Save.Size = new System.Drawing.Size(113, 70);
            this.gb_Save.TabIndex = 2;
            this.gb_Save.TabStop = false;
            this.gb_Save.Text = "Save As:";
            // 
            // rb_BinaryS
            // 
            this.rb_BinaryS.AutoSize = true;
            this.rb_BinaryS.Location = new System.Drawing.Point(7, 44);
            this.rb_BinaryS.Name = "rb_BinaryS";
            this.rb_BinaryS.Size = new System.Drawing.Size(54, 17);
            this.rb_BinaryS.TabIndex = 1;
            this.rb_BinaryS.Text = "Binary";
            this.rb_BinaryS.UseVisualStyleBackColor = true;
            // 
            // rb_xmlS
            // 
            this.rb_xmlS.AutoSize = true;
            this.rb_xmlS.Checked = true;
            this.rb_xmlS.Location = new System.Drawing.Point(7, 20);
            this.rb_xmlS.Name = "rb_xmlS";
            this.rb_xmlS.Size = new System.Drawing.Size(47, 17);
            this.rb_xmlS.TabIndex = 0;
            this.rb_xmlS.TabStop = true;
            this.rb_xmlS.Text = "XML";
            this.rb_xmlS.UseVisualStyleBackColor = true;
            // 
            // btn_SaveWaypoints
            // 
            this.btn_SaveWaypoints.Enabled = false;
            this.btn_SaveWaypoints.Location = new System.Drawing.Point(628, 582);
            this.btn_SaveWaypoints.Name = "btn_SaveWaypoints";
            this.btn_SaveWaypoints.Size = new System.Drawing.Size(114, 32);
            this.btn_SaveWaypoints.TabIndex = 3;
            this.btn_SaveWaypoints.Text = "Save Waypoints";
            this.btn_SaveWaypoints.UseVisualStyleBackColor = true;
            // 
            // btn_LoadWaypoints
            // 
            this.btn_LoadWaypoints.Enabled = false;
            this.btn_LoadWaypoints.Location = new System.Drawing.Point(747, 582);
            this.btn_LoadWaypoints.Name = "btn_LoadWaypoints";
            this.btn_LoadWaypoints.Size = new System.Drawing.Size(114, 32);
            this.btn_LoadWaypoints.TabIndex = 4;
            this.btn_LoadWaypoints.Text = "Load Waypoints";
            this.btn_LoadWaypoints.UseVisualStyleBackColor = true;
            // 
            // gb_Load
            // 
            this.gb_Load.Controls.Add(this.rb_BinaryL);
            this.gb_Load.Controls.Add(this.rb_xmlL);
            this.gb_Load.Location = new System.Drawing.Point(748, 506);
            this.gb_Load.Name = "gb_Load";
            this.gb_Load.Size = new System.Drawing.Size(113, 70);
            this.gb_Load.TabIndex = 3;
            this.gb_Load.TabStop = false;
            this.gb_Load.Text = "Load From:";
            // 
            // rb_BinaryL
            // 
            this.rb_BinaryL.AutoSize = true;
            this.rb_BinaryL.Location = new System.Drawing.Point(7, 44);
            this.rb_BinaryL.Name = "rb_BinaryL";
            this.rb_BinaryL.Size = new System.Drawing.Size(54, 17);
            this.rb_BinaryL.TabIndex = 1;
            this.rb_BinaryL.Text = "Binary";
            this.rb_BinaryL.UseVisualStyleBackColor = true;
            // 
            // rb_xmlL
            // 
            this.rb_xmlL.AutoSize = true;
            this.rb_xmlL.Checked = true;
            this.rb_xmlL.Location = new System.Drawing.Point(7, 20);
            this.rb_xmlL.Name = "rb_xmlL";
            this.rb_xmlL.Size = new System.Drawing.Size(47, 17);
            this.rb_xmlL.TabIndex = 0;
            this.rb_xmlL.TabStop = true;
            this.rb_xmlL.Text = "XML";
            this.rb_xmlL.UseVisualStyleBackColor = true;
            // 
            // wayPointLocationBindingSource
            // 
            this.wayPointLocationBindingSource.DataSource = typeof(WaypointCreator_Assessment.WayPointLocation);
            // 
            // WaypointEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1184, 634);
            this.Controls.Add(this.gb_Load);
            this.Controls.Add(this.btn_LoadWaypoints);
            this.Controls.Add(this.gb_MapSettings);
            this.Controls.Add(this.gb_GridSettings);
            this.Controls.Add(this.btn_SaveWaypoints);
            this.Controls.Add(this.gb_Waypoints);
            this.Controls.Add(this.gb_Save);
            this.Controls.Add(this.pb_Map);
            this.Name = "WaypointEditor";
            this.Text = "Waypoint Creator/Editor";
            ((System.ComponentModel.ISupportInitialize)(this.pb_Map)).EndInit();
            this.gb_Waypoints.ResumeLayout(false);
            this.gb_Waypoints.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgv_Waypoints)).EndInit();
            this.gb_GridSettings.ResumeLayout(false);
            this.gb_GridSettings.PerformLayout();
            this.gb_MapSettings.ResumeLayout(false);
            this.gb_Save.ResumeLayout(false);
            this.gb_Save.PerformLayout();
            this.gb_Load.ResumeLayout(false);
            this.gb_Load.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.wayPointLocationBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button btn_MapImport;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txt_GridWidth;
        private System.Windows.Forms.TextBox txt_GridHeight;
        private System.Windows.Forms.Button btn_GenGrid;
        private System.Windows.Forms.GroupBox gb_Waypoints;
        private System.Windows.Forms.GroupBox gb_GridSettings;
        private System.Windows.Forms.GroupBox gb_MapSettings;
        private System.Windows.Forms.GroupBox gb_Save;
        private System.Windows.Forms.RadioButton rb_BinaryS;
        private System.Windows.Forms.RadioButton rb_xmlS;
        private System.Windows.Forms.Button btn_LoadWaypoints;
        private System.Windows.Forms.Button btn_SaveWaypoints;
        private System.Windows.Forms.Button btn_MapRemove;
        private System.Windows.Forms.GroupBox gb_Load;
        private System.Windows.Forms.RadioButton rb_BinaryL;
        private System.Windows.Forms.RadioButton rb_xmlL;
        private System.Windows.Forms.Button btn_AddWaypoint;
        private System.Windows.Forms.Button btn_RemGrid;
        private System.Windows.Forms.PictureBox pb_Map;
        private System.Windows.Forms.Label lbl_currentX;
        private System.Windows.Forms.Label lbl_currentY;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DataGridView dgv_Waypoints;
        private System.Windows.Forms.BindingSource wayPointLocationBindingSource;
    }
}

