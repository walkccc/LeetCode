class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        ans = ['']
        dict = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
                '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}

        for i in digits:
            tmp = []
            for j in ans:
                for k in dict[i]:
                    tmp.append(j + k)
            ans = tmp

        return ans
