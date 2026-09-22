TESTS=cat chmod kill sleep stat ls

all: $(TESTS)

$(TESTS):
	$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) $@.c $(LDFLAGS)
clean:
	rm -rf $(TESTS) *.o
.PHONY: all clean
