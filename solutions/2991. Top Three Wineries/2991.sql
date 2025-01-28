WITH
  WineryToTotalPoints AS (
    SELECT
      country,
      winery,
      SUM(points) AS total_points
    FROM Wineries
    GROUP BY 1, 2
  ),
  RankedWineries AS (
    SELECT
      *,
      RANK() OVER(
        PARTITION BY country
        ORDER BY total_points DESC, winery
      ) AS `rank`
    FROM WineryToTotalPoints
  )
SELECT
  country,
  MAX(
    CASE WHEN `rank` = 1 THEN CONCAT(winery, ' (', total_points, ')') END
  ) AS top_winery,
  IFNULL(
    MAX(CASE WHEN `rank` = 2 THEN CONCAT(winery, ' (', total_points, ')') END),
    'No second winery'
  ) AS second_winery,
  IFNULL(
    MAX(CASE WHEN `rank` = 3 THEN CONCAT(winery, ' (', total_points, ')') END),
    'No third winery'
  ) AS third_winery
FROM RankedWineries
WHERE `rank` <= 3
GROUP BY 1
ORDER BY 1;
