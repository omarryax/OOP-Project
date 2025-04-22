#include <iostream>
#include <conio.h>
#include<ctime>
using namespace std;

class Account 
{
	public:
    int acno;
    string name;
    int deposit;
    bool member;
    
	Account()
	{
		acno = 210301;
	    name = "Rayyan";
	    deposit = 1000;
	    member = true;
	}
	
    void createAccount()
	{
		cout<<"Set Account no       : ";
		cin>>acno;
		cout<<"Set Your Name        : ";
		cin>>name;
		cout<<"Enter Deposit amount : ";
		cin>>deposit;
		member = true;
	}
    void showAccount() const
	{
		cout<<"\nAccount no      : "<<acno<<endl;
		cout<<"Account Name    : "<<name<<endl;
		cout<<"Account Balance : "<<deposit<<endl;
		cout<<"Member          : "<<member<<endl;
	}  
	
	 void modify()
	{
		cout<<"Change Account no: "<<endl;
		cin>>acno;
		cout<<"Change Your Name "<<endl;
		cin>>name;
		cout<<"Change Deposit amount: "<<endl;
		cin>>deposit;
	} 
	
    void dep()
	{
		cout<<"Enter Amount to Add in current balance: "<<endl;
		cin>>deposit;
	}  
};

class Item
{
	public:
		string ItemName;
		string ItemFlavour;
	    int ItemQuantity;
		float ItemPrice;
	
		public:
		Item(){}    //default constructor
		void setData()
		{
			cout<<"Enter Item name: ";
			cin>>ItemName;
			cout<<"Enter Item Flavour ";
			cin>>ItemFlavour;
			cout<<"Enter Item Quantity: ";
			cin>>ItemQuantity;
			cout<<"Enter Item price: ";
			cin>>ItemPrice;
		}
		
		void override()
		{
			ItemName = "";
			ItemFlavour = "";
			ItemQuantity = 0;
			ItemPrice = 0;
		}
		
		void showData()
		{
			cout<<"\nItem name: "<<ItemName;
			cout<<"\tItem Flavour: "<<ItemFlavour;
			cout<<"\t Item Quantity: "<<ItemQuantity;
			cout<<"\tItem price: "<<ItemPrice;
		}
};

class Admin
{
	public:
	int pos;
	float totalBill;
	int s[50];
	int j ;
	string user;
	int quantity;
	char p[5];
	int counter = 10;
	Item items[50];	 //composition
	
	Admin()      //default contructor
	{
		user = "admin";
		p[0] = 'a';
		p[1] = 'd';
		p[2] = 'm';
		p[3] = 'i';
		p[4] = 'n';
		
		j = 0;
		totalBill = 0;
		
		//initializing all the items in the bakery
		items[0].ItemName = "BDCake";
		items[0].ItemFlavour = "Choclate";
		items[0].ItemQuantity = 15;
		items[0].ItemPrice = 50;
		
		items[1].ItemName = "PanCakaes";
		items[1].ItemFlavour = "Caramel";
		items[1].ItemQuantity = 15;
		items[1].ItemPrice = 10;
		
		items[2].ItemName = "Cookies";
		items[2].ItemFlavour = "Choclate";
		items[2].ItemQuantity = 15;
		items[2].ItemPrice = 5;
		
		items[3].ItemName = "Coffee";
		items[3].ItemFlavour = "Late";
		items[3].ItemQuantity = 15;
		items[3].ItemPrice = 10;
		
		items[4].ItemName = "Brownies";
		items[4].ItemFlavour = "Chocolate";
		items[4].ItemQuantity = 15;
		items[4].ItemPrice = 5;
		
		items[5].ItemName = "IceCream";
		items[5].ItemFlavour = "Choclate";
		items[5].ItemQuantity = 15;
		items[5].ItemPrice = 8;
		
		items[6].ItemName = "Bread";
		items[6].ItemFlavour = "wheat";
		items[6].ItemQuantity = 15;
		items[6].ItemPrice = 2;
		
		items[7].ItemName = "Sandwich";
		items[7].ItemFlavour = "Chicken";
		items[7].ItemQuantity = 15;
		items[7].ItemPrice = 3;
		
		items[8].ItemName = "Sandwich";
		items[8].ItemFlavour = "Vegtables";
		items[8].ItemQuantity = 15;
		items[8].ItemPrice = 2;
		
		items[9].ItemName = "Pizza";
		items[9].ItemFlavour = "Special";
		items[9].ItemQuantity = 15;
		items[9].ItemPrice = 30;
	}
	
