class Creator:
  def __init__(self, popularity: int, videoId: str, maxView: int):
    self.popularity = popularity  # Popularity sum.
    self.videoId = videoId        # Video id that has max view.
    self.maxView = maxView        # Max view of the creator.


class Solution:
  def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
    ans = []
    maxPopularity = 0
    nameToCreator = {}

    for name, id, view in zip(creators, ids, views):
      if name not in nameToCreator:
        nameToCreator[name] = Creator(view, id, view)
        maxPopularity = max(maxPopularity, view)
        continue
      creator = nameToCreator[name]
      creator.popularity += view
      maxPopularity = max(maxPopularity, creator.popularity)
      if creator.maxView < view or \
              creator.maxView == view and creator.videoId > id:
        creator.videoId = id
        creator.maxView = view

    for name, creator in nameToCreator.items():
      if creator.popularity == maxPopularity:
        ans.append([name, creator.videoId])

    return ans
