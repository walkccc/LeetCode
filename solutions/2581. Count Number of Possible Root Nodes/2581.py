class Solution:
  def rootCount(
      self,
      edges: list[list[int]],
      guesses: list[list[int]],
      k: int,
  ) -> int:
    ans = 0
    n = len(edges) + 1
    graph = [[] for _ in range(n)]
    guessGraph = [set() for _ in range(n)]
    parent = [0] * n

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    for u, v in guesses:
      guessGraph[u].add(v)

    def dfs(u: int, prev: int) -> None:
      parent[u] = prev
      for v in graph[u]:
        if v != prev:
          dfs(v, u)

    # Precalculate `parent`.
    dfs(0, -1)

    # Calculate `correctGuess` for tree rooted at 0.
    correctGuess = sum(i in guessGraph[parent[i]] for i in range(1, n))

    def reroot(u: int, prev: int, correctGuess: int) -> None:
      nonlocal ans
      if u != 0:
        # The tree is rooted at u, so a guess edge (u, prev) will match the new
        # `parent` relationship.
        if prev in guessGraph[u]:
          correctGuess += 1
        # A guess edge (prev, u) matching the old `parent` relationship will no
        # longer be True.
        if u in guessGraph[prev]:
          correctGuess -= 1
      if correctGuess >= k:
        ans += 1
      for v in graph[u]:
        if v != prev:
          reroot(v, u, correctGuess)

    reroot(0, -1, correctGuess)
    return ans