	void menuforCustomer()
	{
		for(int i = 0;i < counter ;i++)
		{
			cout<<"["<<i+1<<"]";
			items[i].showData();
			cout<<endl;
		}
		
	}
	
	void bill()
	{
		
		for(int i = 0;i < j;i++)
		{
			float p;
			p = (items[s[i]-1].ItemPrice)*(15-(items[s[i]-1].ItemQuantity));
			cout<<"\nItem name: "<<items[s[i]-1].ItemName<<"\tQuantity: "<<15-(items[s[i]-1].ItemQuantity)
				<<"\tFlavour: "<<items[s[i]-1].ItemFlavour<<"\tPrice: $"<<p<<endl;
			totalBill += p;
		}
		string coupon;
    		cout<<"Enter coupon if you have otherwise press any key and enter"<<endl;
    		cin>>coupon;
    	if(coupon == "usman50" or coupon == "USMAN50" ){	
		cout<<"\nCOUPON SUCCESS!"<<endl
			<<"\t\tTotal = $"<<totalBill<<endl
			<<"\t\tAFTER DISCOUNT: $"<<totalBill-(totalBill*0.25)<<endl;
		}
		else{
			cout<<"\nNO DISCOUNT!"<<endl
			<<"\t\tTotal = $"<<totalBill<<endl;
			
		}	
		
	}
	
	void buy()
	{
		char ch;
		int i;
		do
		{
			i = false;
			cout<<"\nEnter the serial number of item you want to buy: "<<endl;
			cin>>s[j];
			
			do
			{
				cout<<"Enter the required quantity: "<<endl;
				cin>>quantity;
				if( quantity < items[s[j]-1].ItemQuantity )
					i = false;
				else
				 {
				 	cout<<"Invalid Quantity added!"<<endl;
				 	i = true;
				 }
			}while(i);
			
			items[s[j]-1].ItemQuantity -= quantity;
			cout<<"Enter y to buy more items and enter any key to print bill"<<endl;
			cin>>ch;
			if((ch == 'y')||(ch == 'Y'))
				i = true;
			
			j++;
		}while(i);
			
	}
	
	void menu()
	{
		Admin b;
		int c = 0;
		while (c != 5)
		{
			cout << "\n\nWhat you Want to Do        " << endl;
			cout << "[1] Add Item                   " << endl;
			cout << "[2] Delete Item                " << endl;
			cout << "[3] Total Stock                " << endl;
			cout << "[4] Exit                       " << endl;
			cin >> c;
			switch (c)
			{
			case 1:	{add();
				break;
			}
					
			case 2:	{del();
				break;
			
					}
			case 3:	{menuforCustomer();
				break;
			
					}
			case 4:	{
				cout << "****************************************LOGGED OUT***************************************"<<endl<<endl<<endl;
				login();
				break;
			
		}
			default: cout << "You Enter Wrong Choice   ";
			}
    	}
    }
	void add()
	{
		items[counter].setData();
		counter++;
	}
	
	void login()
	{
		h:
		cout << "Please Enter user name : " << endl;
		cin >> user;
		cout << "Please Enter Password : " << endl;
		for (int x = 0; x < 5; x++)
		{
			p[x]=getch();
			cout << "*";
		}
		if (user == "admin"&& p[0] == 'a'&& p[1] == 'd'&&p[2] == 'm'&&p[3] == 'i'&&p[4] == 'n')
		{
			Admin a;
			cout << "************************************LOGGED IN***************************************"<<endl;
			a.menu();
		}
		else
		{
			cout << "*****You Entered Wrong Password*****"<<endl;
		 
			goto h;

		}
	}
	
