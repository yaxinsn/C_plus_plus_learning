


TARGET += test



SRC=main.cpp Student.cpp

%.o:%.cpp
	g++ -g  -c -o $@ $^

test:$(SRC:.cpp=.o)
	g++ -o $@ $^

clean:
	rm $(TARGET) *.o -f;
