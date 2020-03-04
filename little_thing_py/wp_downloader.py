import requests
from bs4 import BeautifulSoup
# import re
import os
import time

def getHTMLText(url) :
    try :
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except :
        return "Request Error!"

def debug_data(html) :
    soup = BeautifulSoup(html, "html.parser")
    #for link in soup.find_all("img"):
    print(soup.find_all())

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
        time.sleep(0.5)
        name = link.get("data-progressive").split('/')[-1]
        name = name[:-10]
        fileName = path + name
        if not os.path.exists(fileName) :
            imgUrl = link.get("data-progressive")
            r = requests.get(imgUrl)
            with open(fileName, "wb") as f :
                f.write(r.content)
                f.close()
                print(fileName + " has been saved.")
        else :
            print(fileName + " has existed.")
    print("Today's picture has downloaded successfully.")

def init_func():
    print("Thanks for using this py program created by Mr.Yang to download wallpapers")
    url = "https://github.com/Ghjk94522/My-Windows-hub/blob/9b3abd9f317179e144c59d65bc429c8bab0b7cb2/little_thing_py/wp_downloader.py#L15"
    print("For more information, you can visit my GitHub : " + url)
    print("All the wallpaper pics are from https://bing.ioliu.cn/")
    print("And you can use this program once a week to get beautiful wallpapers.")

if __name__ == "__main__" :
    init_func()
    url = "https://bing.ioliu.cn/"
    html = getHTMLText(url)
    produce_HTML(html)
    #debug_data(html)
    os.system('pause')