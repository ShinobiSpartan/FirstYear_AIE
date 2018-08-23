using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WaypointCreator_Assessment
{ 


    public partial class WaypointEditor : Form
    {
        Map map = null;
        Bitmap drawArea;

        int gridWidth = 4;
        int gridHeight = 4;

        public WaypointEditor()
        {
            InitializeComponent();

            drawArea = new Bitmap(pb_Map.Width, pb_Map.Height);
        }

        private void btn_ImageImport_Click(object sender, EventArgs e)
        {

            OpenFileDialog dlg = new OpenFileDialog();

            if (dlg.ShowDialog() == DialogResult.OK)
            {
                if(dlg.CheckFileExists == true)
                {
                    map = new Map(dlg.FileName);
                    DrawImage();
                }
            }
        }

        private void DrawImage()
        {
            Graphics g;
            g = Graphics.FromImage(drawArea);

            g.Clear(Color.White);

            if( map != null)
            {
                g.DrawImage(map.image, 0, 0);
            }

            g.Dispose();

            pb_Map.Image = drawArea;
        }

        private void btn_GenGrid_Click(object sender, EventArgs e)
        {
            pb_Map.DrawToBitmap(drawArea, pb_Map.Bounds);

            Graphics g;
            g = Graphics.FromImage(drawArea);

            g.Clear(Color.White);

            Pen pen = new Pen(Brushes.Black);

            int height = pb_Map.Height;
            int width = pb_Map.Width;

            for (int y = 0; y < height; y += gridHeight)
            {
                g.DrawLine(pen, 0, y, width, y);
            }

            for (int x = 0; x < width; x += gridWidth)
            {
                g.DrawLine(pen, x, 0, x, height);
            }

            g.Dispose();

            pb_Map.Image = drawArea;
        }

        private void btn_RemGrid_Click(object sender, EventArgs e)
        {
            Graphics g;
            g = Graphics.FromImage(drawArea);
            g.Clear(Color.White);

            g.Dispose();
            pb_Map.Image = drawArea;
        }

        private void txt_GridWidth_TextChanged(object sender, EventArgs e)
        {

            if (int.TryParse(txt_GridWidth.Text, out gridWidth) == true)
            {
                gridWidth = Convert.ToInt32(txt_GridWidth.Text);
            }

            txt_GridWidth.Text = gridWidth.ToString();
        }

        private void txt_GridHeight_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(txt_GridHeight.Text, out gridHeight) == true)
            {
                gridHeight = Convert.ToInt32(txt_GridHeight.Text);
            }

            txt_GridHeight.Text = gridHeight.ToString();
        }
    }
}
