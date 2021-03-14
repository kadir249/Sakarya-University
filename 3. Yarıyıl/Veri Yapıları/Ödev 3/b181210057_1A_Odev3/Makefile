derlecalistir:program calistir

program:Dugum.o IkiliAramaAgaci.o Odev3.o
	g++ ./lib/Dugum.o ./lib/IkiliAramaAgaci.o ./lib/Odev3.o		-o	./bin/program

Dugum.o:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	
IkiliAramaAgaci.o:
	g++ -I "./include" -c ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	
Odev3.o:
	g++ -I "./include" -c ./src/Odev3.cpp -o ./lib/Odev3.o

calistir:
	./bin/program.exe