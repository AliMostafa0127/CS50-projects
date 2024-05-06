select title from movies
join stars on movies.id= stars.movie_id
join people on people.id = stars.person_id
where  people.name  = "Bradley Cooper"
AND title in
(select title from movies
join stars on movies.id= stars.movie_id
join people on people.id = stars.person_id
where  people.name  =  "Jennifer Lawrence"
);

