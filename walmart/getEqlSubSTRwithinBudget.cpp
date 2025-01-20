class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int max_length = 0;
        int i = 0,j =0;
        int currCost = 0;
        while(j<n){
            currCost += abs(s[j] -t[j]);
            while(currCost > maxCost){
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            max_length = max(max_length, j-i+1);
            j++;
        }
        return max_length;
    }
};
