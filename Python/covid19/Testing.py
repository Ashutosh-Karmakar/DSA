import schedule as sc
import time
import smtplib as sm
def sendErrorMail():
    port = 587
    server = sm.SMTP('smtp.gmail.com',port)
    server.ehlo()
    server.starttls()
    server.ehlo()
    
    server.login('tukusahoo1999@gmail.com','ashu@1999')
    
    sub = 'there is a error in requesting data from API'
    body = "The status code is" + status
        

    msg = f"Subject:{sub}\n\n{body}"
    
    server.sendmail(
        'tukusahoo1999@gmail.com',
        'ashutoshkarmakar72@gmail.com',
        msg
    )

def job():
    print("jeool")

sc.every(10).seconds.do(sendErrorMail)

while True:
    sc.run_pending()
    time.sleep(1)