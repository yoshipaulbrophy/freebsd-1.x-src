DEFS_LOCAL=-DREFCLOCK -DPARSE
NTPDEFS=   -DSYS_FREEBSD -DSYS_386BSD 
AUTHDEFS=  -DMD5
CLOCKDEFS= -DLOCAL_CLOCK -DPST -DWWVB -DAS2201 -DGOES -DGPSTM -DOMEGA \
	-DLEITCH -DTRAK
CFLAGS+= ${NTPDEFS} ${DEFS_LOCAL} ${AUTHDEFS} ${CLOCKDEFS} ${COPTS}
BINDIR?= /usr/sbin
