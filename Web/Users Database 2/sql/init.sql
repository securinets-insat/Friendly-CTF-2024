USE ctf_db;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL
);

INSERT INTO users (username, password) VALUES
('johndoe', 'Qwerty123!'),
('janedoe', 'Secure*Password1'),
('michael92', 'Password@2024'),
('emily_smith', 'Pass1234!'),
('david.jones', 'S3cure@Password'),
('sarah.connor', 'Skynet#2024'),
('robert_brown', 'Brownbear1$'),
('linda.wilson', 'Wilsons#2023'),
('james.miller', 'M1ll3r@P@ss'),
('karen.johnson', 'Karen!2024'),
('michael.white', 'W1nter*2024'),
('steven_clark', 'S!lvercl@rk9'),
('natalie_davis', 'N@talie8$'),
('laura_thompson', 'L@ura!_12'),
('daniel_james', 'Daniel#2023'),
('susan_hall', 'H@ppyDay2024!'),
('joseph_wright', 'JosephW!123'),
('diana_kim', 'D1an@1234'),
('jason_lopez', 'J@sonLopez!21'),
('robin_green', 'R0b1nGreeN#1'),
('maria_clark', 'MariaC@rk!'),
('kevin_harris', 'K3vin#Password!'),
('rachel_watson', 'W@tson1234!'),
('alexandra_hughes', 'HughesA!@2024'),
('thomas_scott', 'T1m3Sc0tt@'),
('erica_martinez', 'M@rt1nez_S3cure!'),
('paul_garcia', 'G@rciaSecure2024!'),
('emily_hernandez', 'U2VjdXJpbmV0c3tTM1FMX0luajNjdGlvbl9NNHN0M3IhfQ=='),
('aaron_james', 'J@mesAaron!'),
('hannah_lee', 'L33H@nnah$!'),
('luke_adams', 'Ad@msLuk3#2024');
