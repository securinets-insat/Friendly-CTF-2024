<?php

function listDirectoryContents($path) {
    $contents = [];

    if (is_dir($path)) {
        $items = scandir($path);
        foreach ($items as $item) {
            if ($item != '.' && $item != '..') {
                $fullPath = $path . DIRECTORY_SEPARATOR . $item;
                if (is_dir($fullPath)) {
                    $contents['directories'][] = $item;
                } else {
                    $contents['files'][] = $item;
                }
            }
        }
    } else {
        $contents['error'] = 'Invalid directory path.';
    }

    return $contents;
}

function readFileContents($path) {
    if (is_file($path) && is_readable($path)) {
        return nl2br(htmlspecialchars(file_get_contents($path)));
    } else {
        return 'Invalid file path or file is not readable.';
    }
}

function writeFileContents($path, $content) {
    if (is_writable(dirname($path))) {
        file_put_contents($path, $content);
        return 'File written successfully.';
    } else {
        return 'Invalid file path or no write permission.';
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $action = $_POST['action'];

    $response = [];

    switch ($action) {
        case 'list_directory':
            $dirPath = $_POST['directory_path'];
            $response = listDirectoryContents($dirPath);
            break;
        case 'read_file':
            $filePath = $_POST['file_path'];
            $response = readFileContents($filePath);
            break;
        case 'write_file':
            $writePath = $_POST['write_path'];
            $content = $_POST['content'];
            $response = writeFileContents($writePath, $content);
            break;
    }

    header('Content-Type: application/json');
    echo json_encode($response);
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>File and Directory Management</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body { font-family: Arial, sans-serif; }
        .container { max-width: 600px; margin: 20px auto; }
        textarea { width: 100%; height: 100px; }
        button { margin-top: 10px; }
        pre { background-color: #f4f4f4; padding: 10px; white-space: pre-wrap; word-wrap: break-word; }
        .result-container { margin-top: 20px; }
    </style>
</head>
<body>
    <div class="container">
        <h1>File and Directory Management</h1>
        
        <!-- Form for Listing Directory Contents -->
        <h2>List Directory Contents</h2>
        <form id="directory-form">
            <label for="directory_path">Directory Path:</label><br>
            <input type="text" id="directory_path" name="directory_path" required><br>
            <input type="hidden" name="action" value="list_directory">
            <button type="submit">List Contents</button>
        </form>
        
        <!-- Form for Reading File Contents -->
        <h2>Read File Contents</h2>
        <form id="file-form">
            <label for="file_path">File Path:</label><br>
            <input type="text" id="file_path" name="file_path" required><br>
            <input type="hidden" name="action" value="read_file">
            <button type="submit">Read File</button>
        </form>
        
        <!-- Form for Writing to a File -->
        <h2>Write to a File</h2>
        <form id="write-form">
            <label for="write_path">File Path:</label><br>
            <input type="text" id="write_path" name="write_path" required><br>
            <label for="content">Content to Write:</label><br>
            <textarea id="content" name="content" required></textarea><br>
            <input type="hidden" name="action" value="write_file">
            <button type="submit">Write to File</button>
        </form>

        <div class="result-container">
            <h2>Result</h2>
            <pre id="result"></pre>
        </div>
    </div>

    <script>
        function handleFormSubmit(formId) {
            document.getElementById(formId).addEventListener('submit', function(event) {
                event.preventDefault();
                var formData = new FormData(this);
                var xhr = new XMLHttpRequest();
                xhr.open('POST', '', true);
                xhr.onload = function () {
                    if (xhr.status === 200) {
                        var result = JSON.parse(xhr.responseText);
                        var resultDisplay = document.getElementById('result');
                        resultDisplay.innerHTML = '';
                        if (result.files) {
                            result.files.forEach(file => {
                                resultDisplay.innerHTML += `File: ${file}<br>`;
                            });
                        } else if (result.directories) {
                            result.directories.forEach(dir => {
                                resultDisplay.innerHTML += `Directory: ${dir}<br>`;
                            });
                        } else {
                            resultDisplay.innerHTML = result;
                        }
                    }
                };
                xhr.send(formData);
            });
        }

        handleFormSubmit('directory-form');
        handleFormSubmit('file-form');
        handleFormSubmit('write-form');
    </script>
</body>
</html>
