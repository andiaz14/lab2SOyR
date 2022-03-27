prefix=/usr/local
CC = g++

# Normal
CFLAGS = -O3 -Wall
LDFLAGS = 

# Profiling, debug
#CFLAGS = -g -pg -Wall -O3 

SRC = forkYTdl.cpp
OBJ = forkYTdl.o
APP = lab2

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(APP) $(OBJ) $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ) $(APP)

install: $(APP)
	install -m 0755 $(APP) $(prefix)/bin

uninstall: $(APP)
	$(RM) $(prefix)/bin/$(APP)
