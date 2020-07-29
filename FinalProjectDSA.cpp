#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class grocery{
public:
	float wallet;
	string name;
	int quant;
	float amount;
	float total_amount;
	grocery *left, *right;
	grocery(int wallet){this->wallet = wallet;}
	void add();
	void del(string name);
	float total();
	float balance();
	void voucher();
	void discount();
	void display();
	void add_wallet(float amount);
};

	grocery *front;
	grocery *rear;

void grocery::add_wallet(float amount)
{
//	wallet = wallet+amount;
	cout<<"Your wallet now holds: "<<balance()+amount<<"bucks"<<endl;
}

void grocery::add()
{   
	grocery *newnode;
	newnode= (grocery*)malloc(sizeof(grocery));
	newnode->name = name;
	newnode->quant = quant;
	newnode->amount = amount;
  
	if(front == NULL)
	{
		newnode->right = NULL;
		newnode->left = NULL;
		front = newnode;
		rear = newnode;
	}
	else{
		rear->right = newnode;
		newnode->left = rear;
		rear = newnode;
	}

}

void grocery::display()
{
	cout<<setw(10)<<"item"<<setw(30)<<"quantity"<<setw(30)<<"amount"<<setw(30)<<"total"<<endl;
	grocery *temp;
	temp = front;
	while(temp <= rear)
	{
		if(temp!=rear){
		cout<<setw(10)<<temp->name<<setw(30)<<temp->quant<<setw(30)<<temp->amount<<setw(30)<<temp->quant*temp->amount<<endl;
		temp = temp->right;}
		else{
		cout<<setw(10)<<temp->name<<setw(30)<<temp->quant<<setw(30)<<temp->amount<<setw(30)<<temp->quant*temp->amount<<endl;			break;
		}
	}
	if(balance() > 500)
	{
		cout<<"Please come again\n";
		cout<<"Your current balance is: "<<balance()<<endl;
		cout<<"Your total expenditure is:"<<total()<<endl;
	}
	else if(balance() < 500 && balance() > 0)
	{
		cout<<"Please recharge your wallet\n";
		cout<<"Your current balance is: "<<balance()<<endl;
		cout<<"Your total expenditure is:"<<total()<<endl;
	}
	else if(balance() < 0)
	{
		cout<<"We are sorry to inform that sufficient balance is not in your account\n";
		cout<<"You exceeded your balance by: "<<(-1)*balance()<<endl;
	}

}

void grocery::del(string name)
{ 
	grocery *temp1,*temp2;
	temp1 = front;
	
	if(temp1->name == name)
	{
		temp2 = temp1;
		temp1 = temp1->right;
		front = temp1;
		free(temp2);
	}
	else{
		while(temp1->right->name != name)
		{
			temp1 = temp1->right;
		}
		temp2 = temp1->right;
		temp1->right = temp2->right;
		free(temp2);
	}
}

float grocery::total()
{
	float total_amount=0;
	grocery *temp3;
	temp3 = front;
	while(temp3 < rear)
	{
		total_amount = total_amount+temp3->quant*temp3->amount;
		temp3 = temp3->right;
	}
	if(temp3 == rear)
	{
		total_amount+=temp3->amount*temp3->quant;
	}

	return total_amount;
}

float grocery::balance()
{ 
	//cout<<"wallet"<<wallet<<endl;
	//cout<<"total"<<total()<<endl;
    float balance_left;
    balance_left= wallet-total();
    return balance_left;
}

void grocery::voucher()
{
	//float balance_left;
	//balance_left = balance();

	float add_amount;
	if(balance() > 0){
	if(total()>=500.00 && total()<1000.00)
	{    
		add_amount = total()*0.1;
		cout<<"You can buy products worth:"<<total()/10<<"for free"<<endl;
		cout<<"Get 10% free shopping between 500 bucks to 1000 bucks"<<endl;
		add_wallet(add_amount);
	}
	else if(total()<500)
	{
		cout<<"You need to buy an item of "<<" "<<500 - total()<<" "<<"to be eligible for a voucher"<<endl;
		
	}
	else if(total()>=1000)
	{
		add_amount = total()*0.2;
		cout<<"Get 20% free shopping between 1000bucks to 5000bucks"<<endl;
		cout<<"You can buy products worth:"<<total()/5<<"for free"<<endl;
		add_wallet(add_amount);
		
	}
	}
	else{
		cout<<"Not applicable for voucher\n";
	}
}

void grocery::discount()
{
	float total_amount;
	total_amount = total();
	if(total()<500)
	{
		cout<<"Not eligible for discount"<<endl;
	}
    else if(total()>=500 && total()<1000)
    {
      total_amount=total_amount-total()/10;
      cout<<"You are gettinga discount of 10%"<<" "<<"which is:"<<total()/10<<" "<<"bucks"<<endl;
	  //printf
	}
    else if(total() >= 1000)
	     {total_amount=total_amount-total()/5;
	       cout<<"You are gettinga discount of 20%"<<" "<<"which is:"<< total()/5<<" "<<"bucks"<<endl;}
		   

}	     

int main()
{   int k,g,b,i,l,m,n,a;
    string s,r;
    cout<<"Enter amount in your wallet"<<endl;
    cin>>k;
    grocery list1(k);
    while(i!=9)
    {   cout<<"Enter 1 for adding 2  for diplaying 3 for deletion 4 for voucher 5 for discount 6  and 9 for exit"<<endl;
        cout<<"Enter the operation you want to perform";
        cin>>i;
     switch(i)
     {
         case 1:
          cout<<"Enter the name of the item: ";
          cin>>s;
          cout<<"Enter the quantity: ";
          cin>>n;
          cout<<"Enter the amount: ";
          cin>>a;
          list1.name = s;
          list1.quant = n;
    	  list1.amount = a;
          list1.add();
             break;
          case 2:
                  cout<<"Displaying items"<<endl;
                  list1.display();
                  break;
         case 3:
                  cout<<"Enter the item you want to delete: ";
                  cin>>r;
                  list1.del(r);
                  //list1.display();
                  break;
        case 4:
                    list1.voucher();
                    break;
        case 5:
                    list1.discount();
                    break;
        case 6:
                   exit;
                  
     }
    }
/*	grocery list1(2000);
	list1.name = "apple";
	list1.quant = 2;
	list1.amount = 50;
	list1.add();
	list1.name = "pineapple";
	list1.quant = 3;
	list1.amount = 30;
	list1.add();
	list1.name = "orange";
	list1.quant = 6;
	list1.amount = 20;
	list1.add();
	list1.display(); 
	list1.del("apple");
	list1.display(); 
	cout<<list1.total()<<endl;
	cout<<list1.balance()<<endl;
	*/
	//return 0;
	return 0;
}