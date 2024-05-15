SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

APP_DIR = $(SRC_DIR)/app
LIB_DIR = $(SRC_DIR)/lib

LIB = $(OBJ_DIR)/$(LIB_DIR)/lib.a

CC = gcc
RM_DIR = rm -rf
CLEAN_OBJ = clean_obj
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I $(SRC_DIR) -MP -MMD
LDLIBS = -lm
DFLAGS = -g

APP_S = $(shell find $(APP_DIR) -name "*.c")
APP_O = $(APP_S:%.c=$(OBJ_DIR)/%.o)

DEP_S = $(shell find $(LIB_DIR) -name "*.c")
DEP_O = $(DEP_S:%.c=$(OBJ_DIR)/%.o)

DEP = $(APP_O.o=.d) $(DEP_O:.o=.d)

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
OBJ_DIRS = $(SRC_DIRS:%=$(OBJ_DIR)/%)

APP_NAMES = $(APP_S:$(APP_DIR)/%.c=$(BIN_DIR)/%)

DELETE_OBJS = DELETE_OBJS
DELETE_BIN = DELETE_BIN

.PHONY: all
all: $(BIN_DIR) $(OBJ_DIR) $(APP_NAMES) $(DELETE_OBJS)

-include $(DEP)

$(BIN_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@ $(OBJ_DIRS)

$(BIN_DIR)/%: $(OBJ_DIR)/$(APP_DIR)/%.o $(LIB)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(DFLAGS) $(LDLIBS)

$(LIB): $(DEP_O)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ $(DFLAGS) $(LDLIBS)

$(DELETE_OBJS):
	$(RM_DIR) $(OBJ_DIR)

$(DELETE_BIN):
	$(RM_DIR) $(BIN_DIR)

.PHONY: clean
clean: $(DELETE_BIN) $(DELETE_OBJS)
