using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CharacterCreator
{
    class Character
    {
        public override string ToString()
        {
            return base.ToString() + "\n\tpath: \t" + spritesheet.path + "\n\ttile coordiantes: \t" + tileCoordinates.ToString();
        }

        public string name;

        public Spritesheet spritesheet;

        public Point tileCoordinates = new Point(0, 0);

        public Character(string name, Spritesheet spritesheet)
        {
            this.name = name;
            this.spritesheet = spritesheet;
        }
    }
}
