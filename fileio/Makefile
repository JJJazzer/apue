
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS  = lseek hole copy pread dup fcntl

all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

