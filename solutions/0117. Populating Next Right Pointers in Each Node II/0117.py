class Solution:
  def connect(self, root: 'Node') -> 'Node':
    node = root  # the node just above current needling

    while node:
      dummy = Node(0)  # dummy node before needling
      # needle children of node
      needle = dummy
      while node:
        if node.left:  # needle left child
          needle.next = node.left
          needle = needle.next
        if node.right:  # needle right child
          needle.next = node.right
          needle = needle.next
        node = node.next
      node = dummy.next  # move node to the next level

    return root
