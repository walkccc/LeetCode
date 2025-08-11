from dataclasses import dataclass


@dataclass
class Node:
  def __init__(self, count: int, key: str | None = None):
    self.count = count
    self.keys: set[str] = {key} if key else set()
    self.prev: Node | None = None
    self.next: Node | None = None

  def __eq__(self, other) -> bool:
    if not isinstance(other, Node):
      return NotImplemented
    return self.count == other.count and self.keys == other.keys


class AllOne:
  def __init__(self):
    self.keyToNode: dict[str, Node] = {}
    self.head = Node(0)
    self.tail = Node(0)
    self.head.next = self.tail
    self.tail.prev = self.head

  def inc(self, key: str) -> None:
    if key in self.keyToNode:
      self._incrementExistingKey(key)
    else:
      self._addNewKey(key)

  def dec(self, key: str) -> None:
    # It is guaranteed that key exists in the data structure before the
    # decrement.
    self._decrementExistingKey(key)

  def getMaxKey(self) -> str:
    return '' if self.tail.prev == self.head \
        else next(iter(self.tail.prev.keys))

  def getMinKey(self) -> str:
    return '' if self.head.next == self.tail \
        else next(iter(self.head.next.keys))

  def _addNewKey(self, key: str) -> None:
    """Adds a new node with frequency 1."""
    if self.head.next.count == 1:
      self.head.next.keys.add(key)
    else:
      self._insertAfter(self.head, Node(1, key))
    self.keyToNode[key] = self.head.next

  def _incrementExistingKey(self, key: str) -> None:
    """Increments the frequency of the key by 1."""
    node = self.keyToNode[key]
    node.keys.remove(key)
    if node.next == self.tail or node.next.count > node.count + 1:
      self._insertAfter(node, Node(node.count + 1))
    node.next.keys.add(key)
    self.keyToNode[key] = node.next
    if not node.keys:
      self._remove(node)

  def _decrementExistingKey(self, key: str) -> None:
    """Decrements the count of the key by 1."""
    node = self.keyToNode[key]
    node.keys.remove(key)
    if node.count > 1:
      if node.prev == self.head or node.prev.count != node.count - 1:
        self._insertAfter(node.prev, Node(node.count - 1))
      node.prev.keys.add(key)
      self.keyToNode[key] = node.prev
    else:
      del self.keyToNode[key]
    if not node.keys:
      self._remove(node)

  def _insertAfter(self, node: Node, newNode: Node) -> None:
    newNode.prev = node
    newNode.next = node.next
    node.next.prev = newNode
    node.next = newNode

  def _remove(self, node: Node) -> None:
    node.prev.next = node.next
    node.next.prev = node.prev
