class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n = nums.size();    
        sort(begin(nums),end(nums));
       vector<int> dp(n,1);
       vector<int> pre_idx(n,-1);
       int last_chosenidx = 0;
       int max_len = 1;
       for(int i =1;i <n;i++){
        for(int j =0;j<i;j++){
            if(nums[i] % nums[j] == 0){
                if (dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                    pre_idx[i] = j;
                }
                if(dp[i] > max_len){
                    max_len = dp[i];
                    last_chosenidx = i;
                }
            }
         }
       }
       vector<int> ans;
       while(last_chosenidx != -1){
        ans.push_back(nums[last_chosenidx]);
        last_chosenidx = pre_idx[last_chosenidx];
       }
       return ans;
    }
};