	void del()
	{
	
	menuforCustomer();
 
	cout << "\nEnter the item no \n";
	cin  >> pos;
	int a = pos-1;
	
	if(a<0 || a >=counter) 
    {
        cout<<"Invalid\n";
    }
    else{
    	items[a].override();
	for(int i = a; i < counter; ++i) {
		items[i] = items[i+1];
   	}
   	counter--;
   	}
   
	
	cout<<"\n******************************DELETED SUCCESSFULLY*****************************"<<endl;
	
	}
	
};

class Customer : public Account
{

	public:
	Customer(){	}
		
};


int main()
{
	Customer c;
	Admin a;
	
	//welcome text
	cout<<"\n*******************************************************************************"
		<<"\n****************************** W E L C O M E  T O *****************************"
		<<"\n*********************** B A K E  Y O U R  D E S I R E S ***********************"
		<<"\n*******************************************************************************\n\n";

	bool i;
	
	do
	{
		i = false;
		int choice;
		a:
		cout<<"ENTER YOUR CHOICE\n[1]\tAdmin\n[2]\tCustomer\n";
		cin>>choice;
		switch(choice)
		{
	
			case 1: system("CLS");
					cout<<"\n*****************************************************************************************"
						<<"\n**************************** B A K E  Y O U R  D E S I R E S ****************************"
						<<"\n*************************************** A D M I N ***************************************"
						<<"\n*****************************************************************************************\n\n";
					
						a.login();
						
					break;
		
			case 2: char ch;
					
					system("CLS");
					cout<<"\n*****************************************************************************************"
						<<"\n**************************** B A K E  Y O U R  D E S I R E S ****************************"
						<<"\n************************************ C U S T O M E R ************************************"
						<<"\n*****************************************************************************************\n\n";
			
					do
					{
						i = true;
						cout<<"\n******************************************************************************************"
							<<"\n**************************** E N T E R  Y O U R  C H O I C E *****************************"
							<<"\n******************************************************************************************"
							<<"\n[1]\tShow Membership Details"
							<<"\n[2]\tModify Details"
							<<"\n[3]\tDeposit Amount"
							<<"\n[4]\tBuy Item"
							<<"\n[5]\tBecome A member"
							<<"\n[6]\tExit the menu"<<endl;
						cin>>choice;
					
						switch(choice)
						{
							case 1: c.showAccount();  //class Account
									break;
								
							case 2: c.modify();       //class Account
									break;
							
							case 3: c.dep();          //class Account
									break;
							
							case 4: a.menuforCustomer();
									a.buy();
									char mode;
									cout<<"Enter c for free CASH ON DELEIVRY and any key for PICKUP"<<endl;
									cin>>mode;
									system("CLS");
									cout<<"******************************************************************************************"<<endl
										<<"**************************** B A K E  Y O U R  D E S I R E S *****************************"<<endl
										<<"**************************************** B I L L *****************************************"<<endl
										<<"******************************************************************************************"<<endl;
									time_t timetoday;
   									time (&timetoday);
  									cout <<"Date and Time : "<< asctime(localtime(&timetoday));
									a.bill();
									c.deposit -= a.totalBill;
									c.showAccount();
									cout<<"Mode            : ";
									((mode == 'c')||(mode == 'C'))?cout<<"Free CASH ON DELEIVERY...":cout<<"PickUp";
									if(a.totalBill>100)
										cout<<"Congratulations! A free gift will also be given to you!"<<endl;
									cout<<"\n\n******************************************************************************************"<<endl;
									i = false;
									break;
							
							case 5: c.createAccount(); //class Account
									break;
							
							case 6: goto a;
									break;
									
							default: cout<<"Wrong choice entered!"<<endl;
								     break;
						}
					}while(i);
					
					
					break;
			
			default: cout<<"Wrong choice entered!"<<endl;
					 i = true;
		}
	}while(i);
	
	return 0;
}
