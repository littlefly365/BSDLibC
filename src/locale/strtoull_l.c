#include <sys/cdefs.h>
#include <stdlib.h>
#include <locale.h>

unsigned long long int
strtoull_l(const char * __restrict nptr, char ** __restrict endptr, int base, locale_t loc __unused)
{
	return strtoull(nptr, endptr, base);
}
