<?php

$flag = "Securinets{C00K13S_4R3NT_F00D}";

if (!isset($_COOKIE['admin'])) {
    setcookie('admin', 'ZmFsc2U', time() + 3600, '/');
}

function is_admin() {
    if (!isset($_COOKIE['admin'])) {
        return false;
    }
    $admin_value = base64_decode($_COOKIE['admin']);
    return $admin_value === 'true';
}

if (is_admin()) {
    $message = "Welcome Boss! " . $flag;
} else {
    $message = "Access Denied. This page is for administrators only.";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Area</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #f0f0f0;
        }
        .container {
            background-color: white;
            padding: 2rem;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
            text-align: center;
        }
        h1 {
            color: #333;
        }
        .message {
            margin-top: 1rem;
            padding: 1rem;
            background-color: <?php echo is_admin() ? '#d4edda' : '#f8d7da'; ?>;
            border: 1px solid <?php echo is_admin() ? '#c3e6cb' : '#f5c6cb'; ?>;
            border-radius: 4px;
            color: <?php echo is_admin() ? '#155724' : '#721c24'; ?>;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Admin Area</h1>
        <div class="message">
            <?php echo $message; ?>
        </div>
    </div>
</body>
</html>