class Solution:
  def findDuplicateSubtrees(self, root: TreeNode | None) -> list[TreeNode | None]:
    ans = []
    count = collections.Counter()

    def encode(root: TreeNode | None) -> str:
      if not root:
        return ''

      encoded = (str(root.val) + '#' +
                 encode(root.left) + '#' +
                 encode(root.right))
      count[encoded] += 1
      if count[encoded] == 2:
        ans.append(root)
      return encoded

    encode(root)
    return ans
