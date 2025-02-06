class Codec:
  def serialize(self, root: 'Node') -> str:
    """Encodes a tree to a single string."""
    if not root:
      return ''

    s = []
    q = collections.deque([root])
    s.append(str(root.val) + ' ')

    while q:
      for _ in range(len(q)):
        node = q.popleft()
        if not node.children:
          s.append('n')
        else:
          for child in node.children:
            q.append(child)
            s.append(str(child.val) + '#')
        s.append(' ')

    return ''.join(s)

  def deserialize(self, data: str) -> 'Node':
    """Decodes your encoded data to tree."""
    if not data:
      return None

    words = data.split()
    root = Node(int(words[0]))
    q = collections.deque([root])

    for word in words[1:]:
      parent = q.popleft()
      children = []
      for kid in word.split('#'):
        if kid in ('', 'n'):
          continue
        child = Node(int(kid))
        children.append(child)
        q.append(child)
      parent.children = children

    return root
