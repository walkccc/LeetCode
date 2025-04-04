class Node:
  def __init__(self, key: int, value: int, freq: int, it):
    self.key = key
    self.value = value
    self.freq = freq
    self.it = it


class LFUCache:
  def __init__(self, capacity: int):
    self.capacity = capacity
    self.minFreq = 0
    self.keyToNode = {}
    self.freqToList = {}

  def get(self, key: int) -> int:
    if key not in self.keyToNode:
      return -1

    node = self.keyToNode[key]
    self._touch(node)
    return node.value

  def put(self, key: int, value: int) -> None:
    if self.capacity == 0:
      return

    if key in self.keyToNode:
      node = self.keyToNode[key]
      node.value = value
      self._touch(node)
      return

    if len(self.keyToNode) == self.capacity:
      # Evict an LRU key from `minFreq` list
      keyToEvict = self.freqToList[self.minFreq][-1]
      self.freqToList[self.minFreq].pop()
      del self.keyToNode[keyToEvict]

    self.minFreq = 1
    if 1 not in self.freqToList:
      self.freqToList[1] = []
    self.freqToList[1].insert(0, key)
    self.keyToNode[key] = Node(key, value, 1, 0)  # Using index 0 as iterator

  def _touch(self, node: Node) -> None:
    # Update the node's frequency
    prevFreq = node.freq
    node.freq += 1
    newFreq = node.freq

    # Remove the key from `prevFreq`'s list
    self.freqToList[prevFreq].remove(node.key)
    if not self.freqToList[prevFreq]:
      del self.freqToList[prevFreq]
      # Update `minFreq` if needed
      if prevFreq == self.minFreq:
        self.minFreq += 1

    # Insert the key to the front of `newFreq`'s list
    if newFreq not in self.freqToList:
      self.freqToList[newFreq] = []
    self.freqToList[newFreq].insert(0, node.key)
    node.it = 0  # Using index 0 as iterator
