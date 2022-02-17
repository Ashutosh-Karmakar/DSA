import pyttsx3
engine = pyttsx3.init()
engine.setProperty('rate', 150)     # setting up new voice rate
voices = engine.getProperty('voices')       #getting details of current voice

engine.setProperty('voice', voices[1].id)   #changing index, changes voices. 1 for female

engine.say("Ping, a program authored in 1983 by Mike Muuss, operates analogously to a sonar using echolocation. The “ping”—a data packet—is sent out to an IP address. Transmitted over the network’s switch and router, the data packet arrives at the device with the specified address. Upon receipt of the packet, the pinged device returns a response—called the pong.")
engine.runAndWait()