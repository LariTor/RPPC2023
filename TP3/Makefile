CC = g++
LDFLAGS = -lm -lcriterion -lginac -lmatplot
CFLAGS = -O
ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

MAINS = $(shell find src/test/mains/ -maxdepth 1 -type f -name "*.cpp") 
MAINSOUT = $(patsubst src/test/mains/%.cpp, %, $(MAINS))
SRCS = $(shell find src/ -maxdepth 1 -type f -name "*.cpp")
MAINSOBJ = $(patsubst src/test/mains/%.cpp, obj/mains/%.o, $(MAINS))
OBJS = $(patsubst src/%.cpp, obj/src/%.o, $(SRCS))

all: $(MAINSOUT)

$(MAINSOUT): $(OBJS) $(MAINSOBJ)
#%: $(OBJS) obj/mains/%.o
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$@ obj/mains/$@.o $(OBJS) $(LDFLAGS)

obj/src/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

obj/mains/%.o: src/test/mains/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf bin/
	rm -rf obj/
