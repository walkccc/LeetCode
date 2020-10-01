class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        def isConcat(word: str) -> bool:
            if word in memo:
                return memo[word]

            for i in range(1, len(word)):
                prefix = word[:i]
                suffix = word[i:]
                if prefix in wordSet and (suffix in wordSet or isConcat(suffix)):
                    memo[word] = True
                    return True

            memo[word] = False
            return False

        wordSet = set(words)
        memo = {}

        return [word for word in words if isConcat(word)]
