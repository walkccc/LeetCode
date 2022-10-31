class Solution:
  def findItinerary(self, tickets: List[List[str]]) -> List[str]:
    ans = []
    graph = defaultdict(list)

    for a, b in reversed(sorted(tickets)):
      graph[a].append(b)

    def dfs(u: str) -> None:
      while u in graph and graph[u]:
        dfs(graph[u].pop())
      ans.append(u)

    dfs('JFK')
    return ans[::-1]
