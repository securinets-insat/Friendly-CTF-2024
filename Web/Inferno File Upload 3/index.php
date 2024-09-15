<?php
$target_dir = "uploads/";
$max_file_size = 2 * 1024 * 1024; // 2 MB
$blacklisted_extensions = [
    'php', 'php2', 'php3', 'php4', 'php5', 'php6', 'php7', 'phps', 'pht', 'phtm', 'phtml', 
    'pgif', 'shtml', 'htaccess', 'phar', 'inc', 'hphp', 'ctp', 'module'
];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $response = ['success' => false, 'message' => ''];
    
    if (!isset($_FILES['file']['error']) || is_array($_FILES['file']['error'])) {
        $response['message'] = 'Invalid parameters.';
    } elseif ($_FILES['file']['error'] !== UPLOAD_ERR_OK) {
        $response['message'] = 'Upload failed. Error code: ' . $_FILES['file']['error'];
    } elseif ($_FILES['file']['size'] > $max_file_size) {
        $response['message'] = 'File is too large. Maximum size is 2 MB.';
    } else {
        $file_extension = pathinfo($_FILES['file']['name'], PATHINFO_EXTENSION);
        
        if (in_array($file_extension, $blacklisted_extensions)) {
            $response['message'] = 'File type not allowed.';
        } else {
            $new_filename = uniqid() . '.' . $file_extension;
            $upload_path = $target_dir . $new_filename;
            
            if (move_uploaded_file($_FILES['file']['tmp_name'], $upload_path)) {
                $response['success'] = true;
                $response['message'] = 'File uploaded successfully!';
                $response['file_url'] = 'uploads/' . $new_filename;
            } else {
                $response['message'] = 'Failed to move uploaded file.';
            }
        }
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
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inferno File Upload</title>
    <style>
        @keyframes flicker {
            0% { text-shadow: 0 0 5px #ff0000, 0 0 10px #ff0000; }
            50% { text-shadow: 0 0 10px #ff0000, 0 0 20px #ff0000; }
            100% { text-shadow: 0 0 5px #ff0000, 0 0 10px #ff0000; }
        }
        body {
            font-family: 'Courier New', monospace;
            background-color: #000;
            color: #ff0000;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            overflow: hidden;
        }
        .upload-container {
            background-color: rgba(20, 20, 20, 0.7);
            padding: 2rem;
            border: 2px solid #ff0000;
            box-shadow: 0 0 20px rgba(255, 0, 0, 0.5);
            text-align: center;
            position: relative;
            max-width: 500px;
            width: 100%;
        }
        .fire-background {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: url("/public/images/Flame-bg.gif") center / cover no-repeat;
            opacity: 0.5;
            z-index: -1;
        }
        .skull {
            position: absolute;
            width: 50px;
            height: 50px;
            background: url("/public/images/skull.gif") center / cover no-repeat;
        }
        .skull-tl { top: 10px; left: 10px; }
        .skull-tr { top: 10px; right: 10px; }
        .skull-bl { bottom: 10px; left: 10px; }
        .skull-br { bottom: 10px; right: 10px; }
        h1 {
            font-size: 2.5em;
            margin-bottom: 1rem;
            animation: flicker 2s infinite;
        }
        #drop-area {
            border: 2px dashed #ff0000;
            border-radius: 10px;
            padding: 2rem;
            cursor: pointer;
            transition: all 0.3s ease;
            margin-bottom: 1rem;
        }
        #drop-area.highlight {
            background-color: rgba(255, 0, 0, 0.1);
            box-shadow: 0 0 20px rgba(255, 0, 0, 0.5) inset;
        }
        #fileElem {
            display: none;
        }
        #upload-button {
            background-color: #ff0000;
            color: #000;
            border: none;
            padding: 10px 20px;
            font-size: 1em;
            cursor: pointer;
            transition: all 0.3s ease;
            font-family: 'Courier New', monospace;
            font-weight: bold;
        }
        #upload-button:hover {
            background-color: #ff4444;
            box-shadow: 0 0 15px rgba(255, 0, 0, 0.7);
        }
        #file-info, #message {
            margin-top: 1rem;
        }
        #message {
            font-weight: bold;
        }
        .success { color: #00ff00; }
        .error { color: #ff4444; }
    </style>
</head>
<body>
<div class="fire-background"></div>
    <div class="upload-container">
    <div class="skull skull-tl"></div>
        <div class="skull skull-tr"></div>
        <div class="skull skull-bl"></div>
        <div class="skull skull-br"></div>
        <h1>Inferno File Upload</h1>
        <div id="drop-area">
            <form class="my-form">
                <p>Drag and drop your file here<br>or click to select</p>
                <input type="file" id="fileElem">
            </form>
        </div>
        <button type="button" id="upload-button" style="display: none;">UPLOAD</button>
        <div id="file-info"></div>
        <div id="message"></div>
    </div>

    <script>
        let dropArea = document.getElementById('drop-area');
        let fileInput = document.getElementById('fileElem');
        let uploadButton = document.getElementById('upload-button');
        let fileInfo = document.getElementById('file-info');
        let messageDiv = document.getElementById('message');

        ['dragenter', 'dragover', 'dragleave', 'drop'].forEach(eventName => {
            dropArea.addEventListener(eventName, preventDefaults, false);
        });

        function preventDefaults(e) {
            e.preventDefault();
            e.stopPropagation();
        }

        ['dragenter', 'dragover'].forEach(eventName => {
            dropArea.addEventListener(eventName, highlight, false);
        });

        ['dragleave', 'drop'].forEach(eventName => {
            dropArea.addEventListener(eventName, unhighlight, false);
        });

        function highlight() {
            dropArea.classList.add('highlight');
        }

        function unhighlight() {
            dropArea.classList.remove('highlight');
        }

        dropArea.addEventListener('drop', handleDrop, false);
        dropArea.addEventListener('click', () => fileInput.click());
        fileInput.addEventListener('change', handleFiles);

        function handleDrop(e) {
            let dt = e.dataTransfer;
            let files = dt.files;
            handleFiles(files);
        }

        function handleFiles(files) {
            if (files instanceof FileList) {
                if (files.length > 0) {
                    uploadButton.style.display = 'inline-block';
                    fileInfo.textContent = `Selected file: ${files[0].name}`;
                }
            } else if (files.target && files.target.files.length > 0) {
                uploadButton.style.display = 'inline-block';
                fileInfo.textContent = `Selected file: ${files.target.files[0].name}`;
            }
        }

        uploadButton.addEventListener('click', uploadFile);

        function uploadFile() {
            let file = fileInput.files[0];
            if (!file) {
                messageDiv.textContent = 'No file selected!';
                messageDiv.className = 'error';
                return;
            }

            let formData = new FormData();
            formData.append('file', file);

            uploadButton.disabled = true;
            uploadButton.textContent = 'UPLOADING...';

            fetch('index.php', {
                method: 'POST',
                body: formData
            })
            .then(response => response.json())
            .then(data => {
                if (data.success) {
                    messageDiv.innerHTML = `${data.message}<br><a href="${data.file_url}" target="_blank">View uploaded file</a>`;
                    messageDiv.className = 'success';
                } else {
                    messageDiv.textContent = data.message;
                    messageDiv.className = 'error';
                }
            })
            .catch(error => {
                console.error('Error:', error);
                messageDiv.textContent = 'An error occurred during upload.';
                messageDiv.className = 'error';
            })
            .finally(() => {
                uploadButton.disabled = false;
                uploadButton.textContent = 'UPLOAD';
                fileInput.value = '';
                fileInfo.textContent = '';
                uploadButton.style.display = 'none';
            });
        }
    </script>
    </div>
</body>
</html>