class Solution:
  def minChanges(self, n: int, k: int) -> int:
    # n needs to be a superset of k.
    return (n ^ k).bit_count() if (n & k) == k else -1
