#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Customer //define struct has customer details
{
	string customer_Name;
	string customer_Phone;
	string customer_ID;
	string assigned_producer;

};

struct Producer //define struct has producer details
{
	string producer_Name;
	string producer_Phone;
	int years_Serviced;
	string producer_ID;
};

Customer customerList[100]; //assign array for customers.
Producer producerList[100]; //assign attay for producers.


void add_customer(int count_c) //adding customeres
{
	        cout<<"-----------Customer "<<count_c+1<<"-----------\n";
			cout << "Enter new customer details \nname:";
			cin >>customerList[count_c].customer_Name;
			cout << "Phone: ";
			cin >>customerList[count_c].customer_Phone;
			cout << "ID: ";
			cin >>customerList[count_c].customer_ID;	
		
}

void add_Producer(int count_p) //adding producers
{
        cout<<"-----------Producer "<<count_p+1<<"-----------\n";
		cout << "Enter new producer details \nName: ";
		cin >> producerList[count_p].producer_Name;
		cout << "Phone: ";
		cin >> producerList[count_p].producer_Phone;
		cout << "Years served: ";
		cin >> producerList[count_p].years_Serviced;
		cout << "producer ID: ";
		cin >>  producerList[count_p].producer_ID;
		
}

void disaplycustomer(int count_c)//Display All customers
{
	int i=0;
	do
	{
		cout<<"-----------Customer "<<i+1<<" Details-----------\n";
		cout<<"Customer Name:"<<customerList[i].customer_Name<<endl;
		cout<<"Customer Phone:"<<customerList[i].customer_Phone<<endl;
		cout<<"Customer ID:"<<customerList[i].customer_ID<<endl;
		i++;
	}
	while(i<count_c);
	
}
void disaplyProducer(int count_p)//Display All Producers
{
	int i=0;
	do
	{
		cout<<"-----------Producer "<<i+1<<" Details-----------\n";
		cout<<"Producer Name:"<<producerList[i].producer_Name<<endl;
		cout<<"Producer Phone:"<<producerList[i].producer_Phone<<endl;
		cout<<"Producer Year Served:"<<producerList[i].years_Serviced<<endl;
		cout << "Producer ID: " << producerList[i].producer_ID<<endl;
		i++;
	}
	while(i<count_p);
	
}

void assign_customer(int assign_c,int assign_p,int count_c, int count_p)//Assign customer to producer
{
    //assign custumer
	int found=0;
	int arr1;
	string cust= customerList[assign_c].customer_ID;
	cout << "Enter customer ID: ";
	cin >> cust;
	
	for(arr1=0; arr1<=count_c; arr1++)
	{    
		if(cust==customerList[arr1].customer_ID)
		{
		   found=1;
		   cout << "Exist\n";
		   break;
	    }
	}
	if(found==0)
	{
	   cout<<"Does not Exist\n";
	}
	//assing producer
	int find=0;
	string prod= producerList[assign_p].producer_ID;
    cout << "\nEnter producer ID: ";
    cin >> prod;
    
    for(int arr2=0; arr2<=count_p; arr2++)
    {
    	if(prod==producerList[arr2].producer_ID)
    	{
    	   find=1;
		   cout << "Exist\n";
		   customerList[arr1].assigned_producer=prod;
		   break;
		}
    }
    if(find==0)
	{
		cout<<"Does not Exist\n";
	}
	
	if(found==1&&find==1)
	{
	    cout << "\nAssigned!\n\n";
	}
	else
	{
		cout << "\nNot Assigned\n\n";
	}
}



void search_p(string producerID, int counter_p)//search for Producer using thier id
{
    bool flag=false;
    for(int l=0;l<=counter_p;l++)
{
	if(producerID==producerList[l].producer_ID)
	{
		cout<<"-----------Producer "<<l+1<<" Details-----------\n";
		cout<<"Producer Name:"<<producerList[l].producer_Name<<endl;
		cout<<"Producer Phone:"<<producerList[l].producer_Phone<<endl;
		cout<<"Producer Year Served:"<<producerList[l].years_Serviced<<endl;
		cout << "Producer ID: " << producerList[l].producer_ID;
		flag=true;
		break;
	}
}
if(flag==false)
{
	cout<<"Producer not found!\n\n";
}	
}

