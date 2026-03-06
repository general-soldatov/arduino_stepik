import json
from pydantic import BaseModel, Field # pyright: ignore[reportMissingImports]
from typing import List, Dict

class Parts(BaseModel):
    type_device: str = Field(alias='type')
    id: str
    top: float
    left: float
    attrs: Dict[str, str]

class Diagram(BaseModel):
    version: int
    author: str
    editor: str
    parts: List[Parts]
    connections: List[list]
    dependencies: dict

TEXT = '''
{
  "version": 1,
  "author": "Юрий Солдатов",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 87, "left": -29.4, "attrs": {} },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": -70.8,
      "left": 176.6,
      "attrs": { "color": "orange" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r1",
      "top": 4.8,
      "left": 172.25,
      "rotate": 90,
      "attrs": { "value": "1000" }
    },
    {
      "type": "wokwi-led",
      "id": "led2",
      "top": -70.8,
      "left": 138.2,
      "attrs": { "color": "orange" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r2",
      "top": 14.4,
      "left": 133.85,
      "rotate": 90,
      "attrs": { "value": "1000" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn1",
      "top": 6.2,
      "left": -153.6,
      "attrs": { "color": "green", "xray": "1", "key": "a" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn2",
      "top": 83,
      "left": -153.6,
      "attrs": { "color": "yellow", "xray": "1", "key": "b", "bounce": "1" }
    },
    { "type": "wokwi-relay-module", "id": "relay1", "top": -134.2, "left": -48, "attrs": {} },
    {
      "type": "wokwi-pushbutton",
      "id": "btn3",
      "top": -51.4,
      "left": -153.6,
      "attrs": { "color": "white", "xray": "1" }
    }
  ],
  "connections": [
    [ "led1:A", "r1:1", "green", [ "v19.2", "h19.2" ] ],
    [ "r1:2", "uno:3", "green", [ "v27.6", "h-4" ] ],
    [ "r2:2", "uno:4", "green", [ "h0", "v18", "h28.8" ] ],
    [ "r2:1", "led2:A", "green", [ "h0" ] ],
    [ "uno:GND.1", "led2:C", "black", [ "v0" ] ],
    [ "btn2:1.r", "uno:7", "yellow", [ "v0", "h29", "v-19.2", "h220.8" ] ],
    [ "uno:GND.1", "led1:C", "black", [ "v-115.2", "h105.9" ] ],
    [ "btn2:2.l", "btn1:2.l", "red", [ "h-28.8", "v-76.6" ] ],
    [ "uno:GND.3", "btn2:2.l", "black", [ "v57.5", "h-332", "v-220.8" ] ],
    [ "btn1:1.r", "uno:6", "green", [ "v0", "h144.2", "v57.6", "h115.2" ] ],
    [ "uno:GND.1", "relay1:GND", "black", [ "v-105.6", "h-239.7", "v-28.8" ] ],
    [ "uno:5V", "relay1:VCC", "red", [ "v86.3", "h-351.4", "v-508.8" ] ],
    [ "btn1:2.l", "btn3:2.l", "green", [ "h-28.8", "v-67" ] ],
    [ "uno:9", "relay1:IN", "green", [ "v-163.2", "h-200.8", "v-28.8" ] ],
    [ "uno:10", "btn3:1.r", "green", [ "v0" ] ]
  ],
  "dependencies": {}
}
'''

class Arduino:
    def __init__(self):
        self.GND: Dict[int, str] = {}
        self.PORT: Dict[int, str] = {}
        self.VCC: List[str] = []

    def validate_parts(self, parts: Parts):
        for key, value in parts.model_dump().items():
            self.__dict__[key] = value

    def addGND(self, key: str, value: str, sep='.'):
        key = int(key.split(sep)[1])
        self.GND.setdefault(key,[])
        self.GND[key].append(value)

    def addPORT(self, key: str, value: str, sep=':'):
        key = int(key.split(sep)[1])
        self.PORT.setdefault(key,[])
        self.PORT[key].append(value)

class ArduinoUno(Arduino):
    pass

diagram = Diagram.model_validate_json(TEXT)

ar = Arduino()
ar.validate_parts(diagram.parts[0])
for connect in diagram.connections:
    if connect[0].startswith('uno:GND'):
        ar.addGND(connect[0], connect[1])
    elif connect[1].startswith('uno:GND'):
        ar.addGND(connect[1], connect[0])
    elif connect[0] == "uno:5V":
        ar.VCC.append(connect[1])
    elif connect[1] == "uno:5V":
        ar.VCC.append(connect[0])
    elif connect[0].startswith('uno:'):
        ar.addPORT(connect[0], connect[1])
    elif connect[1].startswith('uno:'):
        ar.addPORT(connect[1], connect[0])

print(json.dumps(ar.__dict__, indent=4))