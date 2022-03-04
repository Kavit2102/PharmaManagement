/*                      Project Name : Pharmacy Management System 

                        Created By : Mr. Kavit Desai

                        Language : C++ 

                        Date : 23/02/2022
*/


// HEADER FILES
#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;

// BASE CLASS MEDICINE
class Medicine   
{
public:
    int drug_id[10], drug_qty, med_qty, sel, date, rcpt_no;
    int drug_price[10] = {2, 3, 1, 4, 1, 5, 7, 4, 3, 5} , amount , total_amount = 0;
    string drug_name[10] = {"Probiotics", "Vitamin C(500mg)", "Acid Free C(500mg)", "Women'S Multivate", "Marino Tablet", "Maxi Cal Tablet", "Amino Zinc Tablet", "Burnex", "Fabuloss 5", "Royal Propollen"};
    string name;
    Medicine *next;

    Medicine()                  // CONSTRUCTOR OF CLASS MEDICINE
    {
        next = NULL;
    }
};                              // END OF CLASS MEDICINE

Medicine *head = NULL;          // INITIALIZING HEAD POINTER AS NULL 


// FUNCTION TO TAKE NEW ORDER 
void New_Order()
{
    cout << "\nAdd Order Details\n";
    cout << "_____________________________________ \n\n";
    cout << "**************************************************************************\n";
    cout << "DRUGS ID"
         << "\tDRUGS TYPE"
         << "   \t\tDRUGS NAME"
         << "           DRUGS PRICE(RM)" << endl;
    cout << "**************************************************************************\n";
    cout << "0001"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Probiotics"
         << "			RM 2.00" << endl;
    cout << "0002"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Vitamin C(500mg)"
         << "		RM 3.00" << endl;
    cout << "0003"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Acid Free C(500mg)"
         << "		RM 1.00" << endl;
    cout << "0004"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Women'S Multivate"
         << "		RM 4.00" << endl;
    cout << "0005"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Marino Tablet"
         << "	 	RM 1.00" << endl;
    cout << "0006"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Maxi Cal Tablet"
         << " 		RM 5.00" << endl;
    cout << "0007"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Amino Zinc Tablet"
         << "		RM 7.00" << endl;
    cout << "0008"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Burnex"
         << "			RM 4.00" << endl; // 1353fn
    cout << "0009"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Fabuloss 5"
         << "			RM 3.00" << endl;
    cout << "0010"
         << "\t"
         << "\tOTC"
         << "\t\t"
         << "    Royal Propollen"
         << "		RM 5.00" << endl;
    cout << " " << endl;

    Medicine *newCustomer = new Medicine();

    cout << "\n Enter recipt no. : ";
    cin >> newCustomer->rcpt_no;
    cout << "\n Enter customer's name : ";
    cin>>newCustomer->name;
    cout << "\n Enter date : ";
    cin >> newCustomer->date;
    cout << "\n How many medicines do you want to buy ? (max-10) : ";
    cin >> newCustomer->med_qty;
    if (newCustomer->med_qty > 10)
    {
        cout << "\n Order selection limit exceeded !!!! ";
        return;
    }
    for (int i = 0; i < newCustomer->med_qty; i++)
    {
        cout << "\n Enter your selection : ";
        cin >> newCustomer->sel;
        cout << "\n Medicine name : " << newCustomer->drug_name[--newCustomer->sel];
        cout << "\n Enter the quantity of drug you want : ";
        cin >> newCustomer->drug_qty;
        newCustomer->amount = (newCustomer->drug_qty) * (newCustomer->drug_price[--newCustomer->sel]);
        cout << "\n Amount for this drug : " << newCustomer->amount << " Rs\n\n";
        newCustomer->total_amount += newCustomer->amount;
    }
    cout<<"\n Amount you have to pay : \n"<<newCustomer->total_amount<<" Rs";

    if (head == NULL)
    {
        head = newCustomer;
        return;
    }
    Medicine *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newCustomer;

    cout << "===========================================================================" << endl;
    cout << "Order Taken Successfully" << endl;
    cout << "===========================================================================" << endl;
    cout << "Go to Reciept Menu to Pay The Bill" << endl;
    cout << "===========================================================================" << endl;
    system("PAUSE");
}                                       // END OF NEW_ORDER FUNCTION

