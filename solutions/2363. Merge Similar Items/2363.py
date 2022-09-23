class Solution:
  def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
    return sorted((Counter(dict(items1)) + Counter(dict(items2))).items())
