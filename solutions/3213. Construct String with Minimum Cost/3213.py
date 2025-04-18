class Solution:
  def minimumCost(self, target: str, words: list[str], costs: list[int]) -> int:
    n = len(target)
    # dp[i] := the minimum cost to construct target[0..i)
    dp = [0] + [math.inf] * n
    # minCost[c][word] := the minimum cost to construct word starting with `c`
    minCost: dict[str, dict[str, int]] = collections.defaultdict(dict)

    for word, cost in zip(words, costs):
      c = word[0]
      minCost[c][word] = min(minCost[c].get(word, math.inf), cost)

    for i, c in enumerate(target):
      for word, cost in minCost[c].items():
        j = i + len(word)
        if j <= n and cost + dp[i] < dp[j] and target[i:j] == word:
          dp[j] = cost + dp[i]

    return -1 if dp[n] == math.inf else dp[n]
