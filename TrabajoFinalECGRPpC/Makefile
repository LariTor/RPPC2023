CC = gcc
LDFLAGS = -lm
CFLAGS = -O
ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

MAINS = $(shell find test/mains/ -maxdepth 1 -type f -name "*.c") 
MAINSOUT = $(patsubst test/mains/%.c, %, $(MAINS))
SRCS = $(shell find src/mains/ -maxdepth 1 -type f -name "*.c")
MAINSOBJ = $(patsubst test/mains/%.c, obj/mains/%.o, $(MAINS))
OBJS = $(patsubst src/%.c, obj/src/%.o, $(SRCS))

all: $(MAINSOUT)

$(MAINSOUT): $(OBJS) $(MAINSOBJ)
#%: $(OBJS) obj/mains/%.o
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$@ obj/mains/$@.o $(OBJS) $(LDFLAGS)

obj/src/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

obj/mains/%.o: test/mains/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf bin/
	rm -rf obj/
