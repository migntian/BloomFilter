.PHONY:clean
main:bloomfilter.c
	gcc -o $@ $^
clean:
	rm main
