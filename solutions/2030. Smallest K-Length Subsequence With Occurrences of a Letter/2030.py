class Solution:
  def smallestSubsequence(self, s: str, k: int, letter: str, repetition: int) -> str:
    stack = []  # running string
    required = repetition
    nLetters = s.count(letter)

    for i, c in enumerate(s):
      # Make sure the length is sufficient:
      # Len(stack) := the length of running string
      # Len(s) - i := the length of remain chars
      # -1 := we're going to pop a char
      while stack and stack[-1] > c \
              and len(stack) + len(s) - i - 1 >= k \
              and (stack[-1] != letter or nLetters > required):
        if stack.pop() == letter:
          required += 1
      if len(stack) < k:
        if c == letter:
          stack.append(c)
          required -= 1
        elif k - len(stack) > required:
          stack.append(c)
      if c == letter:
        nLetters -= 1

    return ''.join(stack)
