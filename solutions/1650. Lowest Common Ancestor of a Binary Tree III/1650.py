class Solution:
  # Same as 160. Intersection of Two Linked Lists
  def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
    a = p
    b = q

    while a != b:
      a = a.parent if a else q
      b = b.parent if b else p

    return a
