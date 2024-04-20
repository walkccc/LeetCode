SELECT
  country_name,
  (
    CASE
      WHEN AVG(Weather.weather_state * 1.0) <= 15.0 THEN 'Cold'
      WHEN AVG(Weather.weather_state * 1.0) >= 25.0 THEN 'Hot'
      ELSE 'Warm'
    END
  ) AS weather_type
FROM Countries
INNER JOIN Weather
  USING (country_id)
WHERE day BETWEEN '2019-11-01' AND '2019-11-30'
GROUP BY 1;
