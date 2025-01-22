class Solution:
  def minimumOperations(self, root: TreeNode | None) -> int:
    ans = 0
    q = collections.deque([root])

    # e.g. vals = [7, 6, 8, 5]
    # [2, 1, 3, 0]: Initialize the ids based on the order of vals.
    # [3, 1, 2, 0]: Swap 2 with 3, so 2 is in the right place (i == ids[i]).
    # [0, 1, 2, 3]: Swap 3 with 0, so 3 is in the right place.
    while q:
      vals = []
      for _ in range(len(q)):
        node = q.popleft()
        vals.append(node.val)
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      # O(n^2logn), which is not great and leads to TLE.
      ids = [sorted(vals).index(val) for val in vals]
      for i in range(len(ids)):
        while ids[i] != i:
          j = ids[i]
          ids[i] = ids[j]
          ids[j] = j
          ans += 1

    return ans
