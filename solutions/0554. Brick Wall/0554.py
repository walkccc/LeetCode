class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        maxFreq = 0
        count = collections.defaultdict(int)

        for row in wall:
            prefixSum = 0
            for i in range(len(row) - 1):
                prefixSum += row[i]
                count[prefixSum] += 1
                maxFreq = max(maxFreq, count[prefixSum])

        return len(wall) - maxFreq
