

src=$(shell ls *.cpp)

TARGET += hello

$(TARGET) :$(src)
	g++ -o $@ $(src)

clean:
	rm $(TARGET) -f;
