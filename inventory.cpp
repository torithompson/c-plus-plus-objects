#include "inventory.h"

//Tori Thompson
//Implementation file for Assignment 1

Inventory::Inventory(string filename, int initMaxProducts)
{
	maxProducts = initMaxProducts;
	if (initMaxProducts > SIZE)
	{
		maxProducts == SIZE;
	}

	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Unable to open " << filename << endl;
		system("pause");
		exit(-1);
	}
	int length = 0;
	for (; length < maxProducts; length++)
	{
		fin >> inventoryList[length].prodCode;
		fin.ignore(80, '\n');
		getline(fin, inventoryList[length].desc);
		fin >> inventoryList[length].price;
		if (fin.eof())
		{
			break;
		}
	}
	numProducts = length;
}
void Inventory::writeInventory(ostream& out) const
{
	int index = 0;
	out << fixed << setprecision(2);
	if (numProducts != 0)
	{
	out << left << setw(15) << "Product Code" << setw(15) << "Description" 
		<< setw(10) << right << "Price" << endl << endl;
		for (0; index < numProducts; index++)
		{
			out << left << setw(15) << inventoryList[index].prodCode << setw(15) << inventoryList[index].desc
				<< setw(10) << right << inventoryList[index].price << endl;
		}
		out << endl << "Number of products: " << index << endl << endl;
	}
}
void Inventory::showProduct(int prodCode) const
{
	int pos = searchProduct(prodCode);
	if (pos > numProducts)
	{
		cout << "The product is " << inventoryList[pos].desc << endl;
		cout << "The price is " << inventoryList[pos].price << endl;
	}
	else
		cout << "Product not found." << endl;
}
int Inventory::searchProduct(int inventoryCode) const
{
	int pos = 0;
	for (; pos < numProducts; pos++)
	{
		if (inventoryList[pos].prodCode == inventoryCode)
			break;
	}
	return pos;
}
void Inventory::increasePrice(int prodCode, double increaseAmt)
{
	int pos = searchProduct(prodCode);
	if (numProducts == 0)
		cout << "There are no products in your inventory." << endl;
	else
	{
		if (pos <= numProducts)
		{
			if ((inventoryList[pos].price + increaseAmt) < 1000)
				inventoryList[pos].price += increaseAmt;
			else
			{
				inventoryList[pos].price = 1000;
				cout << "Price set to max of $1000" << endl;
			}
		}
		else
			cout << "That product code does not exist in the inventory." << endl;
	}
}