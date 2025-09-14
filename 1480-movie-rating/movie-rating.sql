# Write your MySQL query statement below
(
    SELECT name as results 
    FROM MovieRating JOIN Users USING(user_id)
    GROUP BY user_id
    ORDER BY count(*) DESC, name
    LIMIT 1 
)
UNION ALL
(
    SELECT title as results 
    FROM MovieRating JOIN Movies USING(movie_id)
    WHERE EXTRACT(YEAR_MONTH FROM created_at) = 202002
    GROUP BY movie_id
    ORDER BY AVG(rating) DESC,title
    LIMIT 1 
)