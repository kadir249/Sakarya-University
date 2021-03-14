derlecalistir:program calistir

program:Dugum.o CiftYonluBagliListe.o VeriYapilariOdev2.o
	g++ ./lib/Dugum.o ./lib/CiftYonluBagliListe.o ./lib/VeriYapilariOdev2.o		-o	./bin/program

Dugum.o:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	
CiftYonluBagliListe.o:
	g++ -I "./include" -c ./src/CiftYonluBagliListe.cpp -o ./lib/CiftYonluBagliListe.o
	
VeriYapilariOdev2.o:
	g++ -I "./include" -c ./src/VeriYapilariOdev2.cpp -o ./lib/VeriYapilariOdev2.o

calistir:
	./bin/program.exe