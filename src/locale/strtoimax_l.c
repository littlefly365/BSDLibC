#include <sys/cdefs.h>
#include <inttypes.h>
#include <locale.h>

intmax_t
strtoimax_l(const char *nptr, char **endptr, int base, locale_t loc __unused)
{
	return strtoimax(nptr, endptr, base);
}
