CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra
LDLIBS  = -lm
srcdir  = src
bindir  = bin
PROG    = $(bindir)/tp10

SRC     = $(wildcard $(srcdir)/*.c)
OBJ     = $(patsubst $(srcdir)/%.c,$(bindir)/%.o,$(SRC))

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

$(bindir)/%.o: $(srcdir)/%.c $(srcdir)/%.h | $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

$(bindir):
	mkdir -p $(bindir)

.PHONY: clean
clean:
	rm -rf $(bindir)
