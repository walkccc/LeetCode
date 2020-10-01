class Solution:
    def connect(self, root: 'Node') -> 'Node':
        node = root

        while node and node.left:
            cached = node.left
            while node:
                node.left.next = node.right
                node.right.next = node.next.left if node.next else None
                node = node.next
            node = cached

        return root
