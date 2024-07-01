class Solution:
  def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
    while sx < tx and sy < ty:
      tx, ty = tx % ty, ty % tx

    return sx == tx and sy <= ty and (ty - sy) % tx == 0 or \
        sy == ty and sx <= tx and (tx - sx) % ty == 0
