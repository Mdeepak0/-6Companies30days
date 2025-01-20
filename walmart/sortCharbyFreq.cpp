class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        unordered_map<char, int> mp; 
        // to count freq of each char;
        for(int i =0;i<n;i++){
            mp[s[i]]++;
        }

         priority_queue<pair<int, char>> pq; // to store the characters based on frequency

        // Push all characters with their frequencies into the priority queue
        for(auto& entry : mp) {
            pq.push({entry.second, entry.first});
        }
        string ans = "";
        while(!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            
            // Append the character 'freq' times to the result string
            for(int i = 0; i < freq; i++) {
                ans += ch;
            }
        }
        
        return ans;
    }
};
