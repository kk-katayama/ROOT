#!/usr/bin/python
#!/apps/python/3.4.3/bin/python3


# Toshiyuki Gogami
# Dec 20, 2019

import sys
import time, os.path
from subprocess import call

def main():
    inputfilename= "./root/" + sys.argv[1] + ".root"
    delta = sys.argv[2]
    com = "./plot_time " + sys.argv[1] + " " + delta
    
    print('  Input file        : '+ inputfilename)
    print('  Time offset (ns)  : '+ delta)
    print('')
    print('  --> '+com)
    
    call(com,shell=True)

stime = time.time()
main()
print("\n Jobs were done in %.0f sec \n" % float(time.time()-stime))

