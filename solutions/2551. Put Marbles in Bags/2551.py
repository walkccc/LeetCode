class Solution:
  def putMarbles(self, weights: list[int], k: int) -> int:
    # To distribute marbles into k bags, there will be k - 1 cuts. If there's a
    # cut after weights[i], then weights[i] and weights[i + 1] will be added to
    # the cost. Also, no matter how we cut, weights[0] and weights[n - 1] will
    # be counted. So, the goal is to find the max//min k - 1 weights[i] +
    # weights[i + 1].

    # weights[i] + weights[i + 1]
    A = [a + b for a, b in itertools.pairwise(weights)]
    return sum(heapq.nlargest(k - 1, A)) - sum(heapq.nsmallest(k - 1, A))
