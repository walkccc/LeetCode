class Solution:
  def totalStrength(self, strength: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(strength)

    # next small or equal on the left
    left = [-1] * n
    stack = []

    for i in reversed(range(n)):
      while stack and strength[stack[-1]] >= strength[i]:
        left[stack.pop()] = i
      stack.append(i)

    # next small on the right
    right = [n] * n
    stack = []

    for i in range(n):
      while stack and strength[stack[-1]] > strength[i]:
        right[stack.pop()] = i
      stack.append(i)

    ans = 0
    prefixOfPrefix = list(itertools.accumulate(
        itertools.accumulate(strength), initial=0))

    # for each strength[i] as minimum, calculate sum
    for i, (l, r) in enumerate(zip(left, right)):
      leftSum = prefixOfPrefix[i] - prefixOfPrefix[max(0, l)]
      rightSum = prefixOfPrefix[r] - prefixOfPrefix[i]
      leftLen = i - l
      rightLen = r - i
      ans += strength[i] * (rightSum * leftLen - leftSum * rightLen) % kMod

    return ans % kMod
