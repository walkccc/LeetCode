class Solution:
  def maximumBooks(self, books: List[int]) -> int:
    # dp[i] := max # of books we can take from books[0..i]
    # with taking all of books[i]
    dp = [0] * len(books)
    stack = []  # possible indices we can reach

    for i, book in enumerate(books):
      # we may take all of books[j] where books[j] < books[i] - (i - j)
      while stack and books[stack[-1]] >= book - (i - stack[-1]):
        stack.pop()
      # we can now take books[j + 1..i]
      j = stack[-1] if stack else -1
      lastPicked = book - (i - j) + 1
      if lastPicked > 1:
        # book + (book - 1) + ... + (book - (i - j) + 1)
        dp[i] = (book + lastPicked) * (i - j) // 2
      else:
        # 1 + 2 + ... + book
        dp[i] = book * (book + 1) // 2
      if j >= 0:
        dp[i] += dp[j]
      stack.append(i)

    return max(dp)
