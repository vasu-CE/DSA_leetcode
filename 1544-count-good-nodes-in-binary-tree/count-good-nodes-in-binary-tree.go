/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func helper(root *TreeNode , maxi int , ans *int) {
    if root == nil {
        return
    }

    if root.Val >= maxi {
        maxi = root.Val
        (*ans)++;
    }

    helper(root.Left , maxi , ans)
    helper(root.Right , maxi , ans)
}
func goodNodes(root *TreeNode) int {
    ans := 0
    helper(root , math.MinInt , &ans)
    return ans
}