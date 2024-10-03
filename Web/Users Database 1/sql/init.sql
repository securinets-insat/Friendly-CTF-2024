USE ctf_db;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL
);

INSERT INTO users (username, password) VALUES 
('john_doe', 'qwerty123'),
('jane_smith', 'letmein'),
('bob_johnson', 'password123'),
('alice_wonder', 'wonderland'),
('charlie_brown', 'snoopy'),
('david_cooper', 'securepass'),
('eva_green', 'greenapple'),
('frank_sinatra', 'myway'),
('grace_hopper', 'compiler'),
('henry_ford', 'model_t'),
('iris_west', 'flashfan'),
('jack_sparrow', 'blackpearl'),
('kate_austen', 'oceanic815'),
('liam_neeson', 'taken'),
('mia_wallace', 'jackrabbit'),
('neo_anderson', 'matrix'),
('olivia_pope', 'scandal'),
('peter_parker', 'spidey'),
('quinn_fabray', 'cheerio'),
('ron_weasley', 'hermione'),
('sarah_connor', 'judgment_day'),
('tony_stark', 'ironman'),
('uma_thurman', 'killbill'),
('victor_frankenstein', 'Securinets{1nject0r_4tTack_1s_FuN!}'),
('walter_white', 'heisenberg'),
('xena_warrior', 'princess'),
('yoda_master', 'force'),
('zoe_saldana', 'avatar');