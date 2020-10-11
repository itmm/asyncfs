.PHONY: all app tests clean

TEST_APP := asyncfs-tests
SRCs := $(wildcard *.md)
CPPs := $(wildcard *.cpp)
Hs := $(wildcard *.h)
OBJs := $(CPPs:.cpp=.o)

all: hx-run

hx-run: $(SRCs)
	@echo "HX"
	@which hx >/dev/null || $(MAKE) --no-print-directory tests
	@hx
	@$(MAKE) --no-print-directory tests

$(CPPs): $(Hs)
	@touch $@

$(TEST_APP): $(OBJs)

tests: $(TEST_APP)
	@echo "UNIT-TESTS"
	@./$(TEST_APP) && echo "  ALL TESTS OK"

clean:
	@echo "RM"
	@rm -f *.o *.cpp *.h hx-run $(TEST_APP)
