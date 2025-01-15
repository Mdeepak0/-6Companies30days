class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
         vector<pair<int, int>> indexedNums;
    for (int i = 0; i < nums.size(); ++i) {
        indexedNums.push_back({nums[i], i});
    }

    // Step 2: Sort the vector in descending order based on the values of the elements.
    sort(indexedNums.begin(), indexedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; 
    });
    vector<int> result;
    vector<bool> selected(nums.size(), false); // To keep track of selected indices.
    for (int i = 0; i < k; ++i) {
        selected[indexedNums[i].second] = true;
    }  
    for (int i = 0; i < nums.size(); ++i) {
        if (selected[i]) {
            result.push_back(nums[i]);
        }
    }
    return result;
    }
};
