class BSTIterator:

    def __init__(self, root: TreeNode):
        self.helper(root)

    def next(self) -> int:
        node = self.stack.pop()

        if node.right:
            self.helper(node.right)

        return node.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0

    stack = []

    def helper(self, root: TreeNode) -> None:
        while root:
            self.stack.append(root)
            root = root.left
