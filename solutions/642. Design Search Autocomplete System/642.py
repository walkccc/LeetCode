class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.s: str | None = None
    self.time = 0
    self.top3: list[TrieNode] = []

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
  def __init__(self, sentences: list[str], times: list[int]):
    self.root = TrieNode()
    self.curr = self.root
    self.s: list[str] = []

    for sentence, time in zip(sentences, times):
      self._insert(sentence, time)

  def input(self, c: str) -> list[str]:
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
      node = node.children.setdefault(c, TrieNode())
    node.s = sentence
    node.time += time

    leaf = node
    node: TrieNode = self.root
    for c in sentence:
      node = node.children[c]
      node.update(leaf)
