class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        count = collections.Counter(str(N))
        return any(collections.Counter(str(1 << i)) == count for i in range(30))
