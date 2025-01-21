class Solution {
public:

    unordered_set<string> st;
    int dp[55];
     int n;
    int fn (int idx, string &s){
         if(idx >= n) return 0;
         if (dp[idx] != -1) return dp[idx];
    string currString = "";
    int minExtra = n;
    for(int i = idx;i<n;i++){
            currString.push_back(s[i]);
        int currExtra=(st.find(currString)==st.end()) ? currString.length():0;
            int remainExtra = fn(i+1,s);
           int totalExtra = currExtra+remainExtra;
           minExtra = min(minExtra,totalExtra);
        }
        return dp[idx] =  minExtra;
     }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
      for(string &word : dictionary) st.insert(word);
      return fn(0, s);       
    }
};
