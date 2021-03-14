derlecalistir:program calistir

program:pch.o kova.o top.o kovaKontrol.o test.o
	g++ ./lib/top.o ./lib/kova.o ./lib/kovaKontrol.o ./lib/test.o -o ./bin/program

pch.o:
	g++ -I "./include" -c ./src/pch.cpp -o ./lib/pch.o

kova.o:
	g++ -I "./include" -c ./src/kova.cpp -o ./lib/kova.o

top.o:
	g++ -I "./include" -c ./src/top.cpp -o ./lib/top.o	

kovaKontrol.o:
	g++ -I "./include" -c ./src/kovaKontrol.cpp -o ./lib/kovaKontrol.o
	
test.o:
	g++ -I "./include" -c ./src/test.cpp -o ./lib/test.o

calistir:
	./bin/program.exe