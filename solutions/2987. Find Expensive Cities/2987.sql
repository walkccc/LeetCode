SELECT city
FROM Listings
GROUP BY 1
HAVING AVG(price) > (SELECT AVG(price) FROM Listings)
ORDER BY 1;
