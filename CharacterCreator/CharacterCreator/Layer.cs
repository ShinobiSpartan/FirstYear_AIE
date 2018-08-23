using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CharacterCreator
{
    class Layer
    {
        public string Name { get; set; }

        public Point TileCoordinates { get; set; }

        public int Priority { get; set; }

        public Layer(string name)
        {
            Name = name;
        }

        public Layer(string name, Point coordiantes)
        {
            Name = name;
            TileCoordinates = coordiantes;
        }
    }
}
