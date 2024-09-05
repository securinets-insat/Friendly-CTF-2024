from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST', 'PUT', 'DELETE'])
def methods():
    if request.method == 'GET':
        return render_template('get_page.html')
    elif request.method == 'POST':
        return render_template('post_page.html')
    elif request.method == 'PUT':
        return render_template('put_page.html')
    elif request.method == 'DELETE':
        return render_template('delete_page.html')
    elif request.method == 'HEAD':
        return render_template('head_page.html')


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
