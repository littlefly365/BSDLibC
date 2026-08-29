TESTS=revoke uname hello hostname

all: $(TESTS)

$(TESTS):
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $@.c
	$(CC) -o $@ $@.o $(LDFLAGS)
clean:
	rm -rf $(TESTS) *.o
.PHONY: all clean
