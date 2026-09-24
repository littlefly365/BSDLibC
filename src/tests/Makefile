PROGS=env id

CPPFLAGS=-nostdinc -I../include -fno-stack-protector
LDFLAGS=-nostdlib -L.. -lc -static
CSU=../csu/*.o

all: ${PROGS}

.for i in ${PROGS}
${i}: ${i}.c
	${CC} -o ${i} ${i}.c ${CSU} ${CPPFLAGS} ${LDFLAGS}
.endfor
clean:
	rm -rf ${PROGS} *.o 
