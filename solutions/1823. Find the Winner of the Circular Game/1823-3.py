class Solution:
  def findTheWinner(self, n: int, k: int) -> int:
    # e.g. n = 4, k = 2.
    # By using 0-indexed notation, we have the following circle:
    #
    # 0 -> 1 -> 2 -> 3 -> 0
    #      x
    #           0 -> 1 -> 2 -> 0
    #
    # After the first round, 1 is removed.
    # So, 2 becomes 0, 3 becomes 1, and 0 becomes 2.
    # Let's denote that oldIndex = f(n, k) and newIndex = f(n - 1, k).
    # By observation, we know f(n, k) = (f(n - 1, k) + k) % n.
    def f(n: int, k: int) -> int:
      ans = 0  # f(1, k)
      # Computes f(i, k) based on f(i - 1, k).
      for i in range(2, n + 1):
        ans = (ans + k) % i
      return ans

    # Converts back to 1-indexed.
    return f(n, k) + 1
