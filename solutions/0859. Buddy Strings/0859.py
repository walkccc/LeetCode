class Solution:
  def buddyStrings(self, A: str, B: str) -> bool:
    if len(A) != len(B):
      return False
    if A == B and len(set(A)) < len(A):
      return True

    diff = [(a, b) for a, b in zip(A, B) if a != b]

    return len(diff) == 2 and diff[0] == diff[1][::-1]
