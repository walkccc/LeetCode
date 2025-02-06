import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
  products['quantity'].fillna(0, inplace=True)
  return products
