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

        int gridWidth = 16;
        int gridHeight = 16;

        int counter = 0;
        string[] waypointsArray = new string[3];
        ListViewItem item;

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
            Bitmap image = new Bitmap(map.image);
            pb_Map.Image = (Image)image;
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

            if (gridWidth <= 0 || gridWidth > 1000)
            {
                gridWidth = 2;
                txt_GridWidth.Text = gridWidth.ToString();
            }
        }

        private void txt_GridHeight_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(txt_GridHeight.Text, out gridHeight) == true)
            {
                gridHeight = Convert.ToInt32(txt_GridHeight.Text);
            }

            if (gridHeight <= 0 || gridHeight > 1000)
            {
                gridHeight = 2;
                txt_GridHeight.Text = gridHeight.ToString();
            }
        }

        private void pb_Map_Click(object sender, EventArgs e)
        {
            Graphics g;
            g = Graphics.FromImage(drawArea);
            SolidBrush sBrush = new SolidBrush(Color.Red);

            g.Clear(Color.White);

            if (e.GetType() == typeof(MouseEventArgs))
            {
                MouseEventArgs me = e as MouseEventArgs;

                lbl_currentX.Text = me.Location.X.ToString();
                lbl_currentY.Text = me.Location.Y.ToString();

                g.FillEllipse(sBrush, me.Location.X, me.Location.Y, 8, 8);

                g.Dispose();

                pb_Map.Image = drawArea;

            }
        }

        private void btn_AddWaypoint_Click(object sender, EventArgs e)
        {
            waypointsArray[0] = "Waypoint " + counter++;
            waypointsArray[1] = lbl_currentX.Text;
            waypointsArray[2] = lbl_currentY.Text;

            item = new ListViewItem(waypointsArray);
            lv_Waypoints.Items.Add(item);
        }
    }
}
