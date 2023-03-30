class Solution:
  def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
    hull = []

    trees.sort(key=lambda x: (x[0], x[1]))

    def cross(p: List[int], q: List[int], r: List[int]) -> int:
      return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])

    # Build lower hull: left-to-right scan
    for tree in trees:
      while len(hull) > 1 and cross(hull[-1], hull[-2], tree) > 0:
        hull.pop()
      hull.append(tuple(tree))
    hull.pop()

    # Build upper hull: right-to-left scan
    for tree in reversed(trees):
      while len(hull) > 1 and cross(hull[-1], hull[-2], tree) > 0:
        hull.pop()
      hull.append(tuple(tree))

    # Remove redundant elements from the stack
    return list(set(hull))
