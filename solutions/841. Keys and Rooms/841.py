class Solution:
  def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
    seen = [False] * len(rooms)

    def dfs(node: int) -> None:
      seen[node] = True
      for child in rooms[node]:
        if not seen[child]:
          dfs(child)

    dfs(0)
    return all(seen)
