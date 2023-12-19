#include<bits/stdc++.h>
using namespace std;

#define N 7

class Product
{
public:
    int weight;
    int profit;
};

bool compare(Product a, Product b)
{
    return (a.profit / a.weight) > (b.profit / b.weight);
}

int fractionalKnapsack(Product* products, int capacity)
{
    // first sort the array according to the ratio of profit and weight of an product (products[i][1] / products[i][0]) in decreasing order
    sort(products, products+N, compare);

    int maxProfit = 0, i = 0;

    while(i < N)
    {
        if(capacity >= products[i].weight)
        {
            maxProfit += products[i].profit;
            capacity -= products[i].weight;
        }
        else {
            maxProfit += ((products[i].profit * capacity) / products[i].weight);
            break;
        }

        i++;
    }

    return maxProfit;
}

int main()
{
    Product* products = new Product[N];
    int capacity;
    cout<<"Enter the maximum capacity of your bag: ";
    cin>>capacity;
    cout<<"\n\nNow enter product weight and profit respectively for every product: \n\n";
    for(int i=0; i<N; i++)
    {
        cout<<"Enter "<<i+1<<"th product weight & profit respectively: ";
        cin>>products[i].weight>>products[i].profit;
    }

    int maxProfit = fractionalKnapsack(products, capacity);

    cout<<"\n\nyour maximum possible profit will be: "<<maxProfit<<"\n";

    // release memory
    delete [] products;

    return 0;
}
