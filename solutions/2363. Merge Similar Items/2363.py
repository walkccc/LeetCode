class Solution:
  def mergeSimilarItems(self, items1: list[list[int]],
                        items2: list[list[int]]) -> list[list[int]]:
    return sorted(
        (Counter(dict(items1)) + collections.Counter(dict(items2))).items())
