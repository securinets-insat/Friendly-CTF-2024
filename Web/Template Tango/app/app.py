
from flask import Flask, render_template_string,request

  
app = Flask(__name__) 
  
@app.route("/") 
def home(): 
    template = '''
    <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f9;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .container {
            text-align: center;
            padding: 20px;
            border: 1px solid #ddd;
            border-radius: 8px;
            background: #fff;
        }
        input[type="text"] {
            padding: 10px;
            border: 1px solid #ddd;
            border-radius: 4px;
            width: 100%;
            max-width: 300px;
            margin-bottom: 10px;
        }
        input[type="submit"] {
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            background-color: #5cb85c;
            color: #fff;
            cursor: pointer;
        }
        input[type="submit"]:hover {
            background-color: #4cae4c;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Enter Your Name</h1>
        <form action="{{ url_for('welcome') }}" method="get">
            <input type="text" name="name" placeholder="Your name" required>
            <input type="submit" value="Submit">
        </form>
    </div>
</body>
</html>

'''
    return render_template_string(template) 

@app.route("/welcome")
def welcome():
    name = request.args.get('name', 'Guest')
    print(type(name))
    template = '''
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #e9ecef;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .container {
            text-align: center;
            padding: 20px;
            border: 1px solid #ddd;
            border-radius: 8px;
            background: #fff;
        }
        h1 {
            color: #5bc0de;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Welcome, '''+name+''' !</h1>
        <p>We're glad to have you here.</p>
    </div>
</body>
</html>

'''
    
    return render_template_string(template)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
