class Solution:
  def moveSubTree(self, root: 'Node', p: 'Node', q: 'Node') -> 'Node':
    if p in q.children:
      return root

    # Create a dummy Node for the case when root == p
    dummy = Node(None, [root])

    # Get each parent of p and q
    pParent = self._getParent(dummy, p)
    qParent = self._getParent(p, q)

    # Get p's original index in p's parent
    pIndex = pParent.children.index(p)
    pParent.children.pop(pIndex)

    q.children.append(p)

    # If q is in the p's subtree, qParent != None
    if qParent:
      qParent.children.remove(q)
      pParent.children.insert(pIndex, q)

    return dummy.children[0]

  def _getParent(self, root: 'Node', target: 'Node') -> Optional['Node']:
    for child in root.children:
      if child == target:
        return root
      res = self._getParent(child, target)
      if res:
        return res
    return None
