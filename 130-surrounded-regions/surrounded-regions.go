func dfs(r int , c int , board [][]byte , visited [][]bool){
    visited[r][c] = true

    dr := []int{0 , 0 , 1 , -1}
    dc := []int{1 , -1 , 0 , 0}

    for i:=0 ; i<4 ; i++ {
        nr := r + dr[i]
        nc := c + dc[i]

        if nr < 0 || nr >= len(board) || nc < 0 || nc >= len(board[0]) || visited[nr][nc] || board[nr][nc] == 'X' {
            continue;
        }

        dfs(nr , nc , board , visited)
    }
}

func solve(board [][]byte)  {
    m := len(board)
    n := len(board[0])

    visited := make([][]bool , m)
    for i:=0 ; i<m ; i++ {
        visited[i] = make([]bool , n)
    }

    for i:=0 ; i<m ; i++{
        if board[i][0] == 'O' {
            dfs(i , 0 , board , visited)
        }
        if board[i][n-1] == 'O'{
            dfs(i , n-1 , board , visited)
        }
    }

    for i:=0 ; i<n ; i++ {
        if board[0][i] == 'O'{
            dfs(0 , i , board , visited)
        }
        if board[m-1][i] == 'O'{
            dfs(m-1 , i , board , visited)
        }
    }

    for i:= 0 ; i<m ; i++ {
        for j :=0 ; j<n ; j++ {
            if !visited[i][j] {
                board[i][j] = 'X'
            }
        }
    }
}