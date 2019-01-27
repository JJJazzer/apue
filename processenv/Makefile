
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS  = atexit echoarg getenv jmpbuf prlimit
all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