// FUNCTION TO DELETE ORDER
void Delete_order()
{
    int recipt_no;
    cout << "\n Enter the recipt no. whose data you want to delete : ";
    cin >> recipt_no;
    if (head == NULL)
    {
        cout << "\n SORRY THE LIST IS EMPTY !!! \n\n";
    }
    else
    {
        Medicine *todelete;

        if (head->rcpt_no == recipt_no)
        {
            todelete = head;
            head = head->next;
        }
        else
        {
            Medicine *temp = head;
            while (temp->next->rcpt_no != recipt_no)
            {
                temp = temp->next;
            }
            todelete = temp->next;
            temp->next = temp->next->next;
        }

        cout << "\n\t Deleted recipt no. : " << todelete->rcpt_no << "\n\t Customer Name :  " << todelete->name << "\n\t Amount Paid : "<<todelete->total_amount<<" Rs\n\t Date : "<<todelete->total_amount;
        delete todelete;
    }
    system("PAUSE");
}                                       // END OF DELETE_ORDER FUNCTION


// FUNCTION TO MODIFY ORDER
void Modify_Order()
{
    int recipt_no;
    cout << "\n Enter recipt no. you want to modify : ";
    cin >> recipt_no;
    Medicine *temp = head;

    if (temp == NULL)
    {
        cout << "\n SORRY !! No order to modify \n\n";
        return;
    }

    while (temp->rcpt_no != recipt_no)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "\n SORRY !! The Order No. you entered is invalid or does not exist !!!";
        return;
    }
    else
    {
        cout << "\n\t DETAILS TO BE MODIFIED :- ";
        cout << "\n Recipt No . : " << temp->rcpt_no;
        cout << "\n Customer Name . : " << temp->name;
        cout << "\n Order Date : " << temp->date;
        cout << "\n Medicines purchased : " << temp->med_qty;
        for (int i = 0; i < temp->med_qty; i++)
        {
            cout << "\n Medicine name : " << temp->drug_name[i];
            cout << "\n Quantity of drug purchased : " << temp->drug_qty;
        }
            cout<<"\nn Total amount paid : "<<temp->total_amount;
        cout << "\n Amount Paid : " << temp->total_amount << " Rs\n\n";
        cout << "\n\t ENTER MODIFIED DETAILS : ";
        cout << "\n Enter recipt no. : ";
        cin >> temp->rcpt_no;
        cout << "\n Enter customer's name : ";
        cin >> temp->name;
        cout << "\n Enter date : ";
        cin >> temp->date;
        cout << "\n How many medicines do you want to buy ? (max-10) : ";
        cin >> temp->med_qty;
        for (int i = 0; i < temp->med_qty; i++)
        {
            cout << "\n Enter your selection : ";
            cin >> temp->sel;
            cout << "\n Medicine name : " << temp->drug_name[--temp->sel];
            cout << "\n Enter the quantity of drug you want : ";
            cin >> temp->drug_qty;
            temp->amount = (temp->drug_qty) * (temp->drug_price[--temp->sel]);
            cout<<"\n Amout of Medicine : "<<temp->amount<<" Rs";
            temp->total_amount += temp->amount;
        }
            cout << "\n Your Total amount is : " << temp->total_amount << " Rs\n\n";

        cout << "\n\n\t DETAILS MODIFIED !!!!";
    }
    system("PAUSE");
}                                           // END OF MODIDY_ORDER FUNCTION


