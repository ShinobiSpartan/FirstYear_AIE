using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WaypointCreator_Assessment
{
    class Map
    {
        public Image image { get; private set; }
        private string path;

        public Map()
        {
            image = null;
            path = null;
        }

        public Map (string path)
        {
            this.path = path;
            Load();
        }

        public int Width
        {
            get
            {
                return (image != null) ? image.Width : 0;
            }
        }

        public int Height
        {
            get
            {
                return (image != null) ? image.Height : 0;
            }
        }

        public void Load()
        {
            image = Image.FromFile(path);
        }
    }
}
