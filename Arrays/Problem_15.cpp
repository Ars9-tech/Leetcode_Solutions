//3 Sum Problem
//---------------

  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int n = nums.size();
        //sorting the array
        sort(nums.begin(), nums.end());
        // fixing the first number
        for(int i = 0 ; i<= n-2 ; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            

            int helper = -nums[i];// target(helper)= -first number
            int left = i+1;
            int right = n-1;

            while(left<right){
                int sum = nums[left]+nums[right];
                if(sum==helper){
                    result.push_back({nums[i],nums[left],nums[right]});
                    // skip the duplicates
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum<helper){
                    left++;
                }
                else
                    right--;
            }
        }
        return result;

     }
};
