class DisjointSet{
    vector<int> parent , size;
    public : 
        DisjointSet(int n){
            size.resize(n , 1);
            parent.resize(n);
            for(int i=0 ; i<n ; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int u , int v){
            int ult_u = findUParent(u);
            int ult_v = findUParent(v);

            if(ult_u == ult_v) return;

            if(size[ult_u] < size[ult_v]){
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }else{
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }

        int count(){
            int n = parent.size();
            cout << n<< endl;
            int cnt = 0;
            for(int i=0 ; i<n ; i++){
                if(parent[i] == i) cnt++;
            }

            return cnt;
        }

        vector<vector<string>> helper(vector<vector<string>>& accounts){
            int n = accounts.size();
            unordered_map<int , set<string>> mp;

            for(int i=0 ; i<n ; i++){
                int root = findUParent(i);
                for(int j=1 ; j<accounts[i].size() ; j++){
                    mp[root].insert(accounts[i][j]);
                }
            }

            vector<vector<string>> ans;

            for(auto it : mp){
                vector<string> temp;
                temp.push_back(accounts[it.first][0]);

                for(auto email : it.second){
                    temp.push_back(email);
                }

                ans.push_back(temp);
            }

            return ans;

        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;

        for(int i=0 ; i<n ; i++){
            int size = accounts[i].size();
            for(int j=1 ; j<size; j++){
                string email = accounts[i][j];
                if(mp.count(email)){
                    ds.unionBySize(i , mp[email]);
                }else{
                    mp[email] = i;
                }
            }
        }

        return ds.helper(accounts);

    }
};