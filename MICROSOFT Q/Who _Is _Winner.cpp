class Solution {
public:
    int findWinnerIdx(int n, int k){
        if (n==1){ // base case
            return 0;
        }
         int idx = findWinnerIdx(n-1, k);
         idx = (idx + k) % n; // org idx in org arr
          return idx;
    }

    int findTheWinner(int n, int k) {

        int ans_idx = findWinnerIdx(n,k);
        return ans_idx+1;
    }
};
