CXX ?= g++

PATH_SRC   := src
PATH_BUILD := build
PATH_BIN   := bin
PATH_INC   := include

APP := xkcd_2672

EXT := cpp

SRCS = $(shell find $(PATH_SRC) -name '*.$(EXT)')
OBJS = $(patsubst $(PATH_SRC)/%.$(EXT),$(PATH_BUILD)/%.o,$(SRCS))

INCLUDES = -I$(PATH_INC)

CXXFLAGS := -std=c++17 -Wall -Wextra
LIBS :=

define fancy
echo "\n\e[1m*** $(1)\e[0m\n"
endef

.PHONY: all
all: | verify compile

.PHONY: verify
verify:
	mkdir -p $(PATH_SRC)
	mkdir -p $(PATH_BUILD)
	mkdir -p $(PATH_BIN)
	mkdir -p $(PATH_INC)

	@$(call fancy,"Created directories.")

.PHONY: compile
compile: $(PATH_BIN)/$(APP)

$(PATH_BIN)/$(APP): $(OBJS)
	@$(call fancy,"Linking executable $@...")
	$(CXX) $(OBJS) -o $@ $(LIBS)

$(PATH_BUILD)/%.o: $(PATH_SRC)/%.$(EXT)
	@$(call fancy,"Compiling object $@...")
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm $(PATH_BUILD)/*.o

.PHONY: run
run:
	@$(PATH_BIN)/$(APP) $(ARGS)
