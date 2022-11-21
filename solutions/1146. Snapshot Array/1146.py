class SnapshotArray:
  def __init__(self, length: int):
    self.snaps = [[[0, 0]] for _ in range(length)]
    self.snap_id = 0

  def set(self, index: int, val: int) -> None:
    snap = self.snaps[index][-1]
    if snap[0] == self.snap_id:
      snap[1] = val
    else:
      self.snaps[index].append([self.snap_id, val])

  def snap(self) -> int:
    self.snap_id += 1
    return self.snap_id - 1

  def get(self, index: int, snap_id: int) -> int:
    i = bisect_left(self.snaps[index], [snap_id + 1]) - 1
    return self.snaps[index][i][1]
