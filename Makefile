CXX=g++
CXXFLAGS=-std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
OPTIMIZE=-O2
FILES=src/Database.hpp src/Database.cpp src/ShinyDatabase.hpp src/ShinyDatabase.cpp src/Counter.hpp src/Counter.cpp src/Window.hpp src/Window.cpp src/ShinyCounter.hpp src/ShinyCounter.cpp
MAINFILE=src/main.cpp
TARGET=shinycounter
LIBRARIES=-l sfml-graphics -l sfml-window -l sfml-system -l sqlite3

TESTFILES=tests/gtestmain.cpp tests/counterTests.cpp
TESTLIBRARIES=-l gtest -l pthread

all: $(TARGET)
$(TARGET): $(FILES) $(MAINFILE)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE) $(FILES) $(MAINFILE) -o $(TARGET) $(LIBRARIES)

debug: $(FILES) $(MAINFILE)
	$(CXX) $(CXXFLAGS) -g $(FILES) $(MAINFILE) -o $(TARGET)-debug $(LIBRARIES)

test: $(FILES) $(TESTFILES)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE) $(FILES) $(TESTFILES) -o $(TARGET)-tests $(LIBRARIES) $(TESTLIBRARIES)

run: $(TARGET)
	valgrind ./$(TARGET)

clean:
	/bin/rm -f $(TARGET)
	/bin/rm -f $(TARGET)-debug
	/bin/rm -f $(TARGET)-tests
