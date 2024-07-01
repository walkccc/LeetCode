import pandas as pd


def getDataframeSize(players: pd.DataFrame) -> List[int]:
  return [*players.shape]
