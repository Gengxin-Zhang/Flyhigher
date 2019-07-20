from ws4py.client.threadedclient import WebSocketClient
import json
 
 
class DummyClient(WebSocketClient):
    def opened(self):
        self.send("www.baidu.com")
 
    def closed(self, code, reason=None):
        print("Closed down", code, reason)
 
    def received_message(self, m):
        print("recv:",m)
 
 
if __name__ == '__main__':
    try:
        ws = DummyClient('ws://localhost:9001/websocket', protocols=['chat'])
        ws.connect()
        nd = {
            'appid': 'A',
            'op': 'auth',
            'name': 'XHH',
            'color': '#00FF00'
        }
        ws.send(json.dumps(nd))
        ws.run_forever()
    except KeyboardInterrupt:
        ws.close()