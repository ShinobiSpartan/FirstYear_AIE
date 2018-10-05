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
    public partial class CP_DD_Form : Form
    {
        public CP_DD_Form()
        {
            InitializeComponent();
        }

        private void tb_DD_MouseDown(object sender, MouseEventArgs e)
        {
            tb_DD.DoDragDrop(tb_DD.Text, DragDropEffects.Copy | DragDropEffects.Move);
        }

        private void tb_DD_DragDrop(object sender, DragEventArgs e)
        {
            tb_DD.Text = e.Data.GetData(DataFormats.Text).ToString();
        }

        private void tb_DD_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
                e.Effect = DragDropEffects.Copy;
            else
                e.Effect = DragDropEffects.None;
        }
    }
}
