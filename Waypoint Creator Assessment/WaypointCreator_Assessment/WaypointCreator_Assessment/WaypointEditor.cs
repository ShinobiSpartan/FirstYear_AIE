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
using System.Xml;
using System.Xml.Serialization;

namespace WaypointCreator_Assessment
{
    public partial class WaypointEditor : Form
    {
        Map map = null;
        Bitmap drawArea;
        public List<WayPointLocation> points;

        int gridWidth = 16;
        int gridHeight = 16;

        int currentX = 0;
        int currentY = 0;

        Graphics g;
        int counter = 1;

        public class WaypointSaver
        {
            public List<WayPointLocation> savedPoints;
        }

        private void Draw()
        {
            g.Clear(Color.White);

            Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
            g.DrawImage(image, 0, 0);

            DrawGrid();
            DrawWaypoints();
        }
      
        public WaypointEditor()
        {
            InitializeComponent();

            drawArea = new Bitmap(pb_Map.Width, pb_Map.Height);
            g = Graphics.FromImage(drawArea);

            points = new List<WayPointLocation>();
            dgv_Waypoints.DataSource = points;

            btn_Exit.Enabled = true;
        }

        private void btn_ImageImport_Click(object sender, EventArgs e)
        {

            OpenFileDialog dlg = new OpenFileDialog();
            
            // Open file browser to locate image
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                if(dlg.CheckFileExists == true)
                {
                    map = new Map(dlg.FileName);

                    Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
                    g.DrawImage(image, 0, 0);
                }
            }
            // Once image has been selected, draw to picturebox
            pb_Map.Image = drawArea;

            // If the map is in the picture box, change the grid setting to be enabled
            if (map != null)
            {
                gb_GridSettings.Enabled = true;
            }
        }

        private void btn_MapRemove_Click(object sender, EventArgs e)
        {
            // Clears the entire map space back to white
            g.Clear(Color.White);

            map = null;

            pb_Map.Image = drawArea;

            currentX = 0;
            currentY = 0;

            lbl_currentX.Text = currentX.ToString();
            lbl_currentY.Text = currentY.ToString();

            // Disable most settings when map is removed
            if (map == null)
            {
                gb_GridSettings.Enabled = false;
                btn_SaveWaypoints.Enabled = false;
                btn_LoadWaypoints.Enabled = false;
                btn_AddWaypoint.Enabled = false;
                pb_Map.Enabled = false;
            }

        }

        private void btn_GenGrid_Click(object sender, EventArgs e)
        {
            // Draw map and grid (and waypoints if previously added) onto picturebox
            pb_Map.DrawToBitmap(drawArea, pb_Map.Bounds);

            g.Clear(Color.White);
            Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
            g.DrawImage(image, 0, 0);

            DrawGrid();
            DrawWaypoints();

            pb_Map.Image = drawArea;

            // Enable controls all controls
            pb_Map.Enabled = true;
            btn_AddWaypoint.Enabled = true;
            btn_SaveWaypoints.Enabled = true;
            btn_LoadWaypoints.Enabled = true;
        }

        private void btn_RemGrid_Click(object sender, EventArgs e)
        { 
            // Clear the screen and only redraw the map, removing the grid
            g.Clear(Color.White);

            Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
            g.DrawImage(image, 0, 0);

            pb_Map.Image = drawArea;

            // Disable certain controls
            pb_Map.Enabled = false;
            btn_AddWaypoint.Enabled = false;
            btn_SaveWaypoints.Enabled = false;
            btn_LoadWaypoints.Enabled = false;
        }

