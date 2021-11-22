.PHONY:main main.o cp.o cmp.o wc.o cat.o man.o sh.o rm.o ls.o mk.o head.o
main:cp.o cmp.o wc.o cat.o man.o main.o sh.o rm.o ls.o mk.o head.o command.h sh.h
	g++ cp.o cmp.o wc.o cat.o man.o main.o sh.o rm.o ls.o mk.o head.o command.h sh.h -o main
main.o:main.cpp
	g++ -c main.cpp -o main.o
cp.o:cp.cpp
	g++ -c cp.cpp -o cp.o
cmp.o:cmp.cpp
	g++ -c cmp.cpp -o cmp.o
wc.o:wc.cpp
	g++ -c wc.cpp -o wc.o
cat.o:cat.cpp
	g++ -c cat.cpp -o cat.o
man.o:man.cpp
	g++ -c man.cpp -o man.o
sh.o:sh.cpp
	g++ -c sh.cpp -o sh.o
rm.o:rm.cpp
	g++ -c rm.cpp -o rm.o
ls.o:ls.cpp
	g++ -c ls.cpp -o ls.o
mk.o:mk.cpp
	g++ -c mk.cpp -o mk.o
head.o:head.cpp
	g++ -c head.cpp -o head.o
clean:
	rm *.o
	rm main

