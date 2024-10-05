from flask import Flask, render_template, request, jsonify, redirect, url_for
import jwt
import base64
import json
import datetime
import os
from dotenv import load_dotenv

load_dotenv()

app = Flask(__name__)

# Pre-registered users
users = {
    'guest': 'guest'
}

def generate_jwt(username):
    token = jwt.encode({
        'role': username,
        'exp': datetime.datetime.utcnow() + datetime.timedelta(hours=1)
    }, os.getenv('SECRET_KEY'), algorithm='HS256')
    return token

@app.route('/')
def login():
    return render_template('login.html')

@app.route('/login', methods=['POST'])
def login_user():
    username = request.json.get('username')
    password = request.json.get('password')

    if username in users and users[username] == password:
        token = generate_jwt(username)
        return jsonify({'token': token})
    else:
        return jsonify({'message': 'Invalid credentials'}), 401

@app.route('/welcome')
def welcome():
    return render_template('welcome.html')

@app.route('/api/flag', methods=['GET'])
def get_flag():
    token = request.headers.get('Authorization').split(" ")[1] if request.headers.get('Authorization') else None
    
    if token:
        try:
            header_base64 = token.split('.')[0]
            payload_base64 = token.split('.')[1]
            
            # Decode and validate the header
            header_padding = '=' * (4 - len(header_base64) % 4)
            header_decoded = base64.b64decode(header_base64 + header_padding)
            header = json.loads(header_decoded)

            if header.get('alg') != 'HS256':
                return jsonify({'message': 'Invalid token algorithm'}), 401

            # Decode the payload
            payload_padding = '=' * (4 - len(payload_base64) % 4)
            payload_decoded = base64.b64decode(payload_base64 + payload_padding)
            payload = json.loads(payload_decoded)

            if payload.get('role') == 'admin':
                return jsonify({'flag': os.getenv('FLAG')}), 200
            else:
                return jsonify({'message': 'Unauthorized access'}), 403
            
        except json.JSONDecodeError:
            return jsonify({'message': 'Invalid token format'}), 401
        except Exception as e:
            return jsonify({'message': 'Error processing token'}), 401

    return jsonify({'message': 'Token required'}), 401

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=os.getenv('PORT'), debug=False)
