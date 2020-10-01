class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList = set(wordList)

        if endWord not in wordList:
            return 0

        ans = 0

        set1 = set([beginWord])
        set2 = set([endWord])

        while set1 and set2:
            ans += 1
            if len(set1) > len(set2):
                set1, set2 = set2, set1
            tempSet = set()
            for word in set1:
                for i in range(len(word)):
                    for j in string.ascii_lowercase:
                        newWord = word[:i] + j + word[i + 1:]
                        if newWord in set2:
                            return ans + 1
                        if newWord not in wordList:
                            continue
                        wordList.remove(newWord)
                        tempSet.add(newWord)
            set1 = tempSet

        return 0
