CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

SRC_DIR = src
SRC = $(SRC_DIR)/Board.cpp $(SRC_DIR)/King.cpp $(SRC_DIR)/Queen.cpp $(SRC_DIR)/main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = chess

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
