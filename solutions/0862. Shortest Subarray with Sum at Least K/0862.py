class Solution:
    def shortestSubarray(self, A: List[int], K: int) -> int:
        n = len(A)

        ans = n + 1
        prefixSum = [0] * (n + 1)

        for i in range(n):
            prefixSum[i + 1] = prefixSum[i] + A[i]
        deque = collections.deque()

        for i in range(n + 1):
            while deque and prefixSum[i] - prefixSum[deque[0]] >= K:
                ans = min(ans, i - deque.popleft())
            while deque and prefixSum[i] <= prefixSum[deque[-1]]:
                deque.pop()
            deque.append(i)

        return ans if ans <= n else -1
