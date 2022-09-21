class Solution:
  def connect(self, root: 'Node') -> 'Node':
    node = root  # the node just above current needling

    while node and node.left:
      dummy = Node(0)  # dummy node before needling
      # needle children of node
      needle = dummy
      while node:
        needle.next = node.left
        needle = needle.next
        needle.next = node.right
        needle = needle.next
        node = node.next
      node = dummy.next  # move node to the next level

    return root
