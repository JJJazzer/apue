
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS  = filetype faccess umask chmod

all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

