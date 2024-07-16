from flask import Flask, render_template,send_from_directory,request,make_response
from flask_mysqldb import MySQL
import yaml

app = Flask(__name__)

db = yaml.safe_load(open("db.yaml"))
app.config["MYSQL_HOST"] = db["mysql_host"]
app.config["MYSQL_USER"] = db["mysql_user"]

mysql = MySQL(app)
def init_db():
        setup = mysql.connection.cursor()
        setup.execute("CREATE DATABASE IF NOT EXISTS willowswebsite")
        setup.execute("USE willowswebsite")
        setup.execute("create table if not exists users (username varchar(255), password varchar(255))")
        setup.execute("insert into users (username, password) values ('WIT{w3lc0m3_w1llow}', 'super_duper_secret_unguessable_password')")
        mysql.connection.commit()

@app.route("/", methods = ["GET"])
def index():
    return render_template("index.html", error = "")

@app.route("/login", methods = ["POST"])
def login():
    username = request.form["username"]
    password = request.form["password"]

    query = f"SELECT username FROM users WHERE username = '{username}' AND password = '{password}'"
    cur = mysql.connection.cursor()
    cur.execute("USE willowswebsite")
    cur.execute(query)

    result = cur.fetchone()
    if (result):
        return render_template("success.html", user=result[0]);
    return render_template("index.html", error = "Incorrect username or password!")

if __name__ == "__main__":
        with app.app_context():
                init_db()
                app.run(debug=False,host='127.0.0.1',port="5001")