class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
       
        int ans = 0;
        for (int i =1;i<=n-2;i++){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
                 int count = 1;
                int j =  i; // we found the peak element here
                while(j>0 and arr[j] > arr[j-1]){
                    j--;
                    count++;
                }
                while (i < n-1 and arr[i]>arr[i+1]){
                    i++;
                    count++;
                }
               ans = max(count,ans);
            }
               
        }
        return ans;
    }
};
