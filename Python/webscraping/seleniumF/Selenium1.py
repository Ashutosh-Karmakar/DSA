from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
import time
driver = webdriver.Chrome('chromedriver')
driver.get("https://news.google.com/topstories?gl=IN&hl=en-IN&ceid=IN:en")



print(driver)
# try:
#     main = WebDriverWait(driver,10).until(
#     EC.presence_of_element_located((By.CLASS,"DY5T1d RZIKme"))
#     )
#
# except:
#     driver.quit()
#
# print(main.text)
time.sleep(5)


driver.quit()
