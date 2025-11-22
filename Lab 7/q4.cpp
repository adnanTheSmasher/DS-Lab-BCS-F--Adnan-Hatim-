#include <iostream>  
using namespace std;

struct Product {
	string name;
	double price;
    string description;
	bool inStock;
};

int partition(Product a[], int start, int end)
{
    Product pivot = a[end]; 
    int i = start - 1;  

    for (int j = start; j < end; j++) {
        if (a[j].price <= pivot.price) {
            i++;
    
            Product t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    
    Product t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;

    return i + 1; 
}



void quick(Product a[], int start, int end) 
{
    if (start < end)
    {
        int p = partition(a, start, end);   
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}


void printArr(Product a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i].name << " - $"<< a[i].price << endl;
}
int main()
{
    Product product1 = { "Product 1", 10.99, "This is product 1.", true };
    Product product2 = { "Product 2", 5.99, "This is product 2.", false };
    Product product3 = { "Product 3", 2.99, "This is product 3.", true };

	Product a[] = { product1, product2, product3 };
	int n = sizeof(a) / sizeof(a[0]);

    quick(a, 0, n - 1);
    cout << "\nProduct Sorted by price - \n";
    printArr(a, n);

    return 0;
}
