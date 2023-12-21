import pandas as pd


def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
  return students.astype({'grade': int})
