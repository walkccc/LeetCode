from sortedcontainers import SortedList


class Solution:
  def minReverseOperations(
      self,
      n: int,
      p: int,
      banned: list[int],
      k: int,
  ) -> list[int]:
    bannedSet = set(banned)
    ans = [-1] * n
    # unseen[i] := the unseen numbers that % 2 == i
    unseen = [SortedList(), SortedList()]

    for num in range(n):
      if num != p and num not in bannedSet:
        unseen[num % 2].add(num)

    # Perform BFS from `p`.
    q = collections.deque([p])
    ans[p] = 0

    while q:
      u = q.popleft()
      lo = max(u - k + 1, k - 1 - u)
      hi = min(u + k - 1, n - 1 - (u - (n - k)))
      # Choose the correct set of numbers.
      nums = unseen[lo % 2]
      i = nums.bisect_left(lo)
      while i < len(nums) and nums[i] <= hi:
        num = nums[i]
        ans[num] = ans[u] + 1
        q.append(num)
        nums.pop(i)

    return ans
