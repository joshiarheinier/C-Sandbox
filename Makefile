CC=gcc
 
EXECS= \
	data-structure \


all:	$(EXECS)


data-structure: data-structure.c
	gcc data-structure.c -o data-structure

clean:
	rm -f $(EXECS)

