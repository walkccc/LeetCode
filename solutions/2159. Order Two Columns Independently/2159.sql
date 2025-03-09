WITH
  FirstCols AS(
    SELECT
      first_col,
      ROW_NUMBER() OVER() AS `row_number`
    FROM Data
    ORDER BY 1
  ),
  SecondCols AS (
    SELECT
      second_col,
      ROW_NUMBER() OVER() AS `row_number`
    FROM Data
    ORDER BY 1 DESC
  )
SELECT
  FirstCols.first_col,
  SecondCols.second_col
FROM FirstCols
INNER JOIN SecondCols
  USING (`row_number`);
