WWW = -Wall -Wextra -Werror -std=c11
OS=$(shell uname -s)
LINUX=-lsubunit -lrt
LIBS=-lcheck -lm -lpthread

all: install gcov_report

install: test uninstall
	mkdir build
	cp -rf frontend/* build
	cd build && qmake frontend.pro
	make -C build
	cd build && make clean
ifeq ($(OS), Linux)
	./build/frontend
else
	open ./build/frontend.app/Contents/MacOS/frontend
endif

uninstall:
	rm -rf build*
	make clean

test:
ifeq ($(OS), Darwin)
	gcc -fprofile-arcs -ftest-coverage -pedantic -g backend/s21_calc.c backend/s21_calctest.c -o unit_test $(LIBS) 
else
	gcc -fprofile-arcs -ftest-coverage -pedantic -g backend/s21_calc.c backend/s21_calctest.c -o unit_test $(LIBS) $(LINUX)
endif
	./unit_test

gcov_report:
ifeq ($(OS), Darwin)
	gcc $(WWW) -fprofile-arcs -ftest-coverage -pedantic -g backend/s21_calc.c backend/s21_calctest.c -o unit_test $(LIBS) 
else
	gcc  $(WWW) -fprofile-arcs -ftest-coverage -pedantic  -g backend/s21_calc.c backend/s21_calctest.c -o unit_test $(LIBS) $(LINUX)
endif
	./unit_test
	lcov -t "test" -o test.info -c -d .  
	genhtml test.info --output-directory report
	open ./report/index.html

clang:
	clang-format -i *.c

clean_obj:
	rm -rf *.o

clean_lib:
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.dSYM

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test

valgrind:
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./unit_test

rebuild: clean all
