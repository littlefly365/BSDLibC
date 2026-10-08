/*
 * Copyright (c) 2026, littlefly365
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <sys/cdefs.h>
#include <sys/statvfs.h>
#include <sys/syslimits.h>
#include <string.h>
#include <unistd.h>
#include "libc.h"

#ifdef __weak_alias
__weak_alias(pathconf, _pathconf);
#endif

long
_pathconf(const char *path, int name)
{
	struct statvfs st;

	/* NetBSD pathconf fails if the entire path is larger than PATH_MAX */
	if (strlen(path) > PATH_MAX)
		return seterrno(-ENAMETOOLONG);

	if (access(path, F_OK) != 0)
		return seterrno(-ENOENT);

	switch (name)
	{
	case _PC_NAME_MAX:
		if (statvfs(path, &st) < 0)
			return NAME_MAX;
		return st.f_namemax;
	default:
		/*
		 * I know that fd 0 is stdin, but
		 * fpathconf only use fd to get
		 * _PC_NAME_MAX.
		*/
		return fpathconf(0, name);
	}

	return -1;
}
