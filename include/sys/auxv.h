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

#ifndef _SYS_AUXV_H
#define _SYS_AUXV_H

/* sys/exec_elf.h defines it with solaris values, why? i dont know */
#undef AT_EUID
#undef AT_EGID

unsigned long getauxval(unsigned long type);

#define AT_NULL			0
#define AT_IGNORE		1
#define AT_EXECFD		2
#define AT_PHDR			3
#define AT_PHENT		4
#define AT_PHNUM		5
#define AT_PAGESZ		6
#define AT_BASE			7
#define AT_FLAGS		8
#define AT_ENTRY		9
#define AT_NOTELF		10
#define AT_UID			11
#define AT_EUID			12
#define AT_GID			13
#define AT_EGID			14
#define AT_PLATFORM		15
#define	AT_HWCAP		16
#define AT_CLKTCK		17
#define AT_FPUCW		18
#define AT_DCACHEBSIZE		19
#define AT_ICACHEBSIZE		20
#define AT_UCACHEBSIZE		21
#define AT_IGNOREPPC		22
#define AT_SECURE		23
#define AT_BASE_PLATFORM	24
#define AT_RANDOM		25
#define AT_HWCAP2		26
#define AT_RSEQ_FEATURE_SIZE	27
#define AT_RSEQ_ALIGN		28
#define AT_HWCAP3		29
#define	AT_HWCAP4		30
#define	AT_EXECFN		31
#define AT_SYSINFO		32
#define AT_SYSINFO_EHDR		33
#define AT_L1I_CACHESHAPE	34
#define AT_L1D_CACHESHAPE	35
#define AT_L2_CACHESHAPE	36
#define AT_L3_CACHESHAPE	37

#define AT_L1I_CACHESIZE	40
#define AT_L1I_CACHEGEOMETRY	41
#define AT_L1D_CACHESIZE	42
#define AT_L1D_CACHEGEOMETRY	43
#define AT_L2_CACHESIZE		44
#define AT_L2_CACHEGEOMETRY	45
#define AT_L3_CACHESIZE		46
#define AT_L3_CACHEGEOMETRY	47

#define AT_MINSIGSTKSZ		51

#endif /* !_SYS_AUXV_H_ */
