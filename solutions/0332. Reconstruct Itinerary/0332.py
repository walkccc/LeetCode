class Solution:
  def findItinerary(self, tickets: List[List[str]]) -> List[str]:
    ans = []
    graph = defaultdict(list)

    for a, b in sorted(tickets)[::-1]:
      graph[a].append(b)

    def dfs(node: str) -> None:
      while node in graph and graph[node]:
        dfs(graph[node].pop())
      ans.append(node)

    dfs('JFK')

    return ans[::-1]
