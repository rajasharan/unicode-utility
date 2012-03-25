utf: test/test_unicode.o strlen_unicode.o ischar_unicode.o
	gcc -o utf test/test_unicode.o strlen_unicode.o ischar_unicode.o

test_unicode.o: test/test_unicode.c unicode_util.h
	gcc -c test/test_unicode.c

strlen_unicode.o: strlen_unicode.c unicode_util.h
	gcc -c strlen_unicode.c

ischar_unicode.o: ischar_unicode.c unicode_util.h
	gcc -c ischar_unicode.c

#------------------------------------------------------------------------------#

test: char_test strlen_test
	./char_test && ./strlen_test

char_test: test_ischar.o ischar_unicode.o
	gcc -o char_test test_ischar.o ischar_unicode.o

strlen_test: test_strlen.o strlen_unicode.o ischar_unicode.o
	gcc -o strlen_test test_strlen.o strlen_unicode.o ischar_unicode.o

test_ischar.o: test/test_ischar.c unicode_util.h
	gcc -c test/test_ischar.c

test_strlen.o: test/test_strlen.c unicode_util.h
	gcc -c test/test_strlen.c

#------------------------------------------------------------------------------#

clean: 
	rm -rf *.o char_test strlen_test utf
