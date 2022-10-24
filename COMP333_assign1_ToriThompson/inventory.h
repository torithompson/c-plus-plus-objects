#include <iostream>
#include <string> 
#include <fstream>
#include <iomanip>

//Tori Thompson
//Specification file for Assignment 1

using namespace std;

struct ProductRec
{
	int prodCode;
	string desc;
	double price;
};

const int SIZE = 25;

class Inventory
{
public:
	Inventory(string/*filename*/, int = SIZE /*maxProducts*/);
	void showProduct(int /*product code*/) const;
	void writeInventory(ostream& /*output file*/) const;
	int getNoProducts() { return numProducts; }
	void increasePrice(int /*product code*/, double /*price increase*/);
private:
	ProductRec inventoryList[SIZE];
	int maxProducts;
	int numProducts;
	int searchProduct(int /*inventory list*/)const;
};
