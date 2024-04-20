class Solution:
  def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
    concatenated = []
    startToPiece = {piece[0]: piece for piece in pieces}

    for a in arr:
      concatenated += startToPiece.get(a, [])

    return concatenated == arr
