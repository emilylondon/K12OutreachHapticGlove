import pickle
from flask import Flask,request
import json

clf = pickle.load(open('model.pkl','rb'))


app = Flask(__name__)

@app.route("/classify")
def hello_world():
    sensor1 = float(request.args.get('s1'))
    sensor2 = float(request.args.get('s2'))
    sensor3 = float(request.args.get('s3'))
    sensor4 = float(request.args.get('s4'))
    sensor5 = float(request.args.get('s5'))
    sensor6 = float(request.args.get('s6'))

    object = int(clf.predict([[sensor1, sensor2, sensor3, sensor4, sensor5, sensor6]])[0])
    #print(denomination)
    return json.dumps({"sensor1":sensor1, "sensor2":sensor2 , "sensor3":sensor3, "sensor4":sensor4, "sensor5":sensor5, "sensor6": sensor6, "object":object})