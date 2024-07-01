class Solution:
  def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
    ans = [0] * n
    count = [1] * n
    tree = collections.defaultdict(set)

    for u, v in edges:
      tree[u].add(v)
      tree[v].add(u)

    def postorder(node, parent=None):
      for child in tree[node]:
        if child == parent:
          continue
        postorder(child, node)
        count[node] += count[child]
        ans[node] += ans[child] + count[child]

    def preorder(node, parent=None):
      for child in tree[node]:
        if child == parent:
          continue
        # count[child] nodes are 1 step closer from child than parent.
        # (n - count[child]) nodes are 1 step farther from child than parent.
        ans[child] = ans[node] - count[child] + (n - count[child])
        preorder(child, node)

    postorder(0)
    preorder(0)
    return ans
