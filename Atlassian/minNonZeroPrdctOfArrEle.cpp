#define mod 1000000007
typedef long long ll;
class Solution {
public:

        ll pwr(ll a, ll b){
            ll ans = 1;
            while(b){
                if(b&1) ans = (ans%mod*a%mod) %mod;
                a = (a%mod*a%mod) %mod;
                b>>=1;
            }
            return ans;
        }
        int minNonZeroProduct(int p){
            ll mx = (1LL << p) -1;
            return (pwr((mx - 1+mod)%mod, mx/2) % mod *(mx % mod))%mod;      
    }
};
