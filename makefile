# Environment
BUILD=build
CP=g++ -I src/headers
LIBS=-lSDL2 -lSDL2main
SRC = src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp
OUT = -o $(BUILD)/game

# Game building
all: $(src) clean structure
	$(CP) $(SRC) $(OUT) $(LIBS)

# Structuring and Cleaning
structure:
	mkdir -p ./$(BUILD)

clean:
	rm -rf ./$(BUILD)
