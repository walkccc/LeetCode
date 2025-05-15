class Solution:
  def kthCharacter(self, k: int) -> str:
    return string.ascii_lowercase[(k - 1).bit_count()]
