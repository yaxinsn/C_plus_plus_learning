

all:main


obj=line.o main.o

main: $(obj)
	g++ -o main $(obj)


line.o:line.cpp
	g++ -c line.cpp


main.o:main.c
	g++ -c main.c

clean:
	rm main *.o -rf

