# Write your MySQL query statement below
select LEFT(trans_date, 7) as month,
country,
count(id) as trans_count,
sum(IF(state = 'approved', 1, 0)) as approved_count,
sum(amount) as trans_total_amount,
sum(IF(state = 'approved', amount, 0)) as approved_total_amount
From Transactions 
group by country,month


-- LEFT(trans_date, 7) as month 
-- take 7 letter from left ex : 2018-12-18  -> 2018-12