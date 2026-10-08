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

#define _OPENBSD_SOURCE	/* strtonum(3) */
#include <sys/cdefs.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include "libc.h"

#define LOGIN_FILE	"/proc/self/loginuid"

static int
_getlogin_r_from_file(char *name, size_t namelen)
{
	int fd;
	char buf[512];
	const char *errstr;

	if ((fd = open(LOGIN_FILE, O_RDONLY)) < 0)
		return seterrno(-ENOENT);

	if (read(fd, buf, sizeof(buf)) <= 0)
		return seterrno(-ENOENT); /* ENOENT ? */

	uid_t uid = (unsigned int)strtonum(buf, 0, UINT32_MAX, &errstr);
	if (errstr == NULL)
		return -1;

	struct passwd *pw = getpwuid(uid);
	if (pw == NULL)
		return -1;

	if (strlen(pw->pw_name) > namelen)
		return seterrno(-ENOMEM);

	strlcpy(name, pw->pw_name, namelen);
	return 0;
}

int
__getlogin(char *name, size_t namelen)
{
	char *log = getenv("LOGNAME");
	if (log == NULL || log[0] == '\0') {
		return _getlogin_r_from_file(name, namelen);
	}

	if (strlen(log) >= namelen)
		seterrno(-ENOMEM);

	strlcpy(name, log, namelen);
	return 0;
}

int
__setlogin(const char *name)
{
	return seterrno(-ENOTSUP);
}
