class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        b = len(baskets)
        size = 4 * b
        seg = [0] * size

        def build(node, l, r):
            if l == r:
                seg[node] = baskets[l]
                return
            mid = (r + l) // 2
            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)
            seg[node] = max(seg[node * 2], seg[node * 2 + 1])

        build(1, 0, b - 1)

        def find(node, l, r, fruit):
            if fruit > seg[node]: return -1 # failure base case
            if l == r: # success base case
                seg[node] = -1
                return l
            mid = (r + l) // 2
            candidate = find(node * 2, l, mid, fruit) # go left first
            if candidate == -1:
                candidate = find(node * 2 + 1, mid + 1, r, fruit) # if no candidate, go right
            seg[node] = max(seg[node * 2], seg[node * 2 + 1])
            return candidate

        res = 0
        for fruit in fruits:
            if find(1, 0, b - 1, fruit) == -1: res += 1
        
        return res
