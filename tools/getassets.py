import os
import requests
import json
import zipfile

index_url = "https://launchermeta.mojang.com/v1/packages/72f061c25c8a96c4b8dd9b5609a6da6a8fb7fd73/1.19.json"
assets_url = "https://mcassets.matdoes.dev/versions/1.19/packages/"
jar_url = "https://piston-data.mojang.com/v1/objects/c0898ec7c6a5a2eaa317770203a1554260699994/client.jar" 
try:
   os.mkdir("./res/mc")
except:
   pass

response = requests.get(index_url)
open("./res/mc/1.19.json", "wb+").write(response.content)

response = requests.get(jar_url)
open("./res/mc/1.19.jar", "wb+").write(response.content)

with zipfile.ZipFile("./res/mc/1.19.jar", 'r') as zip_ref:
    zip_ref.extractall("./res/mc/")
    
os.system("rm -rf ./res/mc/com"      )
os.system("rm -rf ./res/mc/net"      )
os.system("rm -rf ./res/mc/META-INF" )
os.system("rm -rf ./res/mc/*.class" ) #hacky solution

os

with open('./res/mc/1.19.json', 'r') as asset_index_file:
    asset_data = json.load(asset_index_file)
    for data in asset_data["objects"]:
        if os.path.exists("./res/mc/assets/" + data):
            continue
        response = requests.get(assets_url + data)
        path = ""
        
        for thingy in data.split('/'):
            if thingy == data.split('/')[-1]:
                break
            path = path + "/" + thingy
            
        try:
            os.makedirs("res/mc/assets/" + path) 
        except:
            pass
        
        print("done with " + data + "\n")
        open("./res/mc/assets/" + data, "wb+").write(response.content)
