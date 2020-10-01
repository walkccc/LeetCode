class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        def findRedundantDirectedConnection(skippedEdgeIndex: int) -> List[int]:
            uf = UF(len(edges) + 1)

            for i, edge in enumerate(edges):
                if i == skippedEdgeIndex:
                    continue
                if not uf.union(edge[0], edge[1]):
                    return edge

            return []

        parents = [0] * (len(edges) + 1)
        nodeWithTwoParents = 0

        for u, v in edges:
            parents[v] += 1
            if parents[v] == 2:
                nodeWithTwoParents = v

        if nodeWithTwoParents == 0:
            return findRedundantDirectedConnection(-1)

        for i in range(len(edges))[::-1]:
            u, v = edges[i]
            if v == nodeWithTwoParents:
                if findRedundantDirectedConnection(i) == []:
                    return edges[i]


class UF:
    def __init__(self, n: int):
        self.rank = [0] * (n + 1)
        self.parent = [i for i in range(n + 1)]

    def union(self, u: int, v: int) -> bool:
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv:
            return False

        if self.rank[pu] < self.rank[pv]:
            self.parent[pu] = pv
        elif self.rank[pv] < self.rank[pu]:
            self.parent[pv] = pu
        else:
            self.parent[pu] = pv
            self.rank[pv] += 1

        return True

    def find(self, u: int) -> int:
        while u != self.parent[u]:
            self.parent[u] = self.parent[self.parent[u]]
            u = self.parent[u]

        return u
