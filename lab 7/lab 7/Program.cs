using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace lab_7
{

    class Program
    {
        static Encoding enc = Encoding.GetEncoding(1251);

        static List<Good> goods = new List<Good>(); 
        static List<Client> clients = new List<Client>();

        static StreamReader fileClients = new StreamReader("Clients.txt", enc);
        static StreamReader fileGoods = new StreamReader("Goods.txt", enc);
        static StreamReader fileHistories = new StreamReader("Histories.txt", enc);

        static void Operations()
        {
            Console.WriteLine("Choose:");
            Console.WriteLine("Input (clients) for show list of clients");
            Console.WriteLine("Input (goods) for show list of goods");
            Console.WriteLine("Input (history) for show history of client.");
            Console.WriteLine("Input (change client) for change info about client.");
            Console.WriteLine("Input (all amount) for show all amount.");
            Console.WriteLine("Input (profit) for show  calculation of profit.");            
            Console.WriteLine("Input (exit) for exit.");
        }

        static void addClient()
        {
            int idClient;
            string fullName;
            List<string> serviceHistory;
            DateTime dateOfRegistration;
            DateTime dateOfIssue;
            string passportID;

            
            idClient = Convert.ToInt32(fileClients.ReadLine());
            fullName = fileClients.ReadLine();
            string date = fileClients.ReadLine();
            string[] ywd = date.Split('.');
            dateOfRegistration = new DateTime(Convert.ToInt32(ywd[2]), Convert.ToInt32(ywd[1]), Convert.ToInt32(ywd[0]));
            date = fileClients.ReadLine();
            ywd = date.Split('.');
            dateOfIssue = new DateTime(Convert.ToInt32(ywd[2]), Convert.ToInt32(ywd[1]), Convert.ToInt32(ywd[0]));
            passportID = fileClients.ReadLine();
            
            serviceHistory = new List<string>();
            
            string history = fileHistories.ReadLine();
            do
            {
                serviceHistory.Add(history);            
            } while ((history != null)&&(!string.IsNullOrEmpty(history=fileHistories.ReadLine())));
            
            clients.Add(new Client (idClient, fullName, serviceHistory, dateOfRegistration, dateOfIssue, passportID));
            
        }

        static void addGood()
        {
            string name;        
            int idClient;
            int assessedValue; //оценочная стоимость
            int amount;//сумма
            int storageLife;//срок хранения 
            DateTime dateOfDelivery; //дата сдачи

           
            name = fileGoods.ReadLine();
            idClient = Convert.ToInt32(fileGoods.ReadLine());
            assessedValue = Convert.ToInt32(fileGoods.ReadLine());
            amount = Convert.ToInt32(fileGoods.ReadLine());           
            string date = fileGoods.ReadLine();
            string[] ywd = date.Split('.');
            dateOfDelivery = new DateTime(Convert.ToInt32(ywd[2]), Convert.ToInt32(ywd[1]), Convert.ToInt32(ywd[0]));
            storageLife = Convert.ToInt32(fileGoods.ReadLine());
            goods.Add(new Good(name, idClient, assessedValue, amount, dateOfDelivery, storageLife));
        }

        static void changeClient()
        {
            
            bool process = true;
            do
            {
                Console.WriteLine("Choose:");
                Console.WriteLine("Input (remove) for remove client from list");
                Console.WriteLine("Input (change) for change client");
                string answer = Console.ReadLine();
                switch (answer)
                {
                    case "remove":
                        {
                            Console.Write("Input id of client, who you want remove - ");
                            int id = Convert.ToInt32(Console.ReadLine());                            
                            foreach (Client client in clients)
                            {
                                if (client.idClient == id) { clients.Remove(client); break; }                               
                            }                            
                            break;
                        }
                    case "change":
                        {                            
                            Console.Write("Input id of client, who you want change - ");
                            int id=Convert.ToInt32(Console.ReadLine());
                            Console.Write("Input new full name for change or input old for stay without change - ");
                            string fullName = Console.ReadLine();
                            Console.Write("Input new date of registration for change or input old for stay without change - ");
                            string date = Console.ReadLine();
                            string[] ywd = date.Split('.');                  
                            DateTime dateOfRegistration = new DateTime(Convert.ToInt32(ywd[2]), Convert.ToInt32(ywd[1]), Convert.ToInt32(ywd[0]));
                            Console.Write("Input new date of Issue for change or input old for stay without change - ");
                            date = Console.ReadLine();
                            ywd = date.Split('.');
                            DateTime dateOfIssue = new DateTime(Convert.ToInt32(ywd[2]), Convert.ToInt32(ywd[1]), Convert.ToInt32(ywd[0]));
                            Console.Write("Input new passport ID for change or input old for stay without change - ");
                            string passportID = Console.ReadLine();
                            List<string> serviceHistory = new List<string>();
                            Client changed = new Client (id, fullName, serviceHistory, dateOfRegistration, dateOfIssue, passportID);
                            foreach(Client client in clients)
                            {
                                if(client.idClient==id) client.change(changed);
                            }                           
                            break;
                        }
                    case "back": { process = false; break; }
                    default: { Console.WriteLine("Error!Try again!"); break; }
              }
            } while (process);
            FileStream fs = new FileStream("Clients.txt", FileMode.Create, FileAccess.Write);
            StreamWriter fileClientsWrite = new StreamWriter(fs,enc);
            foreach (Client client in clients)
            {
                fileClientsWrite.WriteLine("ID - " + client.idClient);
                fileClientsWrite.WriteLine("Full name - " + client.fullName);
                fileClientsWrite.WriteLine("Date of registration - " + client.dateOfRegistration);
                fileClientsWrite.WriteLine("Date of Issue - " + client.dateOfIssue);
                fileClientsWrite.WriteLine("Passport ID - " + client.passportID);
            }
            fileClientsWrite.Close();
        }
    
        static void add()
        {
            
            while (fileClients.Peek() >= 0)
            {
                 addClient();
            }
            fileClients.Close();

            while (fileGoods.Peek() >= 0)
            {
                 addGood();
            }
            fileGoods.Close();
        }

        static void Main(string[] args)
        {
            add();
            
            bool process=true;
            do
            {
                Operations();
                string answer = Console.ReadLine(); 
                switch (answer)
                {
                    case "clients":
                        {
                            foreach(Client client in clients)
                            {
                                client.show();
                            }
                            break;
                        }
                    case "history":
                        {                           
                            Console.Write("Input ID of client, who history you want will see - ");
                            int id=Convert.ToInt32(Console.ReadLine());                           
                            foreach(Client client in clients)
                            {
                                client.showHistory(id);
                            }
                            break;                           
                        }
                    case "goods":
                        {
                            foreach (Good good in goods)
                            {
                                good.show();
                            }
                            break;
                        }
                    case "change client":
                        {
                            changeClient();
                            break;
                        }
                    case "all amount":
                        {
                            int allAmount=0;
                            foreach (Good good in goods)
                            {
                                allAmount += good.assessedValue;
                            }                            
                            Console.WriteLine("All amount - "+allAmount);
                            break;
                        }
                    case "profit":
                        {
                            int profit = 0;
                            foreach (Good good in goods)
                            {
                                profit += good.amount+ good.assessedValue;
                            }
                            Console.WriteLine("Profit - " + profit);
                            break;                          
                        }
                    case "exit": { process = false; break; }
                    default: { Console.WriteLine("Error!Try again!"); break; }

                }

            } while (process);

        }
    }
}
