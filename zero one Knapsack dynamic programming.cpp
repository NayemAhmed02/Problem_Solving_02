#include<bits/stdc++.h>
using namespace std;

class Product
{
public:
    int profit;
    int weight;
};

int zeroOneKnapsackDP(Product* products, int N, int capacity)
{
    // create (N+1) * (capacity+1) 2D matrix
    int dp[N+1][capacity+1];

    // initialize first row by zero
    for(int j=0; j<=capacity; j++)
    {
        dp[0][j] = 0;
    }

    // initialize first column by zero
    for(int i=0; i<=N; i++)
    {
        dp[i][0] = 0;
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            // if current capacity is less than current item weight
            if(j < products[i-1].weight)
            {
                dp[i][j] = dp[i-1][j];
            }
            // else we have an option either add this item or not
            else
            {
                // if current item add to knapsack
                int chooseCurrent = products[i-1].profit + dp[i-1][j - products[i-1].weight];
                // if current item is not add
                int doNotChooseCurrent = dp[i-1][j];
                // take maximum between them
                dp[i][j] = max(chooseCurrent, doNotChooseCurrent);

                //dp[i][j] = max(dp[i-1][j], products[i-1].profit + dp[i-1][j - products[i-1].weight]);
            }
        }
    }

    return dp[N][capacity];
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

    int maxProfit = zeroOneKnapsackDP(products, N, capacity);

    cout<<"\n\nMaximum possible profit is: "<<maxProfit<<"\n";

    // release memory
    delete [] products;

    return 0;
}

