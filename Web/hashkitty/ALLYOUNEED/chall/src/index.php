//ALL YOU NEED IS HERE

<?php
// Hardcoded hashed password UwU
$stored_hash = "b31f2c047e442f9e88f27ab3742c18d8a305d43ac034c6b0f65fb095260c5a7a"; 

$VAR = ""; 

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $hashed_password = hash('sha256', $password);


    if ($hashed_password === $stored_hash && $username === "admin") {
        $VAR = "Securinets{Fake_Flag}"; // cmon it ain't that easy
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
