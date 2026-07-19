class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) {
        
        
        sort(arr, arr + n, [](Job &a, Job &b) {
            return a.profit > b.profit;
        });
        
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }
        
        
        vector<int> slot(maxDeadline + 1, -1);
        
        int countJobs = 0;
        int totalProfit = 0;
        
        
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].deadline; j > 0; j--) {
                if(slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {countJobs, totalProfit};
    }
};
