import requests
from bs4 import BeautifulSoup
# import re
import os

def getHTMLText(url) :
    try :
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except :
        return "Request Error!"

def produce_HTML(html) :
    soup = BeautifulSoup(html, "html.parser")
    flag = input("Input 'y' in the followding line to change the hubfolder location, else save in the D:/bing_wallpaper . If the folder doesn't exist, it will be created automatically\n")
    if(flag == "y") :
        print("Format : 'D:/yourfoldername/' (In the win10 system)\nPay attention to the last '/' or you may save the pictures in the wrong directory with a worng name.")
        print("For example: E:/myfirstfolder/mypichub/")
        path = input("Location: ")
    else :
        path = 'D:/bing_wallpaper/'
    if not os.path.exists(path) :
        os.mkdir(path)
    soup = BeautifulSoup(html, "html.parser")
    for link in soup.find_all("img") :
        os.sleep(1)
        name = link.get("data-progressive").split('/')[-1]
        fileName = path + name
        if not os.path.exists(fileName) :
            imgUrl = link.get("data-progressive")
            r = requests.get(imgUrl)
            with open(fileName, "wb") as f :
                f.write(r.content)
                f.close()
                print(fileName + " has been saved.")
        else :
            print(fileName + "has existed.")
    print("Today's picture has downloaded successfully.")

def init_func():
    print("Thanks for using the py program created by Mr.Yang")
    url = ""
    print("For more information, you can visit " + url)
    print("All the wallpaper pics are from https://bing.ioliu.cn/")
    print("And you can use this program once a week to get beautiful wallpapers.")

if __name__ == "__main__" :
    init_func()
    url = "https://bing.ioliu.cn/"
    html = getHTMLText(url)
    produce_HTML(html)


