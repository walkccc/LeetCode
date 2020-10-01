class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def wordBreak(s: str) -> bool:
            if s in memo:
                return memo[s]
            if s in wordDict:
                memo[s] = True
                return True

            for i in range(1, len(s)):
                if s[:i] in wordDict and wordBreak(s[i:]):
                    memo[s] = True
                    return True

            memo[s] = False
            return False

        memo = {}
        wordDict = set(wordDict)

        return wordBreak(s)
