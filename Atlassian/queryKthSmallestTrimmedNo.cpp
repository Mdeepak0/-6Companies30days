int k,x,i,j,n;
string temp,temp1;
vector<pair<string,int>> v;
bool compare(pair<string,int>&a,pair<string,int>&b){
    if(a.first.size() == b.first.size()){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    else {
        return a.first.size() < b.first.size();
    }
}
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        n = queries.size();
        vector<int>ans(n);
        for(int i =0;i<n;i++){
            k = queries[i][0];
            x = queries[i][1];
            v.clear();
            for(int j = 0;j<nums.size();j++){
                temp = nums[j];
                temp1 = "0";
                if(temp.size() >= x){
                    temp1 = temp.substr(temp.size()-x);
                }
                v.push_back({temp1,j});
            }
            sort(v.begin(),v.end(),compare);
            ans[i] = v[k-1].second;
        }
        return ans;
    }
};
