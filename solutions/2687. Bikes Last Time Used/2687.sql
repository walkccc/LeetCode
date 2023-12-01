SELECT bike_number, MAX(end_time) AS end_time
FROM Bikes
GROUP BY 1;
