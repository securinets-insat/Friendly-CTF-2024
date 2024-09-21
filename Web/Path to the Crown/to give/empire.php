<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo htmlspecialchars($empire); ?> - Path to the Crown</title>
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
            margin: 50px 0 30px;
            color: #8b4513;
            font-size: 2.5em;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3);
            letter-spacing: 2px;
        }
        .empire-image {
            display: block;
            margin: 30px auto;
            max-width: 100%;
            height: auto;
            border-radius: 10px;
            box-shadow: 0 0 15px rgba(0, 0, 0, 0.2);
        }
        .back-link {
            display: block;
            text-align: center;
            margin-top: 30px;
            font-size: 1.2em;
        }
        .back-link a {
            color: #8b4513;
            text-decoration: none;
            font-weight: bold;
            transition: all 0.3s ease;
            position: relative;
            padding: 5px 10px;
        }
        .back-link a::before, .back-link a::after {
            content: '';
            position: absolute;
            width: 0;
            height: 2px;
            background-color: #8b4513;
            transition: all 0.3s ease;
        }
        .back-link a::before {
            top: 0;
            left: 0;
        }
        .back-link a::after {
            bottom: 0;
            right: 0;
        }
        .back-link a:hover::before, .back-link a:hover::after {
            width: 100%;
        }
        .back-link a:hover {
            color: #5e2f0d;
        }
        .empire-description {
			font-family: 'Lora', serif;
            text-align: justify;
            line-height: 1.6;
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <div class="container">
        <?php
        $empire = $_GET['empire'] ?? '';
        $empire = preg_replace('/\.\.\//', '', $empire);
        ?>
        <h1><?php echo htmlspecialchars(str_replace('_', ' ', ucwords($empire))); ?></h1>
        
        <?php
        $base_dir = 'empires/';
        $file = $base_dir . $empire . '.txt';
        if (file_exists($file)) {
            echo '<div class="empire-description">';
            include($file);
            echo '</div>';
        } else {
            echo "<h2>Empire description not found.</h2>";
        }
        ?>
        
        <?php
        $image_path = 'images/' . $empire . '.png';
        if (file_exists($image_path)) {
            echo '<img src="' . $image_path . '" alt="' . htmlspecialchars($empire) . ' Image" class="empire-image">';
        }
        ?>
        
        <div class="back-link">
            <a href="index.php">← Back to Empire List</a>
        </div>
    </div>
</body>
</html>