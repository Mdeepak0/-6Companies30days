class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> substringCount;
        vector<string> ans;
    
    // Sliding window of length 10
    for (int i = 0; i < s.length(); i++) {
        string substring = s.substr(i, 10);  // Extract 10-length substring
        substringCount[substring]++;  // Count the occurrence of this substring
    }

   
    for (const auto& entry : substringCount) {
        if (entry.second > 1) {
            ans.push_back(entry.first);
        }
    }
    
    return ans;

    }
};