void search_c(string ID, int counter_c,int count_p)//search for customer using thier id
{
    bool flag=false;
    for(int l=0;l<=counter_c;l++)
{
	if(ID==customerList[l].customer_ID)
	{
		cout<<"-----------Customer "<<l+1<<" Details-----------\n";
		cout<<"Customer Name:"<<customerList[l].customer_Name<<endl;
		cout<<"Customer Phone:"<<customerList[l].customer_Phone<<endl;
		cout<<"Customer ID:"<<customerList[l].customer_ID<<endl;
		if(customerList[l].assigned_producer.empty()!=1)//check if there is an assigned producer or not 
		{
			cout<<"\n-----------Assigned Producer-----------\n\n";
			search_p(customerList[l].assigned_producer,count_p);//call search function for producers
			cout<<endl;
		}
		flag=true;
		break;
	}
}
if(flag==false)
{
	cout<<"Customer not found!\n\n";
}	
}


void update_c(string ID, int count_c)//Update customer deatalis using customer id
{
	bool flag=false;
    for(int l=0;l<=count_c;l++)
{
	if(ID==customerList[l].customer_ID)
	{
		int op;
		string name,phone;
		flag=true;
		cout<<"customer is located\n";
		cout<<"Do you want to update:\n1.Name\n2.Phone\n";
		cin>>op;
		if(op==1)
		{
			cout<<"Enter the new name: ";
			cin>>name;
			customerList[l].customer_Name=name;
			cout<<"----------The updated vision:----------\n";
			cout<<"Customer Name:"<<customerList[l].customer_Name<<endl;
		    cout<<"Customer Phone:"<<customerList[l].customer_Phone<<endl;
		    cout<<"Customer ID:"<<customerList[l].customer_ID<<endl;
	}
		else if(op==2)
		{
			cout<<"Enter the new phone: ";
			cin>>phone;
			customerList[l].customer_Phone=phone;
			cout<<"----------The updated vision:----------\n";
			cout<<"Customer Name:"<<customerList[l].customer_Name<<endl;
		    cout<<"Customer Phone:"<<customerList[l].customer_Phone<<endl;
		    cout<<"Customer ID:"<<customerList[l].customer_ID<<endl;
		}
		else
		{
			cout<<"Wrong entery!\ntry again\n";	
		}
	}
	
}

    if(flag==false)
    {
	cout<<"Customer not found!\n\n";
    }	
}
void update_p(string producerID, int count_p)//Update producer deatalis using thier id
{
	bool flag=false;
    for(int l=0;l<=count_p;l++)
{
	if(producerID==producerList[l].producer_ID)
	{
		int op,year;
		string phone;
		flag=true;
		cout<<"Producer is located\n";
		cout<<"Do you want to update:\n1.Phone\n2.Year servied.\n";
		cin>>op;
		if(op==1)
		{
			cout<<"Enter the new Phone: ";
			cin>>phone;
			producerList[l].producer_Phone=phone;
			cout<<"Producer Name:"<<producerList[l].producer_Name<<endl;
		    cout<<"Producer Phone:"<<producerList[l].producer_Phone<<endl;
		    cout<<"Producer Year Serviced:"<<producerList[l].years_Serviced<<endl;
		    cout << "Producer ID: " << producerList[l].producer_ID << endl;
			
	}
		else if(op==2)
		{
			cout<<"Enter the new Year servied: ";
			cin>>year;
			producerList[l].years_Serviced=year;
			cout<<"Producer Name:"<<producerList[l].producer_Name<<endl;
		    cout<<"Producer Phone:"<<producerList[l].producer_Phone<<endl;
		    cout<<"Producer Year Serviced:"<<producerList[l].years_Serviced<<endl;
		    cout << "Producer ID: " << producerList[l].producer_ID << endl;
			
		}
		else
		{
			cout<<"Wrong entery!\ntry again\n";	
		}
	}
	
}

    if(flag==false)
    {
	cout<<"Producer not found!\n\n";
    }	
}
void save_c(int count_c)//write customer details in file
{
	ofstream fail;
	fail.open("customer.txt");
	int i=0;
	do
	{
		fail<<"-----------Customer "<<i+1<<" Details-----------\n";
		fail<<"Customer Name:"<<customerList[i].customer_Name<<endl;
		fail<<"Customer Phone:"<<customerList[i].customer_Phone<<endl;
		fail<<"Customer ID:"<<customerList[i].customer_ID<<endl;
		i++;
	}
	while(i<count_c);
	fail.close();
}

