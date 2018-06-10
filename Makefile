all: compile

compile:
	@gcc src/client.c
	@gcc src/server.c

run:
	@./app
