class Solution:
  def connect(self, root: 'Node') -> 'Node':
    node = root  # the node that is above the current needling

    while node:
      dummy = Node(0)  # a dummy node before needling
      # Needle the children of the node.
      needle = dummy
      while node:
        if node.left:  # Needle the left child.
          needle.next = node.left
          needle = needle.next
        if node.right:  # Needle the right child.
          needle.next = node.right
          needle = needle.next
        node = node.next
      node = dummy.next  # Move the node to the next level.

    return root
