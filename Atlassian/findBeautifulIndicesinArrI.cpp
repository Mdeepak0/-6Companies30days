class Solution {
public:

    void computeLPS(string pattern, vector<int>&lps){
        int M = pattern.length();
        int len = 0; // len of prev longest pref and suffix

        lps[0] = 0; // bcz there is no proper suffix snd prefi of pattern[0..0]
        int i =1;
        while(i < M){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> KMP(string pat, string txt){
        int N = txt.length();
        int M = pat.length();
        vector<int> result;
        vector<int> lps(M,0);
        computeLPS(pat,lps);

        int i =0; // for text
        int j =0; // for pattern
        while(i < N){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }
            if(j == M){
                result.push_back(i-j);
                j = lps[j-1];
            }else if (i < N and pat[j] != txt[i]){
                    if( j != 0){
                        j = lps[j-1];
                    }else {
                        i++;
                }
            }
        }
        return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> i_indices = KMP(a,s); // already sorted
        vector<int> j_indices = KMP(b,s); // already sorted

        vector<int> result;

        for(int &i : i_indices){
            int left_limit = max(0, i-k);
            int right_limit = min(n-1, i+k);
         auto it = lower_bound(begin(j_indices),end(j_indices),left_limit);

         if(it != j_indices.end() and *it <= right_limit){
            result.push_back(i); // i is beautiful
         }
        }
        return result;
    }
};
