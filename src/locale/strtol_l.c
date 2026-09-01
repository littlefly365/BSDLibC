#include <sys/cdefs.h>
#include <stdlib.h>
#include <locale.h>

long
strtol_l(const char * __restrict nptr, char ** __restrict endptr, int base, locale_t loc __unused)
{
	return strtol(nptr, endptr, base);
}
