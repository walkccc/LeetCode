class Solution:
  def pushDominoes(self, dominoes: str) -> str:
    ans = list(dominoes)
    L = -1
    R = -1

    for i in range(len(dominoes) + 1):
      if i == len(dominoes) or dominoes[i] == 'R':
        if L < R:
          while R < i:
            ans[R] = 'R'
            R += 1
        R = i
      elif dominoes[i] == 'L':
        if R < L or (L, R) == (-1, -1):
          if (L, R) == (-1, -1):
            L += 1
          while L < i:
            ans[L] = 'L'
            L += 1
        else:
          l = R + 1
          r = i - 1
          while l < r:
            ans[l] = 'R'
            ans[r] = 'L'
            l += 1
            r -= 1
        L = i

    return ''.join(ans)
