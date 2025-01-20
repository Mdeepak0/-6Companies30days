class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        int countLength = 0;
        
        // Create a 2D dp array to store the lengths of common subarrays
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Loop through both arrays
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    // If the elements match, extend the common subarray length by 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    countLength = max(countLength, dp[i][j]);  // Update the maximum length
                }
            }
        }
        
        return countLength;

    }
};
