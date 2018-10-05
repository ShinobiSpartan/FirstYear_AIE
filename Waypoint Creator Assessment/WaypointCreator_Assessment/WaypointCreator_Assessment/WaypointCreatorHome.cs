using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WaypointCreator_Assessment
{
    public partial class WaypointCreatorHome : Form
    {
        private int childFormNumber = 1;
        private int wChildFormNumber = 1;

        MyException mE = new MyException();

        public WaypointCreatorHome()
        {
            InitializeComponent();
        }

        private void ShowNewForm(object sender, EventArgs e)
        {
            CP_DD_Form childForm = new CP_DD_Form();
            childForm.MdiParent = this;
            childForm.Text = "Window " + childFormNumber++;
            childForm.Show();
        }
        private void newWaypointWin_Click(object sender, EventArgs e)
        {
            Form childForm = new WaypointEditor();
            childForm.MdiParent = this;
            childForm.Text = "Waypoint Editor " + wChildFormNumber++;
            childForm.Show();
        }

        private void OpenFile(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            openFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            if (openFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = openFileDialog.FileName;
            }
        }

        private void SaveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            saveFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            if (saveFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = saveFileDialog.FileName;
            }
        }

        private void ExitToolsStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CutToolStripMenuItem_Click(object sender, EventArgs e) { }

        private void CopyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form activeChild = this.ActiveMdiChild;

            if (activeChild != null)
            {
                try
                {
                    TextBox theBox = (TextBox)activeChild.ActiveControl;
                    if (theBox != null)
                    {
                        Clipboard.SetDataObject(theBox.SelectedText);
                    }
                }
                catch
                {
                    MessageBox.Show(mE.Message);
                }
            }
        }

        private void PasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form activeChild = this.ActiveMdiChild;

            if (activeChild != null)
            {
                try
                {
                    TextBox theBox = (TextBox)activeChild.ActiveControl;
                    if (theBox != null)
                    {
                        IDataObject data = Clipboard.GetDataObject();

                        if (data.GetDataPresent(DataFormats.Text))
                        {
                            theBox.SelectedText = data.GetData(DataFormats.Text).ToString();
                        }
                    }
                }
                catch
                {
                    MessageBox.Show(mE.Message);
                }
            }
        }
       
        private void ToolBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStrip.Visible = toolBarToolStripMenuItem.Checked;
        }

        private void StatusBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            statusStrip.Visible = statusBarToolStripMenuItem.Checked;
        }

        private void CascadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }

        private void TileVerticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void TileHorizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void ArrangeIconsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.ArrangeIcons);
        }

        private void CloseAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form childForm in MdiChildren)
            {
                childForm.Close();
            }
        }
    }
}
