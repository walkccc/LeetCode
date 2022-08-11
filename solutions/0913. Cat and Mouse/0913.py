from enum import IntEnum


class State(IntEnum):
  DRAW = 0
  MOUSE_WIN = 1
  CAT_WIN = 2


class Solution:
  def catMouseGame(self, graph: List[List[int]]) -> int:
    n = len(graph)
    # result of (cat, mouse, move)
    # move := 0 (mouse) // 1 (cat)
    states = [[[0] * 2 for i in range(n)] for j in range(n)]
    outDegree = [[[0] * 2 for i in range(n)] for j in range(n)]
    q = deque()  # (cat, mouse, move, state)

    for cat in range(n):
      for mouse in range(n):
        outDegree[cat][mouse][0] = len(graph[mouse])
        outDegree[cat][mouse][1] = len(graph[cat]) - graph[cat].count(0)

    # start from states that winner can be determined
    for cat in range(1, n):
      for move in range(2):
        # mouse is in the hole . MOUSE_WIN
        states[cat][0][move] = int(State.MOUSE_WIN)
        q.append((cat, 0, move, int(State.MOUSE_WIN)))
        # cat catches mouse . CAT_WIN
        states[cat][cat][move] = int(State.CAT_WIN)
        q.append((cat, cat, move, int(State.CAT_WIN)))

    while q:
      cat, mouse, move, state = q.popleft()
      if cat == 2 and mouse == 1 and move == 0:
        return state
      prevMove = move ^ 1
      for prev in graph[cat if prevMove else mouse]:
        prevCat = prev if prevMove else cat
        if prevCat == 0:  # invalid
          continue
        prevMouse = mouse if prevMove else prev
        # the state is already determined
        if states[prevCat][prevMouse][prevMove]:
          continue
        if prevMove == 0 and state == int(State.MOUSE_WIN) or \
                prevMove == 1 and state == int(State.CAT_WIN):
          states[prevCat][prevMouse][prevMove] = state
          q.append((prevCat, prevMouse, prevMove, state))
        else:
          outDegree[prevCat][prevMouse][prevMove] -= 1
          if outDegree[prevCat][prevMouse][prevMove] == 0:
            states[prevCat][prevMouse][prevMove] = state
            q.append((prevCat, prevMouse, prevMove, state))

    return states[2][1][0]
