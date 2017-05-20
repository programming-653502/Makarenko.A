using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_7
{
    class Good
    {
        string name { get; set; }
        public int idClient { get; set; }
        public int assessedValue { get; set; } //оценочная стоимость
        public int amount { get; set; }//сумма
        public int storageLife { get; set; }//срок хранения 
        public DateTime dateOfDelivery { get; set; }//дата сдачи
        public Good(string name, int idClient, int assessedValue, int amount, DateTime dateOfDelivery, int storageLife)
        {
            this.name = name;
            this.idClient = idClient;
            this.assessedValue = assessedValue;
            this.amount = amount;
            this.dateOfDelivery = dateOfDelivery;
            this.storageLife = storageLife;
        }
        public void show()
        {
            Console.WriteLine("Name of good - " + this.name);
            Console.WriteLine("ID of client - " + this.idClient);
            Console.WriteLine("Assessed value - " + this.assessedValue);
            Console.WriteLine("Amount - " + this.amount);
            Console.WriteLine("Date of delivery - " + this.dateOfDelivery);
            Console.WriteLine("Storage life - " + this.storageLife);
        }
        public void Change(Good good)
        {
            this.name = good.name;
            this.idClient = good.idClient;
            this.assessedValue = good.assessedValue;
            this.amount = good.amount;
            this.dateOfDelivery = good.dateOfDelivery;
            this.storageLife = good.storageLife;
        }
    }
}
