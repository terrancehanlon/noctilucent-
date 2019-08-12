from flask import Flask
from flask import request
from flaskext.mysql import MySQL
from flask import g
# from flask.config import Config
import config
import os
from dotenv import load_dotenv

app = Flask(__name__)
mysql = MySQL()


app.config['MYSQL_DATABASE_HOST'] = config.host
app.config['MYSQL_DATABASE_USER'] = config.user
app.config['MYSQL_DATABASE_PASSWORD'] = config.password
app.config['MYSQL_DATABASE_DB'] = config.db

mysql.init_app(app)

@app.route("/")
def hello():
	print(type(os.getenv('host')))
	print(os.getenv('password'))
	return "Hello world"

@app.route("/add", methods=['GET', 'POST'])
def add():
	if request.method == 'POST':
		print(type(os.getenv('host')))
		db = mysql.connect()
		cur = db.cursor()
		print(request.get_json())
		name = request.get_json()['name']
		cur.execute("INSERT INTO user(name) VALUES (%s)", name)
		db.commit()
		cur.close()
		return "done"

@app.route("/login", methods=['POST'])
def login():
	print("HELLO")
	print(request.get_json())
	name = request.get_json()['name']
	db = mysql.connect()
	cur = db.cursor()
	val = cur.execute("SELECT * FROM user WHERE name = %s", name)
	db.commit()
	cur.close()
	return val


if __name__ == "__main__":
	app.run()
