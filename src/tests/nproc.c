#include <sys/sysctl.h>
#include <stdio.h>
#include <err.h>

int
main(void)
{
	int mib[2] = { CTL_HW, HW_NCPU };
	long ncpu;
	size_t len = sizeof(ncpu);

	if (sysctl(mib, 2, &ncpu, &len, NULL, 0) < 0)
		err(1, "sysctl");

	printf("%ld\n", ncpu);
	return 0;
}
