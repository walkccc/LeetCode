class Solution:
    def connect(self, root: 'Node') -> 'Node':
        node = root
        cached = Node(0)

        while node:
            curr = cached
            while node:
                if node.left:
                    curr.next = node.left
                    curr = curr.next
                if node.right:
                    curr.next = node.right
                    curr = curr.next
                node = node.next
            node = cached.next
            cached.next = None

        return root
