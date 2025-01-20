class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
         int n = nums.size();
        
        int sum = 0;
        int currentF = 0;
        
        // Calculate F(0) and the sum of elements in nums
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            currentF += i * nums[i];
        }
        
        int maxF = currentF;
        
        // Calculate F(k) from F(k-1) for k = 1 to n-1
        for (int k = 1; k < n; k++) {
            currentF = currentF + sum - n * nums[n - k];
            maxF = max(maxF, currentF);
        }
        
        return maxF;

    }
};
