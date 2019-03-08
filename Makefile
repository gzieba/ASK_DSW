CC=g++
CFLAGS = -std=c++11 -pthread
MKDIR_P = mkdir -p
OBJ = obj


default: observer_dir Observer mediator_dir Mediator
observer: observer_dir Observer
mediator: mediator_dir Mediator

O_SRC_DIR = observer
O_DEPS =
O_ODIR = $(OBJ)/observer
O_OBJ = $(O_ODIR)/observer.o

observer_dir:
		$(MKDIR_P) $(O_ODIR)

$(O_ODIR)/%.o: $(O_SRC_DIR)/%.cpp $(O_DEPS)
		$(CC) -c -o $@ $< $(CFLAGS) -I./$(M_SRC_DIR)

Observer: $(O_OBJ)
		$(CC) -o $@ $^ $(CFLAGS) -I./$(M_SRC_DIR)

M_SRC_DIR = mediator
M_DEPS = $(M_SRC_DIR)/client.h $(M_SRC_DIR)/chatroom.h $(M_SRC_DIR)/mediator.h
M_ODIR = $(OBJ)/mediator
M_OBJ = $(M_ODIR)/main.o $(M_ODIR)/client.o $(M_ODIR)/chatroom.o

mediator_dir:
		$(MKDIR_P) $(M_ODIR)

$(M_ODIR)/%.o: $(M_SRC_DIR)/%.cpp $(M_DEPS)
		$(CC) -c -o $@ $< $(CFLAGS) -I./$(M_SRC_DIR)

Mediator: $(M_OBJ)
		$(CC) -o $@ $^ $(CFLAGS) -I./$(M_SRC_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ)
	rm -f Mediator Observer
