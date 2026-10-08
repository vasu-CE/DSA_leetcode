/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func h2(p *TreeNode , q *TreeNode) bool{
    if p==nil && q==nil {
        return true
    }

    if p == nil || q==nil {
        return false
    }

    if p.Val != q.Val {
        return false
    }

    return h2(p.Left , q.Left) && h2(p.Right , q.Right)
}

func helper(root *TreeNode , subRoot *TreeNode) bool{
    if root == nil {
        return false;
    }

    if (root.Val == subRoot.Val){
       if h2(root , subRoot) {
            return true;
       }
    }

    return helper(root.Left , subRoot) || helper(root.Right , subRoot)
}
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    return helper(root , subRoot);
}