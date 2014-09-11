
# All Target
all: shared

shared:
	(cd Shared; make)

install: install-shared

install-shared:
	./install-shared.sh

clean:
	(cd Shared; rm *.so*; make clean)
