OBJECTS = proje.c

default: proje

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f proje

run: program
	./proje
