using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Prog_Lab._4._1._15
{
    class Program
    {
        static void Main(string[] args)
        {
            string Text;
            Console.WriteLine("Input text!");
            Text = Console.ReadLine();
            Text = Text + " ";
            Console.WriteLine("Output words!");
            change1(Text);
            Console.ReadLine();
        }
        static void change1(string text)
        {
            string slovo="";
            char[] chr = text.ToCharArray();
            for (int i=0;i<text.Length;i++)
            {
                if (chr[i] != ' ')
                {
                    slovo = slovo + chr[i];
                }else
                    if(chr[i] == ' ')
                {
                    slovo = change2(slovo);
                }

            }
        }
        static string change2(string Slovo)
        {
            int length = Slovo.Length-1;
            string new_slovo = "",slovo;
            char last_symbol =Slovo[length];
            bool k;
            slovo = last_symbol + Slovo;
            length = slovo.Length - 1;
            slovo.Remove(length,1);
            for (int i=0;i<slovo.Length;i++)
            {
                k= new_slovo.Contains(slovo[i]);
                if(!k)
                {
                    new_slovo = new_slovo + slovo[i];                   
                }
            }
            Console.WriteLine(new_slovo+" ");
            return "";
        }
    }
}