        private void txt_GridWidth_TextChanged(object sender, EventArgs e)
        {
            // Check if the value inputted into the Width box for the Grid is actually a number and is not below 2
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
            // Check if the value inputted into the Height box for the Grid is actually a number and is not below 2
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

        private void DrawGrid()
        {
            Pen pen = new Pen(Brushes.DarkGray);

            // Gets the height of the PictureBox
            int height = pb_Map.Height;
            // Gets the width of the PictureBox
            int width = pb_Map.Width;

            // Draws the grid using the inputted height and width values
            for (int y = 0; y < height; y += gridHeight)
            {
                g.DrawLine(pen, 0, y, width, y);
            }

            for (int x = 0; x < width; x += gridWidth)
            {
                g.DrawLine(pen, x, 0, x, height);
            }
        }

        private void pb_Map_Click(object sender, EventArgs e)
        {
            SolidBrush sBrushTemp = new SolidBrush(Color.Red);

            if (e.GetType() == typeof(MouseEventArgs))
            {
                if (cb_EditWaypoints.Checked != true)
                {
                    // When the map is clicked, record coordiantes and draw a red dot to mark the position
                    Draw();

                    MouseEventArgs me = e as MouseEventArgs;

                    currentX = me.Location.X;
                    currentY = me.Location.Y;

                    g.FillEllipse(sBrushTemp, me.Location.X, me.Location.Y, 8, 8);

                    lbl_currentX.Text = currentX.ToString();
                    lbl_currentY.Text = currentY.ToString();

                    pb_Map.Image = drawArea;
                }
                else if(cb_EditWaypoints.Checked == true)
                {
                    int selectedIndex = dgv_Waypoints.CurrentCell.RowIndex;
                    string wpSelectedName = points.ElementAt(selectedIndex).Name;

                    MouseEventArgs me = e as MouseEventArgs;

                    var ePoint = points.FirstOrDefault(p => p.Name == wpSelectedName);
                    if (ePoint != null)
                    {
                        ePoint.Point_X = me.Location.X;
                        ePoint.Point_Y = me.Location.Y;
                    }

                    DataTable table = ConvertListToDataTable(points);
                    dgv_Waypoints.DataSource = table;

                    Draw();

                }
            }
        }

        private void btn_AddWaypoint_Click(object sender, EventArgs e)
        {
            // Adds the current position to the list of waypoints
            WayPointLocation point = new WayPointLocation();

            point.Name = "Waypoint " + counter++;
            point.Point_X = currentX;
            point.Point_Y = currentY;

            points.Add(point);

            DataTable table = ConvertListToDataTable(points);
            dgv_Waypoints.DataSource = table;

            DrawWaypoints();

            btn_ClearWaypoints.Enabled = true;
            cb_EditWaypoints.Enabled = true;
            btn_DeleteWaypoint.Enabled = true;


        }

        private void btn_DeleteWaypoint_Click(object sender, EventArgs e)
        {
            // Removes selected waypoint from list if there is a point to delete
            if (points.Count >= 1)
            {
                int rowSelectedIndex = dgv_Waypoints.CurrentCell.RowIndex;

                points.RemoveAt(rowSelectedIndex);

                DataTable table = ConvertListToDataTable(points);
                dgv_Waypoints.DataSource = table;

                Draw();
            }
            else
            {
                // Will disable the buttons once there is nothing left in the list
                btn_ClearWaypoints.Enabled = false;
                cb_EditWaypoints.Enabled = false;
                btn_DeleteWaypoint.Enabled = false;
            }
        }

        private void btn_ClearWaypoints_Click(object sender, EventArgs e)
        {
            // Removes all Waypoints currently in the list and removes all of the points from the map
            points.Clear();
            counter = 1;

            DataTable table = ConvertListToDataTable(points);
            dgv_Waypoints.DataSource = table;

            Draw();

            btn_ClearWaypoints.Enabled = false;
            cb_EditWaypoints.Enabled = false;
            btn_DeleteWaypoint.Enabled = false;
        }

        private void btn_SaveWaypoints_Click(object sender, EventArgs e)
        {
            // Uses a XML Serialiser to store the list of Waypoints and their positions on the map
            XmlSerializer serializer = new XmlSerializer(typeof(WaypointSaver));
            TextWriter writer = new StreamWriter("SavedWaypoints.xml");

            WaypointSaver ws = new WaypointSaver();
            ws.savedPoints = points;

            serializer.Serialize(writer, ws);

            writer.Close();
        }

        private void btn_LoadWaypoints_Click(object sender, EventArgs e)
        {
            // Reads the file generated from the Save function and loads them into the list
            XmlSerializer serializer = new XmlSerializer(typeof(WaypointSaver));
            TextReader reader = new StreamReader("SavedWaypoints.xml");
            
            points.Clear();

            WaypointSaver ws = (WaypointSaver)serializer.Deserialize(reader);
            points = ws.savedPoints;
            
            reader.Close();


            DataTable table = ConvertListToDataTable(points);
            dgv_Waypoints.DataSource = table;

            // Draws the newly acquired Waypoints onto the map
            g.Clear(Color.White);

            Bitmap image = new Bitmap(map.image, new Size(pb_Map.Width, pb_Map.Height));
            g.DrawImage(image, 0, 0);

            DrawGrid();
            DrawWaypoints();
        
        }

        private void DrawWaypoints()
        {
            SolidBrush sBrushWaypoint = new SolidBrush(Color.Yellow);

            // Gets the position of each waypoint and draws it on the corresponding point on the picturebox/map
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

        private void btn_Exit_Click(object sender, EventArgs e)
        {
            // Closes the window
            Close();
        }
    }
}
