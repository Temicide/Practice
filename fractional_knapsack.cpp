//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double sum = 0, prof = 0;
        int tmp, pos; 
        priority_queue<pair<double, int>> r; 
        for(int i = 0; i < n; i++){
            r.push({double(arr[i].value)/double(arr[i].weight), i});
        }
        
        for(int i = 0; i < n; i++){
            pos = r.top().second; 
            r.pop();
            sum += arr[pos].weight; 
            prof += arr[pos].value; 
            if(sum > W)break;
        }
        
        if(sum > W)prof -= double(arr[pos].value) / double(arr[pos].weight) * (sum-W);
        return prof; 
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
