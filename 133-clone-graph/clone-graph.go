/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil{
        return nil
    }

    visited := make(map[*Node]*Node)

    var dfs func(*Node) *Node
    dfs = func (curr *Node) *Node {
        if clone , exist := visited[curr]; exist { 
            return clone
        }

        clone := &Node{Val : curr.Val}
        visited[curr] = clone

        for _ , neighbor := range curr.Neighbors {
            clone.Neighbors = append(clone.Neighbors , dfs(neighbor))
        }

        return clone
    }
    return dfs(node)
}