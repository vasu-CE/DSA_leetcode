class Solution {
public:
    void helper(vector<int>& nums ,int i, int target , vector<int>& temp , vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if (i >= nums.size()) return;

        if(nums[i] <= target){
            temp.push_back(nums[i]);
            helper(nums , i , target-nums[i] , temp , ans);
            temp.pop_back();
        }
        
        helper(nums , i+1 , target , temp , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin() , candidates.end());
        helper(candidates , 0 ,target , temp , ans);
        return ans;
    }
};