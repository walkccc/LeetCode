class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def dfs(root: TreeNode, minNode: TreeNode, maxNode: TreeNode):
            if not root:
                return True
            if minNode and minNode.val >= root.val or \
                    maxNode and maxNode.val <= root.val:
                return False

            return dfs(root.left, minNode, root) and \
                dfs(root.right, root, maxNode)

        return dfs(root, None, None)
