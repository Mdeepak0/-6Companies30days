class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
         unordered_map<int, int> freq;
         int left = 0, max_len = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // Increment frequency of the current element
        freq[nums[right]]++;

        // If any element's frequency exceeds k, shrink the window from the left
        while (freq[nums[right]] > k) {
            freq[nums[left]]--;
            left++;
        }

        // Update the maximum length of the valid window
        max_len = max(max_len, right - left + 1);
    }

    return max_len;

    }
};
