PROG=	awk
SRCS=	main.c eval.c builtin.c msg.c iop.c io.c field.c getopt1.c \
	getopt.c array.c \
	node.c version.c re.c awk.c regex.c dfa.c
DPADD=	${LIBM}
LDADD=	-lm
CFLAGS+=-I${.CURDIR} -DGAWK
CLEANFILES+=awk.c y.tab.h

MAN1=	awk.1

.include <bsd.prog.mk>
#.include "../../usr.bin/Makefile.inc"
