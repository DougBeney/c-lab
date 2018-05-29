flags = `pkg-config gtk+-3.0 --cflags --libs`
all: compile run

compile:
	@gcc src/main.c src/definitions.c -o app $(flags)

run:
	@./app
