from flask import  Flask,render_template,url_for

app = Flask(__name__)

@app.route("/")
def index():
    return render_template('index.html')

@app.route("/name")
def index_in_name():
    return "hello"

@app.route("/name/<name>")
def index_in_ashu(name):
    return f"hello {name}"


if __name__ == "__main__":
    app.run(debug=True)