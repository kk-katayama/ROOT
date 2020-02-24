#!/usr/bin/python
#!/apps/python/3.4.3/bin/python3


# Toshiyuki Gogami
# Dec 20, 2019

import sys
import time, os.path
from subprocess import call
#import concurrent.futures
#from logging import StreamHandler, Formatter, INFO, getLogger
#from concurrent.futures import ThreadPoolExecutor
#from concurrent.futures.process import ProcessPoolExecutor 
#import numpy as np

datafile="data.dat"

def main():
    inputfile = open(datafile,"r")
    lines = inputfile.readlines()
    for line in lines:
        data = line.split()
        com = "./mkroot " + data[0]
        call(com,shell=True)

stime = time.time()
main()
print("\n Jobs were done in %.0f sec \n" % float(time.time()-stime))

