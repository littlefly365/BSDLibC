#include <stdio.h>
#include <unistd.h>
#include <err.h>

int
main(void)
{
	long ncpu = sysconf(_SC_NPROCESSORS_CONF);
	printf("%ld\n", ncpu);
	return 0;
}
