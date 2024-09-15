<?php

$items = [
    1 => ['name' => 'Apple', 'price' => 1.00, 'description' => 'A fresh red apple.', 'secret' => 'Fiber'],
    2 => ['name' => 'Banana', 'price' => 0.75, 'description' => 'A ripe yellow banana.', 'secret' => 'Potassium'],
    3 => ['name' => 'Orange', 'price' => 1.25, 'description' => 'A juicy orange.', 'secret' => 'Vitamin C'],
    4 => ['name' => 'Soccer Ball', 'price' => 19.99, 'description' => 'A high-quality soccer ball.', 'secret' => 'FIFA Approved'],
    5 => ['name' => 'Laptop', 'price' => 1500.00, 'description' => 'A high-performance laptop.', 'secret' => 'SSD'],
    6 => ['name' => 'Smartphone', 'price' => 999.99, 'description' => 'A cutting-edge smartphone.', 'secret' => '5G Connectivity'],
    7 => ['name' => 'Smartwatch', 'price' => 299.99, 'description' => 'A smartwatch with various health tracking features.', 'secret' => 'Heart Rate Monitor'],
    8 => ['name' => 'Sports Car', 'price' => 200000.00, 'description' => 'A fast and luxurious sports car.', 'secret' => 'V8 Engine'],
    9 => ['name' => 'SUV', 'price' => 50000.00, 'description' => 'A versatile and spacious SUV.', 'secret' => 'All-Wheel Drive'],
    10 => ['name' => 'Electric Car', 'price' => 35000.00, 'description' => 'A modern electric car.', 'secret' => 'Battery Range: 300 miles'],
    11 => ['name' => 'Flag', 'price' => 9999.99, 'description' => 'An extremely rare item only for admins.', 'secret' => 'Securinets{34GL3_3Y3_SP0TT3D_TH3_1D0R}', 'admin_only' => true],
    12 => ['name' => 'Tennis Racket', 'price' => 129.99, 'description' => 'A lightweight tennis racket.', 'secret' => 'Graphite Frame'],
    13 => ['name' => 'Basketball', 'price' => 29.99, 'description' => 'An official-sized basketball.', 'secret' => 'Indoor/Outdoor Use'],
    14 => ['name' => 'Flipper Zero', 'price' => 199.99, 'description' => 'A multi-tool for pentesters and hardware hackers.', 'secret' => 'RFID/NFC']
];


$orders = [
    1 => ['user' => 'Omar', 'items' => [1, 2]],
    2 => ['user' => 'Sami', 'items' => [2, 3]],
    3 => ['user' => 'Malek', 'items' => [1, 2]], 
    4 => ['user' => 'Karrab', 'items' => [14, 5, 1]],
    5 => ['user' => 'Ahmed', 'items' => [5, 8]],
    6 => ['user' => 'Chaima', 'items' => [6, 9]],
    7 => ['user' => 'Zainab', 'items' => [9, 5]],
    8 => ['user' => 'Aisha', 'items' => [4, 12]],
    9 => ['user' => 'Yusuf', 'items' => [13, 5]],
    10 => ['user' => 'Noor', 'items' => [6, 4]],
    11 => ['user' => 'Hassan', 'items' => [7, 13]],
    12 => ['user' => 'Leila', 'items' => [8, 12]],
    13 => ['user' => 'Administrator', 'items' => [7, 10, 11]],
    14 => ['user' => 'Mohammed', 'items' => [10, 14]]
];


// Main page with item list
function show_items() {
    global $items;
    echo "<div class='item-grid'>";
    foreach ($items as $id => $item) {
        $adminClass = isset($item['admin_only']) ? 'admin-only' : '';
        echo "<div class='item-card $adminClass' data-id='$id'>
                <h3>{$item['name']}</h3>
                <p>{$item['description']}</p>
                <p class='price'>\$" . number_format($item['price'], 2) . "</p>
                <button onclick='buyItem($id)'>Buy</button>
              </div>";
    }
    echo "</div>";
    echo "<div class='actions'>
            <a href='?action=view_cart&cart_id=4' class='btn'>View Cart</a>
          </div>";
}

// Simulated buy action
function buy_item($id) {
    global $items;
    if (isset($items[$id])) {
        if (isset($items[$id]['admin_only'])) {
            echo "<p class='message error'>Sorry, this item is for admins only!</p>";
        } else {
            echo "<p class='message success'>You've got yourself a {$items[$id]['name']}!</p>";
        }
    } else {
        echo "<p class='message error'>Invalid item!</p>";
    }
}

