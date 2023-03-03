class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        li = [i if i%2==0 else i*2 for i in nums]

        mn = min(li)
        mx = max(li)

        mxHeap = []
        for i in li:
            heappush(mxHeap,-i)

        mnDiff = mx-mn

        while(mxHeap[0]%2==0):
            top = -heappop(mxHeap)
            top //=2
            heappush(mxHeap,-top)
            mn = min(mn,top)
            mx = -mxHeap[0]
            mnDiff = min(mnDiff,mx-mn)

        return mnDiff