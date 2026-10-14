func dfs(r int , c int , heights [][]int , visited [][]bool){
    visited[r][c] = true

    dr := []int{0 , 0 ,1 , -1}
    dc := []int{1 , -1 , 0 , 0}

    for i:=0 ; i<4 ; i++ {
        nr := r + dr[i];
        nc := c + dc[i];

        if nr <0 || nr >= len(heights) || nc < 0 || nc >= len(heights[0]) || visited[nr][nc] || heights[r][c] > heights[nr][nc] {
            continue;
        }

        dfs(nr , nc , heights , visited)
    }
}

func pacificAtlantic(heights [][]int) [][]int {
    m := len(heights)
    n := len(heights[0])

    pecific := make([][]bool , m)
    atlantic := make([][]bool , m)

    for i :=0 ; i<m ; i++ {
        pecific[i] = make([]bool , n)
        atlantic[i] = make([]bool , n)
    }

    for i:=0 ; i < m ; i++ {
        dfs(i , 0 , heights , pecific)
        dfs(i , n-1 , heights , atlantic)
    }
    for i:=0 ; i<n; i++ {
        dfs(0 , i , heights , pecific)
        dfs(m-1 , i , heights , atlantic)
    }

    ans := [][]int{}

    for i:=0 ; i<m ; i++{
        for j:=0 ; j<n ; j++ {
            if pecific[i][j] && atlantic[i][j] {
                ans = append(ans , []int{i , j})
            }
        }
    }
    return ans
}