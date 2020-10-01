class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)

        uf = UF(n)
        friendCircle = set()

        for i in range(n):
            for j in range(i, n):
                if M[i][j] == 1:
                    uf.union(i, j)

        for i in range(n):
            friendCircle.add(uf.find(i))

        return len(friendCircle)


class UF:
    def __init__(self, n: int):
        self.rank = [0] * (n + 1)
        self.parent = [i for i in range(n + 1)]

    def union(self, u: int, v: int) -> None:
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv:
            return

        if self.rank[pu] < self.rank[pv]:
            self.parent[pu] = pv
        elif self.rank[pv] < self.rank[pu]:
            self.parent[pv] = pu
        else:
            self.parent[pu] = pv
            self.rank[pv] += 1

    def find(self, u: int) -> int:
        while u != self.parent[u]:
            self.parent[u] = self.parent[self.parent[u]]
            u = self.parent[u]

        return u
