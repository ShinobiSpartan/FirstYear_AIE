using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CharacterCreator
{
    class Program
    {
        static Spritesheet spritesheet = null;
        static Character character = null;

        static void Main(string[] args)
        {
            string path;
            string name;

            Console.WriteLine("Working directory is " + Directory.GetCurrentDirectory());

            Console.WriteLine("Enter the relative path of the sprite sheet texture: ");
            path = Console.ReadLine();

            Console.WriteLine("Enter the name of the character to create: ");
            name = Console.ReadLine();

            spritesheet = new Spritesheet(Directory.GetCurrentDirectory() + "\\" + path);
            if (spritesheet == null)
            {
                Console.WriteLine("Error loading sprite sheet. Exiting program.");
                return;
            }

            character = new Character(name, spritesheet);

            Console.WriteLine("Enter the x tile index: ");
            int x = int.Parse(Console.ReadLine());

            Console.WriteLine("Enter the y tile index: ");
            int y = int.Parse(Console.ReadLine());

            character.tileCoordinates = new System.Drawing.Point(x, y);

            Console.WriteLine(character.ToString());

            Console.ReadKey();
        }
    }
}
