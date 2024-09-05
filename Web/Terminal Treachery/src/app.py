from flask import Flask, request, render_template_string
import subprocess

app = Flask(__name__)

index_html = '''
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ping Utility</title>
</head>
<body>
    <h1>Ping Utility</h1>
    <h3>What is Ping?</h3>

    <p>Ping is a tool used to check if a network device is reachable and to measure the time it takes for data to travel there and back. It sends a small packet of data to the target and waits for a response.<br><br> Use the form below to test ping commands on our system.</p>
    <form method="POST" action="/ping">
        <label for="ip">Enter IP Address:</label>
        <input type="text" id="ip" name="ip" required>
        <button type="submit">Ping</button>
    </form>
    {% if result is not none %}
        <h2>Ping Result:</h2>
        <pre>{{ result }}</pre>
    {% endif %}
</body>
</html>
'''

@app.route('/', methods=['GET'])
def index():
    return render_template_string(index_html, result=None)

@app.route('/ping', methods=['POST'])
def ping():
    ip_address = request.form.get('ip')
    if ip_address:
        command = f'ping -c 4 {ip_address}'
        try:
            result = subprocess.check_output(command, shell=True, text=True)
        except subprocess.CalledProcessError as e:
            result = f"Ping failed: {e}"
    else:
        result = "No IP address provided."
    
    return render_template_string(index_html, result=result)

if __name__ == '__main__':
    app.run(debug=True)
