#include <sys/cdefs.h>
#include <inttypes.h>
#include <locale.h>

uintmax_t
strtoumax_l(const char *nptr, char **endptr, int base, locale_t loc __unused)
{
	return strtoumax(nptr, endptr, base);
}
