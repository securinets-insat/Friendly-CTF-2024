from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/S/')
def s():
    return "You have found the 'S' directory!"

@app.route('/S/e/')
def se():
    return "You have found the 'E' directory!"

@app.route('/S/e/c/')
def sec():
    return "You have found the 'C' directory!"

@app.route('/S/e/c/u/')
def secu():
    return "You have found the 'U' directory!"

@app.route('/S/e/c/u/r/')
def secur():
    return "You have found the 'R' directory!"

@app.route('/S/e/c/u/r/i/')
def securi():
    return "You have found the 'I' directory!"

@app.route('/S/e/c/u/r/i/n/')
def securin():
    return "You have found the 'N' directory!"

@app.route('/S/e/c/u/r/i/n/e/')
def securine():
    return "You have found the 'E' directory!"

@app.route('/S/e/c/u/r/i/n/e/t/')
def securinet():
    return "You have found the 'T' directory!"

@app.route('/S/e/c/u/r/i/n/e/t/s/')
def securinets():
    return "Congratulations! You have found the 'Securinets' lare <br> here is your flag : <br>Securinets{Uncover_the_Hidden_Directories}!"

if __name__ == '__main__':
    app.run(debug=True)
