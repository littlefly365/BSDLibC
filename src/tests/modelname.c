#include <sys/sysctl.h>
#include <stdio.h>
#include <err.h>

int
main(void)
{
	int mib[2] = { CTL_HW, HW_MODEL };
	char model[256];
	size_t len = sizeof(model);

	if (sysctl(mib, 2, model, &len, NULL, 0) < 0)
		err(1, "sysctl");

	puts(model);
	return 0;
}
