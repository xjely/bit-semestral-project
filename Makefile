force: force.c
	gcc -ggdb -fno-stack-protector -z execstack -o force force.c
# uaf: uaf.c
	# gcc -ggdb -o uaf uaf.c