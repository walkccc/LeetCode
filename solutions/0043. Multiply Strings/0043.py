class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        m = len(num1)
        n = len(num2)

        ans = ''
        pos = [0] * (m + n)

        for i in range(m)[::-1]:
            for j in range(n)[::-1]:
                multiply = (ord(num1[i]) - ord('0')) * \
                    (ord(num2[j]) - ord('0'))
                sum = multiply + pos[i + j + 1]
                pos[i + j] += sum // 10
                pos[i + j + 1] = (sum) % 10

        for p in pos:
            if not (not ans and p == 0):
                ans += str(p)

        return '0' if not ans else ans
