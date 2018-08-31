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
        List<WayPointLocation> points;

        int gridWidth = 16;
        int gridHeight = 16;

        int currentX = 0;
        int currentY = 0;

        Graphics g;
        int counter = 0;
      
        public WaypointEditor()
        {
            InitializeComponent();

            drawArea = new Bitmap(pb_Map.Width, pb_Map.Height);
            g = Graphics.FromImage(drawArea);

            points = new List<WayPointLocation>();
            dgv_Waypoints.DataSource = points;
        }

        private void btn_ImageImport_Click(object sender, EventArgs e)
        {

            OpenFileDialog dlg = new OpenFileDialog();

            if (dlg.ShowDialog() == DialogResult.OK)
            {
                if(dlg.CheckFileExists == true)
                {
                    map = new Map(dlg.FileName);

                    Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
                    g.DrawImage(image, 0, 0);
                }
            }
            pb_Map.Image = drawArea;

            if (map != null)
            {
                gb_GridSettings.Enabled = true;
            }
        }
        private void btn_MapRemove_Click(object sender, EventArgs e)
        {
            g.Clear(Color.White);

            map = null;

            pb_Map.Image = drawArea;

            currentX = 0;
            currentY = 0;

            lbl_currentX.Text = currentX.ToString();
            lbl_currentY.Text = currentY.ToString();


            if (map == null)
            {
                gb_GridSettings.Enabled = false;
                btn_SaveWaypoints.Enabled = false;
                btn_LoadWaypoints.Enabled = false;
                btn_AddWaypoint.Enabled = false;
                pb_Map.Enabled = false;
            }

        }
        private void DrawGrid()
        {
            Pen pen = new Pen(Brushes.DarkGray);

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
        }
        private void btn_GenGrid_Click(object sender, EventArgs e)
        {
            pb_Map.DrawToBitmap(drawArea, pb_Map.Bounds);

            //g = Graphics.FromImage(drawArea);
            g.Clear(Color.White);
            Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
            g.DrawImage(image, 0, 0);

            DrawGrid();
            DrawWaypoints();

            pb_Map.Image = drawArea;

            pb_Map.Enabled = true;
            btn_AddWaypoint.Enabled = true;
            btn_SaveWaypoints.Enabled = true;
            btn_LoadWaypoints.Enabled = true;
        }
        private void btn_RemGrid_Click(object sender, EventArgs e)
        { 
            g.Clear(Color.White);

            Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
            g.DrawImage(image, 0, 0);

            pb_Map.Image = drawArea;

            pb_Map.Enabled = false;
            btn_AddWaypoint.Enabled = false;
            btn_SaveWaypoints.Enabled = false;
            btn_LoadWaypoints.Enabled = false;
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
            SolidBrush sBrushTemp = new SolidBrush(Color.Red);

            if (e.GetType() == typeof(MouseEventArgs))
            {
                g.Clear(Color.White);

                Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
                g.DrawImage(image, 0, 0);

                DrawGrid();
                DrawWaypoints();

                MouseEventArgs me = e as MouseEventArgs;

                currentX = me.Location.X;
                currentY = me.Location.Y;

                g.FillEllipse(sBrushTemp, me.Location.X, me.Location.Y, 8, 8);

                

                lbl_currentX.Text = currentX.ToString();
                lbl_currentY.Text = currentY.ToString();


                pb_Map.Image = drawArea;
            }
        }
        private void btn_AddWaypoint_Click(object sender, EventArgs e)
        {
            WayPointLocation point = new WayPointLocation();

            point.Name = "Waypoint " + counter++;
            point.Point_X = currentX;
            point.Point_Y = currentY;

            points.Add(point);

            DataTable table = ConvertListToDataTable(points);
            dgv_Waypoints.DataSource = table;

            DrawWaypoints();
        }
        private void DrawWaypoints()
        {
            SolidBrush sBrushWaypoint = new SolidBrush(Color.Yellow);

            for (int i = 0; i < points.Count; i++)
            {
                g.FillEllipse(sBrushWaypoint, points[i].Point_X, points[i].Point_Y, 8, 8);
            }

            pb_Map.Image = drawArea;
        }


        static DataTable ConvertListToDataTable(List<WayPointLocation> list)
        {
            DataTable table = new DataTable();

            table.Columns.Add("Name");
            table.Columns.Add("Point X");
            table.Columns.Add("Point Y");


            foreach (var array in list)
            {
                table.Rows.Add(array.Name, array.Point_X, array.Point_Y);
            }

            return table;
        }
    }
}
