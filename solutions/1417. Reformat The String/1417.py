class Solution:
  def reformat(self, s: str) -> str:
    A = [c for c in s if c.isalpha()]
    B = [c for c in s if c.isdigit()]

    if len(A) < len(B):
      A, B = B, A
    if len(A) - len(B) > 1:
      return ''

    ans = []

    for i in range(len(B)):
      ans.append(A[i])
      ans.append(B[i])

    if len(A) == len(B) + 1:
      ans.append(A[-1])
    return ''.join(ans)
