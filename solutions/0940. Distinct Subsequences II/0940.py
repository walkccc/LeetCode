class Solution:
    def distinctSubseqII(self, S: str) -> int:
        kMod = int(1e9 + 7)

        dict = [0] * 26

        for c in S:
            dict[ord(c) - ord('a')] = (sum(dict) + 1) % kMod

        return sum(dict) % kMod
