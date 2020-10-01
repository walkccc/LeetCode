class Solution:
    def countAndSay(self, n: int) -> str:
        dict = {1: '1', 2: '11', 3: '21', 4: '1211', 5: '111221'}

        if n <= 5:
            return dict[n]

        for i in range(6, n + 1):
            s = ''
            j = 0
            while j <= len(dict[i - 1]) - 2:
                count = 1
                while j <= len(dict[i - 1]) - 2 and dict[i - 1][j] == dict[i - 1][j + 1]:
                    count += 1
                    j += 1
                s += str(count) + dict[i - 1][j]
                j += 1
            if j == len(dict[i - 1]) - 1:
                s += str(1) + dict[i - 1][j]
            dict[i] = s

        return dict[n]
