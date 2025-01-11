class Solution {
public:

     void floydWarshall(vector<vector<long long>>& adJmatrix,
     vector<char>& original, vector<char>& changed, vector<int> &cost){
        for(int i =0;i<original.size();i++){
            char s = original[i]-'a';
            int t = changed[i]-'a';
            adJmatrix[s][t] = min(adJmatrix[s][t], (long long)cost[i]);

        }
        // floyd warshall

        for(int k =0;k<26;k++){
            for(int i =0;i<26;i++){
                for(int j=0;j<26;j++){
    adJmatrix[i][j] = min(adJmatrix[i][j],adJmatrix[i][k]+adJmatrix[k][j]);  
                }
            }
        }
     }

    long long minimumCost(string source, string target,
     vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> adJmatrix(26,vector<long long>(26,INT_MAX));

        floydWarshall(adJmatrix, original,changed,cost); // will update adJmatrix with shortest path using warshsall algo

        long long ans =0;
        for(int i =0; i<source.length();i++){
            if(source[i] == target[i]){
                continue;
            }
          if (adJmatrix[source[i]-'a'][target[i]-'a']== INT_MAX){
            return -1;
          } 
          ans += adJmatrix[source[i]-'a'][target[i]-'a']; 
        }
        return ans;
    }
};
