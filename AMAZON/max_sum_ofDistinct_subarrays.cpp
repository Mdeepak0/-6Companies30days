class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), i=0, j=0;
        //prepare a set to keep tracking of prev element if any duplicate is present
        // agar window ka size equal to k then update max_sum and move i pointer
        long long max_sum = 0;
        long long currWindow_sum =0;
        unordered_set<int> st;
        while(j<n){
           // nums[j] already present in current window nums[i] to noms[j]
           while(st.count(nums[j])){
            currWindow_sum -= nums[i];
            st.erase(nums[i]);
            i++;
           }
           currWindow_sum += nums[j];
           st.insert(nums[j]);

           if(j-i+1 == k){
            max_sum = max(max_sum,currWindow_sum);
            currWindow_sum -= nums[i];
             st.erase(nums[i]);
             i++;
           }
           j++;
        }
        return max_sum;

    }
};
