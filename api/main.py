from typing import Union

from fastapi import FastAPI

app = FastAPI()


@app.get("/")
def read_root():
    return {"status": True}


@app.get("/MuscleGroups")
def read_root():
    return {
        "Chest": 0,
        "Traps": 1,
        "FrontDelts": 2,
        "LateralDelts": 3,
        "RearDelts": 4,
        "Back": 5,
        "Lats": 6,
        "LowerBack": 7,
        "Biceps": 8,
        "Triceps": 9,
        "Abs": 10,
        "Rest": 99,
    }


@app.get("/musclegroups/{muscle_group_id}/exercises")
def read_item(muscle_group_id: int):
    result = {}
    if muscle_group_id == 0:
        result = {
            "exercises": [
                {"name": "Dips", "muscle_groups": [0, 2, 9]},
                {"name": "Bench Press", "muscle_groups": [0, 2, 9]},
            ]
            }
    elif muscle_group_id == 1:
        result = {"b": "b"}
    return result
