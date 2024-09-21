<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Path to the Crown</title>
    <link href="https://fonts.googleapis.com/css2?family=Cinzel:wght@400;700&family=Lora&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Lora', serif;
            background-color: #f3e5d8;
            color: #3c2f2f;
            margin: 0;
            padding: 0;
            background-image: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" width="100" height="100" viewBox="0 0 100 100"><rect fill="%23f3e5d8" width="100" height="100"/><path d="M0 0L50 50L100 0ZM100 100L50 50L0 100Z" fill="%23e6d2bc" fill-opacity="0.5"/></svg>');
            background-size: 100px 100px;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            background-color: rgba(255, 255, 255, 0.8);
            border-radius: 10px;
            box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-family: 'Cinzel', serif;
            text-align: center;
            margin: 50px 0;
            color: #8b4513;
            font-size: 3em;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3);
            letter-spacing: 2px;
        }
        ul {
            list-style-type: none;
            padding: 0;
            text-align: center;
        }
        li {
            margin: 20px 0;
        }
        a {
            text-decoration: none;
            color: #8b4513;
            font-size: 1.2em;
            font-weight: bold;
            transition: all 0.3s ease;
            position: relative;
            padding: 5px 10px;
        }
        a::before, a::after {
            content: '';
            position: absolute;
            width: 0;
            height: 2px;
            background-color: #8b4513;
            transition: all 0.3s ease;
        }
        a::before {
            top: 0;
            left: 0;
        }
        a::after {
            bottom: 0;
            right: 0;
        }
        a:hover::before, a:hover::after {
            width: 100%;
        }
        a:hover {
            color: #5e2f0d;
        }
        .header-decoration {
            text-align: center;
            margin-bottom: 30px;
        }
        .header-decoration::before,
        .header-decoration::after {
            content: "⚔";
            font-size: 2em;
            color: #8b4513;
            margin: 0 20px;
        }
        .disclaimer {
            text-align: center;
            font-style: italic;
            margin-top: 40px;
            padding: 10px;
            background-color: rgba(139, 69, 19, 0.1);
            border-radius: 5px;
            font-size: 0.9em;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header-decoration"></div>
        <h1>Path to the Crown</h1>
        <ul>
            <li><a href="empire.php?empire=british_empire">British Empire</a></li>
            <li><a href="empire.php?empire=umayyad_caliphate">Umayyad Caliphate</a></li>
			<li><a href="empire.php?empire=abbasid_caliphate">Abbasid Caliphate</a></li>
			<li><a href="empire.php?empire=mongol_empire">Mongol Empire</a></li>
            <li><a href="empire.php?empire=russian_empire">Russian Empire</a></li>
            <li><a href="empire.php?empire=ottoman_empire">Ottoman Empire</a></li>
            <li><a href="empire.php?empire=ancient_egypt">Ancient Egypt</a></li>
            <li><a href="empire.php?empire=qing_dynasty">Qing Dynasty</a></li>
            <li><a href="empire.php?empire=roman_empire">Roman Empire</a></li>
            <li><a href="empire.php?empire=persian_achaemenid_empire">Persian Achaemenid Empire</a></li>
        </ul>
        <div class="disclaimer">
            <p>Disclaimer: We cannot guarantee the complete historical precision of all information presented. This content is intended for educational and entertainment purposes.</p>
        </div>
    </div>
</body>
</html>