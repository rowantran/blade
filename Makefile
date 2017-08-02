# App configuration
APPNAME := blade

# Set target executable name
TARGET := bin/$(APPNAME)

# Compiler & linker options
CXX := clang++
CXXFLAGS := -g -Wall

# List source files
SOURCES := $(shell find src -type f -name *.cpp)

# List object files
OBJECTS := $(patsubst src/%.cpp,build/%.o,$(SOURCES))

# Default make target
all: $(APPNAME)

# Link object files
$(APPNAME): $(OBJECTS)
	@echo "Linking...."
	$(CXX) -o $(TARGET) $(OBJECTS) -L /usr/local/lib -l SDL2 -l SDL2_image
	@echo "Done"

# Compile object files
build/%.o: src/%.cpp
	@echo "Compiling $@"
	$(CXX) -c $(CXXFLAGS) -o $@ $< -std=c++11 -Wall -I /usr/local/include -I include

distclean: clean
	rm $(TARGET)

clean:
	rm -f $(OBJECTS)