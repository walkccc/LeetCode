class Solution:
    def calculate(self, s: str) -> int:
        num = 0
        sign = '+'
        stack = []

        for i, c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)
            if not c.isdigit() and c != ' ' or i == len(s) - 1:
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack.append(stack.pop() * num)
                else:
                    if stack[-1] < 0:
                        stack.append(math.ceil(stack.pop() / num))
                    else:
                        stack.append(stack.pop() // num)
                num = 0
                sign = c

        return sum(stack)
