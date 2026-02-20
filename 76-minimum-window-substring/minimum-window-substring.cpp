class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())return "";

        vector<int> freq(128,0);
        for(char ch : t){
            freq[ch]++;
        }
        int l=0,r=0;
        int start = 0;
        int required = t.size(),ans=INT_MAX;

        while(r < s.size()){
            if(freq[s[r]] > 0){
                required--;
            }

            freq[s[r]]--;
            r++;

            while(required == 0){
                if(r - l < ans){
                    ans = r - l;
                    start = l;
                }

                freq[s[l]]++;
                if(freq[s[l]] > 0){
                    required++;
                }
                l++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start , ans);
    }
};