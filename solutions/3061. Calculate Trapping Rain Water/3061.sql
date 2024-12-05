WITH
  HeightsWithMinMax AS (
    SELECT
      height,
      MAX(height) OVER(ORDER BY id ASC) AS prev_max_height,
      MAX(height) OVER(ORDER BY id DESC) AS next_max_height
    FROM Heights
  )
SELECT
  SUM(LEAST(prev_max_height, next_max_height) - height) AS total_trapped_water
FROM HeightsWithMinMax;
