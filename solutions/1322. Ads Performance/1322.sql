SELECT
  ad_id,
  IFNULL(
    ROUND(
      SUM(action = 'Clicked') * 100 /(SUM(action = 'Clicked') + SUM(action = 'Viewed')),
      2
    ),
    0
  ) AS ctr
FROM Ads
GROUP BY 1
ORDER BY ctr DESC, ad_id;
