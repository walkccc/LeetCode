class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def dfs(airport: str) -> None:
            while airport in graph and graph[airport]:
                dfs(graph[airport].pop())
            ans.append(airport)

        ans = []
        graph = collections.defaultdict(list)

        for a, b in sorted(tickets)[::-1]:
            graph[a].append(b)

        dfs('JFK')

        return ans[::-1]
