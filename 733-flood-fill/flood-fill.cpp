class Solution {
public:
    void dfs(vector<vector<int>>& image , int sr , int sc , int color , int starting){
        int m = image.size(), n = image[0].size();
        if(sr < 0 || sr >=m || sc < 0 || sc >=n || image[sr][sc] != starting || image[sr][sc] == color){
            return;
        }

        image[sr][sc] = color;

        dfs(image , sr+1 , sc , color , starting);
        dfs(image , sr-1 , sc , color , starting);
        dfs(image , sr , sc+1 , color , starting);
        dfs(image , sr , sc-1 , color , starting);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image , sr , sc , color , image[sr][sc]);
        return image;
    }
};