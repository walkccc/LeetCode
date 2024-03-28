class Solution:
  def isPreorder(self, nodes: List[List[int]]) -> bool:
    stack = []  # Stores `id`s.

    for id, parentId in nodes:
      if parentId == -1:
        stack.append(id)
        continue
      while stack and stack[-1] != parentId:
        stack.pop()
      if not stack:
        return False
      stack.append(id)

    return True