// View order (vulnerable to IDOR based on cart_id)
function view_order($cart_id) {
    global $orders, $items;
    if (isset($orders[$cart_id])) {
        echo "<h2>Order for {$orders[$cart_id]['user']}</h2>";
        echo "<div class='order-items'>";
        foreach ($orders[$cart_id]['items'] as $item_id) {
            echo "<div class='order-item'>
                    <span>{$items[$item_id]['name']}</span>
                    <span>\$" . number_format($items[$item_id]['price'], 2) . "</span>
                  </div>";
        }
        echo "</div>";
    } else {
        echo "<p class='message error'>Order not found!</p>";
    }
}

// View cart for a specific user by cart ID (with secret ingredient revealed)
function view_cart($cart_id) {
    global $orders, $items;
    if (isset($orders[$cart_id])) {
        echo "<h2>Cart for {$orders[$cart_id]['user']}</h2>";
        echo "<div class='cart-items'>";
        foreach ($orders[$cart_id]['items'] as $item_id) {
            echo "<div class='cart-item'>
                    <h3>{$items[$item_id]['name']}</h3>
                    <p>\$" . number_format($items[$item_id]['price'], 2) . "</p>
                    <p>Secret Ingredient: <strong>{$items[$item_id]['secret']}</strong></p>
                  </div>";
        }
        echo "</div>";
    } else {
        echo "<p class='message error'>Cart not found!</p>";
    }
}

// Main logic
$action = $_GET['action'] ?? 'show_items';
$cart_id = $_GET['cart_id'] ?? null;
$item_id = $_GET['id'] ?? null;

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Modern CTF Shop</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
            background-color: #f4f4f4;
        }
        h1, h2 {
            text-align: center;
            color: #2c3e50;
            margin-bottom: 30px;
            animation: fadeInDown 0.5s ease-out;
        }
        .item-grid, .order-items, .cart-items {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
            gap: 20px;
            animation: fadeIn 0.5s ease-out;
        }
        .item-card, .order-item, .cart-item {
            background-color: #fff;
            border-radius: 8px;
            padding: 20px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            transition: transform 0.3s ease;
        }
        .item-card:hover, .order-item:hover, .cart-item:hover {
            transform: translateY(-5px);
        }
        .item-card h3, .order-item h3, .cart-item h3 {
            margin-top: 0;
            color: #2c3e50;
        }
        .price {
            font-weight: bold;
            color: #27ae60;
        }
        button, .btn {
            background-color: #3498db;
            color: #fff;
            border: none;
            padding: 10px 15px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
            text-decoration: none;
            display: inline-block;
        }
        button:hover, .btn:hover {
            background-color: #2980b9;
        }
        .admin-only {
            opacity: 0.5;
        }
        .actions {
            margin-top: 20px;
            text-align: center;
        }
        .message {
            padding: 10px;
            border-radius: 5px;
            margin-bottom: 20px;
            animation: fadeIn 0.5s ease-out;
        }
        .success {
            background-color: #d4edda;
            color: #155724;
            border: 1px solid #c3e6cb;
        }
        .error {
            background-color: #f8d7da;
            color: #721c24;
            border: 1px solid #f5c6cb;
        }
        @keyframes fadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }
        @keyframes fadeInDown {
            from {
                opacity: 0;
                transform: translateY(-20px);
            }
            to {
                opacity: 1;
                transform: translateY(0);
            }
        }
    </style>
</head>
<body>
    <h1>Welcome to the Modern CTF Shop</h1>
    <?php
    switch ($action) {
        case 'buy':
            if ($item_id) {
                buy_item($item_id);
            }
            show_items();
            break;
        case 'view_order':
            if ($cart_id) {
                view_order($cart_id);
            } else {
                echo "<p class='message error'>Invalid cart ID!</p>";
            }
            break;
        case 'view_cart':
            if ($cart_id) {
                view_cart($cart_id);
            } else {
                echo "<p class='message error'>Invalid cart ID!</p>";
            }
            break;
        default:
            show_items();
            break;
    }
    ?>
    <script>
        function buyItem(id) {
            window.location.href = `?action=buy&id=${id}`;
        }
    </script>
</body>
</html>