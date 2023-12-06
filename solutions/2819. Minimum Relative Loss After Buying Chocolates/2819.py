class Solution:
  def minimumRelativeLosses(self, prices: List[int], queries: List[List[int]]) -> List[int]:
    ans = []

    prices.sort()

    prefix = [0] + list(itertools.accumulate(prices))

    for k, m in queries:
      countFront = self._getCountFront(k, m, prices, prefix)
      countBack = m - countFront
      ans.append(self._getRelativeLoss(countFront, countBack, k, prefix))

    return ans

  def _getCountFront(self, k: int, m: int, prices: List[int], prefix: List[int]) -> int:
    """Returns the `countFront` for query (k, m).

    Returns the `countFront` for query (k, m) s.t. picking the first
    `countFront` and the last `m - countFront` chocolates is optimal.

    Define loss[i] := the relative loss of picking `prices[i]`.
    1. For prices[i] <= k, Bob pays prices[i] while Alice pays 0.
       Thus, loss[i] = prices[i] - 0 = prices[i].
    2. For prices[i] > k, Bob pays k while Alice pays prices[i] - k.
       Thus, loss[i] = k - (prices[i] - k) = 2 * k - prices[i].
    By observation, we deduce that it is always better to pick from the front
    or the back since loss[i] is increasing for 1. and is decreasing for 2.

    Assume that picking `left` chocolates from the left and `right = m - left`
    chocolates from the right is optimal. Therefore, we are selecting
    chocolates from `prices[0..left - 1]` and `prices[n - right..n - 1]`.

    To determine the optimal `left` in each iteration, we simply compare
    `loss[left]` with `loss[n - right]` if `loss[left] < loss[n - right]`,
    it's worth increasing `left`.
    """
    n = len(prices)
    countNoGreaterThanK = bisect.bisect_right(prices, k)
    l = 0
    r = min(countNoGreaterThanK, m)

    while l < r:
      mid = (l + r) // 2
      right = m - mid
      # Picking prices[mid] is better than picking prices[n - right].
      if prices[mid] < 2 * k - prices[n - right]:
        l = mid + 1
      else:
        r = mid

    return l

  def _getRelativeLoss(self, countFront: int, countBack: int, k: int, prefix: List[int]) -> int:
    """Returns the relative loss of picking `countFront` and `countBack` chocolates."""
    lossFront = prefix[countFront]
    lossBack = 2 * k * countBack - (prefix[-1] - prefix[-countBack - 1])
    return lossFront + lossBack
