#include<bits/stdc++.h>
using namespace std;

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int mapp[100001] = {0};

    for(int i=2; i<100001; i+=2)
    {
        mapp[i] = 2;
    }

    for(int i = 3; i<=sqrt(100001)+1; i++) {
        for(int j=i*i; j<100001; j+=i) {
            if(mapp[j] == 0) mapp[j] = i;
        }
    }

    set<int> ans;

    for(int i=0; i<n; i++) {
        if(mapp[arr[i]] == 0) ans.insert(arr[i]);
        else ans.insert(mapp[arr[i]]);
    }

    cout<<ans.size();

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
