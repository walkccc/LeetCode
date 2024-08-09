class TrieNode:
  def __init__(self):
    self.children: Dict[int, TrieNode] = {}
    self.count = 0


class Solution:
  def countDistinct(self, nums: List[int], k: int, p: int) -> int:
    ans = 0
    root = TrieNode()

    def insert(node: TrieNode, i: int, k: int):
      nonlocal ans
      if i == len(nums) or k - (nums[i] % p == 0) < 0:
        return
      if nums[i] not in node.children:
        node.children[nums[i]] = TrieNode()
        ans += 1
      insert(node.children[nums[i]], i + 1, k - (nums[i] % p == 0))

    for i in range(len(nums)):
      insert(root, i, k)

    return ans
