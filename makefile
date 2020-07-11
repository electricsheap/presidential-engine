
CC = clang
CXX = c
OBJS = main.o pres_renderer.o pres_events.o

# MAC/LIN
LIBS = -L../Frameworks -lSDL2  # -lSDL2_image -lpng -lFLAC

# WINDOWS
# LIBS = ../Frameworks/SDL2.dll

FLAGS = -g -I./include -Wall -Wno-unknown-pragmas
PROG_NAME = pres



all: $(OBJS)
	cd bin && \
	$(CC) $(OBJS) $(LIBS) -o $(PROG_NAME) 

$(OBJS): %.o: %.$(CXX)
	$(CC) -c $< -o bin/$@ $(FLAGS)



run: all
	clear
	bin/$(PROG_NAME)

clean:
	rm -f bin/*.o *.o