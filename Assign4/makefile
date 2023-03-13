CC = g++ -std=c++11 -g

EXE_FILE = run

all: $(EXE_FILE)     

$(EXE_FILE): prog.cpp mazeperson.o mazeperson.h mazelocation.o mazelocation.h game.o game.h maze.o maze.h instructor.o instructor.h intrepidstudent.o intrepidstudent.h ta.o ta.h openspace.o openspace.h wall.o wall.h
	$(CC) $(CFLAGS) prog.cpp mazeperson.o mazelocation.o game.o maze.o instructor.o intrepidstudent.o ta.o openspace.o wall.o -o $(EXE_FILE)

game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp

maze.o: maze.cpp maze.h
	$(CC) $(CFLAGS) -c maze.cpp

mazeperson.o: mazeperson.cpp mazeperson.h
	$(CC) $(CFLAGS) -c mazeperson.cpp

instructor.o: instructor.cpp instructor.h
	$(CC) $(CFLAGS) -c instructor.cpp

intrepidstudent.o: intrepidstudent.cpp intrepidstudent.h
	$(CC) $(CFLAGS) -c intrepidstudent.cpp

ta.o: ta.cpp ta.h
	$(CC) $(CFLAGS) -c ta.cpp

mazelocation.o: mazelocation.cpp mazelocation.h
	$(CC) $(CFLAGS) -c mazelocation.cpp

openspace.o: openspace.cpp openspace.h
	$(CC) $(CFLAGS) -c openspace.cpp

wall.o: wall.cpp wall.h
	$(CC) $(CFLAGS) -c wall.cpp

clean:
	rm -f *.o $(EXE_FILE)