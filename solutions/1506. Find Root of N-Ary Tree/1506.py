class Solution:
  def findRoot(self, tree: list['Node']) -> 'Node':
    sum = 0

    for node in tree:
      sum ^= node.val
      for child in node.children:
        sum ^= child.val

    for node in tree:
      if node.val == sum:
        return node
