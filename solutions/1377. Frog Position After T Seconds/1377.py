class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        prob = [0] * (n + 1)
        visited = [False] * (n + 1)
        graph = [[] for _ in range(n + 1)]
        queue = collections.deque([1])

        prob[1] = 1
        visited[1] = True

        for fr, to in edges:
            graph[fr].append(to)
            graph[to].append(fr)

        for _ in range(t):
            for _ in range(len(queue)):
                curr = queue.popleft()
                children = sum(not visited[child] for child in graph[curr])
                for child in graph[curr]:
                    if not visited[child]:
                        visited[child] = True
                        prob[child] = prob[curr] / children
                        queue.append(child)
                if children > 0:
                    prob[curr] = 0

        return prob[target]
