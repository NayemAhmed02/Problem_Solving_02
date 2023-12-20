#include<bits/stdc++.h>
using namespace std;

class Product
{
public:
    int profit;
    int weight;
};

int zeroOneKnapsack(Product* products, int N, int capacity)
{
    // if no item left or capacity became zero
    if(N == 0 || capacity == 0) return 0;

    // if current item weight is larger than our capacity than just ignore current item and call forward
    // Note: since 0 based index is used so for access value we N-1, example: products[N-1].weight
    if(capacity < products[N-1].weight) {
        return zeroOneKnapsack(products, N-1, capacity);
    }

    // add current item to knapsack
    int chooseCurrent = products[N-1].profit + zeroOneKnapsack(products, N-1, capacity-products[N-1].weight);
    // do not current item to knapsack
    int doNotChooseCurrent = zeroOneKnapsack(products, N-1, capacity);
    // return maximum between them
    return max(chooseCurrent, doNotChooseCurrent);
}

int main()
{
    int N, capacity;
    cout<<"Enter number of items: ";
    cin>>N;
    cout<<"Enter maximum capacity of knapsack: ";
    cin>>capacity;

    Product* products = new Product[N];
    cout<<"\n\nEnter every items weight and profit: \n\n";
    for(int i=0; i<N; i++)
    {
        cout<<"Enter "<<i+1<<"th item weight and profit respectively: ";
        cin>>products[i].weight>>products[i].profit;
    }

    int maxProfit = zeroOneKnapsack(products, N, capacity);

    cout<<"\n\nMaximum possible profit is: "<<maxProfit<<"\n";

    // release memory
    delete [] products;

    return 0;
}
