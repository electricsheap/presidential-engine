
CC = clang
CXX = c
OBJS = main.o pres_renderer.o pres_events.o
LIBS = -L../Frameworks -lSDL2 -lSDL2_image-2.0.0
FLAGS = -g -I./include -Wall -Wno-unknown-pragmas
PROG_NAME = pres



all: $(OBJS)
	cd bin && \
	$(CC) $(OBJS) -o $(PROG_NAME) $(LIBS)

$(OBJS): %.o: %.$(CXX)
	$(CC) -c $< -o bin/$@ $(FLAGS)



run: all
	bin/$(PROG_NAME)

clean:
	rm -f bin/*.o *.o