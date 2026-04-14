CXX = g++

SRC = core/build.cpp \
      lexer/lexer.cpp 

OBJ = $(SRC:.cpp=.o)

build: $(OBJ)
	$(CXX) $(OBJ) -o build

%.o: %.cpp
	$(CXX) -c $< -o $@
clean:
	rm -f $(OBJ) build
