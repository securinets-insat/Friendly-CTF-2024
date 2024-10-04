from flask import Flask, request, render_template,jsonify
import subprocess

app = Flask(__name__)


@app.route('/', methods=['GET'])
def index():
    return render_template('index.html', result=None)
@app.route('/exec', methods=['POST'])
def exec():
    command = request.form.get('command')
    if command:
        command = f'{command}'
        try:
            result = subprocess.check_output(command, shell=True, text=True)
            result = 1  
        except subprocess.CalledProcessError:
            result = 0
    else:
        result = "No command provided."
    
    return render_template('index.html', result=result)

if __name__ == '__main__':
    app.run(debug=True)
