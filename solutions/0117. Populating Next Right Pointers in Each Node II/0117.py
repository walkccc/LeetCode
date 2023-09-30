class Solution:
  def connect(self, root: 'Node') -> 'Node':
    node = root  # The node just above current needling

    while node:
      dummy = Node(0)  # Dummy node before needling
      # Needle children of node
      needle = dummy
      while node:
        if node.left:  # Needle left child
          needle.next = node.left
          needle = needle.next
        if node.right:  # Needle right child
          needle.next = node.right
          needle = needle.next
        node = node.next
      node = dummy.next  # Move node to the next level

    return root