void save_p(int count_p)//write produser details in file
{
	ofstream fail;
	fail.open("producer.txt");
	int i=0;
	do
	{
		fail<<"-----------Producer "<<i+1<<" Details-----------\n";
		fail<<"Producer Name:"<<producerList[i].producer_Name<<endl;
		fail<<"Producer Phone:"<<producerList[i].producer_Phone<<endl;
		fail<<"Producer Year Serviced:"<<producerList[i].years_Serviced<<endl;
		fail<<"Producer ID: " << producerList[i].producer_ID<<endl;
		i++;
	}
	while(i<count_p);
	fail.close();
}

void read_p(int count_p)//reading from file
{
	ifstream in_file;
	string line;
	in_file.open("producer.txt");
	
	if(!in_file)
	{
		cerr << "Problem opening file" << endl;
	}
	while(getline(in_file, line))
	{
	   cout << line << endl;
    }
    
	in_file.close();
}



int main()
{
	int option; //choose operation
	int op; //add new customers/producers
	int count_c=0; //number of customers
	int count_p=0; //number of producers
	int c_p; //customer or producer option
	string ID,producerID; //search for a member by using thier ID.
	int assign_c, assign_p; //assign
	
	do
	{
		cout << "========Elecritcal Grid System========" << endl;
		cout << "Choose of the following: " << endl;
	    cout << "1. Add new customer/producer\n2. Assign customer to producer\n";
	    cout << "3. Update customer/producer details\n4. Show customer/producer lists\n5. Search for a specific customer/producer details";
	    cout << "\n6. save customer/producer informations in file\n7. disiplay from file\n8. Exit";
	    cout <<"\n\nEnter your choice: ";
	    cin >> option;
		switch(option)
	    {
		     case 1: 
		        {
			     cout << endl << "===================\nAdd new \n1/ customer\n2/ producer\n\nEnter your choice: ";
			     cin >> c_p;//customer or producer
			     if(c_p==1)
			        {
				      //adding new customer function
				      cout << "\n------Add customer------\n\n";
				      do{
				      	add_customer(count_c);
				      	count_c++;
				      	cout << "\nAdd another customer: \n1. Yes\n2. exit \nEnter your choice: ";
		                cin >> op;
		                while(op !=1 && op!=2)
		                {
		                	cout << "\nwrong choice! Try again.\n";
		                	cout << "\nAdd another customer: \n1. Yes\n2. exit \nEnter your choice: ";
		                    cin >> op;
			            }
		                if(op==1)
		                  {
			                 continue;
		                  }
		                else
		                   {
			                 cout << "\nAdded customer/s successfully\n\n";
			                 break;
		                   }
			            		  }
			            		  while(count_c<100);
			                    }
			     else if(c_p ==2)
			        {
			        	//adding new producer function
			        	cout << "\n------Add producer------\n\n";
				      do{
				      	add_Producer(count_p);;
				      	count_p++;
				      	cout << "\nAdd another producer: \n1. Yes\n2. exit \nEnter your choice: ";
		                cin >> op;
		                while(op !=1 && op!=2)
		                {
		                	cout << "\nwrong choice! Try again.\n";
		                	cout << "\nAdd another producer: \n1. Yes\n2. exit \nEnter your choice: ";
		                    cin >> op;
			            }
		                if(op==1)
		                  {
			                 continue;
		                  }
		                else
		                   {
			                 cout << "\nAdded producer/s successfully\n\n";
			                 break;
		                   }
			            		  }
			            		  while(count_p<100);
			        }
			     else
			        {
		             cout << "Wrong chioce! Please try again.\n\n";
		            }
		        break;
		        }
		     case 2:
			    {
				 cout << endl << "------Assign a customer to producer------\n\n";
				 
				 assign_customer(assign_c,assign_p,count_c,count_p);
				 
				 break;
			    }
		     case 3:
			    {
				 cout << endl << "Update details for: \n1/ customer\n2/ producer\nEnter your choice: ";
				 cin >> c_p;
			     if(c_p==1)
			        {
			        	cout << "update customer detials\n\n";
			        	cout<<"Enter customer ID: ";
			            cin>>ID;
			        	update_c(ID,count_c);
				      //update customer details function
			        }
			     else if(c_p ==2)
			        {
			        	cout << "update producer details\n\n";
			        	cout<<"Enter Producer ID: ";
			            cin>>producerID;
			        	update_p(producerID,count_p);
				     //update producer details function
			        }
			     else
			        {
		             cout << "Wrong chioce! Please try again.\n\n";
		            }
				 break;
			    }
		     /*case :
			    {
				 cout << endl << "Delete \n1/ customer\n2/ producer \nEnter your choice: ";
				 cin >> c_p;
			     if(c_p==1)
			        {
			        	cout << "delete customer\n\n";
				      //delete customer function
			        }
			     else if(c_p ==2)
			        {
			        	cout << "delete producer\n\n";
				     //delete producer function
			        }
			     else
			        {
		             cout << "Wrong chioce! Please try again.\n\n";
		            }
				 break;
			    }*/
		     case 4:
			    {
				 cout << endl << "Show \n1/ customer lists \n2/ producer lists \nEnter your choice: ";
				 cin >> c_p;
			     if(c_p==1)
			        {
			        	cout << "show customers details\n\n";
			        	disaplycustomer(count_c);
			        	cout<<"\n\n";
				      //show customer lists function
			        }
			     else if(c_p ==2)
			        {
			        	cout << "show Producers details\n\n";
			        	disaplyProducer(count_p);
			        	cout<<"\n\n";
				     //show producer lists function
			        }
			     else
			        {
		             cout << "Wrong chioce! Please try again.\n\n";
		            }
				 break;
			    }
		     case 5:
			    {
				 cout << endl << "Search for a specific \n1/ customer details \n2/ producer details \nEnter your choice: ";
				 cin >> c_p;
			     if(c_p==1)
			        {
					    cout << "------search for a customer------\n";
			            cout<<"Enter customer ID: ";
			            cin>>ID;
			            search_c(ID,count_c,count_p);
			            cout<<"\n\n";
				      //search for a customer details function
			        }
			     else if(c_p ==2)
			        {
			        	cout << "------search for a Producer------\n";
			            cout<<"Enter Producer ID: ";
			            cin>>producerID;
			            search_p(producerID,count_p);
			            cout<<"\n\n";
				     //search for a producer details function
			        }
			     else
			        {
		             cout << "Wrong chioce! Please try again.\n\n";
		            }
			     break;
			    }
			 case 6:
			 	{
			 		cout << endl << "save \n1/ customer\n2/ producer \nEnter your choice: ";
				 cin >> c_p;
			     if(c_p==1)
			        {
				        save_c(count_c);
				        cout << "coustmers informations have been saved. \n";
				        cout<<"---------------------------------------------------------------------\n\n";
			        }
			     else if(c_p ==2)
			        {
				        save_p(count_p);
				        cout << "producers informations have been saved. \n";
				        cout<<"---------------------------------------------------------------------\n\n";
			        }
			     else
			        {
		             cout << "Wrong chioce! Please try again.\n\n";
		            }
				 break;
			 		
				 }
			 case 7:
			 	{
			 		read_p(count_p);
			 		cout<<"---------------------------------------------------------------------\n\n";
			 break;
			    }
				 
		     case 8:
			    {
				 cout << endl << "\nProgram terminated! Thank you.\n";
				 break;
			    }
		     default:
			     cout << endl << "Wrong choice! Please try again.\n\n";
		}
	}while(option!=8);
	
	
	
	return 0;
}

