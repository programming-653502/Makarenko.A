using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_7
{
    class Client
    {
        public int idClient { get; set; }
        public string fullName { get; set; }
        public List<string> serviceHistory { get; private set; }
        public DateTime dateOfRegistration { get; set; }
        public DateTime dateOfIssue { get; set; }//Дата выдачи
        public string passportID { get; set; }
        public Client(int idClient, string fullName, List<string> serviceHistory, DateTime dateOfRegistration, DateTime dateOfIssue, string passportID)
        {
            this.idClient = idClient;
            this.fullName = fullName;
            this.serviceHistory = new List<string>(serviceHistory);
            this.dateOfRegistration = dateOfRegistration;
            this.dateOfIssue = dateOfIssue;
            this.passportID = passportID;
        }
        public void show()
        {
            Console.WriteLine("ID - " + this.idClient);
            Console.WriteLine("Full name - " + this.fullName);
            Console.WriteLine("Date of registration - " + this.dateOfRegistration);
            Console.WriteLine("Date of Issue - " + this.dateOfIssue);
            Console.WriteLine("Passport ID - " + this.passportID);
        }
        public void showHistory(int id)
        {
            if (this.idClient == id)
            foreach(string history in this.serviceHistory)
            {
                Console.WriteLine(history);
            }
        }
        public void change(Client client)
        {
            if (this.idClient == client.idClient)
            {               
                this.fullName = client.fullName;              
                this.dateOfRegistration = client.dateOfRegistration;
                this.dateOfIssue = client.dateOfIssue;
                this.passportID = client.passportID;
            }
        }
       
        
            
    }
}
