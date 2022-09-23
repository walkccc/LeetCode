class Solution:
  def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
    ans = 0
    score = 0
    q = deque(sorted(tokens))

    while q and (power >= q[0] or score):
      while q and power >= q[0]:
        # play the smallest face up
        power -= q.popleft()
        score += 1
      ans = max(ans, score)
      if q and score:
        # play the largest face down
        power += q.pop()
        score -= 1

    return ans
