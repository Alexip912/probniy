.PHONY: all clean
FLAGS = -Wall -Werror
SRC = build/src
TST = build/test
MAIN = bin/main
TEST = bin/testing

all: $(MAIN) $(TEST)

$(MAIN): $(SRC)/main.o $(SRC)/crossing.o $(SRC)/fname.o $(SRC)/area.o $(SRC)/perimeter.o $(SRC)/check.o
	gcc $(FLAGS) $(SRC)/main.o $(SRC)/crossing.o $(SRC)/fname.o $(SRC)/area.o $(SRC)/perimeter.o $(SRC)/check.o -o $(MAIN) -lm

$(SRC)/main.o: src/main.c
	gcc $(FLAGS) -c src/main.c -o $(SRC)/main.o

$(SRC)/crossing.o: src/crossing.c
	gcc $(FLAGS) -c src/crossing.c -o $(SRC)/crossing.o

$(SRC)/fname.o: src/fname.c
	gcc $(FLAGS) -c src/fname.c -o $(SRC)/fname.o

$(SRC)/area.o: src/area.c
	gcc $(FLAGS) -c src/area.c -o $(SRC)/area.o

$(SRC)/perimeter.o: src/perimeter.c
	gcc $(FLAGS) -c src/perimeter.c -o $(SRC)/perimeter.o

$(SRC)/check.o: src/check.c
	gcc $(FLAGS) -c src/check.c -o $(SRC)/check.o

$(TST)/main.o: test/main.c
	gcc $(FLAGS) -I thirdparty -c test/main.c -o $(TST)/main.o

$(TST)/tests.o: test/tests.c
	gcc $(FLAGS) -I thirdparty -I src -c test/tests.c -o $(TST)/tests.o

$(TEST): $(TST)/main.o $(TST)/tests.o
	gcc $(FLAGS) $(SRC)/crossing.o $(SRC)/fname.o $(SRC)/area.o $(SRC)/perimeter.o $(TST)/tests.o $(SRC)/check.o $(TST)/main.o -o $(TEST) -lm
   

clean:
	rm -rf $(SRC)/*.o
	rm -rf $(TST)/*.o
	rm -rf bin/*
