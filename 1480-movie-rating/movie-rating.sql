# Write your MySQL query statement below
SELECT name AS results
FROM
(
    SELECT u.name 
    FROM Users AS u
    JOIN MovieRating AS mr
    ON u.user_id=mr.user_id
    GROUP BY u.user_id,u.name
    ORDER BY COUNT(*) DESC,u.name ASC
    LIMIT 1
)t

UNION ALL

SELECT title AS results
FROM
( 
    SELECT m.title 
    FROM Movies AS m
    JOIN MovieRating AS mr
    ON m.movie_id=mr.movie_id
    WHERE mr.created_at>='2020-02-01'
    AND mr.created_at<'2020-03-01'
    GROUP BY m.movie_id,m.title
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
)t