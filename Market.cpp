//limitation of this project :does not update the quantity in the file only maintain in memory
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int i = 0;
class Item
{
public:
	vector<string> item;
	vector<int> rate;
	vector<int> quantity;
	Item()
	{
	}
	Item(string it, int r, int q)
	{
		item.push_back(it);
		rate.push_back(r);
		quantity.push_back(q);
	}
	void addItem()
	{
		ofstream file("ItemInventory.txt", ios::app);
		if (file.is_open())
		{
			int  r, q;
			string i;
			cout << "Enter Item name:";
			cin >> i;
			item.push_back(i);
			cout << "Enter rate of Item:";
			cin >> r;
			rate.push_back(r);
			cout << "Enter quantity of Item:";
			cin >> q;
			quantity.push_back(q);
			if (file.is_open())
			{
				file << "****************************" << '\n';
				file << "    NAME OF ITEM     : " << i << '\n';
				file << "    RATE OF ITEM     : " << r << '\n';
				file << "    QUANTITY OF ITEM : " << q << '\n';
				file << "****************************" << '\n';
				file << '\n';
				file << '\n';
			}
			cout << "******ITEM ADDED SUCCESSFULLY******" << '\n' << '\n';
		}
		file.close();
	}
};
class Bill :public Item
{
public:
	string chi;
	int chsnQ;
	int totalBill;
	Bill()
	{
		chi = "";
		chsnQ = 0;
		totalBill = 0;
	}

	void updateQuantityInFile() {
		ofstream file2("ItemInventory.txt");
		for (int i = 0; i < item.size(); i++) {
			file2 << "****************************" << '\n';
			file2 << " NAME OF ITEM : " << item[i] << '\n';
			file2 << " RATE OF ITEM : " << rate[i] << '\n';
			file2 << " QUANTITY OF ITEM : " << quantity[i] << '\n';
			file2 << "****************************" << '\n';
			file2 << '\n'; file2 << '\n';
		}
		file2.close();
	}

	void order()
	{
		cout << "****ENTER THE REQUIRED INFO OF ITEM*****" << '\n';
		cout << "Enter item name:";
		cin >> chi;
		cout << "Enter quantity of item:";
		cin >> chsnQ;
		int r = 0;
		int q = 0;
		int check = 0;
		int index = 0;
		for (int i = 0; i < item.size(); i++)
		{
			if (chi == item[i])
			{
				r = rate[i];
				q = quantity[i];
				check = 1;
				index = i;
			}
		}
		if (check == 0)
		{
			cout << "!!!!!!!!!ITEM NOT FOUND!!!!!!!!" << '\n' << '\n';
			return;
		}
		else if (q == 0)
		{
			cout << "!!!!!!!!ITEM IS FINISHED!!!!!!!!!" << '\n' << '\n';
			return;
		}
		else if (chsnQ > q)
		{
			cout << "!!!!!!!!NOT ENOUGH QUANTITY!!!!!!!!" << '\n' << '\n';
			return;
		}
		else
		{
			ofstream file("Reciept.txt", ios::app);
			q = q - chsnQ;
			quantity.at(index) = q;
			file << "****************************" << '\n';
			file << "    NAME OF ITEM     : " << chi << '\n';
			file << "    RATE OF ITEM     : " << r << '\n';
			file << "    CHOSEN QUANTITY  : " << chsnQ << '\n';
			file << "    AMOUNT FOR THIS  : " << chsnQ * r << '\n';
			file << "****************************" << '\n';
			file << '\n';
			file << '\n';
			totalBill = totalBill + (chsnQ * r);
			updateQuantityInFile();
			return;
		}
	}
	void reciept()
	{
		char c;
		ifstream file;
		file.open("reciept.txt");
		while (!file.eof())
		{
			file.get(c);
			cout << c;
		}
		file.close();
		ofstream f("reciept.txt", ios::app);
		f << "TOTAL BILL:" << totalBill << '\n';
		f.close();
		cout << '\n' << "YOUR TOTAL BILL:" << totalBill << '\n';
	}
};
void superMarket()
{
	Bill a;
	cout << "**************WELCOME TO THE SUPERMARKET*************" << '\n';
	cout << "           ******ENJOY YOUR SHOPPING*********" << '\n';
	cout << "1.ADD ITEM IN INVENTORY." << '\n';
	cout << "2.BUY ITEM." << "\n";
	cout << "CHOOSE (1 OR 2):" << '\n';
	int c;
	cin >> c;
	while (c != 1 && c != 2)
	{
		cout << "enter valid number" << '\n';
		cin >> c;
	}
	if (c == 1)
	{
		while (c == 1)
		{
			a.addItem();
			cout << "->press 1 if you want to add more item.\n->any other if you want to quit.\n->press 2 to buy item :" << '\n';
			cin >> c;
		}
		if (c == 2)
		{
			while (c == 2)
			{
				a.order();
				cout << "->press 2 if you want to buy more item \n->press any other key to print reciept:" << '\n';
				cin >> c;
			}
			if (c != 2)
			{
				a.reciept();
			}
		}
	}
	else
	{
		while (c == 2)
		{
			a.order();
			cout << "press 1 if you want to buy more item otherwise press any other key to print reciept:" << '\n';
			cin >> c;
		}
		if (c != 2)
		{
			a.reciept();
		}
	}
	cout << "*****THANK YOU FOR SHOPPING*****" << '\n';
	cout << "********HAVE A NICE DAY*********";
}

int main()
{
	superMarket();
}