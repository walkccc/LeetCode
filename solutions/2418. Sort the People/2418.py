class Solution:
  def sortPeople(self, names: list[str], heights: list[int]) -> list[str]:
    return [height for _, height in
            sorted([(height, name) for name, height in zip(names, heights)], reverse=True)]
