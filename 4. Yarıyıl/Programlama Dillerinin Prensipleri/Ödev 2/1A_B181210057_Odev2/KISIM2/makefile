hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Rastgele.o -c ./src/Rastgele.c
	gcc -I ./include/ -o ./lib/IMEINo.o -c ./src/IMEINo.c
	gcc -I ./include/ -o ./lib/KimlikNo.o -c ./src/KimlikNo.c
	gcc -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c
	gcc -I ./include/ -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
	gcc -I ./include/ -o ./bin/RastgeleKisiDeneme ./lib/Rastgele.o ./lib/IMEINo.o ./lib/KimlikNo.o ./lib/Telefon.o ./lib/DosyaOkuma.o ./lib/Kisi.o ./lib/RastgeleKisi.o ./src/RastgeleKisiDeneme.c

calistir:
	./bin/RastgeleKisiDeneme