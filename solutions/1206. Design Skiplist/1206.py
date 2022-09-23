class Node:
  def __init__(self, val=-1, next=None, down=None):
    self.val = val
    self.next = next
    self.down = down


class Skiplist:
  def __init__(self):
    self.dummy = Node()

  def search(self, target: int) -> bool:
    node = self.dummy
    while node:
      while node.next and node.next.val < target:
        node = node.next
      if node.next and node.next.val == target:
        return True
      # move to the next level
      node = node.down
    return False

  def add(self, num: int) -> None:
    # collect nodes that before the insertion point
    nodes = []
    node = self.dummy
    while node:
      while node.next and node.next.val < num:
        node = node.next
      nodes.append(node)
      # move to the next level
      node = node.down

    shouldInsert = True
    down = None
    while shouldInsert and nodes:
      node = nodes.pop()
      node.next = Node(num, node.next, down)
      down = node.next
      shouldInsert = random.getrandbits(1) == 0

    # create a topmost new level dummy pointing to existing dummy
    if shouldInsert:
      self.dummy = Node(-1, None, self.dummy)

  def erase(self, num: int) -> bool:
    node = self.dummy
    found = False
    while node:
      while node.next and node.next.val < num:
        node = node.next
      if node.next and node.next.val == num:
        # delete the node
        node.next = node.next.next
        found = True
      # move to the next level
      node = node.down
    return found

  # move to the node s.t. node.next.val >= target
  def _advance(self, node: Node, target: int) -> None:
    while node.next and node.next.val < target:
      node = node.next
