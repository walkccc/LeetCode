class TrieNode:
  def __init__(self):
    self.children: List[Optional[TrieNode]] = [None] * 2
    self.min = math.inf
    self.max = -math.inf


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
      node.min = min(node.min, num)
      node.max = max(node.max, num)

  def getMaxXor(self, x: int) -> int:
    """Returns max(x ^ y) where |x - y| <= min(x, y).

    If x <= y, |x - y| <= min(x, y) can be written as y - x <= x.
    So, y <= 2 * x.
    """
    maxXor = 0
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = x >> i & 1
      toggleBit = bit ^ 1
      # If `node.children[toggleBit].max > x`, it means there's a number in the
      # node that satisfies the condition to ensure that x <= y among x and y.
      # If `node.children[toggleBit].min <= 2 * x`, it means there's a number in
      # the node that satisfies the condition for a valid y.
      if node.children[toggleBit] \
              and node.children[toggleBit].max > x \
              and node.children[toggleBit].min <= 2 * x:
        maxXor = maxXor | 1 << i
        node = node.children[toggleBit]
      elif node.children[bit]:
        node = node.children[bit]
      else:  # There's nothing in the Bit Trie.
        return 0
    return maxXor


class Solution:
  # Similar to 421. Maximum XOR of Two Numbers in an Array
  def maximumStrongPairXor(self, nums: List[int]) -> int:
    maxNum = max(nums)
    maxBit = int(math.log2(maxNum))
    bitTrie = BitTrie(maxBit)

    for num in nums:
      bitTrie.insert(num)

    return max(bitTrie.getMaxXor(num) for num in nums)
