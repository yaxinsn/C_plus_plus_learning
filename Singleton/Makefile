


TARGET += test



SRC=main.cpp Singleton.cpp

%.o:%.cpp
	g++ -g  -c -o $@ $^

test:$(SRC:.cpp=.o)
	g++ -o $@ $^

clean:
	rm $(TARGET) *.o -f;
