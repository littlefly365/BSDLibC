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
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS longERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <sys/syscall.h>
#include <sys/cdefs.h>
#include <stdarg.h>
#include "libc.h"

#ifdef __weak_alias
__weak_alias(_syscall, syscall);
#endif

#ifdef __strong_alias
__strong_alias(__syscall, syscall);
#endif

extern long __sys_syscall(long n, long a1, long a2, long a3, long a4, long a5, long a6);

long
syscall(long n, ...)
{
	va_list ap;

	va_start(ap, n);
	long a1 = va_arg(ap, long);
	long a2 = va_arg(ap, long);
	long a3 = va_arg(ap, long);
	long a4 = va_arg(ap, long);
	long a5 = va_arg(ap, long);
	long a6 = va_arg(ap, long);
	va_end(ap);

	if (n < 0 || n >= SYS_MAXSYSCALL)
		return seterrno(-ENOSYS);

	return seterrno(__sys_syscall(n, a1, a2, a3, a4, a5, a6));
}
