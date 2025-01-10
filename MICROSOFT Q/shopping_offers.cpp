class Solution {
public:
    map<vector<int>,int> mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        if(mp.count(needs)!=0){
            return mp[needs];
        }

        int res = 0;
        for(int i =0;i<needs.size();i++){
            res += (needs[i]*price[i]);
        }

        for(int i =0;i<special.size();i++){
            bool isValidOffer = true;

            for(int j=0;j<needs.size();j++){
                if(needs[j]<special[i][j]){
                isValidOffer = false;
                    break;
                }
            }
            if(isValidOffer){
                for(int j=0; j<needs.size(); j++){
                    needs[j] -= special[i][j];
                }
             int res2 = special[i].back() + shoppingOffers(price,special,needs);
                res = min(res, res2);

                for(int j =0; j<needs.size(); j++){
                     needs[j] += special[i][j];
                }
            }
        }
        return  mp[needs] = res;
    }
};
