#Makefile


#ROOTLIBS = -L/u/apps/root/6.10.02/root/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
#ROOTLIBS    = `root-config --libs`
ROOTLIBS    = -L/usr/lib/i386-linux-gnu -lCore -lCint -lRIO -lNet -lHist -lGraf -lGpad -lTree -lRint -lMatrix -lMathCore -lThread -pthread -lm -ldl -rdynamic
ROOTINCLUDE = `root-config --cflags`
#GLIBS = $(ROOTLIBS) -lMinuit
GLIBS = $(ROOTLIBS)
CC = g++
#CC = icpc
#CCFLAGS = -pthread -std=c++11 -m64 -I/u/apps/root/6.10.02/root/include
CCFLAGS = $(ROOTINCLUDE)
#LD = g++
#LD = /home/gogami/gcc/gcc-6.3.0-install/bin/g++
LDFLAGS = -g

TARGET1 = mkroot
OBJS1 = mkroot.o
TARGET2 = plot_time
OBJS2 = plot_time.o
TARGET3 = conv_t2pos
OBJS3 = conv_t2pos.o	
TARGET4 = tracking
OBJS4 = tracking.o


all: ${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4}
#all: ${TARGET2}


${TARGET1}: ${OBJS1}
	${CC} ${CCFLAGS} -o $@ ${OBJS1} ${GLIBS}
${OBJS1}: mkroot.cc
	${CC} ${CCFLAGS} -c  mkroot.cc ${GLIBS}

${TARGET2}: ${OBJS2}
	${CC} ${CCFLAGS} -o $@ ${OBJS2} ${GLIBS}
${OBJS2}: plot_time.cc
	${CC} ${CCFLAGS} -c  plot_time.cc ${GLIBS}

${TARGET3}: ${OBJS3}
	${CC} ${CCFLAGS} -o $@ ${OBJS3} ${GLIBS}
${OBJS3}: conv_t2pos.cc
	${CC} ${CCFLAGS} -c  conv_t2pos.cc ${GLIBS}

${TARGET4}: ${OBJS4}
	${CC} ${CCFLAGS} -o $@ ${OBJS4} ${GLIBS}
${OBJS4}: tracking.cc
	${CC} ${CCFLAGS} -c  tracking.cc ${GLIBS}



#.cc.o:
#	${CC} ${CCFLAGS} -c $<

clean:
	rm -rf *.o *~ core ${TARGET1} ${TARGET2} ${TARGET3}

