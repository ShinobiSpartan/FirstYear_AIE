using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CharacterCreator
{
    class Spritesheet
    {
        public override string ToString()
        {
            return base.ToString() + ": " + path.ToString();
        }

        private Image image = null;

        public string path;

        public int GetWidth()
        {
            return 0;
        }

        public int GetHeight()
        {
            return 0;
        }

        public Spritesheet(string path)
        {
            this.path = path;
            Load();
        }

        public void Load()
        {
            image = Image.FromFile(path);
        }
    }
}
