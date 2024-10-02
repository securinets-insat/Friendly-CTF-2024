<?php
// Hardcoded SHA-256 hashed password
$stored_hash = "b31f2c047e442f9e88f27ab3742c18d8a305d43ac034c6b0f65fb095260c5a7a"; // SHA-256 hash of 'not2secure'

$VAR = ""; // Initialize $VAR as an empty string

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Hash the entered password using SHA-256
    $hashed_password = hash('sha256', $password);

    // Check if the entered password hash matches the stored hash
    if ($hashed_password === $stored_hash && $username === "admin") {
        $VAR = "Securinets{DAyuM_S0n_WhRe'd_ya_f1Nd_tH1s}";
    } else {
        $VAR = "Invalid credentials!";
    }
}
?><!DOCTYPE html>
<html>
<head>
    <title>HashKitty</title>
    <style>
        body {
            background-color: #ffb6c1; /* Pink background */
            font-family: 'Arial', sans-serif;
            color: #000; /* Black text */
            text-align: center;
            padding-top: 100px;
        }
        
        h1 {
            color: #000;
            font-size: 48px;
            margin-bottom: 20px;
        }
        
        form {
            background-color: rgba(255, 255, 255, 0.8);
            padding: 20px;
            border-radius: 10px;
            display: inline-block;
        }
        
        label {
            font-size: 18px;
            font-weight: bold;
            display: block;
            margin-bottom: 10px;
        }
        
        input[type="text"],
        input[type="password"] {
            width: 80%;
            padding: 10px;
            margin-bottom: 20px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        
        input[type="submit"] {
            background-color: #ff6b6b;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-size: 18px;
        }
        
        input[type="submit"]:hover {
            background-color: #ff4747;
        }

        img {
            width: 100px;
            height: auto;
            margin-top: 20px;
        }
        
        p {
            font-size: 20px;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <h1>HashKitty</h1>
    <form method="POST" action="">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required><br><br>
        
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required><br><br>
        
        <input type="submit" value="Login">
    </form>
    
    <!-- Kitty image under the form -->
    <img src="fluffytongue.jpg" alt="Cute kitty">
    
    <br>
    <?php
    // Display the $VAR message if it's not empty
    if (!empty($VAR)) {
        echo "<p>$VAR</p>";
    }
    ?>
</body>
</html>
