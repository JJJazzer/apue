
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS  = getpwnam gethostinfo gettime strftime groups shadow

all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

