SELECT MIN(P1.x - P2.x) AS shortest
FROM Point AS P1, Point AS P2
WHERE P1.x > P2.x;
