import os
import requests
import json

index_url = "https://launchermeta.mojang.com/v1/packages/72f061c25c8a96c4b8dd9b5609a6da6a8fb7fd73/1.19.json"
assets_url = "https://mcassets.matdoes.dev/versions/1.19/packages/"
os.mkdir("./res/mc")
response = requests.get(index_url)
open("./res/mc/1.19.json", "wb+").write(response.content)

with open('./res/mc/1.19.json', 'r') as asset_index_file:
    asset_data = json.load(asset_index_file)
    for data in asset_data["objects"]:
        response = requests.get(assets_url + data)
        path = ""
        
        for thingy in data.split('/'):
            if thingy == data.split('/')[-1]:
                break
            path = path + "/" + thingy
            
        try:
            os.makedirs("res/mc" + path) #error is here
        except:
            pass
        
        print("done with " + data + "\n")
        open("./res/mc/" + data, "wb+").write(response.content)