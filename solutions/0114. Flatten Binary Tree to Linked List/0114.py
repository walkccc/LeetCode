class Solution:
    def flatten(self, root: TreeNode) -> None:
        if not root:
            return

        self.flatten(root.right)
        self.flatten(root.left)
        root.right = self.next
        root.left = None
        self.next = root

    next = None
