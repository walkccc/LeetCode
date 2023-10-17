WITH
  InsuranceWithCounts AS (
    SELECT
      tiv_2016,
      COUNT(*) OVER(PARTITION by tiv_2015) AS tiv_2015_count,
      COUNT(*) OVER(PARTITION by lat, lon) AS city_count
    FROM Insurance
  )
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM InsuranceWithCounts
WHERE tiv_2015_count > 1
  AND city_count = 1;
