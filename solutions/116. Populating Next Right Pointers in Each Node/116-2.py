class Solution:
  def connect(self, root: 'Node') -> 'Node':
    node = root  # the node that is above the current needling

    while node and node.left:
      dummy = Node(0)  # a dummy node before needling
      # Needle the children of the node.
      needle = dummy
      while node:
        needle.next = node.left
        needle = needle.next
        needle.next = node.right
        needle = needle.next
        node = node.next
      node = dummy.next  # Move the node to the next level.

    return root
