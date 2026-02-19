class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = -1;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            int mod = sum % k;
            if(mp.count(mod)){
                if(i - mp[mod] >= 2){
                    return true;
                }
            }else{
                mp[mod] = i;
            }
        }

        return false;
    }
};