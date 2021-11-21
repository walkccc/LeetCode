class Node:
  def __init__(self, key: int, value: int):
    self.key = key
    self.value = value
    self.prev = None
    self.next = None


class LRUCache:
  def __init__(self, capacity: int):
    self.capacity = capacity
    self.dict = {}
    self.head = Node(-1, -1)
    self.tail = Node(-1, -1)
    self.join(self.head, self.tail)

  def get(self, key: int) -> int:
    if key not in self.dict:
      return -1

    node = self.dict[key]
    self.remove(node)
    self.moveToHead(node)
    return node.value

  def put(self, key: int, value: int) -> None:
    if key in self.dict:
      node = self.dict[key]
      node.value = value
      self.remove(node)
      self.moveToHead(node)
      return

    if len(self.dict) == self.capacity:
      lastNode = self.tail.prev
      del self.dict[lastNode.key]
      self.remove(lastNode)

    self.moveToHead(Node(key, value))
    self.dict[key] = self.head.next

  def join(self, node1: Node, node2: Node):
    node1.next = node2
    node2.prev = node1

  def moveToHead(self, node: Node):
    self.join(node, self.head.next)
    self.join(self.head, node)

  def remove(self, node: Node):
    self.join(node.prev, node.next)
