class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        count = collections.Counter(nums)

        for key in sorted(count):
            value = count[key]
            if value > 0:
                for i in range(key, key + k):
                    count[i] -= value
                    if count[i] < 0:
                        return False

        return True
