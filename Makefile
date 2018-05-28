flags = `pkg-config gtk+-3.0 --cflags --libs`
all: compile run

ui:
	pug builder.pug
	mv builder.html builder.ui

compile:
	gcc main.c -o app $(flags)

run:
	./app
