class Solution:
  def findCenter(self, edges: List[List[int]]) -> int:
    if edges[0][0] in edges[1]:
      return edges[0][0]
    return edges[0][1]
