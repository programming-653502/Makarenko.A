using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Proga_lab_6_5._2._14_
{
    class Program
    {
        static void Main(string[] args)
        {
            string line, word="";
            System.IO.StreamReader file = new System.IO.StreamReader(@"c:\Users\Andrei\Documents\Visual Studio 2017\Projects\Proga lab 6(5.2.14)\Proga lab 6(5.2.14)\Input.txt");
            Tree t = new Tree();
            while ((line = file.ReadLine()) != null)
            {
                if (line[0] != ' ')
                   line = " " + line;
                if (line[line.Length-1] != ' ')
                   line = line + " ";

                for (var i=1; i<line.Length;i++)
                {
                    if (line[i] != ' ')
                    {
                        word = word + line[i];
                    }
                    else
                    {
                            t.Insert(word);
                            word = "";
                    }
                }
            }


            Console.WriteLine(t.Display(t));
            Tree s = t.Search("dsad");
            Console.WriteLine(s.Display(s));
            Console.Read();

        }
        class Tree
        {
            private string value;
            private int count;
            private Tree left;
            private Tree right;

            // вставка
            public void Insert(string value)
            {
                if (this.value == null)
                    this.value = value;
                else
                {
                    if (this.value.CompareTo(value) == 1)
                    {
                        if (left == null)
                            this.left = new Tree();
                        left.Insert(value);
                    }
                    else if (this.value.CompareTo(value) == -1)
                    {
                        if (right == null)
                            this.right = new Tree();
                        right.Insert(value);
                    }
                    else
                        throw new Exception("Узел уже существует");
                }

                this.count = Recount(this);
            }
            // поиск
            public Tree Search(string value)
            {
                if (this.value == value)
                    return this;
                else if (this.value.CompareTo(value) == 1)
                {
                    if (left != null)
                        return this.left.Search(value);
                    else
                        throw new Exception("Искомого узла в дереве нет");
                }
                else
                {
                    if (right != null)
                        return this.right.Search(value);
                    else
                        throw new Exception("Искомого узла в дереве нет");
                }
            }
            // отображение в строку
            public string Display(Tree t)
            {
                string result = "";
                if (t.left != null)
                    result += Display(t.left);

                result += t.value + " ";

                if (t.right != null)
                    result += Display(t.right);

                return result;
            }
           
            // подсчет
            private int Recount(Tree t)
            {
                int count = 0;

                if (t.left != null)
                    count += Recount(t.left);

                count++;

                if (t.right != null)
                    count += Recount(t.right);

                return count;
            }

        }
    }
}
