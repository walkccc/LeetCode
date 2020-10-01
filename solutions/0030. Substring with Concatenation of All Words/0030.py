class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(s) == 0 or words == []:
            return []

        n = len(words[0])

        ans = []
        count = collections.Counter(words)

        for i in range(len(s) - len(words) * n + 1):
            seen = collections.defaultdict(int)
            j = 0
            while j < len(words):
                word = s[i + j * n: i + j * n + n]
                seen[word] += 1
                if seen[word] > count[word]:
                    break
                j += 1
            if j == len(words):
                ans.append(i)

        return ans
