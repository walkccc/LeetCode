class TrieNode:
  def __init__(self):
    self.children: Dict[chr, TrieNode] = {}
    self.s: Optional[str] = None
    self.time = 0
    self.top3: List[TrieNode] = []

  def __lt__(self, other):
    if self.time == other.time:
      return self.s < other.s
    return self.time > other.time

  def update(self, node) -> None:
    if node not in self.top3:
      self.top3.append(node)
    self.top3.sort()
    if len(self.top3) > 3:
      self.top3.pop()


class AutocompleteSystem:
  def __init__(self, sentences: List[str], times: List[int]):
    self.root = TrieNode()
    self.curr = self.root
    self.s: List[chr] = []

    for sentence, time in zip(sentences, times):
      self._insert(sentence, time)

  def input(self, c: str) -> List[str]:
    if c == '#':
      self._insert(''.join(self.s), 1)
      self.curr = self.root
      self.s = []
      return []

    self.s.append(c)

    if self.curr:
      self.curr = self.curr.children.get(c, None)
    if not self.curr:
      return []
    return [node.s for node in self.curr.top3]

  def _insert(self, sentence: str, time: int) -> None:
    node = self.root
    for c in sentence:
      if c not in node.children:
        node.children[c] = TrieNode()
      node = node.children[c]
    node.s = sentence
    node.time += time

    leaf = node
    node: TrieNode = self.root
    for c in sentence:
      node = node.children[c]
      node.update(leaf)
