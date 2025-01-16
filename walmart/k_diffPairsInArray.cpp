class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> mp; // no and its freq
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count = 0; // no of unique pair
        if(k==0) {
            for(auto x : mp){
                if(x.second > 1){
                    count++;
                }
            }
            return count;
        }
        for(auto x : mp){
            if (mp.count(x.first -k)) count++;
        }
        return count;

    }
};