// FUNCTION TO PRINT RECIPT
void Print_Recipt()
{
    int recipt_no;
    cout << " Enter the Reciept Number To Print The Reciept\n";
    cin >> recipt_no;
    cout << "\n";
    cout << "===========================================================================" << endl;
    cout << "\t\tHere is the Order list\n";
    cout << "===========================================================================" << endl;

    Medicine *temp = head;
    if (temp == NULL)
    {
        cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    else{
        while (temp->rcpt_no != recipt_no)
        {
            temp = temp->next;
        }
            cout << "Reciept Number : " << temp->rcpt_no;
			cout << "\n";
			cout << "Customer Name: " << temp->name << endl;

			cout << "Order Date : " << temp->date << endl;

			cout << "_____________________________________________________________________________" << endl;

			cout << "===============================================================================" << endl;
			cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++===============" << endl;
			for (int i = 0; i < temp->med_qty; i++)
			{
				cout << "OTC" << "  \t\t";
				cout << temp->drug_name[i] << "\t\t\t  ";
				cout << temp->drug_qty << "\t\t";
				cout << temp->drug_price[i] << " RM" << endl;
				cout << "_________________________________________________________________________________" << endl;
			}
            cout<<" Total bill is : "<<temp->total_amount<<" Rs";
    }
    system("CLS");    
}                                           // END OF PRINT_RECIPT FUNCTION


// FUNCTION TO PRINT DAILY SUMMARY
void DailySmry()
{
    Medicine *temp = head;
    if(temp == NULL){
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    else{
        cout << "\n";
		cout << "===========================================================================" << endl;
		cout << " \t\tHere is the Daily Summary of All Orders \n"; // print all receipt
		cout << "===========================================================================" << endl;

		while (temp != NULL)
		{

			cout << "Reciept Number : " << temp->rcpt_no;
			cout << "\n";
			cout << "Customer Name: " << temp->name << endl;

			cout << "Order Date : " << temp->date << endl;

			cout << "____________________________________________________________________________" << endl;

			cout << "==========================================================================" << endl;
			cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++==========" << endl;
			for (int i = 0 ; i < temp->med_qty ; i++)
			{
				cout << "OTC" << "  \t\t";
				cout << temp->drug_name[i] << "\t\t";
				cout << temp->drug_qty << "\t\t";
				cout << temp->drug_price[i] << " RM" << endl;
				cout << "_____________________________________________________________________________" << endl;
			}
			cout << "Total Bill is : " << temp->total_amount;

			cout << "\n";
			cout << "\n";
			cout << "\n_______________________________________________________________________________\n";

			temp = temp->next;
		}
	}
}                                           // END OF DAILY SUMMARY FUNCTION

// MAIN FUNCTION
int main()
{
    system("COLOR 0");
    int menu_choice;
    do
    {
        cout << "\t\t\t    Pharmacy Management System \n";
        cout << "\t\t==================================================\n\n";
        cout << "\t\t--------------------------------------------------\n";
        cout << "\t\t||\t1. Take new Medicine order \t\t ||\n";
        cout << "\t\t||\t2. Delete latest Medicine order\t\t ||\n";
        cout << "\t\t||\t3. Modify Order List \t\t\t ||\n";
        cout << "\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
        cout << "\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
        cout << "\t\t||\t6. Exit\t\t\t\t\t ||\n";
        cout << "\t\t--------------------------------------------------\n";
        cout << "Enter choice: ";
        cin >> menu_choice;
        switch (menu_choice)
        {
        case 1:
        {
            New_Order();
            break;
        }

        case 2:
        {
            Delete_order();
            break;
        }

        case 3:
        {
            Modify_Order();
            break;
        }

        case 4:
        {
            Print_Recipt();
            break;
        }

        case 5:
        {
            DailySmry();
            break;
        }

        case 6:
            cout << "You chose to exit !!!";
            break;
        default:
            break;
        }
    } while (menu_choice != 6);
}                                       // END OF MAIN FUNCTION