class Solution:
  def lengthLongestPath(self, input: str) -> int:
    ans = 0
    stack = [(-1, 0)]  # placeholder

    for token in input.split('\n'):
      depth = token.count('\t')
      token = token.replace('\t', '')
      while depth <= stack[-1][0]:
        stack.pop()
      if '.' in token:  # `token` is file.
        ans = max(ans, stack[-1][1] + len(token))
      else:  # directory + '/'
        stack.append((depth, stack[-1][1] + len(token) + 1))

    return ans
