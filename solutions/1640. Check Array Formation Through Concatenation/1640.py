class Solution:
  def canFormArray(self, arr: list[int], pieces: list[list[int]]) -> bool:
    concatenated = []
    startToPiece = {piece[0]: piece for piece in pieces}

    for a in arr:
      concatenated += startToPiece.get(a, [])

    return concatenated == arr
