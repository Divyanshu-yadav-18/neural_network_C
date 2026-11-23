run:main
	@./main

hot:
	@ls *.c | entr -c make --no-print-directory run

