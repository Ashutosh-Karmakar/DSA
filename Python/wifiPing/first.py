import sys
import subprocess 
import os
from decouple import config

IP_NETWORK = '192.168.0.1'


while True:
    # proc = subprocess.Popen(["arp -a"],stdout=subprocess.PIPE)
    l = os. system('arp -a')
    print(l)
#     line = proc.stdout.readline()
#     if not line:
#         break
#   #the real code does filtering here
#     connected_ip = line.decode('utf-8').split()
#     print(connected_ip)