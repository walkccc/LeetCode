class Solution:
    def decodeString(self, s: str) -> str:
        currNum = 0
        currStr = ''
        stack = []

        for c in s:
            if c.isdigit():
                currNum = currNum * 10 + int(c)
            elif c == '[':
                stack.append(currStr)
                stack.append(currNum)
                currStr = ''
                currNum = 0
            elif c == ']':
                num = stack.pop()
                prevStr = stack.pop()
                currStr = prevStr + num * currStr
            else:
                currStr += c

        return currStr
