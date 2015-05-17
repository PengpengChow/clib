CC=gcc -g
MAIN=main.o
EXEC=main

NAME=garlic
GARLIC_OBJ=stack.o list.o array.o xtring.o
LIBNAME=${HOME}/lib/lib${NAME}.a

GARLICLIB=${LIBNAME}
LINKRULE=${CC} -o ${EXEC} ${MAIN} ${GARLICLIB}

all:${EXEC} ${GARLICLIB}

clean:
	@- rm -rf *.o ${GARLICLIB} ${EXEC} ${MAIN}

${LIBNAME}:${GARLIC_OBJ}
	${AR} rv $@ ${GARLIC_OBJ}

${EXEC}:${GARLICLIB} ${MAIN}
	${LINKRULE}
