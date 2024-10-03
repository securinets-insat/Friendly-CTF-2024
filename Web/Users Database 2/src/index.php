<?php
require 'config.php';


$mysqli = new mysqli($host, $user, $pass, $db);

if ($mysqli->connect_error) {
    die("Connection failed: " . $mysqli->connect_error . " (Error code: " . $mysqli->connect_errno . ")");
}

function basic_filter($input) {
    // Remove some common SQL injection attempts
    $filtered = str_replace(array("or", "\"", ";", "--", "/*", "*/"), "", $input);
    // Remove spaces around equality operator
    $filtered = preg_replace('/\s*=\s*/', '=', $filtered);
    return $filtered;
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Search</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h1>User Search</h1>
        <form method="GET" action="">
            <input type="text" name="username" placeholder="Enter username to search">
            <input type="submit" value="Search">
        </form>

        <?php
        if (isset($_GET['username'])) {
            $username = basic_filter($_GET['username']);
            echo "<p>Searching for username : $username</p>";
            $query = "SELECT id, username, password FROM users WHERE username = '$username'";
            
            try {
                $result = $mysqli->query($query);
            } catch (Exeption $err) {
                echo "<p>Syntax Error : $query </p>";
            }

            if ($result) {
                echo "<table>";
                echo "<tr><th>ID</th><th>Username</th><th>Password</th></tr>";
                while ($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    echo "<td>" . $row['id'] . "</td>";
                    echo "<td>" . $row['username'] . "</td>";
                    echo "<td>" . $row['password'] . "</td>";
                    echo "</tr>";
                }
                echo "</table>";
                $result->free();
            } else {
                echo "<p>Error executing query: " . $mysqli->error . "</p>";
            }
        }
        ?>
    </div>
</body>
</html>