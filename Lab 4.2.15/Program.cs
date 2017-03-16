using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Prog_Lab_4._2._15
{
    class Program
    {
        static void Main(string[] args)
        {
            String Text = "";
            List<string> Dictionary = new List<string>();
            int lengthlist = 0,answer;
            //StreamReader text = new StreamReader(@"C:\Users\Andrei\Documents\Visual Studio 2017\Projects\Prog Lab 4.2.15\Prog Lab 4.2.15\Text.txt");
            StreamReader text = new StreamReader(@"Text.txt");
            while (!text.EndOfStream)
            {
                Text = Text+ " " + text.ReadLine();
            }
            //StreamReader dictionary = new StreamReader(@"C:\Users\Andrei\Documents\Visual Studio 2017\Projects\Prog Lab 4.2.15\Prog Lab 4.2.15\Dictionary.txt");
            StreamReader dictionary = new StreamReader(@"Dictionary.txt");
            while (!dictionary.EndOfStream)
            {
                Dictionary.Add(dictionary.ReadLine());
                lengthlist++;
            }
            answer = search(Text,Dictionary, lengthlist);
            Console.WriteLine("The frequency of repetitions is "+answer);
            Console.ReadLine();
        }
        static int search(String text,List<string> dictionary, int length)
        {
            int frequency=0; 
            for (int i=0;i<length;i++)
            {
                bool b=true;
                while (b)
                {
                    b = text.Contains(dictionary[i]);
                    if (b)
                    {
                        frequency++;
                        text = delete(text, dictionary, i);
                    }
                    
                }
            }
            return frequency;
        }
       static String delete(String text, List<string> dictionary, int index)
        {
            int Long, Position;
            Long = dictionary[index].Length;
            Position= text.IndexOf(dictionary[index]);
            text=text.Remove(Position, Long);
            return text;
        }

    }
}
