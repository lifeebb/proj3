CXX=g++

INC_DIR =./include
SRC_DIR =./src
OBJ_DIR =./obj
BIN_DIR =./bin
TESTBIN_DIR =./testbin

CXXFLAGS = -I $(INC_DIR) -Wall --std=c++14
TESTFLAGS = -lgtest -lgtest_main -lpthread
TESTNAME = testboard

MAIN_OBJ = $(OBJ_DIR)/main.o

TESTBOARD_OBJ = $(OBJ_DIR)/testsixmensmorris.o

PROJ_OBJS = $(OBJ_DIR)/SixMensMorrisBoard.o

all: directories test
test: $(TESTBIN_DIR)/$(TESTNAME)
	$(TESTBIN_DIR)/$(TESTNAME)

$(TESTBIN_DIR)/$(TESTNAME): $(PROJ_OBJS) $(TESTBOARD_OBJ)
	$(CXX) $(PROJ_OBJS) $(TESTBOARD_OBJ) -o $(TESTBIN_DIR)/$(TESTNAME) $(CXXFLAGS) $(TESTFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TESTBIN_DIR)

.PHONY: clean
clean::
	-rm $(OBJ_DIR)/*.o $(INC_DIR)/*.*~ $(SRC_DIR)/*.*~
