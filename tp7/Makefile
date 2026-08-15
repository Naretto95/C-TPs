CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra
srcdir  = src
bindir  = bin
PROG    = $(bindir)/tp7

SRC     = $(wildcard $(srcdir)/*.c)
OBJ     = $(patsubst $(srcdir)/%.c,$(bindir)/%.o,$(SRC))

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(bindir)/%.o: $(srcdir)/%.c $(srcdir)/%.h | $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

$(bindir):
	mkdir -p $(bindir)

.PHONY: clean
clean:
	rm -rf $(bindir)
