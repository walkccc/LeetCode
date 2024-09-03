class Solution:
  def countPalindromePaths(self, parent: list[int], s: str) -> int:
    # A valid (u, v) has at most 1 letter with odd frequency on its path. The
    # frequency of a letter on the u-v path is equal to the sum of its
    # frequencies on the root-u and root-v paths substract twice of its
    # frequency on the root-LCA(u, v) path. Considering only the parity
    # (even/odd), the part involving root-LCA(u, v) can be ignored, making it
    # possible to calculate both parts easily using a simple DFS.
    tree = collections.defaultdict(list)
    maskToCount = collections.Counter({0: 1})

    for i in range(1, len(parent)):
      tree[parent[i]].append(i)

    # mask := 26 bits that represent the parity of each character in the alphabet
    # on the path from node 0 to node u
    def dfs(u: int, mask: int) -> int:
      res = 0
      if u > 0:
        mask ^= 1 << (ord(s[u]) - ord('a'))
        # Consider any u-v path with 1 bit set.
        for i in range(26):
          res += maskToCount[mask ^ (1 << i)]
        # Consider u-v path with 0 bit set.
        res += maskToCount[mask ^ 0]
        maskToCount[mask] += 1
      for v in tree[u]:
        res += dfs(v, mask)
      return res

    return dfs(0, 0)
