from dataclasses import dataclass


@dataclass
class Node:
  val: int = -1
  next: 'Node' = None
  down: 'Node' = None


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
      # Move to the next level
      node = node.down
    return False

  def add(self, num: int) -> None:
    # Collect nodes that are before the insertion point.
    nodes = []
    node = self.dummy
    while node:
      while node.next and node.next.val < num:
        node = node.next
      nodes.append(node)
      # Move to the next level
      node = node.down

    shouldInsert = True
    down = None
    while shouldInsert and nodes:
      node = nodes.pop()
      node.next = Node(num, node.next, down)
      down = node.next
      shouldInsert = random.getrandbits(1) == 0

    # Create a topmost new level dummy that points to the existing dummy.
    if shouldInsert:
      self.dummy = Node(-1, None, self.dummy)

  def erase(self, num: int) -> bool:
    node = self.dummy
    found = False
    while node:
      while node.next and node.next.val < num:
        node = node.next
      if node.next and node.next.val == num:
        # Delete the node
        node.next = node.next.next
        found = True
      # Move to the next level
      node = node.down
    return found

  # Move to the node s.t. node.next.val >= target
  def _advance(self, node: Node, target: int) -> None:
    while node.next and node.next.val < target:
      node = node.next
