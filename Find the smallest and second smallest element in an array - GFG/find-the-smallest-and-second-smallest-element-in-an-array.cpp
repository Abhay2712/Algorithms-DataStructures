// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}// } Driver Code Ends


vector<int> minAnd2ndMin(int arr[], int n) {
    int min=arr[0],min2=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<min) {
            min2=min;
            min=arr[i];
        }
        else if(arr[i]>min && arr[i]<min2) min2=arr[i];
        
    }
    if(min2==INT_MAX) return {-1};
    return {min,min2};
}