class Node:
  def __init__(self):
    self.children: list[int] = []
    self.lockedBy = -1


class LockingTree:
  def __init__(self, parent: list[int]):
    self.parent = parent
    self.nodes = [Node() for _ in range(len(parent))]
    for i in range(1, len(parent)):
      self.nodes[parent[i]].children.append(i)

  def lock(self, num: int, user: int) -> bool:
    if self.nodes[num].lockedBy != -1:
      return False
    self.nodes[num].lockedBy = user
    return True

  def unlock(self, num: int, user: int) -> bool:
    if self.nodes[num].lockedBy != user:
      return False
    self.nodes[num].lockedBy = -1
    return True

  def upgrade(self, num: int, user: int) -> bool:
    if self.nodes[num].lockedBy != -1:
      return False
    if not self._anyLockedDescendant(num):
      return False

    # Walk up the hierarchy to ensure that there are no locked ancestors.
    i = num
    while i != -1:
      if self.nodes[i].lockedBy != -1:
        return False
      i = self.parent[i]

    self._unlockDescendants(num)
    self.nodes[num].lockedBy = user
    return True

  def _anyLockedDescendant(self, i: int) -> bool:
    return (self.nodes[i].lockedBy != -1 or
            any(self._anyLockedDescendant(child)
            for child in self.nodes[i].children))

  def _unlockDescendants(self, i: int) -> None:
    self.nodes[i].lockedBy = -1
    for child in self.nodes[i].children:
      self._unlockDescendants(child)
