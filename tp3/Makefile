CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra
srcdir  = src
bindir  = bin

SRC     = $(wildcard $(srcdir)/*.c)
PROGS   = $(patsubst $(srcdir)/%.c,$(bindir)/%,$(SRC))

all: $(bindir) $(PROGS)

$(bindir):
	mkdir -p $(bindir)

$(bindir)/%: $(srcdir)/%.c | $(bindir)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean
clean:
	rm -rf $(bindir)
