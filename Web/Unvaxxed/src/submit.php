<?php
$data = $_POST['data'];

// Check if the required header is set
if (!isset($_SERVER['HTTP_MEDICAL_SERVICE']) || $_SERVER['HTTP_MEDICAL_SERVICE'] !== 'Data Entry Agent') {
    echo <<<HTML
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="static/submit.css"/>
    <title>Unvaxxed</title>
</head>
<body>
<div class="container">
    <h2>Error</h2>
    <div class="alert alert-danger">
        Unauthorized access!<br>
        Only data entry agents are allowed to submit patients' data.
    </div>
    <pre><code>if (!isset(\$_SERVER['HTTP_MEDICAL_SERVICE']) || \$_SERVER['HTTP_MEDICAL_SERVICE'] !== 'Data Entry Agent')</code></pre>
    <a href="/">Submit Another</a>
</div>
</div>
</body>
</html>
HTML;
    exit();
}

error_reporting(0);
ini_set('display_errors', 0);

libxml_disable_entity_loader(false);

$dom = new DOMDocument();
$dom->loadXML($data, LIBXML_NOENT | LIBXML_DTDLOAD);
$patients = simplexml_import_dom($dom);
$json = json_encode($patients);
$parsedData = json_decode($json, true);

if (isset($parsedData['patients']['patient'])) {
    $count = count($parsedData['patients']['patient']);

    $contents = '';
    foreach ($parsedData['patients']['patient'] as $item) {
        $contents .= '<div class="alert alert-success">' .
            ($item['name'] ?? '?') .
            ' (' . ($item['age'] ?? '?') . ' y.o) has been added!' .
            '</div>';
    }

    echo <<<HTML
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="static/submit.css"/>
    <title>Unvaxxed</title>
</head>
<body>
<div class="container">
    <h2>Patients</h2>
    $contents
    <a href="/">Submit Another</a>
</div>
</div>
</body>
</html>
HTML;

    exit();
}

echo <<<HTML
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="static/submit.css"/>
    <title>Unvaxxed</title>
</head>
<body>
<div class="container">
    <h2>Error</h2>
    <div class="alert alert-danger">
        XML could not be parsed.
    </div>
    <a href="/">Submit Another</a>
</div>
</div>
</body>
</html>
HTML;

exit();
