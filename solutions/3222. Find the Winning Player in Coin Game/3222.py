class Solution:
  def losingPlayer(self, x: int, y: int) -> str:
    return 'Bob' if min(x, y // 4) % 2 == 0 else 'Alice'
