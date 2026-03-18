class Solution {
    void dfs(int i , vector<vector<int>>& isConnected , vector<int>& vis){
        vis[i] = 1;

        for(int j=0 ; j<isConnected.size() ; j++){
            if(isConnected[i][j] == 1 && !vis[j]){
                dfs(j , isConnected , vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        int ans=0;
        vector<int> vis(n , 0);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i ,isConnected , vis);
                ans++;
            }
        }
        return ans;
    }
};