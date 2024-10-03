//ALL YOU NEED IS HERE
<?php
// Hardcoded SHA-256 hashed password
$stored_hash = "c4a521f815496be53f64ef8e1e3f2ab964dbcf5d94cb21cc965796a44985ebb4"; // SHA-256 


$seasoning = "03";

$VAR = ""; // Initialize $VAR as an empty string

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Concatenate the salt to the entered password
    $seasoned_password = $password . $seasoning;

    // Hash the salted password using SHA-256
    $hashed_password = hash('sha256', $seasoned_password);


    // Check if the entered password hash matches the stored hash
    if ($hashed_password === $stored_hash && $username === "admin") {
        $VAR = "Securinets{HELP}";
    } else {
        $VAR = "Invalid credentials!";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>HashKitty</title>
</head>
<body>
    <h1>Login</h1>
    <form method="POST" action="">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required><br><br>
        
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required><br><br>
        
        <input type="submit" value="Login">
    </form>
    <br>
    <?php
    // Display the $VAR message if it's not empty
    if (!empty($VAR)) {
        echo "<p>$VAR</p>";
    }
    ?>
</body>
</html>
