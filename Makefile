FLAGS = -Wall

MAIN = main
LIB = lib
NAME = generator

default: obj
	$(CC) $(FLAGS) $(MAIN).o $(LIB).o -o $(NAME)

obj:
	$(CC) $(STD) *.c -c

$(MAIN).o: $(MAIN).c $(LIB).h

$(LIB).o: $(LIB).c $(LIB).h

clean:
	rm -f *~ *.o .*.swp

veryclean: clean
	rm -f $(NAME) *.in *.out
