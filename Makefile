CXX=g++
CXXFLAGS=-std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
OPTIMIZE=-O2
FILES=Database.hpp Database.cpp ShinyDatabase.hpp ShinyDatabase.cpp Counter.hpp Counter.cpp Window.hpp Window.cpp ShinyCounter.hpp ShinyCounter.cpp main.cpp
TARGET=shinycounter
LIBRARIES=-l sfml-graphics -l sfml-window -l sfml-system -l sqlite3

all: $(TARGET)
$(TARGET): $(FILES)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE) $(FILES) -o $(TARGET) $(LIBRARIES)

debug: $(FILES)
	$(CXX) $(CXXFLAGS) -g $(FILES) -o $(TARGET)-debug $(LIBRARIES)

run: $(TARGET)
	valgrind ./$(TARGET)

clean:
	/bin/rm -f $(TARGET)
	/bin/rm -f $(TARGET)-debug
