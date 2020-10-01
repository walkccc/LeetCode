class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c)
            else:
                if not stack or \
                        c == ')' and stack[-1] != '(' or \
                        c == '}' and stack[-1] != '{' or \
                        c == ']' and stack[-1] != '[':
                    return False
                stack.pop()

        return not stack
