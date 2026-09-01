#include <sys/cdefs.h>
#include <stdlib.h>
#include <locale.h>

long long int
strtoll_l(const char * __restrict nptr, char ** __restrict endptr, int base, locale_t loc __unused)
{
	return strtoll(nptr, endptr, base);
}
