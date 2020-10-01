class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def dfs(index: int, path: List[str]):
            if len(path) == 4 and index == len(s):
                ans.append(path[0] + '.' + path[1] +
                           '.' + path[2] + '.' + path[3])
                return
            if len(path) == 4 or index == len(s):
                return

            for i in range(1, 4):
                if index + i > len(s):
                    return
                if i > 1 and s[index] == '0':
                    return
                num = s[index:index + i]
                if int(num) > 255:
                    return
                dfs(index + i, path + [num])

        ans = []

        dfs(0, [])

        return ans
