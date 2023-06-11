class SnapshotArray:
  def __init__(self, length: int):
    # index -> array of (version, value)
    self.snaps = [[[0, 0]] for _ in range(length)]
    self.snap_id = 0

  def set(self, index: int, val: int) -> None:
    snap = self.snaps[index][-1]
    # if the snapshot at the current idx
    # is the most up to date one.
    if snap[0] == self.snap_id:
      snap[1] = val
    else:
      self.snaps[index].append([self.snap_id, val])

  def snap(self) -> int:
    self.snap_id += 1
    return self.snap_id - 1

  def get(self, index: int, snap_id: int) -> int:
    # binary search on snap_id
    # for a particular index,
    # the snap ids s_i and s_j, s_i < s_j and i < j, are not necessarily in the form
    # of s_i = s_j + 1
    # see ["SnapshotArray","set","snap","set","get"] [[3],[0,5],[],[0,6],[0,0]]
    # testcase for example.
    # so it follows that we cannot do self.snaps[index][snap_id] right away.
    i = bisect_left(self.snaps[index], [snap_id + 1]) - 1
    return self.snaps[index][i][1]
