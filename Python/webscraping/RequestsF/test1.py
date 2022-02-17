import requests
from bs4 import BeautifulSoup as bs
import smtplib as sm
import pytz
from datetime import datetime
from pytz import timezone

checkBalance = 2400.00
date = 0
temp = 0

def checkPrice(url,header):
    global date
    global temp
    tz_NY = pytz.timezone('Asia/Calcutta') 
    datetime_IN = datetime.now(tz_NY)
    t = datetime_IN.strftime('%Y:%m:%d:%H:%M:%S %Z %z').split(':')
    curTD = int(t[2])
    print("NY time:", curTD)
    if(date != curTD):
        print("hi")
        date = curTD
        temp = 1
    r = requests.get(url,headers = header)
    print(r.status_code)
    soup = bs(r.content,'html.parser')
    # title = soup.find(id="productTitle").getText()
    price = soup.find(id="priceblock_dealprice").getText().split()
    print(title.strip())
    price = float(price[1].replace(',',''))
    print(price)
    
    if temp == 1:
        print("hello")
        temp = 0
        c = 1
        sendMail(price,c)
    if price < checkBalance:
        c = 0
        sendMail(price,c)

def sendMail(price,c):
    port = 587
    server = sm.SMTP('smtp.gmail.com',port)
    server.ehlo()
    server.starttls()
    server.ehlo()
    
    server.login('tukusahoo1999@gmail.com','ashu@1999')
    if(c==0):
        sub = 'Price Drop Hurry to: '+ str(price)
        body = 'Check the link : https://www.amazon.in/Redragon-KUMARA-Backlit-Mechanical-Keyboard/dp/B016MAK38U/ref=sr_1_3?crid=21YWEUGO058A4&dchild=1&keywords=redragon+keyboard&qid=1619591319&smid=A14CZOWI0VEHLG&sprefix=readra%2Caps%2C332&sr=8-3'
    elif(c==1):
        sub = 'Todays Price: '+ str(price)
        body = 'Check the link : https://www.amazon.in/Redragon-KUMARA-Backlit-Mechanical-Keyboard/dp/B016MAK38U/ref=sr_1_3?crid=21YWEUGO058A4&dchild=1&keywords=redragon+keyboard&qid=1619591319&smid=A14CZOWI0VEHLG&sprefix=readra%2Caps%2C332&sr=8-3'
        

    msg = f"Subject:{sub}\n\n{body}"
    
    server.sendmail(
        'tukusahoo1999@gmail.com',
        'ashutoshkarmakar72@gmail.com',
        msg
    )
  
 
  
    
url = 'https://www.amazon.in/Redragon-KUMARA-Backlit-Mechanical-Keyboard/dp/B016MAK38U/ref=sr_1_3?crid=21YWEUGO058A4&dchild=1&keywords=redragon+keyboard&qid=1619591319&smid=A14CZOWI0VEHLG&sprefix=readra%2Caps%2C332&sr=8-3'
header = {"User-Agent":'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36'}
while(True):
    checkPrice(url,header)

