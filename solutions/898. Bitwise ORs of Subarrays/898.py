class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        # 'cur' holds all unique ORs ending at previous element
        res = set()
        cur = set()
        for num in arr:
            # New set: OR current num with everything in cur, as well as num itself
            cur = {num | x for x in cur} | {num}
            res |= cur  # add all to result
        return len(res)
