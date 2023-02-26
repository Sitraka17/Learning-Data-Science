import datetime

 

with open("demofile2.txt", mode='a') as file:

    file.write('Printed string %s recorded at %s.\n' %

               (str, datetime.datetime.now()))
