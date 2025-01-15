class Solution {
public:
unordered_set<string> st; // To store the dictionary words for quick lookup
    int n; // Length of the string
    int dp[301]; 

   
    bool solve(int idx, string &s) {
        if (idx == n) {
            return true; // If we've processed the entire string, return true
        }
        if (dp[idx] != -1) {
            return dp[idx]; // If already computed, return the stored result
        }
        
        // Try all possible substrings starting from idx
        for (int l = 1; l <= n - idx; l++) {
            string temp = s.substr(idx, l); // Extract substring
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return dp[idx] = true; // If valid substring and remainder can also be broken
            }
        }
        return dp[idx] = false; // If no valid substring found
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        n = s.length(); // Initialize the length of the string
        memset(dp, -1, sizeof(dp)); // Initialize the DP table with -1
        st.clear(); // Clear the set before using it

        // Insert all words from the dictionary into the set
        for (string &word : wordDict) {
            st.insert(word);
        }

        // Start the recursion from index 0
        return solve(0, s);
    }
};
