class Solution:
    def longestPalindrome(self, s: str) -> str:
        T = '$#' + '#'.join(s) + '#@'

        center = 1
        right = 1
        P = [0] * len(T)

        for i in range(1, len(T) - 1):
            mirr = 2 * center - i
            if i < right:
                P[i] = min(P[mirr], right - i)
            while T[i + P[i] + 1] == T[i - P[i] - 1]:
                P[i] += 1
            if i + P[i] > right:
                center = i
                right = i + P[i]

        max = 0
        c = 0
        for i in range(len(T)):
            if P[i] > max:
                max = P[i]
                c = i

        return T[c - max + 1: c + max].replace('#', '')
