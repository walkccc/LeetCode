class Solution:
  def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
    return [name for _, name in
            sorted([(height, name) for name, height in zip(names, heights)], reverse=True)]
