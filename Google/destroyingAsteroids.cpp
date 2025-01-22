class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long currentMass = mass;
        for(int i =0;i<n;i++){
            if(nums[i] <= currentMass) currentMass += nums[i];
            else return false;
        }
        return true;
    }
};
