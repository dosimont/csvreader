
# All Target
all: shared

shared:
	(cd Shared; make)

static:
	(cd Static; make)

install: install-shared

install-shared:
	./install-shared.sh

install-static:
	./install-static.sh

clean:
	(cd Shared; rm *.so*; make clean)
	(cd Static; rm *.a*; make clean)
