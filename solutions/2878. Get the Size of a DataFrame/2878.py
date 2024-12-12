import pandas as pd


def getDataframeSize(players: pd.DataFrame) -> list[int]:
  return [*players.shape]
