class TrieNode:
  def __init__(self):
    self.children: List[Optional[TrieNode]] = [None] * 2


class BitTrie:
  def __init__(self, maxBit: int):
    self.maxBit = maxBit
    self.root = TrieNode()

  def insert(self, num: int) -> None:
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = num >> i & 1
      if not node.children[bit]:
        node.children[bit] = TrieNode()
      node = node.children[bit]

  def getMaxXor(self, num: int) -> int:
    maxXor = 0
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = num >> i & 1
      toggleBit = bit ^ 1
      if node.children[toggleBit]:
        maxXor = maxXor | 1 << i
        node = node.children[toggleBit]
      elif node.children[bit]:
        node = node.children[bit]
      else:  # There's nothing in the Bit Trie.
        return 0
    return maxXor


class IndexedQuery:
  def __init__(self, queryIndex: int, x: int, m: int):
    self.queryIndex = queryIndex
    self.x = x
    self.m = m

  def __iter__(self):
    yield self.queryIndex
    yield self.x
    yield self.m


class Solution:
  def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
    ans = [-1] * len(queries)
    maxBit = int(math.log2(max(max(nums), max(x for x, _ in queries))))
    bitTrie = BitTrie(maxBit)

    nums.sort()

    i = 0  # nums' index
    for queryIndex, x, m in sorted([IndexedQuery(i, x, m)
                                    for i, (x, m) in enumerate(queries)],
                                   key=lambda iq: iq.m):
      while i < len(nums) and nums[i] <= m:
        bitTrie.insert(nums[i])
        i += 1
      if i > 0 and nums[i - 1] <= m:
        ans[queryIndex] = bitTrie.getMaxXor(x)

    return ans
