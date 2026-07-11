4Sum Problem
--------------

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        int n = nums.size();
        //sorting the array
        sort(nums.begin(), nums.end());
        // first number represented as i
        for(int i = 0; i<n-3; i++){
            if(i>0 && nums[i-1]== nums[i])continue;
            //second number taken as j
            for(int j = i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                
                //remaining target- to get other two numbers
                long long remainingTarget= (long long )target-nums[i]-nums[j];
                //using two pointers
                int left = j+1;//initiallization of left pointer
                int right = n-1;//initialization of right pointer
                while(left<right){
                    long long sum = (long long) nums[left]+nums[right];
                    if(sum<remainingTarget)
                        left++;
                    else if(sum>remainingTarget)
                        right--;
                    else{
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        //to slip duplicates
                        int prevLeft = nums[left];
                        int prevRight = nums[right];

                        while(left<right && nums[left]==prevLeft)
                            left++;
                        while(left<right && nums[right]==prevRight)
                            right--;
                    }
                }
            }
        }
        return result;

        
    }
};
