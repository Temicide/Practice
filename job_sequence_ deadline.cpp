//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution
{


    public:
    static bool compare(Job a, Job b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, compare);
        int deadline[10001];
        int prof = 0;
        int cnt = 0;
        memset(deadline, 0, sizeof(deadline));
        for(int i = 0; i < n; i++){
            int tm = arr[i].dead;
            for(int j = tm; j > 0; j--){
                if(deadline[j] == 0){
                    cnt++;
                    prof+=arr[i].profit;
                    deadline[j]=-1;
                    break;
                }
            }
        }
        vector<int>result;
        result.push_back(cnt);
        result.push_back(prof);
        return result;
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
