from ws4py.client.threadedclient import WebSocketClient
import json
import math
import random
from datetime import datetime
 
 
class ClientB(WebSocketClient):
    def opened(self):
        self.send("{'op': 'auth', 'uid': 'ABC', 'name': 'XHH', 'color_a':100, 'color_r':120,  'color_g':80, 'color_b':210}")
 
    def closed(self, code, reason=None):
        print("Closed down", code, reason)
 
    def received_message(self, m):
        d = json.loads(m)
        carrier_id = d['player_data']['carrier']['uid']
        b_ids = []
        for i in d['player_data']['bomber']:
            b_ids.append(i['uid'])
        f_ids = []
        for i in d['player_data']['fighter']:
            f_ids.append(i['uid'])
        fighters = []
        for i in range(0,5):
            new_d = {
                "uid": f_ids[i],
                "move": True,
                "turn_direction": random.uniform(-math.pi()/24, math.pi()/24),
                "use_weapon": True,
                "weapon_shoot_direction": random.uniform(-math.pi(), math.pi()),
                "collect": False,
                "collect_entity_uid": 9
                }
            fighters.append(new_d)
        bombers = []
        for i in range(0,3):
            new_d = {
                "uid": b_ids[i],
                "move": True,
                "turn_direction": random.uniform(-math.pi()/24, math.pi()/24),
                "use_weapon": True,
                "weapon_shoot_direction": random.uniform(-math.pi(), math.pi())
                }
            bombers.append(new_d)
        carrier = {
            "uid": carrier_id,
            "move": True,
            "turn_direction": random.uniform(-math.pi()/24, math.pi()/24),
            "use_weapon": True,
            "weapon_shoot_direction": random.uniform(-math.pi(), math.pi()),
            "use_nuke": True,
            "nuke_shoot_direction": 3.14159
        }
        data_dict = {
            "allow_heal": True,
            "build": False,
            "carrier": carrier,
            "bomber": bombers,
            "fighter": fighters
        }
        total_dict = {
            'time': datetime.now().microsecond,
            'uid': 'ABC',
            'op': 'action',
            'player_data': data_dict
        }
        self.send(json.dumps(total_dict))


 
 
if __name__ == '__main__':
    try:
        ws = ClientB('ws://localhost:9001/websocket', protocols=['chat'])
        ws.connect()
        ws.run()
    except KeyboardInterrupt:
        ws.close()