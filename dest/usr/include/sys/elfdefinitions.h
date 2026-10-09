/*-
 * Copyright (c) 2010,2021,2024 Joseph Koshy
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS `AS IS' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * WARNING: GENERATED FILE.  DO NOT MODIFY.
 *
 *  GENERATED FROM: Id: elfdefinitions.m4 4318 2025-12-18 21:02:33Z jkoshy
 *  GENERATED FROM: Id: elfconstants.m4 4311 2025-12-17 14:53:55Z jkoshy
 */

/*
 * Compile-time knobs controlling the inclusion of this file's
 * contents.
 */
#define _USE_SYS_ELFDEFINITIONS_H_	1
#if defined(__NetBSD__) && defined(_SYS_EXEC_ELF_H_)
/*
 * Ignore the definitions provided by this file if <sys/exec_elf.h> has
 * already been included.
 *
 * Doing so allows NetBSD code to use either (or both) <sys/exec_elf.h>
 * or this file without breaking the build.
 */
#undef _USE_SYS_ELFDEFINITIONS_H_
#endif /* defined(__NetBSD__) && defined(_SYS_EXEC_ELF_H_) */

/*
 *  These definitions are believed to be compatible with:
 * 
 *  - The ELF object file format specification at: https://gabi.xinuos.com/.
 * 
 *  - The May 1998 (version 1.5) draft of "The ELF-64 object format".
 * 
 *  - The "Linkers and Libraries Guide", from Sun Microsystems.
 * 
 *  - Processor-specific ELF ABI definitions for the aarch64, arm, i386,
 *    ia_64, loongarch, mips, ppc, ppc64, riscv, s390, sparc, vax and
 *    x86_64 architectures:
 * 
 *    i386 ::
 *      System V Application Binary Interface
 *      Intel386 Architecture Processor Supplement Version 1.2
 *      https://gitlab.com/x86-psABIs/i386-ABI/-/tree/hjl/x86/master
 * 
 *    68k ::
 *      System V Application Binary Interface
 *      Motorola 68000 Processor Family Supplement
 * 
 *    aarch64 ::
 *      ELF for the Arm® 64-bit Architecture (AArch64)
 *      https://github.com/ARM-software/abi-aa/blob/main/aaelf64/aaelf64.rst
 * 
 *    arm ::
 *      ELF for the Arm® Architecture
 *      https://github.com/ARM-software/abi-aa/blob/main/aaelf32/aaelf32.rst
 * 
 *    alpha ::
 *      Believed to be compatible with NetBSD/Alpha and GNU binutils.
 * 
 *    ia_64 ::
 *      Intel® Itanium™ Processor-specific Application Binary Interface (ABI)
 *      Document Number: 245370-003
 *      http://refspecs.linux-foundation.org/elf/IA64-SysV-psABI.pdf
 * 
 *    loongarch ::
 *      ELF for the LoongArch™ Architecture
 *      https://github.com/loongson/la-abi-specs/blob/release/laelf.adoc.
 * 
 *    mips ::
 *      SYSTEM V APPLICATION BINARY INTERFACE, MIPS RISC Processor Supplement,
 *      3rd Edition, 1996.
 *      https://refspecs.linuxfoundation.org/elf/mipsabi.pdf
 * 
 *      64-bit ELF Object File Specification, Draft Version 2.5
 *      Document: 007-4658-001
 *      MIPS Technologies/Silicon Graphics Computer Systems
 *      https://irix7.com/techpubs/007-4658-001.pdf
 * 
 *    openrisc ::
 *      OpenRISC 1000 Architecture Manual, Architecture Version 1.4
 *      https://openrisc.io/revisions/r1.4
 * 
 *    parisc ::
 *      Processor-Specific ELF Supplement for PA-RISC, Version 1.5, August 20, 1998.
 *      https://parisc.docs.kernel.org/en/latest/technical_documentation.html
 * 
 *      Implementing Thread Local Storage for HP PA-RISC Linux, November 11, 2013
 *      (Archived link) https://web.archive.org/web/20240722131647/\
 *        http://www.parisc-linux.org/documentation/tls/hppa-tls-implementation.pdf
 * 
 *    ppc ::
 *      Power Architecture® 32-bit Application Binary Interface
 *      Supplement 1.0 - Linux® & Embedded
 *      (Archived link) https://web.archive.org/web/20120608002551/\
 *        https://www.power.org/resources/downloads/\
 *        Power-Arch-32-bit-ABI-supp-1.0-Unified.pdf
 * 
 *    ppc64 ::
 *      64-bit ELF ABI Specification for OpenPOWER Architecture
 *      https://openpowerfoundation.org/specifications/64bitelfabi/
 * 
 *    riscv ::
 *      RISC-V ELF Specification
 *      https://github.com/riscv-non-isa/riscv-elf-psabi-doc/blob/master/riscv-elf.adoc
 * 
 *    s390 ::
 *      S/390 ELF Application Binary Interface Supplement
 *      https://refspecs.linuxfoundation.org/ELF/zSeries/lzsabi0_zSeries.htm
 * 
 *    sh ::
 *      Believed to be compatible with NetBSD/sh3, GNU and GDB-NG.
 * 
 *    sparc ::
 *      Oracle Solaris Linkers and Libraries Guide
 *      November 2024, Document E36783-04.
 * 
 *    x86_64 ::
 *      ELF x86-64-ABI psABI
 *      https://gitlab.com/x86-psABIs/x86-64-ABI
 */
 
#if defined(_USE_SYS_ELFDEFINITIONS_H_)

#ifndef _SYS_ELFDEFINITIONS_H_
#define _SYS_ELFDEFINITIONS_H_

#include <stdint.h>

/*
 * Types of capabilities.
 */

#define CA_SUNW_NULL	0 /* ignored */
#define CA_SUNW_HW_1	1 /* hardware capability */
#define CA_SUNW_SW_1	2 /* software capability */

/*
 * Flags used with dynamic linking entries.
 */

#define DF_ORIGIN	0x00000001U /* object being loaded may refer to $ORIGIN */
#define DF_SYMBOLIC	0x00000002U /* search library for references before executable */
#define DF_TEXTREL	0x00000004U /* relocation entries may modify text segment */
#define DF_BIND_NOW	0x00000008U /* process relocation entries at load time */
#define DF_STATIC_TLS	0x00000010U /* uses static thread-local storage */
#define DF_1_BIND_NOW	0x00000001U /* process relocation entries at load time */
#define DF_1_GLOBAL	0x00000002U /* unused */
#define DF_1_GROUP	0x00000004U /* object is a member of a group */
#define DF_1_NODELETE	0x00000008U /* object cannot be deleted from a process */
#define DF_1_LOADFLTR	0x00000010U /* immediate load filtees */
#define DF_1_INITFIRST	0x00000020U /* initialize object first */
#define DF_1_NOOPEN	0x00000040U /* disallow dlopen() */
#define DF_1_ORIGIN	0x00000080U /* object being loaded may refer to $ORIGIN */
#define DF_1_DIRECT	0x00000100U /* direct bindings enabled */
#define DF_1_INTERPOSE	0x00000400U /* object is interposer */
#define DF_1_NODEFLIB	0x00000800U /* ignore default library search path */
#define DF_1_NODUMP	0x00001000U /* disallow dldump() */
#define DF_1_CONFALT	0x00002000U /* object is a configuration alternative */
#define DF_1_ENDFILTEE	0x00004000U /* filtee terminates filter search */
#define DF_1_DISPRELDNE	0x00008000U /* displacement relocation done */
#define DF_1_DISPRELPND	0x00010000U /* displacement relocation pending */
#define DF_1_NODIRECT	0x00020000U /* object contains non-direct bindings */
#define DF_1_IGNMULDEF	0x00040000U /* unused */
#define DF_1_NOKSYMS	0x00080000U /* unused */
#define DF_1_NOHDR	0x00100000U /* unused */
#define DF_1_EDITED	0x00200000U /* object has been modified */
#define DF_1_NORELOC	0x00400000U /* unused */
#define DF_1_SYMINTPOSE	0x00800000U /* symbol interposers exist */
#define DF_1_GLOBAUDIT	0x01000000U /* global auditing */
#define DF_1_SINGLETON	0x02000000U /* contains singleton symbols */
#define DF_1_STUB	0x04000000U /* stub object */
#define DF_1_PIE	0x08000000U /* position-independent executable */
#define DF_1_KMOD	0x10000000U /* kernel module */
#define DF_1_WEAKFILTER	0x20000000U /* object is a weak filter */


/*
 * Aliases for the DF_* symbols.
 */

#define DF_1_NOW	DF_1_BIND_NOW


/*
 * Dynamic linking entry types.
 */

#define DT_NULL		0 /* end of array */
#define DT_NEEDED	1 /* names a needed library */
#define DT_PLTRELSZ	2 /* size in bytes of associated relocation entries */
#define DT_PLTGOT	3 /* address associated with the procedure linkage table */
#define DT_HASH		4 /* address of the symbol hash table */
#define DT_STRTAB	5 /* address of the string table */
#define DT_SYMTAB	6 /* address of the symbol table */
#define DT_RELA		7 /* address of the relocation table */
#define DT_RELASZ	8 /* size of the DT_RELA table */
#define DT_RELAENT	9 /* size of each DT_RELA entry */
#define DT_STRSZ	10 /* size of the string table */
#define DT_SYMENT	11 /* size of a symbol table entry */
#define DT_INIT		12 /* address of the initialization function */
#define DT_FINI		13 /* address of the finalization function */
#define DT_SONAME	14 /* names the shared object */
#define DT_RPATH	15 /* runtime library search path */
#define DT_SYMBOLIC	16 /* alter symbol resolution algorithm */
#define DT_REL		17 /* address of the DT_REL table */
#define DT_RELSZ	18 /* size of the DT_REL table */
#define DT_RELENT	19 /* size of each DT_REL entry */
#define DT_PLTREL	20 /* type of relocation entry in the procedure linkage table */
#define DT_DEBUG	21 /* used for debugging */
#define DT_TEXTREL	22 /* text segment may be written to during relocation */
#define DT_JMPREL	23 /* address of relocation entries associated with the procedure linkage table */
#define DT_BIND_NOW	24 /* bind symbols at loading time */
#define DT_INIT_ARRAY	25 /* pointers to initialization functions */
#define DT_FINI_ARRAY	26 /* pointers to termination functions */
#define DT_INIT_ARRAYSZ	27 /* size of the DT_INIT_ARRAY */
#define DT_FINI_ARRAYSZ	28 /* size of the DT_FINI_ARRAY */
#define DT_RUNPATH	29 /* index of library search path string */
#define DT_FLAGS	30 /* flags specific to the object being loaded */
#define DT_ENCODING	32 /* standard semantics */
#define DT_PREINIT_ARRAY 32 /* pointers to pre-initialization functions */
#define DT_PREINIT_ARRAYSZ 33 /* size of pre-initialization array */
#define DT_SYMTAB_SHNDX	34 /* the address of the SHT_SYMTAB_SHNDX section for the DT_SYMTAB entry */
#define DT_RELRSZ	35 /* the total size in bytes of the DT_RELR relocation table */
#define DT_RELR		36 /* The address of a table with relative relocation entries */
#define DT_RELRENT	37 /* The size in bytes of a DT_RELR relocation entry */
#define DT_SYMTABSZ	39 /* The size in bytes of the DT_SYMTAB symbol table */
#define DT_LOOS		0x6000000D /* start of OS-specific types */
#define DT_SUNW_AUXILIARY 0x6000000D /* offset of string naming auxiliary filtees */
#define DT_SUNW_RTLDINF	0x6000000E /* rtld internal use */
#define DT_SUNW_FILTER	0x6000000F /* offset of string naming standard filtees */
#define DT_SUNW_CAP	0x60000010 /* address of hardware capabilities section */
#define DT_SUNW_ASLR	0x60000023 /* Address Space Layout Randomization flag */
#define DT_HIOS		0x6FFFF000 /* end of OS-specific types */
#define DT_VALRNGLO	0x6FFFFD00 /* start of range using the d_val field */
#define DT_GNU_PRELINKED 0x6FFFFDF5 /* prelinking timestamp */
#define DT_GNU_CONFLICTSZ 0x6FFFFDF6 /* size of conflict section */
#define DT_GNU_LIBLISTSZ 0x6FFFFDF7 /* size of library list */
#define DT_CHECKSUM	0x6FFFFDF8 /* checksum for the object */
#define DT_PLTPADSZ	0x6FFFFDF9 /* size of PLT padding */
#define DT_MOVEENT	0x6FFFFDFA /* size of DT_MOVETAB entries */
#define DT_MOVESZ	0x6FFFFDFB /* total size of the MOVETAB table */
#define DT_FEATURE	0x6FFFFDFC /* feature values */
#define DT_POSFLAG_1	0x6FFFFDFD /* dynamic position flags */
#define DT_SYMINSZ	0x6FFFFDFE /* size of the DT_SYMINFO table */
#define DT_SYMINENT	0x6FFFFDFF /* size of a DT_SYMINFO entry */
#define DT_VALRNGHI	0x6FFFFDFF /* end of range using the d_val field */
#define DT_ADDRRNGLO	0x6FFFFE00 /* start of range using the d_ptr field */
#define DT_GNU_HASH	0x6FFFFEF5 /* GNU style hash tables */
#define DT_TLSDESC_PLT	0x6FFFFEF6 /* location of PLT entry for TLS descriptor resolver calls */
#define DT_TLSDESC_GOT	0x6FFFFEF7 /* location of GOT entry used by TLS descriptor resolver PLT entry */
#define DT_GNU_CONFLICT	0x6FFFFEF8 /* address of conflict section */
#define DT_GNU_LIBLIST	0x6FFFFEF9 /* address of conflict section */
#define DT_CONFIG	0x6FFFFEFA /* configuration file */
#define DT_DEPAUDIT	0x6FFFFEFB /* string defining audit libraries */
#define DT_AUDIT	0x6FFFFEFC /* string defining audit libraries */
#define DT_PLTPAD	0x6FFFFEFD /* PLT padding */
#define DT_MOVETAB	0x6FFFFEFE /* address of a move table */
#define DT_SYMINFO	0x6FFFFEFF /* address of the symbol information table */
#define DT_ADDRRNGHI	0x6FFFFEFF /* end of range using the d_ptr field */
#define DT_VERSYM	0x6FFFFFF0 /* address of the version section */
#define DT_RELACOUNT	0x6FFFFFF9 /* count of RELA relocations */
#define DT_RELCOUNT	0x6FFFFFFA /* count of REL relocations */
#define DT_FLAGS_1	0x6FFFFFFB /* flag values */
#define DT_VERDEF	0x6FFFFFFC /* address of the version definition segment */
#define DT_VERDEFNUM	0x6FFFFFFD /* the number of version definition entries */
#define DT_VERNEED	0x6FFFFFFE /* address of section with needed versions */
#define DT_VERNEEDNUM	0x6FFFFFFF /* the number of version needed entries */
#define DT_LOPROC	0x70000000 /* start of processor-specific types */
#define DT_ALPHA_PLTRO	0x70000000 /* secure (read-only) PLT */
#define DT_ARM_SYMTABSZ	0x70000001 /* number of entries in the dynamic symbol table */
#define DT_SPARC_REGISTER 0x70000001 /* index of an STT_SPARC_REGISTER symbol */
#define DT_ARM_PREEMPTMAP 0x70000002 /* address of the preemption map */
#define DT_MIPS_RLD_VERSION 0x70000001 /* version ID for runtime linker interface */
#define DT_MIPS_TIME_STAMP 0x70000002 /* timestamp */
#define DT_MIPS_ICHECKSUM 0x70000003 /* checksum of all external strings and common sizes */
#define DT_MIPS_IVERSION 0x70000004 /* string table index of a version string */
#define DT_MIPS_FLAGS	0x70000005 /* MIPS-specific flags */
#define DT_MIPS_BASE_ADDRESS 0x70000006 /* base address for the executable/DSO */
#define DT_MIPS_CONFLICT 0x70000008 /* address of .conflict section */
#define DT_MIPS_LIBLIST	0x70000009 /* address of .liblist section */
#define DT_MIPS_LOCAL_GOTNO 0x7000000A /* number of local GOT entries */
#define DT_MIPS_CONFLICTNO 0x7000000B /* number of entries in the .conflict section */
#define DT_MIPS_LIBLISTNO 0x70000010 /* number of entries in the .liblist section */
#define DT_MIPS_SYMTABNO 0x70000011 /* number of entries in the .dynsym section */
#define DT_MIPS_UNREFEXTNO 0x70000012 /* index of first external dynamic symbol not referenced locally */
#define DT_MIPS_GOTSYM	0x70000013 /* index of first dynamic symbol corresponds to a GOT entry */
#define DT_MIPS_HIPAGENO 0x70000014 /* number of page table entries in GOT */
#define DT_MIPS_RLD_MAP	0x70000016 /* address of runtime linker map */
#define DT_MIPS_DELTA_CLASS 0x70000017 /* Delta C++ class definition */
#define DT_MIPS_DELTA_CLASS_NO 0x70000018 /* number of entries in DT_MIPS_DELTA_CLASS */
#define DT_MIPS_DELTA_INSTANCE 0x70000019 /* Delta C++ class instances */
#define DT_MIPS_DELTA_INSTANCE_NO 0x7000001A /* number of entries in DT_MIPS_DELTA_INSTANCE */
#define DT_MIPS_DELTA_RELOC 0x7000001B /* Delta relocations */
#define DT_MIPS_DELTA_RELOC_NO 0x7000001C /* number of entries in DT_MIPS_DELTA_RELOC */
#define DT_MIPS_DELTA_SYM 0x7000001D /* Delta symbols referred by Delta relocations */
#define DT_MIPS_DELTA_SYM_NO 0x7000001E /* number of entries in DT_MIPS_DELTA_SYM */
#define DT_MIPS_DELTA_CLASSSYM 0x70000020 /* Delta symbols for class declarations */
#define DT_MIPS_DELTA_CLASSSYM_NO 0x70000021 /* number of entries in DT_MIPS_DELTA_CLASSSYM */
#define DT_MIPS_CXX_FLAGS 0x70000022 /* C++ flavor flags */
#define DT_MIPS_PIXIE_INIT 0x70000023 /* address of an initialization routine created by pixie */
#define DT_MIPS_SYMBOL_LIB 0x70000024 /* address of .MIPS.symlib section */
#define DT_MIPS_LOCALPAGE_GOTIDX 0x70000025 /* GOT index of first page table entry for a segment */
#define DT_MIPS_LOCAL_GOTIDX 0x70000026 /* GOT index of first page table entry for a local symbol */
#define DT_MIPS_HIDDEN_GOTIDX 0x70000027 /* GOT index of first page table entry for a hidden symbol */
#define DT_MIPS_PROTECTED_GOTIDX 0x70000028 /* GOT index of first page table entry for a protected symbol */
#define DT_MIPS_OPTIONS	0x70000029 /* address of .MIPS.options section */
#define DT_MIPS_INTERFACE 0x7000002A /* address of .MIPS.interface section */
#define DT_MIPS_DYNSTR_ALIGN 0x7000002B /* ??? */
#define DT_MIPS_INTERFACE_SIZE 0x7000002C /* size of .MIPS.interface section */
#define DT_MIPS_RLD_TEXT_RESOLVE_ADDR 0x7000002D /* address of _rld_text_resolve in GOT */
#define DT_MIPS_PERF_SUFFIX 0x7000002E /* default suffix of DSO to be appended by dlopen */
#define DT_MIPS_COMPACT_SIZE 0x7000002F /* size of a ucode compact relocation record (o32) */
#define DT_MIPS_GP_VALUE 0x70000030 /* GP value of a specified GP relative range */
#define DT_MIPS_AUX_DYNAMIC 0x70000031 /* address of an auxiliary dynamic table */
#define DT_MIPS_PLTGOT	0x70000032 /* address of the PLTGOT */
#define DT_MIPS_RLD_OBJ_UPDATE 0x70000033 /* object list update callback */
#define DT_MIPS_RWPLT	0x70000034 /* address of a writable PLT */
#define DT_MIPS_RLD_MAP_REL 0x70000035 /* (GNU) RLD_MAP usable in a PIE */
#define DT_MIPS_XHASH	0x70000036 /* (GNU) GNU-style hash table */ 
#define DT_PPC_GOT	0x70000000 /* value of _GLOBAL_OFFSET_TABLE_ */
#define DT_PPC_TLSOPT	0x70000001 /* TLS descriptor should be optimized */
#define DT_PPC64_GLINK	0x70000000 /* address of .glink section */
#define DT_PPC64_OPD	0x70000001 /* address of .opd section */
#define DT_PPC64_OPDSZ	0x70000002 /* size of .opd section */
#define DT_PPC64_TLSOPT	0x70000003 /* TLS descriptor should be optimized */
#define DT_AUXILIARY	0x7FFFFFFD /* offset of string naming auxiliary filtees */
#define DT_USED		0x7FFFFFFE /* ignored */
#define DT_FILTER	0x7FFFFFFF /* index of string naming filtees */
#define DT_HIPROC	0x7FFFFFFF /* end of processor-specific types */


/* Aliases for dynamic linking entry symbols. */

#define DT_DEPRECATED_SPARC_REGISTER DT_SPARC_REGISTER


/*
 * Flags used in the executable header (field: e_flags).
 */

#define EF_M68K_CPU32	0x00810000U /* low-cost 68020 variant, GNU spelling */
#define EF_M68K_M68000	0x01000000U /* GNU spelling */
#define EF_M68K_CFV4E	0x00008000U /* ColdFire Version 4e */
#define EF_M68K_FIDO	0x02000000U /* real-time optimized variant */

#define EF_M68K_ARCH_MASK 0x03818000U /* bitwise OR of CPU flags */

#define EF_ARM_RELEXEC	0x00000001U /* GNU pre-EABI, deprecated */
#define EF_ARM_HASENTRY	0x00000002U /* e_entry contains a program entry point */
#define EF_ARM_SYMSARESORTED 0x00000004U /* subsection of symbol table is sorted by symbol value */
#define EF_ARM_DYNSYMSUSESEGIDX 0x00000008U /* dynamic symbol st_shndx = containing segment index + 1 */
#define EF_ARM_MAPSYMSFIRST 0x00000010U /* mapping symbols precede other local symbols in symtab */
#define EF_ARM_BE8	0x00800000U /* Executable contains BE-8 code for ARMv6. */
#define EF_ARM_LE8	0x00400000U /* file contains LE-8 code */
#define EF_ARM_EABI_UNKNOWN 0x00000000U /* Unknown or GNU ARM EABI version number */
#define EF_ARM_EABI_VER1 0x01000000U /* ARM EABI version 1 */
#define EF_ARM_EABI_VER2 0x02000000U /* ARM EABI version 2 */
#define EF_ARM_EABI_VER3 0x03000000U /* ARM EABI version 3 */
#define EF_ARM_EABI_VER4 0x04000000U /* ARM EABI version 4 */
#define EF_ARM_EABI_VER5 0x05000000U /* ARM EABI version 5 */
#define EF_ARM_INTERWORK 0x00000004U /* GNU pre-EABI, deprecated */
#define EF_ARM_APCS_26	0x00000008U /* GNU pre-EABI, deprecated */
#define EF_ARM_APCS_FLOAT 0x00000010U /* GNU pre-EABI, deprecated */
#define EF_ARM_PIC	0x00000020U /* GNU pre-EABI, deprecated */
#define EF_ARM_ALIGN8	0x00000040U /* GNU pre-EABI, deprecated */
#define EF_ARM_NEW_ABI	0x00000080U /* GNU pre-EABI, deprecated */
#define EF_ARM_OLD_ABI	0x00000100U /* GNU pre-EABI, deprecated */
#define EF_ARM_ABI_FLOAT_SOFT 0x00000200U /* Object uses the software floating point procedure call standard. */
#define EF_ARM_ABI_FLOAT_HARD 0x00000400U /* Object uses the hardware floating point procedure call standard. */
#define EF_ARM_MAVERICK_FLOAT 0x00000800U /* GNU EABI extension */

#define EF_ARM_EABIMASK	0xFF000000U /* mask for ARM EABI version number (0 denotes GNU or unknown) */
#define EF_ARM_GCCMASK	0x00400FFFU /* Legacy code generated by GCC may use these bits */

#define EF_IA_64_ABI64	0x00000010U /* Object uses the LP64 programming model. */
#define EF_IA_64_REDUCEDFP 0x00000020U /* Object has been compiled with a reduced floating-point model. */
#define EF_IA_64_CONS_GP 0x00000040U /* The global pointer is constant except for indirect function calls. */
#define EF_IA_64_NOFUNCDESC_CONS_GP 0x00000080U /* The global pointer is a program-wide constant. */
#define EF_IA_64_ABSOLUTE 0x00000100U /* The program headers specify the load address. */

#define EF_IA_64_MASKOS	0x00FF000FU /* Bits reserved for OS-specific flags. */
#define EF_IA_64_ARCH	0xFF000000U /* These bits record the minimum architecture level required. */

#define EF_LOONGARCH_ABI_SOFT_FLOAT 0x00000001U /* LoongArch software floating point emulation */
#define EF_LOONGARCH_ABI_SINGLE_FLOAT 0x00000002U /* LoongArch 32-bit floating point registers */
#define EF_LOONGARCH_ABI_DOUBLE_FLOAT 0x00000003U /* LoongArch 64-bit floating point registers */
#define EF_LOONGARCH_OBJABI_V0 0x00000000U /* LoongArch object file ABI version 0 */
#define EF_LOONGARCH_OBJABI_V1 0x00000040U /* LoongArch object file ABI version 1 */

#define EF_LOONGARCH_ABI_MODIFIER_MASK 0x00000007U /* LoongArch floating point modifier mask */
#define EF_LOONGARCH_OBJABI_MASK 0x000000C0U /* LoongArch object file ABI version mask */

#define EF_MIPS_NOREORDER 0x00000001U /* at least one .noreorder directive appeared in the source */
#define EF_MIPS_PIC	0x00000002U /* file contains position independent code */
#define EF_MIPS_CPIC	0x00000004U /* file code uses standard conventions for calling PIC */
#define EF_MIPS_UCODE	0x00000010U /* file contains UCODE (obsolete) */
#define EF_MIPS_ABI2	0x00000020U /* file follows MIPS III 32-bit ABI */
#define EF_MIPS_ABI_O32	0x00001000U /* Original o32 ABI */
#define EF_MIPS_ABI_O64	0x00002000U /* 64-bit extension of o32 */
#define EF_MIPS_ABI_EABI32 0x00003000U /* 32-bit EABI */
#define EF_MIPS_ABI_EABI64 0x00004000U /* 64-bit EABI */
#define EF_MIPS_OPTIONS_FIRST 0x00000080U /* ld(1) should process .MIPS.options section first */
#define EF_MIPS_ARCH_ASE_MDMX 0x08000000U /* file uses MDMX multimedia extensions */
#define EF_MIPS_ARCH_ASE_M16 0x04000000U /* file uses MIPS-16 ISA extensions */
#define EF_MIPS_ARCH_ASE_MICROMIPS 0x02000000U /* MicroMIPS architecture */
#define EF_MIPS_ARCH_1	0x00000000U /* MIPS I instruction set */
#define EF_MIPS_ARCH_2	0x10000000U /* MIPS II instruction set */
#define EF_MIPS_ARCH_3	0x20000000U /* MIPS III instruction set */
#define EF_MIPS_ARCH_4	0x30000000U /* MIPS IV instruction set */
#define EF_MIPS_ARCH_5	0x40000000U /* Never introduced */
#define EF_MIPS_ARCH_32	0x50000000U /* Mips32 Revision 1 */
#define EF_MIPS_ARCH_64	0x60000000U /* Mips64 Revision 1 */
#define EF_MIPS_ARCH_32R2 0x70000000U /* Mips32 Revision 2 */
#define EF_MIPS_ARCH_64R2 0x80000000U /* Mips64 Revision 2 */

#define EF_MIPS_ABI	0x00007000U /* Application binary interface, see EF_MIPS_ARCH_* values */
#define EF_MIPS_ARCH_ASE 0x0F000000U /* file uses application-specific architectural extensions */
#define EF_MIPS_ARCH	0xF0000000U /* 4-bit MIPS architecture field */

#define EF_OR1K_NODELAY	0x00000001U

#define EF_PARISC_TRAPNIL 0x00010000U /* Trap nil pointer deferences */
#define EF_PARISC_EXT	0x00020000U /* Uses a .PARISC.archext section */
#define EF_PARISC_LSB	0x00040000U /* LSB mode */
#define EF_PARISC_WIDE	0x00080000U /* wide mode */
#define EF_PARISC_NO_KABP 0x00100000U /* no kernel-assisted branch prediction */
#define EF_PARISC_LAZYSWAP 0x00200000U /* lazy swap of dynamic segments */
	/* PARISC Architecture versions */
#define EFA_PARISC_1_0	0x0000020BU /* PA-RISC 1.0 */
#define EFA_PARISC_1_1	0x00000210U /* PA-RISC 1.1 */
#define EFA_PARISC_2_0	0x00000214U /* PA-RISC 2.0 */

#define EF_PARISC_ARCH	0x0000FFFFU /* architecture version */

#define EF_PPC_EMB	0x80000000U /* Embedded PowerPC flag */
#define EF_PPC_RELOCATABLE 0x00010000U /* -mrelocatable flag */
#define EF_PPC_RELOCATABLE_LIB 0x00008000U /* -mrelocatable-lib flag */

#define EF_RISCV_RVC	0x00000001U /* Binary uses the C ABI. */
#define EF_RISCV_FLOAT_ABI_SOFT 0x00000000U /* Software emulated floating point */
#define EF_RISCV_FLOAT_ABI_SINGLE 0x00000002U /* Single precision floating point */
#define EF_RISCV_FLOAT_ABI_DOUBLE 0x00000004U /* Double precision floating point */
#define EF_RISCV_FLOAT_ABI_QUAD 0x00000006U /* Quad precision floating point */
#define EF_RISCV_RVE	0x00000008U /* Binary targets the E ABI. */
#define EF_RISCV_TSO	0x00000010U /* Binary requires the RVTSO memory consistency model. */
#define EF_RISCV_RV64ILP32 0x00000020U /* Binary requires RV64ILP32 ABIs. */

#define EF_RISCV_FLOAT_ABI_MASK 0x00000006U /* Bits determining the floating point ABI. */

#define EF_SH_UNKNOWN	0x00000000U
#define EF_SH1		0x00000001U
#define EF_SH2		0x00000002U
#define EF_SH3		0x00000003U
#define EF_SH_DSP	0x00000004U
#define EF_SH3_DSP	0x00000005U
#define EF_SH4AL_DSP	0x00000006U
#define EF_SH3E		0x00000008U
#define EF_SH4		0x00000009U
#define EF_SH2E		0x0000000BU
#define EF_SH4A		0x0000000CU
#define EF_SH2A		0x0000000DU
#define EF_SH4_NOFPU	0x00000010U
#define EF_SH4A_NOFPU	0x00000011U
#define EF_SH4_NOMMU_NOFPU 0x00000012U
#define EF_SH2A_NOFPU	0x00000013U
#define EF_SH3_NOMMU	0x00000014U
#define EF_SH2A_SH4_NOFPU 0x00000015U
#define EF_SH2A_SH3_NOFPU 0x00000016U
#define EF_SH2A_SH4	0x00000017U
#define EF_SH2A_SH3EU	0x00000018U
#define EF_SH_PIC	0x00000100U
#define EF_SH_FDPIC	0x00008000U

#define EF_SH_MACH_MASK	0x0000001FU

#define EF_SPARC_32PLUS	0x00000100U /* Generic V8+ features */
#define EF_SPARC_SUN_US1 0x00000200U /* Sun UltraSPARCTM 1 Extensions */
#define EF_SPARC_HAL_R1	0x00000400U /* HAL R1 Extensions */
#define EF_SPARC_SUN_US3 0x00000800U /* Sun UltraSPARC 3 Extensions */
#define EF_SPARCV9_TSO	0x00000000U /* Total Store Ordering */
#define EF_SPARCV9_PSO	0x00000001U /* Partial Store Ordering */
#define EF_SPARCV9_RMO	0x00000002U /* Relaxed Memory Ordering */

#define EF_SPARC_EXT_MASK 0x00FFFF00U /* SPARC International vendor extension mask */
#define EF_SPARC_32PLUS_MASK 0x00FFFF00U /* mask for V8+ cpu features */
#define EF_SPARCV9_MM	0x00000003U /* Mask for Memory Model */



/*
 * Alternate spellings for executable header flags.
 */

#define EF_CPU32	EF_M68K_CPU32 /* NetBSD spelling */
#define EF_M68000	EF_M68K_M68000 /* NetBSD spelling */

#define EF_ARM_VFP_FLOAT 0x00000400U /* GNU spelling, see EF_ARM_ABI_FLOAT_HARD. */
#define EF_ARM_SOFT_FLOAT 0x00000200U /* GNU spelling, see EF_ARM_FLOAT_SOFT. */

#define EF_MIPS_ARCH_MDMX EF_MIPS_ARCH_ASE_MDMX /* Android, NetBSD */
#define EF_MIPS_ARCH_M16 EF_MIPS_ARCH_ASE_M16 /* Android, NetBSD */

/* NetBSD spellings */
#define EF_SH_SH1	EF_SH1
#define EF_SH_SH2	EF_SH2
#define EF_SH_SH3	EF_SH3
#define EF_SH_SH3_DSP	EF_SH3_DSP
#define EF_SH_SH3E	EF_SH3E
#define EF_SH_SH4	EF_SH4



/*
 * Offsets in the ei_ident[] field of an ELF executable header.
 */

#define EI_MAG0		0 /* magic number */
#define EI_MAG1		1 /* magic number */
#define EI_MAG2		2 /* magic number */
#define EI_MAG3		3 /* magic number */
#define EI_CLASS	4 /* file class */
#define EI_DATA		5 /* data encoding */
#define EI_VERSION	6 /* file version */
#define EI_OSABI	7 /* OS ABI kind */
#define EI_ABIVERSION	8 /* OS ABI version */
#define EI_PAD		9 /* padding start */
#define EI_NIDENT	16 /* total size */


/*
 * The ELF class of an object.
 */

#define ELFCLASSNONE	0U /* Unknown ELF class */
#define ELFCLASS32	1U /* 32 bit objects */
#define ELFCLASS64	2U /* 64 bit objects */


/*
 * Endianness of data in an ELF object.
 */

#define ELFDATANONE	0U /* Unknown data endianness */
#define ELFDATA2LSB	1U /* little endian */
#define ELFDATA2MSB	2U /* big endian */


/*
 * The magic numbers used in the initial four bytes of an ELF object.
 *
 * These numbers are 0x7F, and the characters 'E', 'L' and 'F' encoded
 * in ASCII.
 */

#define ELFMAG0	0x7FU
#define ELFMAG1	0x45U /* 'E' */
#define ELFMAG2	0x4CU /* 'L' */
#define ELFMAG3	0x46U /* 'F' */


/* Additional magic-related constants. */

#define ELFMAG		"\177ELF" /* ELF magic bytes as a string. */
#define SELFMAG		4 /* The number of ELF magic bytes. */


/*
 * ELF OS ABI field.
 */

#define ELFOSABI_NONE	0U /* No extensions or unspecified */
#define ELFOSABI_SYSV	0U /* SYSV */
#define ELFOSABI_HPUX	1U /* Hewlett-Packard HP-UX */
#define ELFOSABI_NETBSD	2U /* NetBSD */
#define ELFOSABI_GNU	3U /* GNU */
#define ELFOSABI_HURD	4U /* GNU/HURD */
#define ELFOSABI_86OPEN	5U /* 86Open Common ABI */
#define ELFOSABI_SOLARIS 6U /* Sun Solaris */
#define ELFOSABI_AIX	7U /* AIX */
#define ELFOSABI_IRIX	8U /* IRIX */
#define ELFOSABI_FREEBSD 9U /* FreeBSD */
#define ELFOSABI_TRU64	10U /* Compaq TRU64 UNIX */
#define ELFOSABI_MODESTO 11U /* Novell Modesto */
#define ELFOSABI_OPENBSD 12U /* Open BSD */
#define ELFOSABI_OPENVMS 13U /* Open VMS */
#define ELFOSABI_NSK	14U /* Hewlett-Packard Non-Stop Kernel */
#define ELFOSABI_AROS	15U /* Amiga Research OS */
#define ELFOSABI_FENIXOS 16U /* The FenixOS highly scalable multi-core OS */
#define ELFOSABI_CLOUDABI 17U /* Nuxi CloudABI */
#define ELFOSABI_OPENVOS 18U /* Stratus Technologies OpenVOS */
#define ELFOSABI_ARM_AEABI 64U /* ARM specific symbol versioning extensions */
#define ELFOSABI_ARM	97U /* ARM ABI */
#define ELFOSABI_STANDALONE 255U /* Standalone (embedded) application */


/* OS ABI Aliases. */

#define ELFOSABI_LINUX	ELFOSABI_GNU
#define ELFOSABI_MONTEREY ELFOSABI_AIX /* Project Monterey */


/*
 * ELF Machine types: (EM_*).
 */

#define EM_NONE		0U /* No machine */
#define EM_M32		1U /* AT&T WE 32100 */
#define EM_SPARC	2U /* SPARC */
#define EM_386		3U /* Intel 80386 */
#define EM_68K		4U /* Motorola 68000 */
#define EM_88K		5U /* Motorola 88000 */
#define EM_IAMCU	6U /* Intel MCU */
#define EM_860		7U /* Intel 80860 */
#define EM_MIPS		8U /* MIPS I Architecture */
#define EM_S370		9U /* IBM System/370 Processor */
#define EM_MIPS_RS3_LE	10U /* MIPS RS3000 Little-endian */
	/* Reserved: 11-14. */
#define EM_PARISC	15U /* Hewlett-Packard PA-RISC */
	/* Reserved: 16. */
#define EM_VPP500	17U /* Fujitsu VPP500 */
#define EM_SPARC32PLUS	18U /* Enhanced instruction set SPARC */
#define EM_960		19U /* Intel 80960 */
#define EM_PPC		20U /* PowerPC */
#define EM_PPC64	21U /* 64-bit PowerPC */
#define EM_S390		22U /* IBM System/390 Processor */
#define EM_SPU		23U /* IBM SPU/SPC */
	/* Reserved: 24-35. */
#define EM_V800		36U /* NEC V800 */
#define EM_FR20		37U /* Fujitsu FR20 */
#define EM_RH32		38U /* TRW RH-32 */
#define EM_RCE		39U /* Motorola RCE */
#define EM_ARM		40U /* Advanced RISC Machines ARM */
#define EM_ALPHA	41U /* Digital Alpha */
#define EM_SH		42U /* Hitachi SH */
#define EM_SPARCV9	43U /* SPARC Version 9 */
#define EM_TRICORE	44U /* Siemens TriCore embedded processor */
#define EM_ARC		45U /* Argonaut RISC Core, Argonaut Technologies Inc. */
#define EM_H8_300	46U /* Hitachi H8/300 */
#define EM_H8_300H	47U /* Hitachi H8/300H */
#define EM_H8S		48U /* Hitachi H8S */
#define EM_H8_500	49U /* Hitachi H8/500 */
#define EM_IA_64	50U /* Intel IA-64 processor architecture */
#define EM_MIPS_X	51U /* Stanford MIPS-X */
#define EM_COLDFIRE	52U /* Motorola ColdFire */
#define EM_68HC12	53U /* Motorola M68HC12 */
#define EM_MMA		54U /* Fujitsu MMA Multimedia Accelerator */
#define EM_PCP		55U /* Siemens PCP */
#define EM_NCPU		56U /* Sony nCPU embedded RISC processor */
#define EM_NDR1		57U /* Denso NDR1 microprocessor */
#define EM_STARCORE	58U /* Motorola Star*Core processor */
#define EM_ME16		59U /* Toyota ME16 processor */
#define EM_ST100	60U /* STMicroelectronics ST100 processor */
#define EM_TINYJ	61U /* Advanced Logic Corp. TinyJ embedded processor family */
#define EM_X86_64	62U /* AMD x86-64 architecture */
#define EM_PDSP		63U /* Sony DSP Processor */
#define EM_PDP10	64U /* Digital Equipment Corp. PDP-10 */
#define EM_PDP11	65U /* Digital Equipment Corp. PDP-11 */
#define EM_FX66		66U /* Siemens FX66 microcontroller */
#define EM_ST9PLUS	67U /* STMicroelectronics ST9+ 8/16 bit microcontroller */
#define EM_ST7		68U /* STMicroelectronics ST7 8-bit microcontroller */
#define EM_68HC16	69U /* Motorola MC68HC16 Microcontroller */
#define EM_68HC11	70U /* Motorola MC68HC11 Microcontroller */
#define EM_68HC08	71U /* Motorola MC68HC08 Microcontroller */
#define EM_68HC05	72U /* Motorola MC68HC05 Microcontroller */
#define EM_SVX		73U /* Silicon Graphics SVx */
#define EM_ST19		74U /* STMicroelectronics ST19 8-bit microcontroller */
#define EM_VAX		75U /* Digital VAX */
#define EM_CRIS		76U /* Axis Communications 32-bit embedded processor */
#define EM_JAVELIN	77U /* Infineon Technologies 32-bit embedded processor */
#define EM_FIREPATH	78U /* Element 14 64-bit DSP Processor */
#define EM_ZSP		79U /* LSI Logic 16-bit DSP Processor */
#define EM_MMIX		80U /* Educational 64-bit processor by Donald Knuth */
#define EM_HUANY	81U /* Harvard University machine-independent object files */
#define EM_PRISM	82U /* SiTera Prism */
#define EM_AVR		83U /* Atmel AVR 8-bit microcontroller */
#define EM_FR30		84U /* Fujitsu FR30 */
#define EM_D10V		85U /* Mitsubishi D10V */
#define EM_D30V		86U /* Mitsubishi D30V */
#define EM_V850		87U /* NEC v850 */
#define EM_M32R		88U /* Mitsubishi M32R */
#define EM_MN10300	89U /* Matsushita MN10300 */
#define EM_MN10200	90U /* Matsushita MN10200 */
#define EM_PJ		91U /* picoJava */
#define EM_OPENRISC	92U /* OpenRISC 32-bit embedded processor */
#define EM_ARC_COMPACT	93U /* ARC International ARCompact processor */
#define EM_XTENSA	94U /* Tensilica Xtensa Architecture */
#define EM_VIDEOCORE	95U /* Alphamosaic VideoCore processor */
#define EM_TMM_GPP	96U /* Thompson Multimedia General Purpose Processor */
#define EM_NS32K	97U /* National Semiconductor 32000 series */
#define EM_TPC		98U /* Tenor Network TPC processor */
#define EM_SNP1K	99U /* Trebia SNP 1000 processor */
#define EM_ST200	100U /* STMicroelectronics (www.st.com) ST200 microcontroller */
#define EM_IP2K		101U /* Ubicom IP2xxx microcontroller family */
#define EM_MAX		102U /* MAX Processor */
#define EM_CR		103U /* National Semiconductor CompactRISC microprocessor */
#define EM_F2MC16	104U /* Fujitsu F2MC16 */
#define EM_MSP430	105U /* Texas Instruments embedded microcontroller msp430 */
#define EM_BLACKFIN	106U /* Analog Devices Blackfin (DSP) processor */
#define EM_SE_C33	107U /* S1C33 Family of Seiko Epson processors */
#define EM_SEP		108U /* Sharp embedded microprocessor */
#define EM_ARCA		109U /* Arca RISC Microprocessor */
#define EM_UNICORE	110U /* Microprocessor series from PKU-Unity Ltd. and MPRC of Peking University */
#define EM_EXCESS	111U /* eXcess: 16/32/64-bit configurable embedded CPU */
#define EM_DXP		112U /* Icera Semiconductor Inc. Deep Execution Processor */
#define EM_ALTERA_NIOS2	113U /* Altera Nios II soft-core processor */
#define EM_CRX		114U /* National Semiconductor CompactRISC CRX microprocessor */
#define EM_XGATE	115U /* Motorola XGATE embedded processor */
#define EM_C166		116U /* Infineon C16x/XC16x processor */
#define EM_M16C		117U /* Renesas M16C series microprocessors */
#define EM_DSPIC30F	118U /* Microchip Technology dsPIC30F Digital Signal Controller */
#define EM_CE		119U /* Freescale Communication Engine RISC core */
#define EM_M32C		120U /* Renesas M32C series microprocessors */
	/* Reserved: 121-130. */
#define EM_TSK3000	131U /* Altium TSK3000 core */
#define EM_RS08		132U /* Freescale RS08 embedded processor */
#define EM_SHARC	133U /* Analog Devices SHARC family of 32-bit DSP processors */
#define EM_ECOG2	134U /* Cyan Technology eCOG2 microprocessor */
#define EM_SCORE7	135U /* Sunplus S+core7 RISC processor */
#define EM_DSP24	136U /* New Japan Radio (NJR) 24-bit DSP Processor */
#define EM_VIDEOCORE3	137U /* Broadcom VideoCore III processor */
#define EM_LATTICEMICO32 138U /* RISC processor for Lattice FPGA architecture */
#define EM_SE_C17	139U /* Seiko Epson C17 family */
#define EM_TI_C6000	140U /* The Texas Instruments TMS320C6000 DSP family */
#define EM_TI_C2000	141U /* The Texas Instruments TMS320C2000 DSP family */
#define EM_TI_C5500	142U /* The Texas Instruments TMS320C55x DSP family */
#define EM_TI_ARP32	143U /* Texas Instruments Application Specific RISC Processor, 32bit fetch */
#define EM_TI_PRU	144U /* Texas Instruments Programmable Realtime Unit */
	/* Reserved: 145-159. */
#define EM_MMDSP_PLUS	160U /* STMicroelectronics 64bit VLIW Data Signal Processor */
#define EM_CYPRESS_M8C	161U /* Cypress M8C microprocessor */
#define EM_R32C		162U /* Renesas R32C series microprocessors */
#define EM_TRIMEDIA	163U /* NXP Semiconductors TriMedia architecture family */
#define EM_QDSP6	164U /* QUALCOMM DSP6 Processor */
#define EM_8051		165U /* Intel 8051 and variants */
#define EM_STXP7X	166U /* STMicroelectronics STxP7x family of configurable and extensible RISC processors */
#define EM_NDS32	167U /* Andes Technology compact code size embedded RISC processor family */
#define EM_ECOG1X	168U /* Cyan Technology eCOG1X family */
#define EM_MAXQ30	169U /* Dallas Semiconductor MAXQ30 Core Micro-controllers */
#define EM_XIMO16	170U /* New Japan Radio (NJR) 16-bit DSP Processor */
#define EM_MANIK	171U /* M2000 Reconfigurable RISC Microprocessor */
#define EM_CRAYNV2	172U /* Cray Inc. NV2 vector architecture */
#define EM_RX		173U /* Renesas RX family */
#define EM_METAG	174U /* Imagination Technologies META processor architecture */
#define EM_MCST_ELBRUS	175U /* MCST Elbrus general purpose hardware architecture */
#define EM_ECOG16	176U /* Cyan Technology eCOG16 family */
#define EM_CR16		177U /* National Semiconductor CompactRISC CR16 16-bit microprocessor */
#define EM_ETPU		178U /* Freescale Extended Time Processing Unit */
#define EM_SLE9X	179U /* Infineon Technologies SLE9X core */
#define EM_L10M		180U /* Intel L10M */
#define EM_K10M		181U /* Intel K10M */
	/* Reserved for future Intel use: 182. */
#define EM_AARCH64	183U /* AArch64 (64-bit ARM) */
	/* Reserved for future ARM use: 184. */
#define EM_AVR32	185U /* Atmel Corporation 32-bit microprocessor family */
#define EM_STM8		186U /* STMicroeletronics STM8 8-bit microcontroller */
#define EM_TILE64	187U /* Tilera TILE64 multicore architecture family */
#define EM_TILEPRO	188U /* Tilera TILEPro multicore architecture family */
#define EM_MICROBLAZE	189U /* Xilinx MicroBlaze 32-bit RISC soft processor core */
#define EM_CUDA		190U /* NVIDIA CUDA architecture */
#define EM_TILEGX	191U /* Tilera TILE-Gx multicore architecture family */
#define EM_CLOUDSHIELD	192U /* CloudShield architecture family */
#define EM_COREA_1ST	193U /* KIPO-KAIST Core-A 1st generation processor family */
#define EM_COREA_2ND	194U /* KIPO-KAIST Core-A 2nd generation processor family */
#define EM_ARC_COMPACT2	195U /* Synopsys ARCompact V2 */
#define EM_OPEN8	196U /* Open8 8-bit RISC soft processor core */
#define EM_RL78		197U /* Renesas RL78 family */
#define EM_VIDEOCORE5	198U /* Broadcom VideoCore V processor */
#define EM_78KOR	199U /* Renesas 78KOR family */
#define EM_56800EX	200U /* Freescale 56800EX Digital Signal Controller */
#define EM_BA1		201U /* Beyond BA1 CPU architecture */
#define EM_BA2		202U /* Beyond BA2 CPU architecture */
#define EM_XCORE	203U /* XMOS xCORE processor family */
#define EM_MCHP_PIC	204U /* Microchip 8-bit PIC(r) family */
#define EM_INTEL205	205U /* Intel Graphics Technology */
#define EM_INTEL206	206U /* Reserved by Intel */
#define EM_INTEL207	207U /* Reserved by Intel */
#define EM_INTEL208	208U /* Reserved by Intel */
#define EM_INTEL209	209U /* Reserved by Intel */
#define EM_KM32		210U /* KM211 KM32 32-bit processor */
#define EM_KMX32	211U /* KM211 KMX32 32-bit processor */
#define EM_KMX16	212U /* KM211 KMX16 16-bit processor */
#define EM_KMX8		213U /* KM211 KMX8 8-bit processor */
#define EM_KVARC	214U /* KM211 KMX32 KVARC processor */
#define EM_CDP		215U /* Paneve CDP architecture family */
#define EM_COGE		216U /* Cognitive Smart Memory Processor */
#define EM_COOL		217U /* Bluechip Systems CoolEngine */
#define EM_NORC		218U /* Nanoradio Optimized RISC */
#define EM_CSR_KALIMBA	219U /* CSR Kalimba architecture family */
#define EM_Z80		220U /* Zilog Z80 */
#define EM_VISIUM	221U /* Controls and Data Services VISIUMcore processor */
#define EM_FT32		222U /* FTDI Chip FT32 high performance 32-bit RISC architecture */
#define EM_MOXIE	223U /* Moxie processor family */
#define EM_AMDGPU	224U /* AMD GPU architecture */
	/* Reserved for future use: 225-242. */
#define EM_RISCV	243U /* RISC-V */
#define EM_LANAI	244U /* Lanai processor */
#define EM_CEVA		245U /* CEVA Processor Architecture Family */
#define EM_CEVA_X2	246U /* CEVA X2 Processor Family */
#define EM_BPF		247U /* Linux BPF – in-kernel virtual machine */
#define EM_GRAPHCORE_IPU 248U /* Graphcore Intelligent Processing Unit */
#define EM_IMG1		249U /* Imagination Technologies */
#define EM_NFP		250U /* Netronome Flow Processor (NFP) */
#define EM_VE		251U /* NEC Vector Engine */
#define EM_CSKY		252U /* C-SKY processor family */
#define EM_ARC_COMPACT3_64 253U /* Synopsys ARCv2.3 64-bit */
#define EM_MCS6502	254U /* MOS Technology MCS 6502 processor */
#define EM_ARC_COMPACT3	255U /* Synopsys ARCv2.3 32-bit */
#define EM_KVX		256U /* Kalray VLIW core of the MPPA processor family */
#define EM_65816	257U /* WDC 65816/65C816 */
#define EM_LOONGARCH	258U /* Loongson LoongArch */
#define EM_KF32		259U /* ChipON KungFu 32 */
#define EM_U16_U8CORE	260U /* LAPIS nX-U16/U8 */
#define EM_TACHYUM	261U /* Reserved for Tachyum processor */
#define EM_56800EF	262U /* NXP 56800EF Digital Signal Controller (DSC) */
#define EM_SBF		263U /* Solana Bytecode Format */
#define EM_AIENGINE	264U /* AMD/Xilinx AIEngine architecture */
#define EM_SIMA_MLA	265U /* SiMa MLA */
#define EM_BANG		266U /* Cambricon BANG */
#define EM_LOONGGPU	267U /* Loongson LoongArch GPU */
#define EM_SW64		268U /* Wuxi Institute of Advanced Technology SW64 */
#define EM_AIECTRLCODE	269U /* AMD/Xilinx AIEngine ctrlcode */
	/* Historical and experimental values.  */
#define EM_ALPHA_HISTORICAL 0x9026U /* Prior value used by GNU and NetBSD */

/* Other synonyms. */

#define EM_486		EM_IAMCU
#define EM_AMD64	EM_X86_64
#define EM_ARC_A5	EM_ARC_COMPACT
#define EM_ECOG1	EM_ECOG1X
#define EM_INTELGT	EM_INTEL205
#define EM_OR1K		EM_OPENRISC /* GNU spelling */
#define EM_OLD_ALPHA	EM_ALPHA /* GNU spelling */


/*
 * ELF file types: (ET_*).
 */

#define ET_NONE		0U /* No file type */
#define ET_REL		1U /* Relocatable object */
#define ET_EXEC		2U /* Executable */
#define ET_DYN		3U /* Shared object */
#define ET_CORE		4U /* Core file */
#define ET_LOOS		0xFE00U /* Begin OS-specific range */
#define ET_HIOS		0xFEFFU /* End OS-specific range */
#define ET_LOPROC	0xFF00U /* Begin processor-specific range */
#define ET_HIPROC	0xFFFFU /* End processor-specific range */


/* ELF file format version numbers. */

#define EV_NONE		0U
#define EV_CURRENT	1U


/*
 * Flags for section groups.
 */

#define GRP_COMDAT	0x1U /* COMDAT semantics */
#define GRP_MASKOS	0x0FF00000U /* OS-specific flags */
#define GRP_MASKPROC	0xF0000000U /* processor-specific flags */


/*
 * Flags / mask for .gnu.versym sections.
 */

#define VERSYM_VERSION	0x7FFFU
#define VERSYM_HIDDEN	0x8000U


/*
 * Flags used by program header table entries.
 */

#define PF_X		0x1 /* Execute */
#define PF_W		0x2 /* Write */
#define PF_R		0x4 /* Read */
#define PF_MASKOS	0x0FF00000 /* OS-specific flags */
#define PF_MASKPROC	0xF0000000 /* Processor-specific flags */
#define PF_ARM_SB	0x10000000 /* segment contains the location addressed by the static base */
#define PF_ARM_PI	0x20000000 /* segment is position-independent */
#define PF_ARM_ABS	0x40000000 /* segment must be loaded at its base address */
#define PF_IA_64_NORECOV 0x80000000 /* segment has speculative instructions without recovery code */
#define PF_PARRISC_SBP	0x08000000 /* segment has code compiled for static branch prediction */


/*
 * Types of program header table entries.
 */

#define PT_NULL		0U /* ignored entry */
#define PT_LOAD		1U /* loadable segment */
#define PT_DYNAMIC	2U /* contains dynamic linking information */
#define PT_INTERP	3U /* names an interpreter */
#define PT_NOTE		4U /* auxiliary information */
#define PT_SHLIB	5U /* reserved */
#define PT_PHDR		6U /* describes the program header itself */
#define PT_TLS		7U /* thread local storage */
#define PT_NUM		8U /* the number of basic PHDR types */
#define PT_LOOS		0x60000000U /* start of OS-specific range */
#define PT_SUNW_UNWIND	0x6464E550U /* Solaris/amd64 stack unwind tables */
#define PT_GNU_EH_FRAME	0x6474E550U /* GCC generated .eh_frame_hdr segment */
#define PT_GNU_STACK	0x6474E551U /* Stack flags */
#define PT_GNU_RELRO	0x6474E552U /* Segment becomes read-only after relocation */
#define PT_OPENBSD_RANDOMIZE 0x65A3DBE6U /* Segment filled with random data */
#define PT_OPENBSD_WXNEEDED 0x65A3DBE7U /* Program violates W^X */
#define PT_OPENBSD_BOOTDATA 0x65A41BE6U /* Boot data */
#define PT_SUNWBSS	0x6FFFFFFAU /* A Solaris .SUNW_bss section */
#define PT_SUNWSTACK	0x6FFFFFFBU /* A Solaris process stack */
#define PT_SUNWDTRACE	0x6FFFFFFCU /* Used by dtrace(1) */
#define PT_SUNWCAP	0x6FFFFFFDU /* Special hardware capability requirements */
#define PT_HIOS		0x6FFFFFFFU /* end of OS-specific range */
#define PT_LOPROC	0x70000000U /* start of processor-specific range */
#define PT_AARCH64_ARCHEXT 0x70000000U /* platform architecture compatibility information */
#define PT_AARCH64_UNWIND 0x70000001U /* exception unwinding tables */
#define PT_AARCH64_MEMTAG_MTE 0x70000002U /* MTE memory tag data dumps in core files */
#define PT_ARM_ARCHEXT	0x70000000U /* platform architecture compatibility information */
#define PT_ARM_EXIDX	0x70000001U /* exception unwind tables */
#define PT_MIPS_REGINFO	0x70000000U /* register usage information */
#define PT_MIPS_RTPROC	0x70000001U /* runtime procedure table */
#define PT_MIPS_OPTIONS	0x70000002U /* options segment */
#define PT_MIPS_ABIFLAGS 0x70000003U /* segment contains a .MIPS.abiflags section */
#define PT_PARISC_ARCHEXT 0x70000000U /* segment contains the .PARISC.archext section */
#define PT_PARISC_UNWIND 0x70000001U /* segment contains the .unwind section */
#define PT_HIPROC	0x7FFFFFFFU /* end of processor-specific range */

/* synonyms. */

#define PT_ARM_UNWIND	PT_ARM_EXIDX
#define PT_HISUNW	PT_HIOS
#define PT_LOSUNW	PT_SUNWBSS


/*
 * Platform-specific flags.
 */

#define PT_ARM_ARCHEXT_FMTMSK 0xFF000000U /* Mask bits describing the format of subsequent data */
#define PT_ARM_ARCHEXT_PROFMSK 0x00FF0000U /* Mask bits describing the architecture profile required */
#define PT_ARM_ARCHEXT_ARCHMSK 0x000000FFU /* Mask bits describing the base architecture required */
#define PT_ARM_ARCHEXT_FMT_OS 0x00000000U /* No additional words of data */
#define PT_ARM_ARCHEXT_FMT_ABI 0x01000000U /* ABI format defines the following words of data */
#define PT_ARM_ARCHEXT_PROF_NONE 0x00000000U /* No profile-specific constraints */
#define PT_ARM_ARCHEXT_PROF_ARM 0x00410000U /* Executable requires the Application profile */
#define PT_ARM_ARCHEXT_PROF_RT 0x00520000U /* Executable requires the Real-Time profile */
#define PT_ARM_ARCHEXT_PROF_MC 0x004D0000U /* Executable requires the Microcontroller profile */
#define PT_ARM_ARCHEXT_PROF_CLASSIC 0x00530000U /* Executable requires the A or R profile exception model */
#define PT_ARM_ARCHEXT_ARCH_UNKNOWN 0x00000000U /* Unspecified architecture */
#define PT_ARM_ARCHEXT_ARCHv4 0x00000001U /* Architecture v4 */
#define PT_ARM_ARCHEXT_ARCHv4T 0x00000002U /* Architecture v4T */
#define PT_ARM_ARCHEXT_ARCHv5T 0x00000003U /* Architecture v5T */
#define PT_ARM_ARCHEXT_ARCHv5TE 0x00000004U /* Architecture v5TE */
#define PT_ARM_ARCHEXT_ARCHv5TEJ 0x00000005U /* Architecture v5TE */
#define PT_ARM_ARCHEXT_ARCHv6 0x00000006U /* Architecture v6 */
#define PT_ARM_ARCHEXT_ARCHv6KZ 0x00000007U /* Architecture v6KZ */
#define PT_ARM_ARCHEXT_ARCHv6T2 0x00000008U /* Architecture v6KT2 */
#define PT_ARM_ARCHEXT_ARCHv6K 0x00000009U /* Architecture v6K */
#define PT_ARM_ARCHEXT_ARCHv7 0x0000000AU /* Architecture v7 */
#define PT_ARM_ARCHEXT_ARCHv6M 0x0000000BU /* Architecture v6M */
#define PT_ARM_ARCHEXT_ARCHv6SM 0x0000000CU /* Architecture v6S-M */
#define PT_ARM_ARCHEXT_ARCHv7EM 0x0000000DU /* Architecture v7E-M */

#define PT_IA_64_ARCHEXT 0x70000000U /* segment contains a section of type SHT_IA64_EXT */
#define PT_IA_64_UNWIND	0x70000001U /* section contains stack unwind tables */



/*
 * Section flags.
 */

#define SHF_WRITE	0x00000001U /* writable during program execution */
#define SHF_ALLOC	0x00000002U /* occupies memory during program execution */
#define SHF_EXECINSTR	0x00000004U /* executable instructions */
#define SHF_MERGE	0x00000010U /* may be merged to prevent duplication */
#define SHF_STRINGS	0x00000020U /* NUL-terminated character strings */
#define SHF_INFO_LINK	0x00000040U /* the sh_info field holds a link */
#define SHF_LINK_ORDER	0x00000080U /* special ordering requirements during linking */
#define SHF_OS_NONCONFORMING 0x00000100U /* requires OS-specific processing during linking */
#define SHF_GROUP	0x00000200U /* member of a section group */
#define SHF_TLS		0x00000400U /* holds thread-local storage */
#define SHF_COMPRESSED	0x00000800U /* holds compressed data */
#define SHF_MASKOS	0x0FF00000U /* bits reserved for OS-specific semantics */
#define SHF_AMD64_LARGE	0x10000000U /* section uses large code model */
#define SHF_ENTRYSECT	0x10000000U /* section contains an entry point (ARM) */
#define SHF_ARM_PURECODE 0x20000000U /* section has only code without data (ARM) */
#define SHF_COMDEF	0x80000000U /* section may be multiply defined in input to link step (ARM) */
#define SHF_IA_64_SHORT	0x10000000U /* section must be placed near GP */
#define SHF_IA_64_NORECOV 0x20000000U /* section uses speculative instructions without recovery code */
#define SHF_MIPS_GPREL	0x10000000U /* section must be part of global data area */
#define SHF_MIPS_MERGE	0x20000000U /* section data should be merged to eliminate duplication */
#define SHF_MIPS_ADDR	0x40000000U /* section data is addressed by default */
#define SHF_MIPS_STRING	0x80000000U /* section data is string data by default */
#define SHF_MIPS_NOSTRIP 0x08000000U /* section data may not be stripped */
#define SHF_MIPS_LOCAL	0x04000000U /* section data local to process */
#define SHF_MIPS_NAMES	0x02000000U /* linker must generate implicit hidden weak names */
#define SHF_MIPS_NODUPE	0x01000000U /* linker must retain only one copy */
#define SHF_PARISC_SBP	0x80000000U /* code compiled for static branch prediction */
#define SHF_PARISC_HUGE	0x40000000U /* section should be allocated far from GP */
#define SHF_PARISC_SHORT 0x20000000U /* section should be allocated near GP */
#define SHF_ORDERED	0x40000000U /* section is ordered with respect to other sections */
#define SHF_EXCLUDE	0x80000000U /* section is excluded from executables and shared objects */
#define SHF_MASKPROC	0xF0000000U /* bits reserved for processor-specific semantics */


/*
 * Special section indices.
 */

#define SHN_UNDEF	0U /* undefined section */
#define SHN_LORESERVE	0xFF00U /* start of reserved area */
#define SHN_LOPROC	0xFF00U /* start of processor-specific range */
#define SHN_BEFORE	0xFF00U /* used for section ordering */
#define SHN_AFTER	0xFF01U /* used for section ordering */
#define SHN_AMD64_LCOMMON 0xFF02U /* large common block label */
#define SHN_MIPS_ACOMMON 0xFF00U /* allocated common symbols in a DSO */
#define SHN_MIPS_TEXT	0xFF01U /* Reserved (obsolete) */
#define SHN_MIPS_DATA	0xFF02U /* Reserved (obsolete) */
#define SHN_MIPS_SCOMMON 0xFF03U /* gp-addressable common symbols */
#define SHN_MIPS_SUNDEFINED 0xFF04U /* gp-addressable undefined symbols */
#define SHN_MIPS_LCOMMON 0xFF05U /* local common symbols */
#define SHN_MIPS_LUNDEFINED 0xFF06U /* local undefined symbols */
#define SHN_PARISC_ANSI_COMMON 0xFF00U /* symbol is tentative */
#define SHN_PARISC_HUGE_COMMON 0xFF01U /* symbol denotes a huge-memory common block */
#define SHN_HIPROC	0xFF1FU /* end of processor-specific range */
#define SHN_LOOS	0xFF20U /* start of OS-specific range */
#define SHN_SUNW_IGNORE	0xFF3FU /* used by dtrace */
#define SHN_HIOS	0xFF3FU /* end of OS-specific range */
#define SHN_ABS		0xFFF1U /* absolute references */
#define SHN_COMMON	0xFFF2U /* references to COMMON areas */
#define SHN_XINDEX	0xFFFFU /* extended index */
#define SHN_HIRESERVE	0xFFFFU /* end of reserved area */


/*
 * Section types.
 */

#define SHT_NULL	0U /* inactive header */
#define SHT_PROGBITS	1U /* program defined information */
#define SHT_SYMTAB	2U /* symbol table */
#define SHT_STRTAB	3U /* string table */
#define SHT_RELA	4U /* relocation entries with addends */
#define SHT_HASH	5U /* symbol hash table */
#define SHT_DYNAMIC	6U /* information for dynamic linking */
#define SHT_NOTE	7U /* additional notes */
#define SHT_NOBITS	8U /* section occupying no space */
#define SHT_REL		9U /* relocation entries without addends */
#define SHT_SHLIB	10U /* reserved */
#define SHT_DYNSYM	11U /* symbol table */
#define SHT_INIT_ARRAY	14U /* pointers to initialization functions */
#define SHT_FINI_ARRAY	15U /* pointers to termination functions */
#define SHT_PREINIT_ARRAY 16U /* pointers to functions called before initialization */
#define SHT_GROUP	17U /* defines a section group */
#define SHT_SYMTAB_SHNDX 18U /* used for extended section numbering */
#define SHT_RELR	19U /* used to encode relative relocations */
#define SHT_LOOS	0x60000000U /* start of OS-specific range */
#define SHT_GNU_INCREMENTAL_INPUTS 0x6FFFF4700U /* incremental build information */
#define SHT_SUNW_dof	0x6FFFFFF4U /* used by dtrace */
#define SHT_SUNW_cap	0x6FFFFFF5U /* capability requirements */
#define SHT_GNU_ATTRIBUTES 0x6FFFFFF5U /* object attributes */
#define SHT_SUNW_SIGNATURE 0x6FFFFFF6U /* module verification signature */
#define SHT_GNU_HASH	0x6FFFFFF6U /* GNU Hash sections */
#define SHT_GNU_LIBLIST	0x6FFFFFF7U /* List of libraries to be prelinked */
#define SHT_PARISC_EXT	0x70000000U /* product-specific extension bits */
#define SHT_PARISC_UNWIND 0x70000001U /* unwind table entries */
#define SHT_PARISC_DOC	0x70000002U /* debug information for optimized code */
#define SHT_SUNW_ANNOTATE 0x6FFFFFF7U /* special section where unresolved references are allowed */
#define SHT_SUNW_DEBUGSTR 0x6FFFFFF8U /* debugging information */
#define SHT_CHECKSUM	0x6FFFFFF8U /* checksum for dynamic shared objects */
#define SHT_SUNW_DEBUG	0x6FFFFFF9U /* debugging information */
#define SHT_SUNW_move	0x6FFFFFFAU /* information to handle partially initialized symbols */
#define SHT_SUNW_COMDAT	0x6FFFFFFBU /* section supporting merging of multiple copies of data */
#define SHT_SUNW_syminfo 0x6FFFFFFCU /* additional symbol information */
#define SHT_SUNW_verdef	0x6FFFFFFDU /* symbol versioning information */
#define SHT_SUNW_verneed 0x6FFFFFFEU /* symbol versioning requirements */
#define SHT_SUNW_versym	0x6FFFFFFFU /* symbol versioning table */
#define SHT_HIOS	0x6FFFFFFFU /* end of OS-specific range */
#define SHT_LOPROC	0x70000000U /* start of processor-specific range */
#define SHT_AARCH64_ATTRIBUTES 0x70000003U /* object file compatibility attributes */
#define SHT_AARCH64_AUTH_RELR 0x70000004U /* compressed signed relative relocations */
#define SHT_AARCH64_AUTH_SYM 0x70000005U /* symbol signing information */
#define SHT_AARCH64_MEMTAG_GLOBALS_STATIC 0x70000007U /* used to tag global variables */
#define SHT_AARCH64_MEMTAG_GLOBALS_DYNAMIC 0x70000008U /* used to tag global variables */
#define SHT_ARM_EXIDX	0x70000001U /* exception index table */
#define SHT_ARM_PREEMPTMAP 0x70000002U /* BPABI DLL dynamic linking preemption map */
#define SHT_ARM_ATTRIBUTES 0x70000003U /* object file compatibility attributes */
#define SHT_ARM_DEBUGOVERLAY 0x70000004U /* overlay debug information */
#define SHT_ARM_OVERLAYSECTION 0x70000005U /* overlay debug information */
#define SHT_IA_64_EXT	0x70000000U /* section has product-specific extension bits */
#define SHT_IA_64_UNWIND 0x70000001U /* section contains stack unwinding tables */
#define SHT_IA_64_LOPSREG 0x78000000U /* start of range for implementation-specific section types */
#define SHT_IA_64_HIPSREG 0x7FFFFFFFU /* end of range for implementation-specific section types */
#define SHT_IA_64_PRIORITY_INIT 0x79000000U /* section contains priority initialization records */
#define SHT_MIPS_LIBLIST 0x70000000U /* DSO library information used in link */
#define SHT_MIPS_MSYM	0x70000001U /* MIPS symbol table extension */
#define SHT_MIPS_CONFLICT 0x70000002U /* symbol conflicting with DSO-defined symbols  */
#define SHT_MIPS_GPTAB	0x70000003U /* global pointer table */
#define SHT_MIPS_UCODE	0x70000004U /* reserved */
#define SHT_MIPS_DEBUG	0x70000005U /* reserved (obsolete debug information) */
#define SHT_MIPS_REGINFO 0x70000006U /* register usage information */
#define SHT_MIPS_PACKAGE 0x70000007U /* OSF reserved */
#define SHT_MIPS_PACKSYM 0x70000008U /* OSF reserved */
#define SHT_MIPS_RELD	0x70000009U /* dynamic relocation */
#define SHT_MIPS_IFACE	0x7000000BU /* subprogram interface information */
#define SHT_MIPS_CONTENT 0x7000000CU /* section content classification */
#define SHT_MIPS_OPTIONS 0x7000000DU /* general options */
#define SHT_MIPS_DELTASYM 0x7000001BU /* Delta C++: symbol table */
#define SHT_MIPS_DELTAINST 0x7000001CU /* Delta C++: instance table */
#define SHT_MIPS_DELTACLASS 0x7000001DU /* Delta C++: class table */
#define SHT_MIPS_DWARF	0x7000001EU /* DWARF debug information */
#define SHT_MIPS_DELTADECL 0x7000001FU /* Delta C++: declarations */
#define SHT_MIPS_SYMBOL_LIB 0x70000020U /* symbol-to-library mapping */
#define SHT_MIPS_EVENTS	0x70000021U /* event locations */
#define SHT_MIPS_TRANSLATE 0x70000022U /* ??? */
#define SHT_MIPS_PIXIE	0x70000023U /* special pixie sections */
#define SHT_MIPS_XLATE	0x70000024U /* address translation table */
#define SHT_MIPS_XLATE_DEBUG 0x70000025U /* SGI internal address translation table */
#define SHT_MIPS_WHIRL	0x70000026U /* intermediate code */
#define SHT_MIPS_EH_REGION 0x70000027U /* C++ exception handling region info */
#define SHT_MIPS_XLATE_OLD 0x70000028U /* obsolete */
#define SHT_MIPS_PDR_EXCEPTION 0x70000029U /* runtime procedure descriptor table exception information */
#define SHT_MIPS_ABIFLAGS 0x7000002AU /* ABI flags */
#define SHT_MIPS_XHASH	0x7000002BU /* GNU-style hash table */
#define SHT_SPARC_GOTDATA 0x70000000U /* SPARC-specific data */
#define SHT_X86_64_UNWIND 0x70000001U /* unwind tables for the AMD64 */
#define SHT_ORDERED	0x7FFFFFFFU /* sort entries in the section */
#define SHT_HIPROC	0x7FFFFFFFU /* end of processor-specific range */
#define SHT_LOUSER	0x80000000U /* start of application-specific range */
#define SHT_HIUSER	0xFFFFFFFFU /* end of application-specific range */

/* Aliases for section types. */

#define SHT_AMD64_UNWIND SHT_X86_64_UNWIND
#define SHT_GNU_verdef	SHT_SUNW_verdef
#define SHT_GNU_verneed	SHT_SUNW_verneed
#define SHT_GNU_versym	SHT_SUNW_versym


#define	PN_XNUM			0xFFFFU /* Use extended section numbering. */

/*
 * Special indices into symbol tables.
 */
#define STN_UNDEF	0 /* undefined symbol */


/*
 * Symbol binding information.
 */

#define STB_LOCAL	0 /* not visible outside defining object file */
#define STB_GLOBAL	1 /* visible across all object files being combined */
#define STB_WEAK	2 /* visible across all object files but with low precedence */
#define STB_LOOS	10 /* start of OS-specific range */
#define STB_GNU_UNIQUE	10 /* unique symbol (GNU) */
#define STB_HIOS	12 /* end of OS-specific range */
#define STB_LOPROC	13 /* start of processor-specific range */
#define STB_SPLIT_COMMON 13 /* (MIPS64) split common symbol */
#define STB_HIPROC	15 /* end of processor-specific range */


/*
 * Symbol types
 */

#define STT_NOTYPE	0 /* unspecified type */
#define STT_OBJECT	1 /* data object */
#define STT_FUNC	2 /* executable code */
#define STT_SECTION	3 /* section */
#define STT_FILE	4 /* source file */
#define STT_COMMON	5 /* uninitialized common block */
#define STT_TLS		6 /* thread local storage */
#define STT_LOOS	10 /* start of OS-specific types */
#define STT_GNU_IFUNC	10 /* indirect function */
#define STT_HIOS	12 /* end of OS-specific types */
#define STT_LOPROC	13 /* start of processor-specific types */
#define STT_ARM_TFUNC	13 /* Thumb function (GNU) */
#define STT_ARM_16BIT	15 /* Thumb label (GNU) */
#define STT_PARISC_MILLI 13 /* entry point of a millicode routine */
#define STT_SPARC_REGISTER 13 /* SPARC register information */
#define STT_HIPROC	15 /* end of processor-specific types */

/* Additional constants related to symbol types. */

#define STT_NUM		7 /* the number of symbol types */


/*
 * Symbol visibility.
 */

#define STV_DEFAULT	0 /* as specified by symbol type */
#define STV_INTERNAL	1 /* as defined by processor semantics */
#define STV_HIDDEN	2 /* hidden from other components */
#define STV_PROTECTED	3 /* local references are not preemptable */
#define STV_EXPORTED	4 /* symbol is always global */
#define STV_SINGLETON	5 /* all references to this symbol bind to a single instance */
#define STV_ELIMINATE	6 /* symbol is not to be added to the dynamic symbol table */


/*
 * Syminfo flags.
 */

#define SYMINFO_FLG_DIRECT 0x0001U /* directly assocated reference */
#define SYMINFO_FLG_FILTER 0x0002U /* associated with a filter */
#define SYMINFO_FLG_COPY 0x0004U /* definition by copy-relocation */
#define SYMINFO_FLG_LAZYLOAD 0x0008U /* object should be lazily loaded */
#define SYMINFO_FLG_DIRECTBIND 0x0010U /* reference should be directly bound */
#define SYMINFO_FLG_NOEXTDIRECT 0x0020U /* external references not allowed to bind to definition */
#define SYMINFO_FLG_AUXILIARY 0x0040U /* auxiliary filter */
#define SYMINFO_FLG_INTERPOSE 0x0080U /* interposer symbol */
#define SYMINFO_FLG_CAP	0x0100U /* associated with capabilities */
#define SYMINFO_FLG_DEFERRED 0x0200U /* deferred reference */
#define SYMINFO_FLG_WEAKFILTER 0x0400U /* weak filter */

#define SYMINFO_FLG_PASSTHRU SYMINFO_FLG_FILTER /* GNU spelling */


/*
 * Syminfo bindigs.
 */

#define SYMINFO_BT_SELF	0xFFFFU /* bound to self */
#define SYMINFO_BT_PARENT 0xFFFEU /* bound to parent */
#define SYMINFO_BT_NONE	0xFFFDU /* no special binding */
#define SYMINFO_BT_EXTERN 0xFFFCU /* defined as external */
#define SYMINFO_BT_LOWRESERVE 0xFF00U /* start of reserved entries */


/*
 * Syminfo section versions.
 */

#define SYMINFO_NONE	0 /* no version */
#define SYMINFO_CURRENT	1 /* current version */
#define SYMINFO_NUM	2 /* (GNU) */


/*
 * Versioning dependencies.
 */

#define VER_NDX_LOCAL	0 /* local scope */
#define VER_NDX_GLOBAL	1 /* global scope */
#define VER_NDX_GIVEN	2 /* global, with user-specified versioning */


/*
 * Versioning flags.
 */

#define VER_FLG_BASE	0x1 /* file version */
#define VER_FLG_WEAK	0x2 /* weak version */
#define VER_FLG_INFO	0x4 /* informational-only version */


/*
 * Versioning needs
 */

#define VER_NEED_NONE	0 /* invalid version */
#define VER_NEED_CURRENT 1 /* current version */


/*
 * Versioning numbers.
 */

#define VER_DEF_NONE	0 /* invalid version */
#define VER_DEF_CURRENT	1 /* current version */


/**
 ** Relocation types.
 **/


/* EM_386 */
#define R_386_NONE	0
#define R_386_32	1
#define R_386_PC32	2
#define R_386_GOT32	3
#define R_386_PLT32	4
#define R_386_COPY	5
#define R_386_GLOB_DAT	6
#define R_386_JUMP_SLOT	7
#define R_386_RELATIVE	8
#define R_386_GOTOFF	9
#define R_386_GOTPC	10
#define R_386_32PLT	11
	/* unused: 12-13 */
#define R_386_TLS_TPOFF	14
#define R_386_TLS_IE	15
#define R_386_TLS_GOTIE	16
#define R_386_TLS_LE	17
#define R_386_TLS_GD	18
#define R_386_TLS_LDM	19
#define R_386_16	20
#define R_386_PC16	21
#define R_386_8		22
#define R_386_PC8	23
#define R_386_TLS_GD_32	24
#define R_386_TLS_GD_PUSH 25
#define R_386_TLS_GD_CALL 26
#define R_386_TLS_GD_POP 27
#define R_386_TLS_LDM_32 28
#define R_386_TLS_LDM_PUSH 29
#define R_386_TLS_LDM_CALL 30
#define R_386_TLS_LDM_POP 31
#define R_386_TLS_LDO_32 32
#define R_386_TLS_IE_32	33
#define R_386_TLS_LE_32	34
#define R_386_TLS_DTPMOD32 35
#define R_386_TLS_DTPOFF32 36
#define R_386_TLS_TPOFF32 37
#define R_386_SIZE32	38
#define R_386_TLS_GOTDESC 39
#define R_386_TLS_DESC_CALL 40
#define R_386_TLS_DESC	41
#define R_386_IRELATIVE	42
#define R_386_GOT32X	43


#define R_68K_NONE	0
#define R_68K_32	1
#define R_68K_16	2
#define R_68K_8		3
#define R_68K_PC32	4
#define R_68K_PC16	5
#define R_68K_PC8	6
#define R_68K_GOT32	7
#define R_68K_GOT16	8
#define R_68K_GOT8	9
#define R_68K_GOT32O	10
#define R_68K_GOT16O	11
#define R_68K_GOT8O	12
#define R_68K_PLT32	13
#define R_68K_PLT16	14
#define R_68K_PLT8	15
#define R_68K_PLT32O	16
#define R_68K_PLT16O	17
#define R_68K_PLT8O	18
#define R_68K_COPY	19
#define R_68K_GLOB_DAT	20
#define R_68K_JMP_SLOT	21
#define R_68K_RELATIVE	22
	/* TLS relocations */
#define R_68K_TLS_GD32	25
#define R_68K_TLS_GD16	26
#define R_68K_TLS_GD8	27
#define R_68K_TLS_LDM32	28
#define R_68K_TLS_LDM16	29
#define R_68K_TLS_LDM8	30
#define R_68K_TLS_LDO32	31
#define R_68K_TLS_LDO16	32
#define R_68K_TLS_LDO8	33
#define R_68K_TLS_IE32	34
#define R_68K_TLS_IE16	35
#define R_68K_TLS_IE8	36
#define R_68K_TLS_LE32	37
#define R_68K_TLS_LE16	38
#define R_68K_TLS_LE8	39
#define R_68K_TLS_DTPMOD32 40
#define R_68K_TLS_DTPREL32 41
#define R_68K_TLS_TPREL32 42


/* EM_AARCH64 */
#define R_AARCH64_NONE	0
#define R_AARCH64_P32_ABS32 1
#define R_AARCH64_P32_ABS16 2
#define R_AARCH64_P32_PREL32 3
#define R_AARCH64_P32_PREL16 4
#define R_AARCH64_P32_MOVW_UABS_G0 5
#define R_AARCH64_P32_MOVW_UABS_G0_NC 6
#define R_AARCH64_P32_MOVW_UABS_G1 7
#define R_AARCH64_P32_MOVW_SABS_G0 8
#define R_AARCH64_P32_LD_PREL_LO19 9
#define R_AARCH64_P32_ADR_PREL_LO21 10
#define R_AARCH64_P32_ADR_PREL_PG_HI21 11
#define R_AARCH64_P32_ADD_ABS_LO12_NC 12
#define R_AARCH64_P32_LDST8_ABS_LO12_NC 13
#define R_AARCH64_P32_LDST16_ABS_LO12_NC 14
#define R_AARCH64_P32_LDST32_ABS_LO12_NC 15
#define R_AARCH64_P32_LDST64_ABS_LO12_NC 16
#define R_AARCH64_P32_LDST128_ABS_LO12_NC 17
#define R_AARCH64_P32_TSTBR14 18
#define R_AARCH64_P32_CONDBR19 19
#define R_AARCH64_P32_JUMP26 20
#define R_AARCH64_P32_CALL26 21
#define R_AARCH64_P32_MOVW_PREL_G0 22
#define R_AARCH64_P32_MOVW_PREL_G0_NC 23
#define R_AARCH64_P32_MOVW_PREL_G1 24
#define R_AARCH64_P32_GOT_LD_PREL19 25
#define R_AARCH64_P32_ADR_GOT_PAGE 26
#define R_AARCH64_P32_LD32_GOT_LO12_NC 27
#define R_AARCH64_P32_LD32_GOTPAGE_LO14 28
#define R_AARCH64_P32_PLT32 29
	/* Unused: 30-79. */
#define R_AARCH64_P32_TLSGD_ADR_PREL21 80
#define R_AARCH64_P32_TLSGD_ADR_PAGE21 81
#define R_AARCH64_P32_TLSGD_ADD_LO12_NC 82
#define R_AARCH64_P32_TLSLD_ADR_PREL21 83
#define R_AARCH64_P32_TLSLD_ADR_PAGE21 84
#define R_AARCH64_P32_TLSLD_ADD_LO12_NC 85
#define R_AARCH64_P32_TLSLD_LD_PREL19 86
#define R_AARCH64_P32_TLSLD_MOVW_DTPREL_G1 87
#define R_AARCH64_P32_TLSLD_MOVW_DTPREL_G0 88
#define R_AARCH64_P32_TLSLD_MOVW_DTPREL_G0_NC 89
#define R_AARCH64_P32_TLSLD_ADD_DTPREL_HI12 90
#define R_AARCH64_P32_TLSLD_ADD_DTPREL_LO12 91
#define R_AARCH64_P32_TLSLD_ADD_DTPREL_LO12_NC 92
#define R_AARCH64_P32_TLSLD_LDST8_DTPREL_LO12 93
#define R_AARCH64_P32_TLSLD_LDST8_DTPREL_LO12_NC 94
#define R_AARCH64_P32_TLSLD_LDST16_DTPREL_LO12 95
#define R_AARCH64_P32_TLSLD_LDST16_DTPREL_LO12_NC 96
#define R_AARCH64_P32_TLSLD_LDST32_DTPREL_LO12 97
#define R_AARCH64_P32_TLSLD_LDST32_DTPREL_LO12_NC 98
#define R_AARCH64_P32_TLSLD_LDST64_DTPREL_LO12 99
#define R_AARCH64_P32_TLSLD_LDST64_DTPREL_LO12_NC 100
#define R_AARCH64_P32_TLSLD_LDST128_DTPREL_LO12 101
#define R_AARCH64_P32_TLSLD_LDST128_DTPREL_LO12_NC 102
#define R_AARCH64_P32_TLSIE_ADR_GOTTPREL_PAGE21 103
#define R_AARCH64_P32_TLSIE_LD32_GOTTPREL_LO12_NC 104
#define R_AARCH64_P32_TLSIE_LD_GOTTPREL_PREL19 105
#define R_AARCH64_P32_TLSLE_MOVW_TPREL_G1 106
#define R_AARCH64_P32_TLSLE_MOVW_TPREL_G0 107
#define R_AARCH64_P32_TLSLE_MOVW_TPREL_G0_NC 108
#define R_AARCH64_P32_TLSLE_ADD_TPREL_HI12 109
#define R_AARCH64_P32_TLSLE_ADD_TPREL_LO12 110
#define R_AARCH64_P32_TLSLE_ADD_TPREL_LO12_NC 111
#define R_AARCH64_P32_TLSLE_LDST8_TPREL_LO12 112
#define R_AARCH64_P32_TLSLE_LDST8_TPREL_LO12_NC 113
#define R_AARCH64_P32_TLSLE_LDST16_TPREL_LO12 114
#define R_AARCH64_P32_TLSLE_LDST16_TPREL_LO12_NC 115
#define R_AARCH64_P32_TLSLE_LDST32_TPREL_LO12 116
#define R_AARCH64_P32_TLSLE_LDST32_TPREL_LO12_NC 117
#define R_AARCH64_P32_TLSLE_LDST64_TPREL_LO12 118
#define R_AARCH64_P32_TLSLE_LDST64_TPREL_LO12_NC 119
#define R_AARCH64_P32_TLSLE_LDST128_TPREL_LO12 120
#define R_AARCH64_P32_TLSLE_LDST128_TPREL_LO12_NC 121
#define R_AARCH64_P32_TLSDESC_LD_PREL19 122
#define R_AARCH64_P32_TLSDESC_ADR_PREL21 123
#define R_AARCH64_P32_TLSDESC_ADR_PAGE21 124
#define R_AARCH64_P32_TLSDESC_LD32_LO12 125
#define R_AARCH64_P32_TLSDESC_ADD_LO12 126
#define R_AARCH64_P32_TLSDESC_CALL 127
	/* Unused: 128-179. */
#define R_AARCH64_P32_COPY 180
#define R_AARCH64_P32_GLOB_DAT 181
#define R_AARCH64_P32_JUMP_SLOT 182
#define R_AARCH64_P32_RELATIVE 183
#define R_AARCH64_P32_TLS_IMPDEF1 184 /* R_AARCH64_P32_TLS_DTPREL or R_AARCH64_P32_TLS_DTPMOD. */
#define R_AARCH64_P32_TLS_IMPDEF2 185 /* R_AARCH64_P32_TLS_DTPMOD or R_AARCH64_P32_TLS_DTPREL. */
#define R_AARCH64_P32_TLS_TPREL 186
#define R_AARCH64_P32_TLSDESC 187
#define R_AARCH64_P32_IRELATIVE 188
	/* Unused: 189-256. */
#define R_AARCH64_ABS64	257
#define R_AARCH64_ABS32	258
#define R_AARCH64_ABS16	259
#define R_AARCH64_PREL64 260
#define R_AARCH64_PREL32 261
#define R_AARCH64_PREL16 262
#define R_AARCH64_MOVW_UABS_G0 263
#define R_AARCH64_MOVW_UABS_G0_NC 264
#define R_AARCH64_MOVW_UABS_G1 265
#define R_AARCH64_MOVW_UABS_G1_NC 266
#define R_AARCH64_MOVW_UABS_G2 267
#define R_AARCH64_MOVW_UABS_G2_NC 268
#define R_AARCH64_MOVW_UABS_G3 269
#define R_AARCH64_MOVW_SABS_G0 270
#define R_AARCH64_MOVW_SABS_G1 271
#define R_AARCH64_MOVW_SABS_G2 272
#define R_AARCH64_LD_PREL_LO19 273
#define R_AARCH64_ADR_PREL_LO21 274
#define R_AARCH64_ADR_PREL_PG_HI21 275
#define R_AARCH64_ADR_PREL_PG_HI21_NC 276
#define R_AARCH64_ADD_ABS_LO12_NC 277
#define R_AARCH64_LDST8_ABS_LO12_NC 278
#define R_AARCH64_TSTBR14 279
#define R_AARCH64_CONDBR19 280
	/* unused: 281 */
#define R_AARCH64_JUMP26 282
#define R_AARCH64_CALL26 283
#define R_AARCH64_LDST16_ABS_LO12_NC 284
#define R_AARCH64_LDST32_ABS_LO12_NC 285
#define R_AARCH64_LDST64_ABS_LO12_NC 286
#define R_AARCH64_MOVW_PREL_G0 287
#define R_AARCH64_MOVW_PREL_G0_NC 288
#define R_AARCH64_MOVW_PREL_G1 289
#define R_AARCH64_MOVW_PREL_G1_NC 290
#define R_AARCH64_MOVW_PREL_G2 291
#define R_AARCH64_MOVW_PREL_G2_NC 292
#define R_AARCH64_MOVW_PREL_G3 293
	/* unused: 294-298 */
#define R_AARCH64_LDST128_ABS_LO12_NC 299
#define R_AARCH64_MOVW_GOTOFF_G0 300
#define R_AARCH64_MOVW_GOTOFF_G0_NC 301
#define R_AARCH64_MOVW_GOTOFF_G1 302
#define R_AARCH64_MOVW_GOTOFF_G1_NC 303
#define R_AARCH64_MOVW_GOTOFF_G2 304
#define R_AARCH64_MOVW_GOTOFF_G2_NC 305
#define R_AARCH64_MOVW_GOTOFF_G3 306
#define R_AARCH64_GOTREL64 307
#define R_AARCH64_GOTREL32 308
#define R_AARCH64_GOT_LD_PREL19 309
#define R_AARCH64_LD64_GOTOFF_LO15 310
#define R_AARCH64_ADR_GOT_PAGE 311
#define R_AARCH64_LD64_GOT_LO12_NC 312
#define R_AARCH64_LD64_GOTPAGE_LO15 313
#define R_AARCH64_PLT32	314
#define R_AARCH64_GOTPCREL32 315
	/* unused: 316-511 */
#define R_AARCH64_TLSGD_ADR_PREL21 512
#define R_AARCH64_TLSGD_ADR_PAGE21 513
#define R_AARCH64_TLSGD_ADD_LO12_NC 514
#define R_AARCH64_TLSGD_MOVW_G1 515
#define R_AARCH64_TLSGD_MOVW_G0_NC 516
#define R_AARCH64_TLSLD_ADR_PREL21 517
#define R_AARCH64_TLSLD_ADR_PAGE21 518
#define R_AARCH64_TLSLD_ADD_LO12_NC 519
#define R_AARCH64_TLSLD_MOVW_G1 520
#define R_AARCH64_TLSLD_MOVW_G0_NC 521
#define R_AARCH64_TLSLD_LD_PREL19 522
#define R_AARCH64_TLSLD_MOVW_DTPREL_G2 523
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1 524
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC 525
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0 526
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC 527
#define R_AARCH64_TLSLD_ADD_DTPREL_HI12 528
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12 529
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC 530
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12 531
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC 532
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12 533
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC 534
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12 535
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC 536
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12 537
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC 538
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G1 539
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC 540
#define R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21 541
#define R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC 542
#define R_AARCH64_TLSIE_LD_GOTTPREL_PREL19 543
#define R_AARCH64_TLSLE_MOVW_TPREL_G2 544
#define R_AARCH64_TLSLE_MOVW_TPREL_G1 545
#define R_AARCH64_TLSLE_MOVW_TPREL_G1_NC 546
#define R_AARCH64_TLSLE_MOVW_TPREL_G0 547
#define R_AARCH64_TLSLE_MOVW_TPREL_G0_NC 548
#define R_AARCH64_TLSLE_ADD_TPREL_HI12 549
#define R_AARCH64_TLSLE_ADD_TPREL_LO12 550
#define R_AARCH64_TLSLE_ADD_TPREL_LO12_NC 551
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12 552
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC 553
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12 554
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC 555
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12 556
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC 557
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12 558
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC 559
#define R_AARCH64_TLSDESC_LD_PREL19 560
#define R_AARCH64_TLSDESC_ADR_PREL21 561
#define R_AARCH64_TLSDESC_ADR_PAGE21 562
#define R_AARCH64_TLSDESC_LD64_LO12 563
#define R_AARCH64_TLSDESC_ADD_LO12 564
#define R_AARCH64_TLSDESC_OFF_G1 565
#define R_AARCH64_TLSDESC_OFF_G0_NC 566
#define R_AARCH64_TLSDESC_LDR 567
#define R_AARCH64_TLSDESC_ADD 568
#define R_AARCH64_TLSDESC_CALL 569
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12 570
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC 571
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12 572
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC 573
	/* unused: 574-579 */
#define R_AARCH64_AUTH_ABS64 580
#define R_AARCH64_AUTH_MOVW_GOTOFF_G0 581
#define R_AARCH64_AUTH_MOVW_GOTOFF_G0_NC 582
#define R_AARCH64_AUTH_MOVW_GOTOFF_G1 583
#define R_AARCH64_AUTH_MOVW_GOTOFF_G1_NC 584
#define R_AARCH64_AUTH_MOVW_GOTOFF_G2 585
#define R_AARCH64_AUTH_MOVW_GOTOFF_G2_NC 586
#define R_AARCH64_AUTH_MOVW_GOTOFF_G3 587
#define R_AARCH64_AUTH_GOT_LD_PREL19 588
#define R_AARCH64_AUTH_LD64_GOTOFF_LO15 589
#define R_AARCH64_AUTH_ADR_GOT_PAGE 590
#define R_AARCH64_AUTH_LD64_GOT_LO12_NC 591
#define R_AARCH64_AUTH_LD64_GOTPAGE_LO15 592
#define R_AARCH64_AUTH_GOT_ADD_LO12_NC 593
#define R_AARCH64_AUTH_GOT_ADR_PREL_LO21 594
#define R_AARCH64_AUTH_TLSDESC_ADR_PAGE21 595
#define R_AARCH64_AUTH_TLSDESC_LD64_LO12 596
#define R_AARCH64_AUTH_TLSDESC_ADD_LO12 597
	/* unused: 598-1023 */
#define R_AARCH64_COPY	1024
#define R_AARCH64_GLOB_DAT 1025
#define R_AARCH64_JUMP_SLOT 1026
#define R_AARCH64_RELATIVE 1027
#define R_AARCH64_TLS_IMPDEF1 1028 /* R_AARCH64_TLS_DTPREL or R_AARCH64_TLS_DTPMOD. */
#define R_AARCH64_TLS_IMPDEF2 1029 /* R_AARCH64_TLS_DTPMOD or R_AARCH64_TLS_DTPREL. */
#define R_AARCH64_TLS_TPREL 1030
#define R_AARCH64_TLSDESC 1031
#define R_AARCH64_IRELATIVE 1032
	/* unused: 1033-1040 */
#define R_AARCH64_AUTH_RELATIVE 1041
#define R_AARCH64_AUTH_GLOB_DAT 1042
#define R_AARCH64_AUTH_TLSDESC 1043
#define R_AARCH64_AUTH_IRELATIVE 1044


/* EM_ARM */
#define R_ARM_NONE	0
#define R_ARM_PC24	1 /* Deprecated. */
#define R_ARM_ABS32	2
#define R_ARM_REL32	3
#define R_ARM_LDR_PC_G0	4
#define R_ARM_ABS16	5
#define R_ARM_ABS12	6
#define R_ARM_THM_ABS5	7
#define R_ARM_ABS8	8
#define R_ARM_SBREL32	9
#define R_ARM_THM_CALL	10
#define R_ARM_THM_PC8	11
#define R_ARM_BREL_ADJ	12
#define R_ARM_TLS_DESC	13
#define R_ARM_THM_SWI8	14 /* Obsolete. */
#define R_ARM_XPC25	15 /* Obsolete. */
#define R_ARM_THM_XPC22	16 /* Obsolete. */
#define R_ARM_TLS_DTPMOD32 17
#define R_ARM_TLS_DTPOFF32 18
#define R_ARM_TLS_TPOFF32 19
#define R_ARM_COPY	20
#define R_ARM_GLOB_DAT	21
#define R_ARM_JUMP_SLOT	22
#define R_ARM_RELATIVE	23
#define R_ARM_GOTOFF32	24
#define R_ARM_BASE_PREL	25
#define R_ARM_GOT_BREL	26
#define R_ARM_PLT32	27 /* Deprecated. */
#define R_ARM_CALL	28
#define R_ARM_JUMP24	29
#define R_ARM_THM_JUMP24 30
#define R_ARM_BASE_ABS	31
#define R_ARM_ALU_PCREL_7_0 32 /* Obsolete. */
#define R_ARM_ALU_PCREL_15_8 33 /* Obsolete. */
#define R_ARM_ALU_PCREL_23_15 34 /* Obsolete. */
#define R_ARM_LDR_SBREL_11_0_NC 35 /* Deprecated. */
#define R_ARM_ALU_SBREL_19_12_NC 36 /* Deprecated. */
#define R_ARM_ALU_SBREL_27_20_CK 37 /* Deprecated. */
#define R_ARM_TARGET1	38
#define R_ARM_SBREL31	39 /* Deprecated. */
#define R_ARM_V4BX	40
#define R_ARM_TARGET2	41
#define R_ARM_PREL31	42
#define R_ARM_MOVW_ABS_NC 43
#define R_ARM_MOVT_ABS	44
#define R_ARM_MOVW_PREL_NC 45
#define R_ARM_MOVT_PREL	46
#define R_ARM_THM_MOVW_ABS_NC 47
#define R_ARM_THM_MOVT_ABS 48
#define R_ARM_THM_MOVW_PREL_NC 49
#define R_ARM_THM_MOVT_PREL 50
#define R_ARM_THM_JUMP19 51
#define R_ARM_THM_JUMP6	52
#define R_ARM_THM_ALU_PREL_11_0 53
#define R_ARM_THM_PC12	54
#define R_ARM_ABS32_NOI	55
#define R_ARM_REL32_NOI	56
#define R_ARM_ALU_PC_G0_NC 57
#define R_ARM_ALU_PC_G0	58
#define R_ARM_ALU_PC_G1_NC 59
#define R_ARM_ALU_PC_G1	60
#define R_ARM_ALU_PC_G2	61
#define R_ARM_LDR_PC_G1	62
#define R_ARM_LDR_PC_G2	63
#define R_ARM_LDRS_PC_G0 64
#define R_ARM_LDRS_PC_G1 65
#define R_ARM_LDRS_PC_G2 66
#define R_ARM_LDC_PC_G0	67
#define R_ARM_LDC_PC_G1	68
#define R_ARM_LDC_PC_G2	69
#define R_ARM_ALU_SB_G0_NC 70
#define R_ARM_ALU_SB_G0	71
#define R_ARM_ALU_SB_G1_NC 72
#define R_ARM_ALU_SB_G1	73
#define R_ARM_ALU_SB_G2	74
#define R_ARM_LDR_SB_G0	75
#define R_ARM_LDR_SB_G1	76
#define R_ARM_LDR_SB_G2	77
#define R_ARM_LDRS_SB_G0 78
#define R_ARM_LDRS_SB_G1 79
#define R_ARM_LDRS_SB_G2 80
#define R_ARM_LDC_SB_G0	81
#define R_ARM_LDC_SB_G1	82
#define R_ARM_LDC_SB_G2	83
#define R_ARM_MOVW_BREL_NC 84
#define R_ARM_MOVT_BREL	85
#define R_ARM_MOVW_BREL	86
#define R_ARM_THM_MOVW_BREL_NC 87
#define R_ARM_THM_MOVT_BREL 88
#define R_ARM_THM_MOVW_BREL 89
#define R_ARM_TLS_GOTDESC 90
#define R_ARM_TLS_CALL	91
#define R_ARM_TLS_DESCSEQ 92
#define R_ARM_THM_TLS_CALL 93
#define R_ARM_PLT32_ABS	94
#define R_ARM_GOT_ABS	95
#define R_ARM_GOT_PREL	96
#define R_ARM_GOT_BREL12 97
#define R_ARM_GOTOFF12	98
#define R_ARM_GOTRELAX	99
#define R_ARM_GNU_VTENTRY 100 /* Deprecated. */
#define R_ARM_GNU_VTINHERIT 101 /* Deprecated. */
#define R_ARM_THM_JUMP11 102
#define R_ARM_THM_JUMP8	103
#define R_ARM_TLS_GD32	104
#define R_ARM_TLS_LDM32	105
#define R_ARM_TLS_LDO32	106
#define R_ARM_TLS_IE32	107
#define R_ARM_TLS_LE32	108
#define R_ARM_TLS_LDO12	109
#define R_ARM_TLS_LE12	110
#define R_ARM_TLS_IE12GP 111
#define R_ARM_PRIVATE_0	112
#define R_ARM_PRIVATE_1	113
#define R_ARM_PRIVATE_2	114
#define R_ARM_PRIVATE_3	115
#define R_ARM_PRIVATE_4	116
#define R_ARM_PRIVATE_5	117
#define R_ARM_PRIVATE_6	118
#define R_ARM_PRIVATE_7	119
#define R_ARM_PRIVATE_8	120
#define R_ARM_PRIVATE_9	121
#define R_ARM_PRIVATE_10 122
#define R_ARM_PRIVATE_11 123
#define R_ARM_PRIVATE_12 124
#define R_ARM_PRIVATE_13 125
#define R_ARM_PRIVATE_14 126
#define R_ARM_PRIVATE_15 127
#define R_ARM_ME_TOO	128 /* Obsolete. */
#define R_ARM_THM_TLS_DESCSEQ16 129
#define R_ARM_THM_TLS_DESCSEQ32 130
#define R_ARM_THM_GOT_BREL12 131
#define R_ARM_THM_ALU_ABS_G0_NC 132
#define R_ARM_THM_ALU_ABS_G1_NC 133
#define R_ARM_THM_ALU_ABS_G2_NC 134
#define R_ARM_THM_ALU_ABS_G3 135
#define R_ARM_THM_BF16	136
#define R_ARM_THM_BF12	137
#define R_ARM_THM_BF18	138
	/* Reserved: 139-159. */
#define R_ARM_IRELATIVE	160
#define R_ARM_PRIVATE_16 161
#define R_ARM_PRIVATE_17 162
#define R_ARM_PRIVATE_18 163
#define R_ARM_PRIVATE_19 164
#define R_ARM_PRIVATE_20 165
#define R_ARM_PRIVATE_21 166
#define R_ARM_PRIVATE_22 167
#define R_ARM_PRIVATE_23 168
#define R_ARM_PRIVATE_24 169
#define R_ARM_PRIVATE_25 170
#define R_ARM_PRIVATE_26 171
#define R_ARM_PRIVATE_27 172
#define R_ARM_PRIVATE_28 173
#define R_ARM_PRIVATE_29 174
#define R_ARM_PRIVATE_30 175
#define R_ARM_PRIVATE_31 176
	/* Reserved: 177-248. */
	/* GNU extensions */
#define R_ARM_RXPC25	249
#define R_ARM_RSBREL32	250
#define R_ARM_THM_RPC22	251
#define R_ARM_RREL32	252
#define R_ARM_RABS32	253
#define R_ARM_RPC24	254
#define R_ARM_RBASE	255


#define R_ALPHA_NONE	0 /* No relocation */
#define R_ALPHA_REFLONG	1 /* 32 bit direct */
#define R_ALPHA_REFQUAD	2 /* 64 bit direct */
#define R_ALPHA_GPREL32	3 /* GP-relative 32-bit */
#define R_ALPHA_LITERAL	4 /* GP-relative 16-bit */
#define R_ALPHA_LITUSE	5 /* Optimization hint for LITERAL */
#define R_ALPHA_GPDISP	6 /* Add displacement to GP */
#define R_ALPHA_BRADDR	7 /* PC+4-relative 23-bit shifted */
#define R_ALPHA_HINT	8 /* PC+4-relative 16-bit shifted */
#define R_ALPHA_SREL16	9 /* PC-relative 16 bit */
#define R_ALPHA_SREL32	10 /* PC-relative 32 bit */
#define R_ALPHA_SREL64	11 /* PC-relative 64 bit */
#define R_ALPHA_OP_PUSH	12 /* deprecated, ECOFF OP stack push */
#define R_ALPHA_OP_STORE 13 /* deprecated, ECOFF OP pop and store */
#define R_ALPHA_OP_PSUB	14 /* deprecated, ECOFF OP stack subtract */
#define R_ALPHA_OP_PRSHIFT 15 /* deprecated, ECOFF OP stack right shift */
#define R_ALPHA_GPVALUE	16 /* deprecated, ECOFF relocation */
#define R_ALPHA_GPRELHIGH 17 /* GP-relative 32-bit high 16 bits */
#define R_ALPHA_GPRELLOW 18 /* GP-relative 32-bit low 16 bits */
#define R_ALPHA_GPREL16	19 /* GP-relative 16-bit */
#define R_ALPHA_IMMED_GP_HI32 20 /* deprecated ECOFF relocation */
#define R_ALPHA_IMMED_SCN_HI32 21 /* deprecated ECOFF relocation */
#define R_ALPHA_IMMED_BR_HI32 22 /* deprecated ECOFF relocation */
#define R_ALPHA_IMMED_LO32 23 /* deprecated ECOFF relocation */
	/* Relocations for shared libraries */	
#define R_ALPHA_COPY	24 /* copy symbol at runtime */
#define R_ALPHA_GLOB_DAT 25 /* create GOT entry */
#define R_ALPHA_JMP_SLOT 26 /* create PLT entry */
#define R_ALPHA_RELATIVE 27 /* adjust by program base */
#define R_ALPHA_BRSGP	28 /* PC relative with target address adjustment */
	/* TLS relocations */
#define R_ALPHA_TLSGD	29
#define R_ALPHA_TLSDM	30
#define R_ALPHA_DTPMOD64 31
#define R_ALPHA_GOTDTPREL 32
#define R_ALPHA_DTPREL64 33
#define R_ALPHA_DTPRELHI 34
#define R_ALPHA_DTPRELLO 35
#define R_ALPHA_DTPREL16 36
#define R_ALPHA_GOTTPREL 37
#define R_ALPHA_TPREL64	38
#define R_ALPHA_TPRELHI	39
#define R_ALPHA_TPRELLO	40
#define R_ALPHA_TPREL16	41


/* EM_IA_64 */
#define R_IA_64_NONE	0
	/* unused: 0x1-0x20 */
#define R_IA_64_IMM14	0x21
#define R_IA_64_IMM22	0x22
#define R_IA_64_IMM64	0x23
#define R_IA_64_DIR32MSB 0x24
#define R_IA_64_DIR32LSB 0x25
#define R_IA_64_DIR64MSB 0x26
#define R_IA_64_DIR64LSB 0x27
	/* unused: 0x28-0x29 */
#define R_IA_64_GPREL22	0x2a
#define R_IA_64_GPREL64I 0x2b
#define R_IA_64_GPREL32MSB 0x2c
#define R_IA_64_GPREL32LSB 0x2d
#define R_IA_64_GPREL64MSB 0x2e
#define R_IA_64_GPREL64LSB 0x2f
	/* unused: 0x30-0x31 */
#define R_IA_64_LTOFF22	0x32
#define R_IA_64_LTOFF64I 0x33
	/* unused: 0x34-0x39 */
#define R_IA_64_PLTOFF22 0x3a
#define R_IA_64_PLTOFF64I 0x3b
	/* unused: 0x3c-0x3d */
#define R_IA_64_PLTOFF64MSB 0x3e
#define R_IA_64_PLTOFF64LSB 0x3f
	/* unused: 0x40-0x42 */
#define R_IA_64_FPTR64I	0x43
#define R_IA_64_FPTR32MSB 0x44
#define R_IA_64_FPTR32LSB 0x45
#define R_IA_64_FPTR64MSB 0x46
#define R_IA_64_FPTR64LSB 0x47
#define R_IA_64_PCREL60B 0x48
#define R_IA_64_PCREL21B 0x49
#define R_IA_64_PCREL21M 0x4a
#define R_IA_64_PCREL21F 0x4b
#define R_IA_64_PCREL32MSB 0x4c
#define R_IA_64_PCREL32LSB 0x4d
#define R_IA_64_PCREL64MSB 0x4e
#define R_IA_64_PCREL64LSB 0x4f
	/* unused: 0x50-0x51 */
#define R_IA_64_LTOFF_FPTR22 0x52
#define R_IA_64_LTOFF_FPTR64I 0x53
#define R_IA_64_LTOFF_FPTR32MSB 0x54
#define R_IA_64_LTOFF_FPTR32LSB 0x55
#define R_IA_64_LTOFF_FPTR64MSB 0x56
#define R_IA_64_LTOFF_FPTR64LSB 0x57
	/* unused: 0x58-0x5b */
#define R_IA_64_SEGREL32MSB 0x5c
#define R_IA_64_SEGREL32LSB 0x5d
#define R_IA_64_SEGREL64MSB 0x5e
#define R_IA_64_SEGREL64LSB 0x5f
	/* unused: 0x60-0x63 */
#define R_IA_64_SECREL32MSB 0x64
#define R_IA_64_SECREL32LSB 0x65
#define R_IA_64_SECREL64MSB 0x66
#define R_IA_64_SECREL64LSB 0x67
	/* unused: 0x68-0x6b */
#define R_IA_64_REL32MSB 0x6c
#define R_IA_64_REL32LSB 0x6d
#define R_IA_64_REL64MSB 0x6e
#define R_IA_64_REL64LSB 0x6f
	/* unused: 0x70-0x73 */
#define R_IA_64_LTV32MSB 0x74
#define R_IA_64_LTV32LSB 0x75
#define R_IA_64_LTV64MSB 0x76
#define R_IA_64_LTV64LSB 0x77
	/* unused: 0x78 */
#define R_IA_64_PCREL21BI 0x79
#define R_IA_64_PCREL22	0x7A
#define R_IA_64_PCREL64I 0x7B
	/* unused: 0x7C-0x7F */
#define R_IA_64_IPLTMSB	0x80
#define R_IA_64_IPLTLSB	0x81
	/* unused: 0x82-0x84 */
#define R_IA_64_SUB	0x85
#define R_IA_64_LTOFF22X 0x86
#define R_IA_64_LDXMOV	0x87
	/* unused: 0x88-0x90 */
#define R_IA_64_TPREL14	0x91
#define R_IA_64_TPREL22	0x92
#define R_IA_64_TPREL64I 0x93
	/* unused: 0x94-0x95 */
#define R_IA_64_TPREL64MSB 0x96
#define R_IA_64_TPREL64LSB 0x97
	/* unused: 0x98-0x99 */
#define R_IA_64_LTOFF_TPREL22 0x9A
	/* unused: 0x9B-0xA5 */
#define R_IA_64_DTPMOD64MSB 0xA6
#define R_IA_64_DTPMOD64LSB 0xA7
	/* unused: 0xA8-0xA9 */
#define R_IA_64_LTOFF_DTPMOD22 0xAA
	/* unused: 0xAB-0xB0 */
#define R_IA_64_DTPREL14 0xB1
#define R_IA_64_DTPREL22 0xB2
#define R_IA_64_DTPREL64I 0xB3
#define R_IA_64_DTPREL32MSB 0xB4
#define R_IA_64_DTPREL32LSB 0xB5
#define R_IA_64_DTPREL64MSB 0xB6
#define R_IA_64_DTPREL64LSB 0xB7
	/* unused: 0xB8-0xB9 */
#define R_IA_64_LTOFF_DTPREL22 0xBA


/* EM_LOONGARCH */
#define R_LARCH_NONE	0
#define R_LARCH_32	1
#define R_LARCH_64	2
#define R_LARCH_RELATIVE 3
#define R_LARCH_COPY	4
#define R_LARCH_JUMP_SLOT 5
#define R_LARCH_TLS_DTPMOD32 6
#define R_LARCH_TLS_DTPMOD64 7
#define R_LARCH_TLS_DTPREL32 8
#define R_LARCH_TLS_DTPREL64 9
#define R_LARCH_TLS_TPREL32 10
#define R_LARCH_TLS_TPREL64 11
#define R_LARCH_IRELATIVE 12
#define R_LARCH_TLS_DESC32 13
#define R_LARCH_TLS_DESC64 14
	/* reserved for the dynamic linker: 15-19 */
#define R_LARCH_MARK_LA	20
#define R_LARCH_MARK_PCREL 21
#define R_LARCH_SOP_PUSH_PCREL 22
#define R_LARCH_SOP_PUSH_ABSOLUTE 23
#define R_LARCH_SOP_PUSH_DUP 24
#define R_LARCH_SOP_PUSH_GPREL 25
#define R_LARCH_SOP_PUSH_TLS_TPREL 26
#define R_LARCH_SOP_PUSH_TLS_GOT 27
#define R_LARCH_SOP_PUSH_TLS_GD 28
#define R_LARCH_SOP_PUSH_PLT_PCREL 29
#define R_LARCH_SOP_ASSERT 30
#define R_LARCH_SOP_NOT	31
#define R_LARCH_SOP_SUB	32
#define R_LARCH_SOP_SL	33
#define R_LARCH_SOP_SR	34
#define R_LARCH_SOP_ADD	35
#define R_LARCH_SOP_AND	36
#define R_LARCH_SOP_IF_ELSE 37
#define R_LARCH_SOP_POP_32_S_10_5 38
#define R_LARCH_SOP_POP_32_U_10_12 39
#define R_LARCH_SOP_POP_32_S_10_12 40
#define R_LARCH_SOP_POP_32_S_10_16 41
#define R_LARCH_SOP_POP_32_S_10_16_S2 42
#define R_LARCH_SOP_POP_32_S_5_20 43
#define R_LARCH_SOP_POP_32_S_0_5_10_16_S2 44
#define R_LARCH_SOP_POP_32_S_0_10_10_16_S2 45
#define R_LARCH_SOP_POP_32_U 46
#define R_LARCH_ADD8	47
#define R_LARCH_ADD16	48
#define R_LARCH_ADD24	49
#define R_LARCH_ADD32	50
#define R_LARCH_ADD64	51
#define R_LARCH_SUB8	52
#define R_LARCH_SUB16	53
#define R_LARCH_SUB24	54
#define R_LARCH_SUB32	55
#define R_LARCH_SUB64	56
#define R_LARCH_GNU_VTINHERIT 57
#define R_LARCH_GNU_VTENTRY 58
	/* reserved: 59-63 */
#define R_LARCH_B16	64
#define R_LARCH_B21	65
#define R_LARCH_B26	66
#define R_LARCH_ABS_HI20 67
#define R_LARCH_ABS_LO12 68
#define R_LARCH_ABS64_LO20 69
#define R_LARCH_ABS64_HI12 70
#define R_LARCH_PCALA_HI20 71
#define R_LARCH_PCALA_LO12 72
#define R_LARCH_PCALA64_LO20 73
#define R_LARCH_PCALA64_HI12 74
#define R_LARCH_GOT_PC_HI20 75
#define R_LARCH_GOT_PC_LO12 76
#define R_LARCH_GOT64_PC_LO20 77
#define R_LARCH_GOT64_PC_HI12 78
#define R_LARCH_GOT_HI20 79
#define R_LARCH_GOT_LO12 80
#define R_LARCH_GOT64_LO20 81
#define R_LARCH_GOT64_HI12 82
#define R_LARCH_TLS_LE_HI20 83
#define R_LARCH_TLS_LE_LO12 84
#define R_LARCH_TLS_LE64_LO20 85
#define R_LARCH_TLS_LE64_HI12 86
#define R_LARCH_TLS_IE_PC_HI20 87
#define R_LARCH_TLS_IE_PC_LO12 88
#define R_LARCH_TLS_IE64_PC_LO20 89
#define R_LARCH_TLS_IE64_PC_HI12 90
#define R_LARCH_TLS_IE_HI20 91
#define R_LARCH_TLS_IE_LO12 92
#define R_LARCH_TLS_IE64_LO20 93
#define R_LARCH_TLS_IE64_HI12 94
#define R_LARCH_TLS_LD_PC_HI20 95
#define R_LARCH_TLS_LD_HI20 96
#define R_LARCH_TLS_GD_PC_HI20 97
#define R_LARCH_TLS_GD_HI20 98
#define R_LARCH_32_PCREL 99
#define R_LARCH_RELAX	100
	/* reserved: 101 */
#define R_LARCH_ALIGN	102
#define R_LARCH_PCREL20_S2 103
	/* reserved: 104 */
#define R_LARCH_ADD6	105
#define R_LARCH_SUB6	106
#define R_LARCH_ADD_ULEB128 107
#define R_LARCH_SUB_ULEB128 108
#define R_LARCH_64_PCREL 109
#define R_LARCH_CALL36	110
#define R_LARCH_TLS_DESC_PC_HI20 111
#define R_LARCH_TLS_DESC_PC_LO12 112
#define R_LARCH_TLS_DESC64_PC_LO20 113
#define R_LARCH_TLS_DESC64_PC_HI12 114
#define R_LARCH_TLS_DESC_HI20 115
#define R_LARCH_TLS_DESC_LO12 116
#define R_LARCH_TLS_DESC64_LO20 117
#define R_LARCH_TLS_DESC64_HI12 118
#define R_LARCH_TLS_DESC_LD 119
#define R_LARCH_TLS_DESC_CALL 120
#define R_LARCH_TLS_LE_HI20_R 121
#define R_LARCH_TLS_LE_ADD_R 122
#define R_LARCH_TLS_LE_LO12_R 123
#define R_LARCH_TLS_LD_PCREL20_S2 124
#define R_LARCH_TLS_GD_PCREL20_S2 125
#define R_LARCH_TLS_DESC_PCREL20_S2 126
#define R_LARCH_CALL30	127
#define R_LARCH_PCADD_HI20 128
#define R_LARCH_PCADD_LO12 129
#define R_LARCH_GOT_PCADD_HI20 130
#define R_LARCH_GOT_PCADD_LO12 131
#define R_LARCH_TLS_IE_PCADD_HI20 132
#define R_LARCH_TLS_IE_PCADD_LO12 133
#define R_LARCH_TLS_LD_PCADD_HI20 134
#define R_LARCH_TLS_LD_PCADD_LO12 135
#define R_LARCH_TLS_GD_PCADD_HI20 136
#define R_LARCH_TLS_GD_PCADD_LO12 137
#define R_LARCH_TLS_DESC_PCADD_HI20 138
#define R_LARCH_TLS_DESC_PCADD_LO12 139


/* EM_MIPS */
#define R_MIPS_NONE	0 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_16	1 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_32	2 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_REL32	3 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_26	4 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_HI16	5 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_LO16	6 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_GPREL16	7 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_LITERAL	8 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_GOT16	9 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_PC16	10 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_CALL16	11 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_GPREL32	12 /* GNU binutils, LLVM, MIPS psABI. */
	/* Unused: 13-15. */
#define R_MIPS_SHIFT5	16 /* GNU binutils, LLVM. */
#define R_MIPS_SHIFT6	17 /* GNU binutils, LLVM. */
#define R_MIPS_64	18 /* GNU binutils, LLVM */
#define R_MIPS_GOT_DISP	19 /* GNU binutils, LLVM. */
#define R_MIPS_GOT_PAGE	20 /* GNU binutils, LLVM. */
#define R_MIPS_GOTHI16	21 /* MIPS psABI. */
#define R_MIPS_GOTLO16	22 /* MIPS psABI. */
#define R_MIPS_GOT_LO16	23 /* GNU binutils, LLVM. */
#define R_MIPS_SUB	24 /* GNU binutils, LLVM. */
#define R_MIPS_INSERT_A	25 /* GNU binutils, LLVM. */
#define R_MIPS_INSERT_B	26 /* GNU binutils, LLVM. */
#define R_MIPS_DELETE	27 /* GNU binutils, LLVM. */
#define R_MIPS_HIGHER	28 /* GNU binutils, LLVM. */
#define R_MIPS_HIGHEST	29 /* GNU binutils, LLVM. */
#define R_MIPS_CALLHI16	30 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_CALLLO16	31 /* GNU binutils, LLVM, MIPS psABI. */
#define R_MIPS_SCN_DISP	32 /* GNU binutils, LLVM. */
#define R_MIPS_REL16	33 /* GNU binutils, LLVM. */
#define R_MIPS_ADD_IMMEDIATE 34 /* GNU binutils, LLVM. */
#define R_MIPS_PJUMP	35 /* GNU binutils, LLVM. */
#define R_MIPS_RELGOT	36 /* GNU binutils, LLVM. */
#define R_MIPS_JALR	37 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_DTPMOD32 38 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_DTPREL32 39 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_DTPMOD64 40 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_DTPREL64 41 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_GD	42 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_LDM	43 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_DTPREL_HI16 44 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_DTPREL_LO16 45 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_GOTTPREL 46 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_TPREL32 47 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_TPREL64 48 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_TPREL_HI16 49 /* GNU binutils, LLVM. */
#define R_MIPS_TLS_TPREL_LO16 50 /* GNU binutils, LLVM. */
#define R_MIPS_GLOB_DAT	51 /* GNU binutils, LLVM. */
	/* Unused: 52-59. */
#define R_MIPS_PC21_S2	60 /* GNU binutils, LLVM. */
#define R_MIPS_PC26_S2	61 /* GNU binutils, LLVM. */
#define R_MIPS_PC18_S3	62 /* GNU binutils, LLVM. */
#define R_MIPS_PC19_S2	63 /* GNU binutils, LLVM. */
#define R_MIPS_PCHI16	64 /* GNU binutils, LLVM. */
#define R_MIPS_PCLO16	65 /* GNU binutils, LLVM. */
	/* Unused: 66-99. */
#define R_MIPS16_26	100 /* GNU binutils, LLVM. */
#define R_MIPS16_GPREL	101 /* GNU binutils, LLVM. */
#define R_MIPS16_GOT16	102 /* GNU binutils, LLVM. */
#define R_MIPS16_CALL16	103 /* GNU binutils, LLVM. */
#define R_MIPS16_HI16	104 /* GNU binutils, LLVM. */
#define R_MIPS16_LO16	105 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_GD	106 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_LDM 107 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_DTPREL_HI16 108 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_DTPREL_LO16 109 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_GOTTPREL 110 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_TPREL_HI16 111 /* GNU binutils, LLVM. */
#define R_MIPS16_TLS_TPREL_LO16 112 /* GNU binutils, LLVM. */
	/* Unused: 113-125. */
#define R_MIPS_COPY	126 /* GNU binutils, LLVM. */
#define R_MIPS_JUMP_SLOT 127 /* GNU binutils, LLVM. */
	/* Unused: 128-132. */
#define R_MICROMIPS_26_S1 133 /* GNU binutils, LLVM. */
#define R_MICROMIPS_HI16 134 /* GNU binutils, LLVM. */
#define R_MICROMIPS_LO16 135 /* GNU binutils, LLVM. */
#define R_MICROMIPS_GPREL16 136 /* GNU binutils, LLVM. */
#define R_MICROMIPS_LITERAL 137 /* GNU binutils, LLVM. */
#define R_MICROMIPS_GOT16 138 /* GNU binutils, LLVM. */
#define R_MICROMIPS_PC7_S1 139 /* GNU binutils, LLVM. */
#define R_MICROMIPS_PC10_S1 140 /* GNU binutils, LLVM. */
#define R_MICROMIPS_PC16_S1 141 /* GNU binutils, LLVM. */
#define R_MICROMIPS_CALL16 142 /* GNU binutils, LLVM. */
	/* Unused: 143-144. */
#define R_MICROMIPS_GOT_DISP 145 /* GNU binutils, LLVM. */
#define R_MICROMIPS_GOT_PAGE 146 /* GNU binutils, LLVM. */
#define R_MICROMIPS_GOT_OFST 147 /* GNU binutils, LLVM. */
#define R_MICROMIPS_GOT_HI16 148 /* GNU binutils, LLVM. */
#define R_MICROMIPS_GOT_LO16 149 /* GNU binutils, LLVM. */
#define R_MICROMIPS_SUB	150 /* GNU binutils, LLVM. */
#define R_MICROMIPS_HIGHER 151 /* GNU binutils, LLVM. */
#define R_MICROMIPS_HIGHEST 152 /* GNU binutils, LLVM. */
#define R_MICROMIPS_CALL_HI16 153 /* GNU binutils, LLVM. */
#define R_MICROMIPS_CALL_LO16 154 /* GNU binutils, LLVM. */
#define R_MICROMIPS_SCN_DISP 155 /* GNU binutils, LLVM. */
#define R_MICROMIPS_JALR 156 /* GNU binutils, LLVM. */
#define R_MICROMIPS_HI0_LO16 157 /* GNU binutils, LLVM. */
	/* Unused: 158-161. */
#define R_MICROMIPS_TLS_GD 162 /* GNU binutils, LLVM. */
#define R_MICROMIPS_TLS_LDM 163 /* GNU binutils, LLVM. */
#define R_MICROMIPS_TLS_DTPREL_HI16 164 /* GNU binutils, LLVM. */
#define R_MICROMIPS_TLS_DTPREL_LO16 165 /* GNU binutils, LLVM. */
#define R_MICROMIPS_TLS_GOTTPREL 166 /* GNU binutils, LLVM. */
	/* Unused: 167-168. */
#define R_MICROMIPS_TLS_TPREL_HI16 169 /* GNU binutils, LLVM. */
#define R_MICROMIPS_TLS_TPREL_LO16 170 /* GNU binutils, LLVM. */
	/* Unused: 171. */
#define R_MICROMIPS_GPREL7_S2 172 /* GNU binutils, LLVM. */
#define R_MICROMIPS_PC23_S2 173 /* GNU binutils, LLVM. */
#define R_MICROMIPS_PC21_S1 174 /* LLVM. */
#define R_MICROMIPS_PC26_S1 175 /* LLVM. */
#define R_MICROMIPS_PC18_S3 176 /* LLVM. */
#define R_MICROMIPS_PC19_S2 177 /* LLVM. */
	/* Unused: 178-247. */
#define R_MIPS_PC32	248 /* GNU binutils, LLVM. */
#define R_MIPS_EH	249 /* GNU binutils, LLVM. */
	/* GNU extensions. */
#define R_MIPS_GNU_REL16_S2 250 /* GNU binutils. */
#define R_MIPS_GNU_VTINHERIT 251 /* GNU binutils. */
#define R_MIPS_GNU_VTENTRY 252 /* GNU binutils. */


/* EM_OPENRISC */
#define R_OR1K_NONE	0
#define R_OR1K_32	1
#define R_OR1K_16	2
#define R_OR1K_8	3
#define R_OR1K_LO_16_IN_INSN 4
#define R_OR1K_HI_16_IN_INSN 5
#define R_OR1K_INSN_REL_26 6
#define R_OR1K_GNU_VTENTRY 7
#define R_OR1K_GNU_VTINHERIT 8
#define R_OR1K_32_PCREL	9
#define R_OR1K_16_PCREL	10
#define R_OR1K_8_PCREL	11
#define R_OR1K_GOTPC_HI16 12
#define R_OR1K_GOTPC_LO16 13
#define R_OR1K_GOT16	14
#define R_OR1K_PLT26	15
#define R_OR1K_GOTOFF_HI16 16
#define R_OR1K_GOTOFF_LO16 17
#define R_OR1K_COPY	18
#define R_OR1K_GLOB_DAT	19
#define R_OR1K_JMP_SLOT	20
#define R_OR1K_RELATIVE	21
#define R_OR1K_TLS_GD_HI16 22
#define R_OR1K_TLS_GD_LO16 23
#define R_OR1K_TLS_LDM_HI16 24
#define R_OR1K_TLS_LDM_LO16 25
#define R_OR1K_TLS_LDO_HI16 26
#define R_OR1K_TLS_LDO_LO16 27
#define R_OR1K_TLS_IE_HI16 28
#define R_OR1K_TLS_IE_LO16 29
#define R_OR1K_TLS_LE_HI16 30
#define R_OR1K_TLS_LE_LO16 31
#define R_OR1K_TLS_TPOFF 32
#define R_OR1K_TLS_DTPOFF 33
#define R_OR1K_TLS_DTPMOD 34
#define R_OR1K_AHI16	35
#define R_OR1K_GOTOFF_AHI16 36
#define R_OR1K_TLS_IE_AHI16 37
#define R_OR1K_TLS_LE_AHI16 38
#define R_OR1K_SLO16	39
#define R_OR1K_GOTOFF_SLO16 40
#define R_OR1K_TLS_LE_SLO16 41
#define R_OR1K_PCREL_PG21 42
#define R_OR1K_GOT_PG21	43
#define R_OR1K_TLS_GD_PG21 44
#define R_OR1K_TLS_LDM_PG21 45
#define R_OR1K_TLS_IE_PG21 46
#define R_OR1K_LO13	47
#define R_OR1K_GOT_LO13	48
#define R_OR1K_TLS_GD_LO13 49
#define R_OR1K_TLS_LDM_LO13 50
#define R_OR1K_TLS_IE_LO13 51
#define R_OR1K_SLO13	52
#define R_OR1K_PLTA26	53
#define R_OR1K_GOT_AHI16 54


#define R_OR32_NONE	R_OR1K_NONE
#define R_OR32_32	R_OR1K_32
#define R_OR32_16	R_OR1K_16
#define R_OR32_8	R_OR1K_8
#define R_OR32_CONST	R_OR1K_LO_16_IN_INSN
#define R_OR32_CONSTH	R_OR1K_HI_16_IN_INSN
#define R_OR32_JUMPTARG	R_OR1K_INSN_REL_26
#define R_OR32_VTENTRY	R_OR1K_GNU_VTENTRY
#define R_OR32_VTINHERIT R_OR1K_GNU_VTINHERIT


#define R_PARISC_NONE	0
#define R_PARISC_DIR32	1
#define R_PARISC_DIR21L	2
#define R_PARISC_DIR17R	3
#define R_PARISC_DIR17F	4
	/* Unused: 5 */
#define R_PARISC_DIR14R	6
#define R_PARISC_DIR14F	7 /* GNU */
#define R_PARISC_PCREL12F 8 /* GNU */
#define R_PARISC_PCREL32 9
#define R_PARISC_PCREL21L 10
#define R_PARISC_PCREL17R 11
#define R_PARISC_PCREL17F 12
#define R_PARISC_PCREL17C 13
#define R_PARISC_PCREL14R 14
#define R_PARISC_PCREL14F 15 /* GNU */
	/* Unused: 16-17 */
#define R_PARISC_DPREL21L 18
#define R_PARISC_DPREL14WR 19
#define R_PARISC_DPREL14DR 20
	/* Unused: 21 */
#define R_PARISC_DPREL14R 22
#define R_PARISC_DPREL14F 23 /* GNU */
	/* Unused: 24-25 */
#define R_PARISC_DLTREL21L 26
	/* Unused: 27-29 */
#define R_PARISC_DLTREL14R 30
#define R_PARISC_DLTREL14F 31 /* GNU */
	/* Unused: 32-33 */
#define R_PARISC_DLTIND21L 34
	/* Unused: 35-37 */
#define R_PARISC_DLTIND14R 38
#define R_PARISC_DLTIND14F 39
#define R_PARISC_SETBASE 40
#define R_PARISC_SECREL32 41
#define R_PARISC_BASEREL21L 42
#define R_PARISC_BASEREL17R 43
#define R_PARISC_BASEREL17F 44 /* GNU */
	/* Unused: 45 */
#define R_PARISC_BASEREL14R 46
#define R_PARISC_BASEREL14F 47 /* GNU */
#define R_PARISC_SEGBASE 48
#define R_PARISC_SEGREL32 49
#define R_PARISC_PLTOFF21L 50
	/* Unused: 51-53 */
#define R_PARISC_PLTOFF14R 54
#define R_PARISC_PLTOFF14F 55
	/* Unused: 56 */
#define R_PARISC_LTOFF_FPTR32 57
#define R_PARISC_LTOFF_FPTR21L 58
	/* Unused: 59-61 */
#define R_PARISC_LTOFF_FPTR14R 62
	/* Unused: 63 */
#define R_PARISC_FPTR64	64
#define R_PARISC_PLABEL32 65 /* GNU */
#define R_PARISC_PLABEL21L 66 /* GNU */
	/* Unused: 67-69 */
#define R_PARISC_PLABEL14R 70 /* GNU */
	/* Unused: 71 */
#define R_PARISC_PCREL64 72
#define R_PARISC_PCREL22C 73
#define R_PARISC_PCREL22F 74
#define R_PARISC_PCREL14WR 75
#define R_PARISC_PCREL14DR 76
#define R_PARISC_PCREL16F 77
#define R_PARISC_PCREL16WF 78
#define R_PARISC_PCREL16DF 79
#define R_PARISC_DIR64	80
#define R_PARISC_DIR64WR 81 /* GNU */
#define R_PARISC_DIR64DR 82 /* GNU */
#define R_PARISC_DIR14WR 83
#define R_PARISC_DIR14DR 84
#define R_PARISC_DIR16F	85
#define R_PARISC_DIR16WF 86
#define R_PARISC_DIR16DF 87
#define R_PARISC_GPREL64 88
	/* Unused: 90 */
#define R_PARISC_DLTREL14WR 91
#define R_PARISC_DLTREL14DR 92
#define R_PARISC_GPREL16F 93
#define R_PARISC_GPREL16WF 94
#define R_PARISC_GPREL16DF 95
#define R_PARISC_LTOFF64 96
	/* Unused: 97-98 */
#define R_PARISC_DLTIND14WR 99
#define R_PARISC_DLTIND14DR 100
#define R_PARISC_LTOFF16F 101
#define R_PARISC_LTOFF16WF 102
#define R_PARISC_LTOFF16DF 103
#define R_PARISC_SECREL64 104
	/* Unused: 105-106 */
#define R_PARISC_BASEREL14WR 107
#define R_PARISC_BASEREL14DR 108
	/* Unused: 109-111 */
#define R_PARISC_SEGREL64 112
	/* Unused: 113-114 */
#define R_PARISC_PLTOFF14WR 115
#define R_PARISC_PLTOFF14DR 116
#define R_PARISC_PLTOFF16F 117
#define R_PARISC_PLTOFF16WF 118
#define R_PARISC_PLTOFF16DF 119
#define R_PARISC_LTOFF_FPTR64 120
	/* Unused: 121-122 */
#define R_PARISC_LTOFF_FPTR14WR 123
#define R_PARISC_LTOFF_FPTR14DR 124
#define R_PARISC_LTOFF_FPTR16F 125
#define R_PARISC_LTOFF_FPTR16WF 126
#define R_PARISC_LTOFF_FPTR16DF 127
#define R_PARISC_COPY	128
#define R_PARISC_IPLT	129
#define R_PARISC_EPLT	130
	/* Unused: 131-152 */
#define R_PARISC_TPREL32 153
#define R_PARISC_TPREL21L 154
	/* Unused: 155-157 */
#define R_PARISC_TPREL14R 158
	/* Unused: 159-161 */
#define R_PARISC_LTOFF_TP21L 162
	/* Unused: 163-165 */
#define R_PARISC_LTOFF_TP14R 166
#define R_PARISC_LTOFF_TP14F 167
	/* Unused: 168-215 */
#define R_PARISC_TPREL64 216
	/* Unused: 217-218 */
#define R_PARISC_TPREL14WR 219
#define R_PARISC_TPREL14DR 220
#define R_PARISC_TPREL16F 221
#define R_PARISC_TPREL16WF 222
#define R_PARISC_TPREL16DF 223
#define R_PARISC_LTOFF_TP64 224
	/* Unused: 225-226 */
#define R_PARISC_LTOFF_TP14WR 227
#define R_PARISC_LTOFF_TP14DR 228
#define R_PARISC_LTOFF_TP16F 229
#define R_PARISC_LTOFF_TP16WF 230
#define R_PARISC_LTOFF_TP16DF 231
#define R_PARISC_GNU_VTENTRY 232 /* GNU */
#define R_PARISC_GNU_VTINHERIT 233 /* GNU */
	/* TLS relocations */
#define R_PARISC_TLS_GD21L 234 /* GNU */
#define R_PARISC_TLS_GD14R 235 /* GNU */
#define R_PARISC_TLS_GDCALL 236 /* GNU */
#define R_PARISC_TLS_LDM21L 237 /* GNU */
#define R_PARISC_TLS_LDM14R 238 /* GNU */
#define R_PARISC_TLS_LDMCALL 239 /* GNU */
#define R_PARISC_TLS_LDO21L 240 /* GNU */
#define R_PARISC_TLS_LDO14R 241 /* GNU */
#define R_PARISC_TLS_DTPMOD32 242 /* GNU */
#define R_PARISC_TLS_DTPMOD64 243 /* GNU */
#define R_PARISC_TLS_DTPOFF32 244 /* GNU */
#define R_PARISC_TLS_DTPOFF64 245 /* GNU */


/* EM_PPC64 */
#define R_PPC64_NONE	0
#define R_PPC64_ADDR32	1
#define R_PPC64_ADDR24	2
#define R_PPC64_ADDR16	3
#define R_PPC64_ADDR16_LO 4
#define R_PPC64_ADDR16_HI 5
#define R_PPC64_ADDR16_HA 6
#define R_PPC64_ADDR14	7
	/* unused: 8-9. */
#define R_PPC64_REL24	10
#define R_PPC64_REL14	11
	/* unused: 12-13. */
#define R_PPC64_GOT16	14
#define R_PPC64_GOT16_LO 15
#define R_PPC64_GOT16_HI 16
#define R_PPC64_GOT16_HA 17
	/* unused: 18. */
#define R_PPC64_COPY	19
#define R_PPC64_GLOB_DAT 20
#define R_PPC64_JMP_SLOT 21
#define R_PPC64_RELATIVE 22
	/* unused: 23. */
#define R_PPC64_UADDR32	24
#define R_PPC64_UADDR16	25
#define R_PPC64_REL32	26
#define R_PPC64_PLT32	27
#define R_PPC64_PLTREL32 28
#define R_PPC64_PLT16_LO 29
#define R_PPC64_PLT16_HI 30
#define R_PPC64_PLT16_HA 31
	/* unused: 32. */
#define R_PPC64_SECTOFF	33
#define R_PPC64_SECTOFF_LO 34
#define R_PPC64_SECTOFF_HI 35
#define R_PPC64_SECTOFF_HA 36
#define R_PPC64_REL30	37
#define R_PPC64_ADDR64	38
#define R_PPC64_ADDR16_HIGHER 39
#define R_PPC64_ADDR16_HIGHERA 40
#define R_PPC64_ADDR16_HIGHEST 41
#define R_PPC64_ADDR16_HIGHESTA 42
#define R_PPC64_UADDR64	43
#define R_PPC64_REL64	44
#define R_PPC64_PLT64	45
#define R_PPC64_PLTREL64 46
#define R_PPC64_TOC16	47
#define R_PPC64_TOC16_LO 48
#define R_PPC64_TOC16_HI 49
#define R_PPC64_TOC16_HA 50
#define R_PPC64_TOC	51
#define R_PPC64_PLTGOT16 52
#define R_PPC64_PLTGOT16_LO 53
#define R_PPC64_PLTGOT16_HI 54
#define R_PPC64_PLTGOT16_HA 55
#define R_PPC64_ADDR16_DS 56
#define R_PPC64_ADDR16_LO_DS 57
#define R_PPC64_GOT16_DS 58
#define R_PPC64_GOT16_LO_DS 59
#define R_PPC64_PLT16_LO_DS 60
#define R_PPC64_SECTOFF_DS 61
#define R_PPC64_SECTOFF_LO_DS 62
#define R_PPC64_TOC16_DS 63
#define R_PPC64_TOC16_LO_DS 64
#define R_PPC64_PLTGOT16_DS 65
#define R_PPC64_PLTGOT16_LO_DS 66
#define R_PPC64_TLS	67
#define R_PPC64_DTPMOD64 68
#define R_PPC64_TPREL16	69
#define R_PPC64_TPREL16_LO 70
#define R_PPC64_TPREL16_HI 71
#define R_PPC64_TPREL16_HA 72
#define R_PPC64_TPREL64	73
#define R_PPC64_DTPREL16 74
#define R_PPC64_DTPREL16_LO 75
#define R_PPC64_DTPREL16_HI 76
#define R_PPC64_DTPREL16_HA 77
#define R_PPC64_DTPREL64 78
#define R_PPC64_GOT_TLSGD16 79
#define R_PPC64_GOT_TLSGD16_LO 80
#define R_PPC64_GOT_TLSGD16_HI 81
#define R_PPC64_GOT_TLSGD16_HA 82
#define R_PPC64_GOT_TLSLD16 83
#define R_PPC64_GOT_TLSLD16_LO 84
#define R_PPC64_GOT_TLSLD16_HI 85
#define R_PPC64_GOT_TLSLD16_HA 86
#define R_PPC64_GOT_TPREL16_DS 87
#define R_PPC64_GOT_TPREL16_LO_DS 88
#define R_PPC64_GOT_TPREL16_HI 89
#define R_PPC64_GOT_TPREL16_HA 90
#define R_PPC64_GOT_DTPREL16_DS 91
#define R_PPC64_GOT_DTPREL16_LO_DS 92
#define R_PPC64_GOT_DTPREL16_HI 93
#define R_PPC64_GOT_DTPREL16_HA 94
#define R_PPC64_TPREL16_DS 95
#define R_PPC64_TPREL16_LO_DS 96
#define R_PPC64_TPREL16_HIGHER 97
#define R_PPC64_TPREL16_HIGHERA 98
#define R_PPC64_TPREL16_HIGHEST 99
#define R_PPC64_TPREL16_HIGHESTA 100
#define R_PPC64_DTPREL16_DS 101
#define R_PPC64_DTPREL16_LO_DS 102
#define R_PPC64_DTPREL16_HIGHER 103
#define R_PPC64_DTPREL16_HIGHERA 104
#define R_PPC64_DTPREL16_HIGHEST 105
#define R_PPC64_DTPREL16_HIGHESTA 106
#define R_PPC64_TLSGD	107
#define R_PPC64_TLSLD	108
#define R_PPC64_TOCSAVE	109
#define R_PPC64_ADDR16_HIGH 110
#define R_PPC64_ADDR16_HIGHA 111
#define R_PPC64_TPREL16_HIGH 112
#define R_PPC64_TPREL16_HIGHA 113
#define R_PPC64_DTPREL16_HIGH 114
#define R_PPC64_DTPREL16_HIGHA 115
#define R_PPC64_REL24_NOTOC 116
#define R_PPC64_ADDR64_LOCAL 117
#define R_PPC64_ENTRY	118
#define R_PPC64_PLTSEQ	119
#define R_PPC64_PLTCALL	120
#define R_PPC64_PLTSEQ_NOTOC 121
#define R_PPC64_PLTCALL_NOTOC 122
#define R_PPC64_PCREL_OPT 123
	/* unused: 124-127. */
#define R_PPC64_D34	128
#define R_PPC64_D34_LO	129
#define R_PPC64_D34_HI30 130
#define R_PPC64_D34_HA30 131
#define R_PPC64_PCREL34	132
#define R_PPC64_GOT_PCREL34 133
#define R_PPC64_PLT_PCREL34 134
#define R_PPC64_PLT_PCREL34_NOTOC 135
#define R_PPC64_ADDR16_HIGHER34 136
#define R_PPC64_ADDR16_HIGHERA34 137
#define R_PPC64_ADDR16_HIGHEST34 138
#define R_PPC64_ADDR16_HIGHESTA34 139
#define R_PPC64_REL16_HIGHER34 140
#define R_PPC64_REL16_HIGHERA34 141
#define R_PPC64_REL16_HIGHEST34 142
#define R_PPC64_REL16_HIGHESTA34 143
#define R_PPC64_D28	144
#define R_PPC64_PCREL28	145
#define R_PPC64_TPREL34	146
#define R_PPC64_DTPREL34 147
#define R_PPC64_GOT_TLSGD_PCREL34 148
#define R_PPC64_GOT_TLSLD_PCREL34 149
#define R_PPC64_GOT_TPREL_PCREL34 150
#define R_PPC64_GOT_DTPREL_PCREL34 151
	/* unused: 152-239. */
#define R_PPC64_REL16_HIGH 240
#define R_PPC64_REL16_HIGHA 241
#define R_PPC64_REL16_HIGHER 242
#define R_PPC64_REL16_HIGHERA 243
#define R_PPC64_REL16_HIGHEST 244
#define R_PPC64_REL16_HIGHESTA 245
#define R_PPC64_REL16DX_HA 246
	/* unused: 247. */
#define R_PPC64_IRELATIVE 248
#define R_PPC64_REL16	249
#define R_PPC64_REL16_LO 250
#define R_PPC64_REL16_HI 251
#define R_PPC64_REL16_HA 252
#define R_PPC64_GNU_VTINHERIT 253
#define R_PPC64_GNU_VTENTRY 254


/* EM_PPC */
#define R_PPC_NONE	0
#define R_PPC_ADDR32	1
#define R_PPC_ADDR24	2
#define R_PPC_ADDR16	3
#define R_PPC_ADDR16_LO	4
#define R_PPC_ADDR16_HI	5
#define R_PPC_ADDR16_HA	6
#define R_PPC_ADDR14	7
#define R_PPC_ADDR14_BRTAKEN 8
#define R_PPC_ADDR14_BRNTAKEN 9
#define R_PPC_REL24	10
#define R_PPC_REL14	11
#define R_PPC_REL14_BRTAKEN 12
#define R_PPC_REL14_BRNTAKEN 13
#define R_PPC_GOT16	14
#define R_PPC_GOT16_LO	15
#define R_PPC_GOT16_HI	16
#define R_PPC_GOT16_HA	17
#define R_PPC_PLTREL24	18
#define R_PPC_COPY	19
#define R_PPC_GLOB_DAT	20
#define R_PPC_JMP_SLOT	21
#define R_PPC_RELATIVE	22
#define R_PPC_LOCAL24PC	23
#define R_PPC_UADDR32	24
#define R_PPC_UADDR16	25
#define R_PPC_REL32	26
#define R_PPC_PLT32	27
#define R_PPC_PLTREL32	28
#define R_PPC_PLT16_LO	29
#define R_PPC_PLT16_HI	30
#define R_PPC_PLT16_HA	31
	/* Not in the psABI: 32 */
#define R_PPC_SDAREL16	32
#define R_PPC_SECTOFF	33
#define R_PPC_SECTOFF_LO 34
#define R_PPC_SECTOFF_HI 35
#define R_PPC_SECTOFF_HA 36
#define R_PPC_ADDR30	37
	/* Used by the PPC64 ABI: 38-66. */
#define R_PPC_TLS	67
#define R_PPC_DTPMOD32	68
#define R_PPC_TPREL16	69
#define R_PPC_TPREL16_LO 70
#define R_PPC_TPREL16_HI 71
#define R_PPC_TPREL16_HA 72
#define R_PPC_TPREL32	73
#define R_PPC_DTPREL16	74
#define R_PPC_DTPREL16_LO 75
#define R_PPC_DTPREL16_HI 76
#define R_PPC_DTPREL16_HA 77
#define R_PPC_DTPREL32	78
#define R_PPC_GOT_TLSGD16 79
#define R_PPC_GOT_TLSGD16_LO 80
#define R_PPC_GOT_TLSGD16_HI 81
#define R_PPC_GOT_TLSGD16_HA 82
#define R_PPC_GOT_TLSLD16 83
#define R_PPC_GOT_TLSLD16_LO 84
#define R_PPC_GOT_TLSLD16_HI 85
#define R_PPC_GOT_TLSLD16_HA 86
#define R_PPC_GOT_TPREL16 87
#define R_PPC_GOT_TPREL16_LO 88
#define R_PPC_GOT_TPREL16_HI 89
#define R_PPC_GOT_TPREL16_HA 90
	/* Not in the psABI: 91-94. */
#define R_PPC_GOT_DTPREL16 91
#define R_PPC_GOT_DTPREL16_LO 92
#define R_PPC_GOT_DTPREL16_HI 93
#define R_PPC_GOT_DTPREL16_HA 94
#define R_PPC_TLSGD	95
#define R_PPC_TLSLD	96
	/* Reserved: 97-100. */
#define R_PPC_EMB_NADDR32 101
#define R_PPC_EMB_NADDR16 102
#define R_PPC_EMB_NADDR16_LO 103
#define R_PPC_EMB_NADDR16_HI 104
#define R_PPC_EMB_NADDR16_HA 105
#define R_PPC_EMB_SDAI16 106
#define R_PPC_EMB_SDA2I16 107
#define R_PPC_EMB_SDA2REL 108
#define R_PPC_EMB_SDA21	109
#define R_PPC_EMB_MRKREF 110
#define R_PPC_EMB_RELSEC16 111
#define R_PPC_EMB_RELST_LO 112
#define R_PPC_EMB_RELST_HI 113
#define R_PPC_EMB_RELST_HA 114
#define R_PPC_EMB_BIT_FLD 115
#define R_PPC_EMB_RELSDA 116
	/* Reserved: 117-179. */
#define R_PPC_DIAB_SDA21_LO 180
#define R_PPC_DIAB_SDA21_HI 181
#define R_PPC_DIAB_SDA21_HA 182
#define R_PPC_DIAB_RELSDA_LO 183
#define R_PPC_DIAB_RELSDA_HI 184
#define R_PPC_DIAB_RELSDA_HA 185
	/* Reserved: 201-200. */
#define R_PPC_EMB_SPE_DOUBLE 201
#define R_PPC_EMB_SPE_WORD 202
#define R_PPC_EMB_SPE_HALF 203
#define R_PPC_EMB_SPE_DOUBLE_SDAREL 204
#define R_PPC_EMB_SPE_WORD_SDAREL 205
#define R_PPC_EMB_SPE_HALF_SDAREL 206
#define R_PPC_EMB_SPE_DOUBLE_SDA2REL 207
#define R_PPC_EMB_SPE_WORD_SDA2REL 208
#define R_PPC_EMB_SPE_HALF_SDA2REL 209
#define R_PPC_EMB_SPE_DOUBLE_SDA0REL 210
#define R_PPC_EMB_SPE_WORD_SDA0REL 211
#define R_PPC_EMB_SPE_HALF_SDA0REL 212
#define R_PPC_EMB_SPE_DOUBLE_SDA 213
#define R_PPC_EMB_SPE_WORD_SDA 214
#define R_PPC_EMB_SPE_HALF_SDA 215
#define R_PPC_VLE_REL8	216
#define R_PPC_VLE_REL15	217
#define R_PPC_VLE_REL24	218
#define R_PPC_VLE_LO16A	219
#define R_PPC_VLE_LO16D	220
#define R_PPC_VLE_HI16A	221
#define R_PPC_VLE_HI16D	222
#define R_PPC_VLE_HA16A	223
#define R_PPC_VLE_HA16D	224
#define R_PPC_VLE_SDA21	225
#define R_PPC_VLE_SDA21_LO 226
#define R_PPC_VLE_SDAREL_LO16A 227
#define R_PPC_VLE_SDAREL_LO16D 228
#define R_PPC_VLE_SDAREL_HI16A 229
#define R_PPC_VLE_SDAREL_HI16D 230
#define R_PPC_VLE_SDAREL_HA16A 231
#define R_PPC_VLE_SDAREL_HA16D 232
#define R_PPC_VLE_ADDR20 233
	/* Reserved: 234-247. */
#define R_PPC_IRELATIVE	248 /* GNU spelling */
#define R_PPC_REL16	249
#define R_PPC_REL16_LO	250
#define R_PPC_REL16_HI	251
#define R_PPC_REL16_HA	252
	/* Reserved: 253-255. */


/* EM_RISCV */
#define R_RISCV_NONE	0
#define R_RISCV_32	1
#define R_RISCV_64	2
#define R_RISCV_RELATIVE 3
#define R_RISCV_COPY	4
#define R_RISCV_JUMP_SLOT 5
#define R_RISCV_TLS_DTPMOD32 6
#define R_RISCV_TLS_DTPMOD64 7
#define R_RISCV_TLS_DTPREL32 8
#define R_RISCV_TLS_DTPREL64 9
#define R_RISCV_TLS_TPREL32 10
#define R_RISCV_TLS_TPREL64 11
#define R_RISCV_TLSDESC	12
	/* unused: 13-15 */
#define R_RISCV_BRANCH	16
#define R_RISCV_JAL	17
#define R_RISCV_CALL	18
#define R_RISCV_CALL_PLT 19
#define R_RISCV_GOT_HI20 20
#define R_RISCV_TLS_GOT_HI20 21
#define R_RISCV_TLS_GD_HI20 22
#define R_RISCV_PCREL_HI20 23
#define R_RISCV_PCREL_LO12_I 24
#define R_RISCV_PCREL_LO12_S 25
#define R_RISCV_HI20	26
#define R_RISCV_LO12_I	27
#define R_RISCV_LO12_S	28
#define R_RISCV_TPREL_HI20 29
#define R_RISCV_TPREL_LO12_I 30
#define R_RISCV_TPREL_LO12_S 31
#define R_RISCV_TPREL_ADD 32
#define R_RISCV_ADD8	33
#define R_RISCV_ADD16	34
#define R_RISCV_ADD32	35
#define R_RISCV_ADD64	36
#define R_RISCV_SUB8	37
#define R_RISCV_SUB16	38
#define R_RISCV_SUB32	39
#define R_RISCV_SUB64	40
#define R_RISCV_GOT32_PCREL 41
	/* reserved: 42 */
#define R_RISCV_ALIGN	43
#define R_RISCV_RVC_BRANCH 44
#define R_RISCV_RVC_JUMP 45
	/* reserved: 46-50 */
#define R_RISCV_RELAX	51
#define R_RISCV_SUB6	52
#define R_RISCV_SET6	53
#define R_RISCV_SET8	54
#define R_RISCV_SET16	55
#define R_RISCV_SET32	56
#define R_RISCV_32_PCREL 57
#define R_RISCV_IRELATIVE 58
#define R_RISCV_PLT32	59
#define R_RISCV_SET_ULEB128 60
#define R_RISCV_SUB_ULEB128 61
#define R_RISCV_TLSDESC_HI20 62
#define R_RISCV_TLSDESC_LOAD_LO12 63
#define R_RISCV_TLSDESC_ADD_LO12 64
#define R_RISCV_TLSDESC_CALL 65
	/* reserved: 66-190 */
#define R_RISCV_VENDOR	191
	/* reserved: 192-255 */


/* EM_S390 */
#define R_390_NONE	0
#define R_390_8		1
#define R_390_12	2
#define R_390_16	3
#define R_390_32	4
#define R_390_PC32	5
#define R_390_GOT12	6
#define R_390_GOT32	7
#define R_390_PLT32	8
#define R_390_COPY	9
#define R_390_GLOB_DAT	10
#define R_390_JMP_SLOT	11
#define R_390_RELATIVE	12
#define R_390_GOTOFF	13
#define R_390_GOTPC	14
#define R_390_GOT16	15
#define R_390_PC16	16
#define R_390_PC16DBL	17
#define R_390_PLT16DBL	18
#define R_390_PC32DBL	19
#define R_390_PLT32DBL	20
#define R_390_GOTPCDBL	21
#define R_390_64	22
#define R_390_PC64	23
#define R_390_GOT64	24
#define R_390_PLT64	25
#define R_390_GOTENT	26


/* SuperH */
#define R_SH_NONE	0
#define R_SH_DIR32	1
#define R_SH_REL32	2
#define R_SH_DIR8WPN	3
#define R_SH_IND12W	4
#define R_SH_DIR8WPL	5
#define R_SH_DIR8WPZ	6
#define R_SH_DIR8BP	7
#define R_SH_DIR8W	8
#define R_SH_DIR8L	9
#define R_SH_LOOP_START	10
#define R_SH_LOOP_END	11
	/* Unused: 12-21 */
#define R_SH_GNU_VTINHERIT 22
#define R_SH_GNU_VTENTRY 23
#define R_SH_SWITCH8	24
#define R_SH_SWITCH16	25
#define R_SH_SWITCH32	26
#define R_SH_USES	27
#define R_SH_COUNT	28
#define R_SH_ALIGN	29
#define R_SH_CODE	30
#define R_SH_DATA	31
#define R_SH_LABEL	32
#define R_SH_DIR16	33
#define R_SH_DIR8	34
#define R_SH_DIR8UL	35
#define R_SH_DIR8UW	36
#define R_SH_DIR8U	37
#define R_SH_DIR8SW	38
#define R_SH_DIR8S	39
#define R_SH_DIR4UL	40
#define R_SH_DIR4UW	41
#define R_SH_DIR4U	42
#define R_SH_PSHA	43
#define R_SH_PSHL	44
#define R_SH_DIR5U	45
#define R_SH_DIR6U	46
#define R_SH_DIR6S	47
#define R_SH_DIR10S	48
#define R_SH_DIR10SW	49
#define R_SH_DIR10SL	50
#define R_SH_DIR10SQ	51
	/* Unused: 52 */
#define R_SH_DIR16S	53
	/* Unused: 54-143 */
	/* TLS relocations */
#define R_SH_TLS_GD_32	144
#define R_SH_TLS_LD_32	145
#define R_SH_TLS_LDO_32	146
#define R_SH_TLS_IE_32	147
#define R_SH_TLS_LE_32	148
#define R_SH_TLS_DTPMOD32 149
#define R_SH_TLS_DTPOFF32 150
#define R_SH_TLS_TPOFF32 151
	/* Unused: 152-159 */
#define R_SH_GOT32	160
#define R_SH_PLT32	161
#define R_SH_COPY	162
#define R_SH_GLOB_DAT	163
#define R_SH_JMP_SLOT	164
#define R_SH_RELATIVE	165
#define R_SH_GOTOFF	166
#define R_SH_GOTPC	167
#define R_SH_GOTPLT32	168
#define R_SH_GOT_LOW16	169
#define R_SH_GOT_MEDLOW16 170
#define R_SH_GOT_MEDHI16 171
#define R_SH_GOT_HI16	172
#define R_SH_GOTPLT_LOW16 173
#define R_SH_GOTPLT_MEDLOW16 174
#define R_SH_GOTPLT_MEDHI16 175
#define R_SH_GOTPLT_HI16 176
#define R_SH_PLT_LOW16	177
#define R_SH_PLT_MEDLOW16 178
#define R_SH_PLT_MEDHI16 179
#define R_SH_PLT_HI16	180
#define R_SH_GOTOFF_LOW16 181
#define R_SH_GOTOFF_MEDLOW16 182
#define R_SH_GOTOFF_MEDHI16 183
#define R_SH_GOTOFF_HI16 184
#define R_SH_GOTPC_LOW16 185
#define R_SH_GOTPC_MEDLOW16 186
#define R_SH_GOTPC_MEDHI16 187
#define R_SH_GOTPC_HI16	188
#define R_SH_GOT10BY4	189
#define R_SH_GOTPLT10BY4 190
#define R_SH_GOT10BY8	191
#define R_SH_GOTPLT10BY8 192
#define R_SH_COPY64	193
#define R_SH_GLOB_DAT64	194
#define R_SH_JMP_SLOT64	195
#define R_SH_RELATIVE64	196
	/* Unused: 197-200 */
	/* FDPIC ABI */
#define R_SH_GOT20	201
#define R_SH_GOTOFF20	202
#define R_SH_GOTFUNCDESC 203
#define R_SH_GOTFUNCDESC20 204
#define R_SH_GOTOFFFUNCDESC 205
#define R_SH_GOTOFFFUNCDESC20 206
#define R_SH_FUNCDESC	207
#define R_SH_FUNCDESC_VALUE 208
	/* Unused: 209-241 */
#define R_SH_SHMEDIA_CODE 242
#define R_SH_PT_16	243
#define R_SH_IMMS16	244
#define R_SH_IMMU16	245
#define R_SH_IMM_LOW16	246
#define R_SH_IMM_LOW16_PCREL 247
#define R_SH_IMM_MEDLOW16 248
#define R_SH_IMM_MEDLOW16_PCREL 249
#define R_SH_IMM_MEDHI16 250
#define R_SH_IMM_MEDHI16_PCREL 251
#define R_SH_IMM_HI16	252
#define R_SH_IMM_HI16_PCREL 253
#define R_SH_64		254
#define R_SH_64_PCREL	255


/* EM_SPARC */
#define R_SPARC_NONE	0
#define R_SPARC_8	1
#define R_SPARC_16	2
#define R_SPARC_32	3
#define R_SPARC_DISP8	4
#define R_SPARC_DISP16	5
#define R_SPARC_DISP32	6
#define R_SPARC_WDISP30	7
#define R_SPARC_WDISP22	8
#define R_SPARC_HI22	9
#define R_SPARC_22	10
#define R_SPARC_13	11
#define R_SPARC_LO10	12
#define R_SPARC_GOT10	13
#define R_SPARC_GOT13	14
#define R_SPARC_GOT22	15
#define R_SPARC_PC10	16
#define R_SPARC_PC22	17
#define R_SPARC_WPLT30	18
#define R_SPARC_COPY	19
#define R_SPARC_GLOB_DAT 20
#define R_SPARC_JMP_SLOT 21
#define R_SPARC_RELATIVE 22
#define R_SPARC_UA32	23
#define R_SPARC_PLT32	24
#define R_SPARC_HIPLT22	25
#define R_SPARC_LOPLT10	26
#define R_SPARC_PCPLT32	27
#define R_SPARC_PCPLT22	28
#define R_SPARC_PCPLT10	29
#define R_SPARC_10	30
#define R_SPARC_11	31
#define R_SPARC_64	32
#define R_SPARC_OLO10	33
#define R_SPARC_HH22	34
#define R_SPARC_HM10	35
#define R_SPARC_LM22	36
#define R_SPARC_PC_HH22	37
#define R_SPARC_PC_HM10	38
#define R_SPARC_PC_LM22	39
#define R_SPARC_WDISP16	40
#define R_SPARC_WDISP19	41
	/* unused: 42 */
#define R_SPARC_7	43
#define R_SPARC_5	44
#define R_SPARC_6	45
#define R_SPARC_DISP64	46
#define R_SPARC_PLT64	47
#define R_SPARC_HIX22	48
#define R_SPARC_LOX10	49
#define R_SPARC_H44	50
#define R_SPARC_M44	51
#define R_SPARC_L44	52
#define R_SPARC_REGISTER 53
#define R_SPARC_UA64	54
#define R_SPARC_UA16	55
#define R_SPARC_TLS_GD_HI22 56
#define R_SPARC_TLS_GD_LO10 57
#define R_SPARC_TLS_GD_ADD 58
#define R_SPARC_TLS_GD_CALL 59
#define R_SPARC_TLS_LDM_HI22 60
#define R_SPARC_TLS_LDM_LO10 61
#define R_SPARC_TLS_LDM_ADD 62
#define R_SPARC_TLS_LDM_CALL 63
#define R_SPARC_TLS_LDO_HIX22 64
#define R_SPARC_TLS_LDO_LOX10 65
#define R_SPARC_TLS_LDO_ADD 66
#define R_SPARC_TLS_IE_HI22 67
#define R_SPARC_TLS_IE_LO10 68
#define R_SPARC_TLS_IE_LD 69
#define R_SPARC_TLS_IE_LDX 70
#define R_SPARC_TLS_IE_ADD 71
#define R_SPARC_TLS_LE_HIX22 72
#define R_SPARC_TLS_LE_LOX10 73
#define R_SPARC_TLS_DTPMOD32 74
#define R_SPARC_TLS_DTPMOD64 75
#define R_SPARC_TLS_DTPOFF32 76
#define R_SPARC_TLS_DTPOFF64 77
#define R_SPARC_TLS_TPOFF32 78
#define R_SPARC_TLS_TPOFF64 79
#define R_SPARC_GOTDATA_HIX22 80
#define R_SPARC_GOTDATA_LOX10 81
#define R_SPARC_GOTDATA_OP_HIX22 82
#define R_SPARC_GOTDATA_OP_LOX10 83
#define R_SPARC_GOTDATA_OP 84
#define R_SPARC_H34	85
#define R_SPARC_SIZE32	86
#define R_SPARC_SIZE64	87
#define R_SPARC_WDISP10	88
#define R_SPARC_JMP_IREL 248 /* GNU */
#define R_SPARC_IRELATIVE 249 /* GNU */


/* EM_VAX */
#define R_VAX_NONE	0
#define R_VAX_32	1
#define R_VAX_16	2
#define R_VAX_8		3
#define R_VAX_PC32	4
#define R_VAX_PC16	5
#define R_VAX_PC8	6
#define R_VAX_GOT32	7
#define R_VAX_PLT32	13
#define R_VAX_COPY	19
#define R_VAX_GLOB_DAT	20
#define R_VAX_JMP_SLOT	21
#define R_VAX_RELATIVE	22


/* EM_X86_64 */
#define R_X86_64_NONE	0
#define R_X86_64_64	1
#define R_X86_64_PC32	2
#define R_X86_64_GOT32	3
#define R_X86_64_PLT32	4
#define R_X86_64_COPY	5
#define R_X86_64_GLOB_DAT 6
#define R_X86_64_JUMP_SLOT 7
#define R_X86_64_RELATIVE 8
#define R_X86_64_GOTPCREL 9
#define R_X86_64_32	10
#define R_X86_64_32S	11
#define R_X86_64_16	12
#define R_X86_64_PC16	13
#define R_X86_64_8	14
#define R_X86_64_PC8	15
#define R_X86_64_DTPMOD64 16
#define R_X86_64_DTPOFF64 17
#define R_X86_64_TPOFF64 18
#define R_X86_64_TLSGD	19
#define R_X86_64_TLSLD	20
#define R_X86_64_DTPOFF32 21
#define R_X86_64_GOTTPOFF 22
#define R_X86_64_TPOFF32 23
#define R_X86_64_PC64	24
#define R_X86_64_GOTOFF64 25
#define R_X86_64_GOTPC32 26
#define R_X86_64_GOT64	27
#define R_X86_64_GOTPCREL64 28
#define R_X86_64_GOTPC64 29
	/* deprecated: 30 */
#define R_X86_64_PLTOFF64 31
#define R_X86_64_SIZE32	32
#define R_X86_64_SIZE64	33
#define R_X86_64_GOTPC32_TLSDESC 34
#define R_X86_64_TLSDESC_CALL 35
#define R_X86_64_TLSDESC 36
#define R_X86_64_IRELATIVE 37
#define R_X86_64_RELATIVE64 38
	/* deprecated: 39-40 */
#define R_X86_64_GOTPCRELX 41
#define R_X86_64_REX_GOTPCRELX 42
#define R_X86_64_CODE_4_GOTPCRELX 43
#define R_X86_64_CODE_4_GOTTPOFF 44
#define R_X86_64_CODE_4_GOTPC32_TLSDESC 45
#define R_X86_64_CODE_5_GOTPCRELX 46
#define R_X86_64_CODE_5_GOTTPOFF 47
#define R_X86_64_CODE_5_GOTPC32_TLSDESC 48
#define R_X86_64_CODE_6_GOTPCRELX 49
#define R_X86_64_CODE_6_GOTTPOFF 50
#define R_X86_64_CODE_6_GOTPC32_TLSDESC 51



/*
 * Obsolete relocation types.
 */

#define R_ARM_PC13	4
#define R_ARM_THM_PC22	10
#define R_ARM_AMP_VCALL9 12
#define R_ARM_SWI24	13
#define R_ARM_GOTOFF	24
#define R_ARM_GOTPC	25
#define R_ARM_GOT32	26
#define R_ARM_THM_PC11	102
#define R_ARM_THM_PC9	103


#define R_PPC64_ADDR14_BRTAKEN 8
#define R_PPC64_ADDR14_BRNTAKEN 9
#define R_PPC64_REL14_BRTAKEN 12
#define R_PPC64_REL14_BRNTAKEN 13
#define R_PPC64_ADDR30	37


#define R_RISCV_GNU_VTINHERIT 41
#define R_RISCV_GNU_VTENTRY 42
#define R_RISCV_RVC_LUI	46
#define R_RISCV_GPREL_I	47
#define R_RISCV_GPREL_S	48
#define R_RISCV_TPREL_I	49
#define R_RISCV_TPREL_S	50


#define R_SPARC_GLOB_JMP 42


#define R_X86_64_GOTPLT64 30
#define R_X86_64_PC32_BND 39
#define R_X86_64_PLT32_BND 40



/*
 * Alternate spellings for relocation type symbols.
 */


#define R_386_JMP_SLOT	R_386_JUMP_SLOT


#define R_AARCH64_TLS_TPREL64 R_AARCH64_TLS_TPREL


#define R_ALPHA_TLS_GD	R_ALPHA_TLSGD /* NetBSD spelling */
#define R_ALPHA_IMMED_GP_16 R_ALPHA_GPREL16 /* NetBSD spelling */


#define R_IA64_NONE	R_IA_64_NONE
#define R_IA64_IMM14	R_IA_64_IMM14
#define R_IA64_IMM22	R_IA_64_IMM22
#define R_IA64_IMM64	R_IA_64_IMM64
#define R_IA64_DIR32MSB	R_IA_64_DIR32MSB
#define R_IA64_DIR32LSB	R_IA_64_DIR32LSB
#define R_IA64_DIR64MSB	R_IA_64_DIR64MSB
#define R_IA64_DIR64LSB	R_IA_64_DIR64LSB
#define R_IA64_GPREL22	R_IA_64_GPREL22
#define R_IA64_GPREL64I	R_IA_64_GPREL64I
#define R_IA64_GPREL64MSB R_IA_64_GPREL64MSB
#define R_IA64_GPREL64LSB R_IA_64_GPREL64LSB
#define R_IA64_LTOFF22	R_IA_64_LTOFF22
#define R_IA64_LTOFF64I	R_IA_64_LTOFF64I
#define R_IA64_PLTOFF22	R_IA_64_PLTOFF22
#define R_IA64_PLTOFF64I R_IA_64_PLTOFF64I
#define R_IA64_PLTOFF64MSB R_IA_64_PLTOFF64MSB
#define R_IA64_PLTOFF64LSB R_IA_64_PLTOFF64LSB
#define R_IA64_FPTR64I	R_IA_64_FPTR64I
#define R_IA64_FPTR32MSB R_IA_64_FPTR32MSB
#define R_IA64_FPTR32LSB R_IA_64_FPTR32LSB
#define R_IA64_FPTR64MSB R_IA_64_FPTR64MSB
#define R_IA64_FPTR64LSB R_IA_64_FPTR64LSB
#define R_IA64_PCREL21B	R_IA_64_PCREL21B
#define R_IA64_PCREL21M	R_IA_64_PCREL21M
#define R_IA64_PCREL21F	R_IA_64_PCREL21F
#define R_IA64_PCREL32MSB R_IA_64_PCREL32MSB
#define R_IA64_PCREL32LSB R_IA_64_PCREL32LSB
#define R_IA64_PCREL64MSB R_IA_64_PCREL64MSB
#define R_IA64_PCREL64LSB R_IA_64_PCREL64LSB
#define R_IA64_LTOFF_FPTR22 R_IA_64_LTOFF_FPTR22
#define R_IA64_LTOFF_FPTR64I R_IA_64_LTOFF_FPTR64I
#define R_IA64_LTOFF_FPTR32MSB R_IA_64_LTOFF_FPTR32MSB
#define R_IA64_LTOFF_FPTR32LSB R_IA_64_LTOFF_FPTR32LSB
#define R_IA64_LTOFF_FPTR64MSB R_IA_64_LTOFF_FPTR64MSB
#define R_IA64_LTOFF_FPTR64LSB R_IA_64_LTOFF_FPTR64LSB
#define R_IA64_SEGREL32MSB R_IA_64_SEGREL32MSB
#define R_IA64_SEGREL32LSB R_IA_64_SEGREL32LSB
#define R_IA64_SEGREL64MSB R_IA_64_SEGREL64MSB
#define R_IA64_SEGREL64LSB R_IA_64_SEGREL64LSB
#define R_IA64_SECREL32MSB R_IA_64_SECREL32MSB
#define R_IA64_SECREL32LSB R_IA_64_SECREL32LSB
#define R_IA64_SECREL64MSB R_IA_64_SECREL64MSB
#define R_IA64_SECREL64LSB R_IA_64_SECREL64LSB
#define R_IA64_REL32MSB	R_IA_64_REL32MSB
#define R_IA64_REL32LSB	R_IA_64_REL32LSB
#define R_IA64_REL64MSB	R_IA_64_REL64MSB
#define R_IA64_REL64LSB	R_IA_64_REL64LSB
#define R_IA64_LTV32MSB	R_IA_64_LTV32MSB
#define R_IA64_LTV32LSB	R_IA_64_LTV32LSB
#define R_IA64_LTV64MSB	R_IA_64_LTV64MSB
#define R_IA64_LTV64LSB	R_IA_64_LTV64LSB
#define R_IA64_IPLTMSB	R_IA_64_IPLTMSB
#define R_IA64_IPLTLSB	R_IA_64_IPLTLSB
#define R_IA64_SUB	R_IA_64_SUB
#define R_IA64_LTOFF22X	R_IA_64_LTOFF22X
#define R_IA64_LDXMOV	R_IA_64_LDXMOV
#define R_IA64_TPREL14	R_IA_64_TPREL14
#define R_IA64_TPREL22	R_IA_64_TPREL22
#define R_IA64_TPREL64I	R_IA_64_TPREL64I
#define R_IA64_TPREL64MSB R_IA_64_TPREL64MSB
#define R_IA64_TPREL64LSB R_IA_64_TPREL64LSB
#define R_IA64_LTOFF_TPREL22 R_IA_64_LTOFF_TPREL22
#define R_IA64_DTPMOD64MSB R_IA_64_DTPMOD64MSB
#define R_IA64_DTPMOD64LSB R_IA_64_DTPMOD64LSB
#define R_IA64_LTOFF_DTPMOD22 R_IA_64_LTOFF_DTPMOD22
#define R_IA64_DTPREL14	R_IA_64_DTPREL14
#define R_IA64_DTPREL22	R_IA_64_DTPREL22
#define R_IA64_DTPREL64I R_IA_64_DTPREL64I
#define R_IA64_DTPREL32MSB R_IA_64_DTPREL32MSB
#define R_IA64_DTPREL32LSB R_IA_64_DTPREL32LSB
#define R_IA64_DTPREL64MSB R_IA_64_DTPREL64MSB
#define R_IA64_DTPREL64LSB R_IA_64_DTPREL64LSB
#define R_IA64_LTOFF_DTPREL22 R_IA_64_LTOFF_DTPREL22


#define R_MIPS_ADD	R_MIPS_32
#define R_MIPS_REL	R_MIPS_REL32
#define R_MIPS_GPREL	R_MIPS_GPREL16
#define R_MIPS_GOT	R_MIPS_GOT16
#define R_MIPS_CALL	R_MIPS_CALL16
#define R_MIPS_GOT_OFST	21 /* MIPS64 psABI, GNU binutils, LLVM. */
#define R_MIPS_GOT_HI16	22 /* MIPS64 psABI, GNU binutils, LLVM. */
#define R_MIPS_CALL_HI16 R_MIPS_CALLHI16 /* MIPS64 psABI, NetBSD */
#define R_MIPS_CALL_LO16 R_MIPS_CALLLO16 /* MIPS64 psABI, NetBSD */


#define R_PARISC_TLS_LE21L R_PARISC_TPREL21L
#define R_PARISC_TLS_LE14R R_PARISC_TPREL14R
#define R_PARISC_TLS_IE21L R_PARISC_LTOFF_TP21L
#define R_PARISC_TLS_IE14R R_PARISC_LTOFF_TP14R
#define R_PARISC_TLS_TPREL32 R_PARISC_TPREL32
#define R_PARISC_TLS_TPREL64 R_PARISC_TPREL64


#define R_PPC_TOC16	47 /* Elfutils spelling */


#define R_RISCV_JMP_SLOT R_RISCV_JUMP_SLOT /* NetBSD */


#define R_AMD64_NONE	R_X86_64_NONE
#define R_AMD64_64	R_X86_64_64
#define R_AMD64_PC32	R_X86_64_PC32
#define R_AMD64_GOT32	R_X86_64_GOT32
#define R_AMD64_PLT32	R_X86_64_PLT32
#define R_AMD64_COPY	R_X86_64_COPY
#define R_AMD64_GLOB_DAT R_X86_64_GLOB_DAT
#define R_AMD64_JUMP_SLOT R_X86_64_JUMP_SLOT
#define R_AMD64_RELATIVE R_X86_64_RELATIVE
#define R_AMD64_GOTPCREL R_X86_64_GOTPCREL
#define R_AMD64_32	R_X86_64_32
#define R_AMD64_32S	R_X86_64_32S
#define R_AMD64_16	R_X86_64_16
#define R_AMD64_PC16	R_X86_64_PC16
#define R_AMD64_8	R_X86_64_8
#define R_AMD64_PC8	R_X86_64_PC8
#define R_AMD64_PC64	R_X86_64_PC64
#define R_AMD64_GOTOFF64 R_X86_64_GOTOFF64
#define R_AMD64_GOTPC32	R_X86_64_PC32



/*
 * MIPS ABI related.
 */

#define E_MIPS_ABI_O32	0x00001000 /* MIPS 32 bit ABI (UCODE) */
#define E_MIPS_ABI_O64	0x00002000 /* UCODE MIPS 64 bit ABI */
#define E_MIPS_ABI_EABI32 0x00003000 /* Embedded ABI for 32-bit */
#define E_MIPS_ABI_EABI64 0x00004000 /* Embedded ABI for 64-bit */


/**
 ** ELF Types.
 **/

typedef uint32_t	Elf32_Addr;	/* Program address. */
typedef uint8_t		Elf32_Byte;	/* Unsigned tiny integer. */
typedef uint16_t	Elf32_Half;	/* Unsigned medium integer. */
typedef uint32_t	Elf32_Off;	/* File offset. */
typedef uint16_t	Elf32_Section;	/* Section index. */
typedef int32_t		Elf32_Sword;	/* Signed integer. */
typedef uint32_t	Elf32_Word;	/* Unsigned integer. */
typedef uint64_t	Elf32_Lword;	/* Unsigned long integer. */

typedef uint64_t	Elf64_Addr;	/* Program address. */
typedef uint8_t		Elf64_Byte;	/* Unsigned tiny integer. */
typedef uint16_t	Elf64_Half;	/* Unsigned medium integer. */
typedef uint64_t	Elf64_Off;	/* File offset. */
typedef uint16_t	Elf64_Section;	/* Section index. */
typedef int32_t		Elf64_Sword;	/* Signed integer. */
typedef uint32_t	Elf64_Word;	/* Unsigned integer. */
typedef uint64_t	Elf64_Lword;	/* Unsigned long integer. */
typedef uint64_t	Elf64_Xword;	/* Unsigned long integer. */
typedef int64_t		Elf64_Sxword;	/* Signed long integer. */

typedef uint8_t		Elf_Byte;	/* Synonym used in NetBSD. */

/*
 * Capability descriptors.
 */

/* 32-bit capability descriptor. */
typedef struct {
	Elf32_Word	c_tag;	     /* Type of entry. */
	union {
		Elf32_Word	c_val; /* Integer value. */
		Elf32_Addr	c_ptr; /* Pointer value. */
	} c_un;
} Elf32_Cap;

/* 64-bit capability descriptor. */
typedef struct {
	Elf64_Xword	c_tag;	     /* Type of entry. */
	union {
		Elf64_Xword	c_val; /* Integer value. */
		Elf64_Addr	c_ptr; /* Pointer value. */
	} c_un;
} Elf64_Cap;

/*
 * MIPS .conflict section entries.
 */

/* 32-bit entry. */
typedef struct {
	Elf32_Addr	c_index;
} Elf32_Conflict;

/* 64-bit entry. */
typedef struct {
	Elf64_Addr	c_index;
} Elf64_Conflict;

/*
 * Dynamic section entries.
 */

/* 32-bit entry. */
typedef struct {
	Elf32_Sword	d_tag;	     /* Type of entry. */
	union {
		Elf32_Word	d_val; /* Integer value. */
		Elf32_Addr	d_ptr; /* Pointer value. */
	} d_un;
} Elf32_Dyn;

/* 64-bit entry. */
typedef struct {
	Elf64_Sxword	d_tag;	     /* Type of entry. */
	union {
		Elf64_Xword	d_val; /* Integer value. */
		Elf64_Addr	d_ptr; /* Pointer value; */
	} d_un;
} Elf64_Dyn;


/*
 * The executable header (EHDR).
 */

/* 32 bit EHDR. */
typedef struct {
	Elf32_Byte      e_ident[EI_NIDENT]; /* ELF identification. */
	Elf32_Half      e_type;	     /* Object file type (ET_*). */
	Elf32_Half      e_machine;   /* Machine type (EM_*). */
	Elf32_Word      e_version;   /* File format version (EV_*). */
	Elf32_Addr      e_entry;     /* Start address. */
	Elf32_Off       e_phoff;     /* File offset to the PHDR table. */
	Elf32_Off       e_shoff;     /* File offset to the SHDRheader. */
	Elf32_Word      e_flags;     /* Flags (EF_*). */
	Elf32_Half      e_ehsize;    /* Elf header size in bytes. */
	Elf32_Half      e_phentsize; /* PHDR table entry size in bytes. */
	Elf32_Half      e_phnum;     /* Number of PHDR entries. */
	Elf32_Half      e_shentsize; /* SHDR table entry size in bytes. */
	Elf32_Half      e_shnum;     /* Number of SHDR entries. */
	Elf32_Half      e_shstrndx;  /* Index of section name string table. */
} Elf32_Ehdr;


/* 64 bit EHDR. */
typedef struct {
	Elf64_Byte      e_ident[EI_NIDENT]; /* ELF identification. */
	Elf64_Half      e_type;	     /* Object file type (ET_*). */
	Elf64_Half      e_machine;   /* Machine type (EM_*). */
	Elf64_Word      e_version;   /* File format version (EV_*). */
	Elf64_Addr      e_entry;     /* Start address. */
	Elf64_Off       e_phoff;     /* File offset to the PHDR table. */
	Elf64_Off       e_shoff;     /* File offset to the SHDRheader. */
	Elf64_Word      e_flags;     /* Flags (EF_*). */
	Elf64_Half      e_ehsize;    /* Elf header size in bytes. */
	Elf64_Half      e_phentsize; /* PHDR table entry size in bytes. */
	Elf64_Half      e_phnum;     /* Number of PHDR entries. */
	Elf64_Half      e_shentsize; /* SHDR table entry size in bytes. */
	Elf64_Half      e_shnum;     /* Number of SHDR entries. */
	Elf64_Half      e_shstrndx;  /* Index of section name string table. */
} Elf64_Ehdr;


/*
 * Shared object information.
 */

/* 32-bit entry. */
typedef struct {
	Elf32_Word l_name;	     /* The name of a shared object. */
	Elf32_Word l_time_stamp;     /* 32-bit timestamp. */
	Elf32_Word l_checksum;	     /* Checksum of visible symbols, sizes. */
	Elf32_Word l_version;	     /* Interface version string index. */
	Elf32_Word l_flags;	     /* Flags (LL_*). */
} Elf32_Lib;

/* 64-bit entry. */
typedef struct {
	Elf64_Word l_name;	     /* The name of a shared object. */
	Elf64_Word l_time_stamp;     /* 32-bit timestamp. */
	Elf64_Word l_checksum;	     /* Checksum of visible symbols, sizes. */
	Elf64_Word l_version;	     /* Interface version string index. */
	Elf64_Word l_flags;	     /* Flags (LL_*). */
} Elf64_Lib;


#define LL_NONE		0 /* no flags */
#define LL_EXACT_MATCH	0x1 /* require an exact match */
#define LL_IGNORE_INT_VER 0x2 /* ignore version incompatibilities */
#define LL_REQUIRE_MINOR 0x4
#define LL_EXPORTS	0x8
#define LL_DELAY_LOAD	0x10
#define LL_DELTA	0x20


/*
 * ELF Note types.
 */

#define NT_ABI_TAG	1 /* Tag indicating the OS ABI */

/* GNU note types */
#define NT_GNU_ABI_TAG	1 /* GNU ABI version */
#define NT_GNU_HWCAP	2 /* Hardware capabilities */
#define NT_GNU_BUILD_ID	3 /* Build id, set by ld(1) */
#define NT_GNU_GOLD_VERSION 4 /* Version number of the GNU gold linker */

/* FreeBSD note types. */
#define NT_FREEBSD_ABI_TAG 1 /* FreeBSD ABI version */
#define NT_FREEBSD_NOINIT_TAG 2 /* FreeBSD no .init tag */
#define NT_FREEBSD_ARCH_TAG 3 /* FreeBSD arch tag */
#define NT_FREEBSD_FEATURE_CTL 4 /* FreeBSD feature control */

/* Note types used in core files. */
#define NT_PRSTATUS	1 /* Process status */
#define NT_FPREGSET	2 /* Floating point information */
#define NT_PRPSINFO	3 /* Process information */
#define NT_AUXV		6 /* Auxiliary vector */
#define NT_PSTATUS	10 /* Linux process status */
#define NT_FPREGS	12 /* Linux floating point regset */
#define NT_PSINFO	13 /* Linux process information */
#define NT_LWPSTATUS	16 /* Linux lwpstatus_t type */
#define NT_LWPSINFO	17 /* Linux lwpinfo_t type */
#define NT_PRXFPREG	0x46E62B7FU /* Linux user_xfpregs structure */

/* Aliases for the ABI tag. */

#define NT_NETBSD_IDENT	NT_ABI_TAG
#define NT_OPENBSD_IDENT NT_ABI_TAG


/*
 * Note descriptors.
 */

typedef	struct {
	uint32_t	n_namesz;    /* Length of note's name. */
	uint32_t	n_descsz;    /* Length of note's value. */
	uint32_t	n_type;	     /* Type of note. */
} Elf_Note;

typedef Elf_Note Elf32_Nhdr;	     /* 32-bit note header. */
typedef Elf_Note Elf64_Nhdr;	     /* 64-bit note header. */

/*
 * MIPS ELF options descriptor header.
 */

typedef struct {
	Elf64_Byte	kind;        /* Type of options. */
	Elf64_Byte     	size;	     /* Size of option descriptor. */
	Elf64_Half	section;     /* Index of section affected. */
	Elf64_Word	info;        /* Kind-specific information. */
} Elf_Options;

/*
 * Option kinds.
 */

#define ODK_NULL	0 /* undefined */
#define ODK_REGINFO	1 /* register usage info */
#define ODK_EXCEPTIONS	2 /* exception processing info */
#define ODK_PAD		3 /* section padding */
#define ODK_HWPATCH	4 /* hardware patch applied */
#define ODK_FILL	5 /* fill value used by linker */
#define ODK_TAGS	6 /* reserved space for tools */
#define ODK_HWAND	7 /* hardware AND patch applied */
#define ODK_HWOR	8 /* hardware OR patch applied */
#define ODK_GP_GROUP	9 /* GP group to use for text/data sections */
#define ODK_IDENT	10 /* ID information */
#define ODK_PAGESIZE	11 /* page size information */


/*
 * ODK_EXCEPTIONS info field masks.
 */

#define OEX_FPU_MIN	0x0000001FU /* minimum FPU exception which must be enabled */
#define OEX_FPU_MAX	0x00001F00U /* maximum FPU exception which can be enabled */
#define OEX_PAGE0	0x00010000U /* page zero must be mapped */
#define OEX_SMM		0x00020000U /* run in sequential memory mode */
#define OEX_PRECISEFP	0x00040000U /* run in precise FP exception mode */
#define OEX_DISMISS	0x00080000U /* dismiss invalid address traps */


/*
 * ODK_PAD info field masks.
 */

#define OPAD_PREFIX	0x0001
#define OPAD_POSTFIX	0x0002
#define OPAD_SYMBOL	0x0004


/*
 * ODK_HWPATCH info field masks and ODK_HWAND/ODK_HWOR info field
 * and hwp_flags[12] masks.
 */

#define OHW_R4KEOP	0x00000001U /* patch for R4000 branch at end-of-page bug */
#define OHW_R8KPFETCH	0x00000002U /* R8000 prefetch bug may occur */
#define OHW_R5KEOP	0x00000004U /* patch for R5000 branch at end-of-page bug */
#define OHW_R5KCVTL	0x00000008U /* R5000 cvt.[ds].l bug: clean == 1 */
#define OHW_R10KLDL	0x00000010U /* need patch for R10000 misaligned load */
#define OHWA0_R4KEOP_CHECKED 0x00000001U /* object checked for R4000 end-of-page bug */
#define OHWA0_R4KEOP_CLEAN 0x00000002U /* object verified clean for R4000 end-of-page bug */
#define OHWO0_FIXADE	0x00000001U /* object requires call to fixade */


/*
 * ODK_IDENT/ODK_GP_GROUP info field masks.
 */

#define OGP_GROUP	0x0000FFFFU /* GP group number */
#define OGP_SELF	0x00010000U /* GP group is self-contained */


/*
 * MIPS ELF register info descriptor.
 */

/* 32 bit RegInfo entry. */
typedef struct {
	Elf32_Word	ri_gprmask;  /* Mask of general register used. */
	Elf32_Word	ri_cprmask[4]; /* Mask of coprocessor register used. */
	Elf32_Addr	ri_gp_value; /* GP register value. */
} Elf32_RegInfo;

/* 64 bit RegInfo entry. */
typedef struct {
	Elf64_Word	ri_gprmask;  /* Mask of general register used. */
	Elf64_Word	ri_pad;	     /* Padding. */
	Elf64_Word	ri_cprmask[4]; /* Mask of coprocessor register used. */
	Elf64_Addr	ri_gp_value; /* GP register value. */
} Elf64_RegInfo;

/*
 * Program Header Table (PHDR) entries.
 */

/* 32 bit PHDR entry. */
typedef struct {
	Elf32_Word	p_type;	     /* Type of segment. */
	Elf32_Off	p_offset;    /* File offset to segment. */
	Elf32_Addr	p_vaddr;     /* Virtual address in memory. */
	Elf32_Addr	p_paddr;     /* Physical address (if relevant). */
	Elf32_Word	p_filesz;    /* Size of segment in file. */
	Elf32_Word	p_memsz;     /* Size of segment in memory. */
	Elf32_Word	p_flags;     /* Segment flags. */
	Elf32_Word	p_align;     /* Alignment constraints. */
} Elf32_Phdr;

/* 64 bit PHDR entry. */
typedef struct {
	Elf64_Word	p_type;	     /* Type of segment. */
	Elf64_Word	p_flags;     /* Segment flags. */
	Elf64_Off	p_offset;    /* File offset to segment. */
	Elf64_Addr	p_vaddr;     /* Virtual address in memory. */
	Elf64_Addr	p_paddr;     /* Physical address (if relevant). */
	Elf64_Xword	p_filesz;    /* Size of segment in file. */
	Elf64_Xword	p_memsz;     /* Size of segment in memory. */
	Elf64_Xword	p_align;     /* Alignment constraints. */
} Elf64_Phdr;


/*
 * Move entries, for describing data in COMMON blocks in a compact
 * manner.
 */

/* 32-bit move entry. */
typedef struct {
	Elf32_Lword	m_value;     /* Initialization value. */
	Elf32_Word 	m_info;	     /* Encoded size and index. */
	Elf32_Word	m_poffset;   /* Offset relative to symbol. */
	Elf32_Half	m_repeat;    /* Repeat count. */
	Elf32_Half	m_stride;    /* Number of units to skip. */
} Elf32_Move;

/* 64-bit move entry. */
typedef struct {
	Elf64_Lword	m_value;     /* Initialization value. */
	Elf64_Xword 	m_info;	     /* Encoded size and index. */
	Elf64_Xword	m_poffset;   /* Offset relative to symbol. */
	Elf64_Half	m_repeat;    /* Repeat count. */
	Elf64_Half	m_stride;    /* Number of units to skip. */
} Elf64_Move;

#define ELF_M_SYM(I)		((I) >> 8)
#define ELF_M_SIZE(I)		((I) & 0xFFU)
#define ELF_M_INFO(M, S)	(((M) << 8) + ((S) & 0xFFU))

#define ELF32_M_SYM(I)		ELF_M_SYM(I)
#define ELF32_M_SIZE(I)		ELF_M_SIZE(I)
#define ELF32_M_INFO(M, S)	ELF_M_INFO(M, S)

#define ELF64_M_SYM(I)		ELF_M_SYM(I)
#define ELF64_M_SIZE(I)		ELF_M_SIZE(I)
#define ELF64_M_INFO(M, S)	ELF_M_INFO(M, S)

/*
 * Section Header Table (SHDR) entries.
 */

/* 32 bit SHDR */
typedef struct {
	Elf32_Word	sh_name;     /* index of section name */
	Elf32_Word	sh_type;     /* section type */
	Elf32_Word	sh_flags;    /* section flags */
	Elf32_Addr	sh_addr;     /* in-memory address of section */
	Elf32_Off	sh_offset;   /* file offset of section */
	Elf32_Word	sh_size;     /* section size in bytes */
	Elf32_Word	sh_link;     /* section header table link */
	Elf32_Word	sh_info;     /* extra information */
	Elf32_Word	sh_addralign; /* alignment constraint */
	Elf32_Word	sh_entsize;   /* size for fixed-size entries */
} Elf32_Shdr;

/* 64 bit SHDR */
typedef struct {
	Elf64_Word	sh_name;     /* index of section name */
	Elf64_Word	sh_type;     /* section type */
	Elf64_Xword	sh_flags;    /* section flags */
	Elf64_Addr	sh_addr;     /* in-memory address of section */
	Elf64_Off	sh_offset;   /* file offset of section */
	Elf64_Xword	sh_size;     /* section size in bytes */
	Elf64_Word	sh_link;     /* section header table link */
	Elf64_Word	sh_info;     /* extra information */
	Elf64_Xword	sh_addralign; /* alignment constraint */
	Elf64_Xword	sh_entsize;  /* size for fixed-size entries */
} Elf64_Shdr;


/*
 * Symbol table entries.
 */

typedef struct {
	Elf32_Word	st_name;     /* index of symbol's name */
	Elf32_Addr	st_value;    /* value for the symbol */
	Elf32_Word	st_size;     /* size of associated data */
	Elf32_Byte	st_info;     /* type and binding attributes */
	Elf32_Byte	st_other;    /* visibility */
	Elf32_Half	st_shndx;    /* index of related section */
} Elf32_Sym;

typedef struct {
	Elf64_Word	st_name;     /* index of symbol's name */
	Elf64_Byte	st_info;     /* type and binding attributes */
	Elf64_Byte	st_other;    /* visibility */
	Elf64_Half	st_shndx;    /* index of related section */
	Elf64_Addr	st_value;    /* value for the symbol */
	Elf64_Xword	st_size;     /* size of associated data */
} Elf64_Sym;

#define ELF_ST_BIND(I)		((I) >> 4)
#define ELF_ST_TYPE(I)		((I) & 0xFU)
#define ELF_ST_INFO(B, T)	(((B) << 4) + ((T) & 0xFU))

#define ELF32_ST_BIND(I)	ELF_ST_BIND(I)
#define ELF32_ST_TYPE(I)	ELF_ST_TYPE(I)
#define ELF32_ST_INFO(B,T)	ELF_ST_INFO(B,T)

#define ELF64_ST_BIND(I)	ELF_ST_BIND(I)
#define ELF64_ST_TYPE(I)	ELF_ST_TYPE(I)
#define ELF64_ST_INFO(B,T)	ELF_ST_INFO(B,T)

#define ELF_ST_VISIBILITY(O)	((O) & 0x3U)

#define ELF32_ST_VISIBILITY(O)	ELF_ST_VISIBILITY(O)
#define ELF64_ST_VISIBILITY(O)	ELF_ST_VISIBILITY(O)

/*
 * Syminfo descriptors, containing additional symbol information.
 */

/* 32-bit entry. */
typedef struct {
	Elf32_Half	si_boundto;  /* Entry index with additional flags. */
	Elf32_Half	si_flags;    /* Flags. */
} Elf32_Syminfo;

/* 64-bit entry. */
typedef struct {
	Elf64_Half	si_boundto;  /* Entry index with additional flags. */
	Elf64_Half	si_flags;    /* Flags. */
} Elf64_Syminfo;

/*
 * Relocation descriptors.
 */

typedef struct {
	Elf32_Addr	r_offset;    /* location to apply relocation to */
	Elf32_Word	r_info;	     /* type+section for relocation */
} Elf32_Rel;

typedef struct {
	Elf32_Addr	r_offset;    /* location to apply relocation to */
	Elf32_Word	r_info;      /* type+section for relocation */
	Elf32_Sword	r_addend;    /* constant addend */
} Elf32_Rela;

typedef struct {
	Elf64_Addr	r_offset;    /* location to apply relocation to */
	Elf64_Xword	r_info;      /* type+section for relocation */
} Elf64_Rel;

typedef struct {
	Elf64_Addr	r_offset;    /* location to apply relocation to */
	Elf64_Xword	r_info;      /* type+section for relocation */
	Elf64_Sxword	r_addend;    /* constant addend */
} Elf64_Rela;

/*
 * Relative relocations.
 */
typedef Elf32_Word	Elf32_Relr;
typedef Elf64_Xword	Elf64_Relr;

#define ELF32_R_SYM(I)		((I) >> 8)
#define ELF32_R_TYPE(I)		((I) & 0xFFU)
#define ELF32_R_INFO(S,T)	(((S) << 8) + ((T) & 0xFFU))

#define ELF64_R_SYM(I)		((I) >> 32)
#define ELF64_R_TYPE(I)		((I) & 0xFFFFFFFFUL)
#define ELF64_R_INFO(S,T)	\
	(((Elf64_Xword) (S) << 32) + ((T) & 0xFFFFFFFFUL))

/*
 * Symbol versioning structures.
 */

#define ELF_VER_CHR	'@'	/* Used in versioned names. */

/* 32-bit structures. */
typedef struct
{
	Elf32_Word	vda_name;    /* Index to name. */
	Elf32_Word	vda_next;    /* Offset to next entry. */
} Elf32_Verdaux;

typedef struct
{
	Elf32_Word	vna_hash;    /* Hash value of dependency name. */
	Elf32_Half	vna_flags;   /* Flags. */
	Elf32_Half	vna_other;   /* Version index, if non-zero. */
	Elf32_Word	vna_name;    /* Offset to dependency name. */
	Elf32_Word	vna_next;    /* Offset to next vernaux entry. */
} Elf32_Vernaux;

typedef struct
{
	Elf32_Half	vd_version;  /* Version information. */
	Elf32_Half	vd_flags;    /* Flags. */
	Elf32_Half	vd_ndx;	     /* Index into the versym section. */
	Elf32_Half	vd_cnt;	     /* Number of aux entries. */
	Elf32_Word	vd_hash;     /* Hash value of name. */
	Elf32_Word	vd_aux;	     /* Offset to aux entries. */
	Elf32_Word	vd_next;     /* Offset to next version definition. */
} Elf32_Verdef;

typedef struct
{
	Elf32_Half	vn_version;  /* Version number. */
	Elf32_Half	vn_cnt;	     /* Number of aux entries. */
	Elf32_Word	vn_file;     /* Offset of associated file name. */
	Elf32_Word	vn_aux;	     /* Offset of vernaux array. */
	Elf32_Word	vn_next;     /* Offset of next verneed entry. */
} Elf32_Verneed;

typedef Elf32_Half	Elf32_Versym;

/* 64-bit structures. */

typedef struct {
	Elf64_Word	vda_name;    /* Index to name. */
	Elf64_Word	vda_next;    /* Offset to next entry. */
} Elf64_Verdaux;

typedef struct {
	Elf64_Word	vna_hash;    /* Hash value of dependency name. */
	Elf64_Half	vna_flags;   /* Flags. */
	Elf64_Half	vna_other;   /* Version index, if non-zero. */
	Elf64_Word	vna_name;    /* Offset to dependency name. */
	Elf64_Word	vna_next;    /* Offset to next vernaux entry. */
} Elf64_Vernaux;

typedef struct {
	Elf64_Half	vd_version;  /* Version information. */
	Elf64_Half	vd_flags;    /* Flags. */
	Elf64_Half	vd_ndx;	     /* Index into the versym section. */
	Elf64_Half	vd_cnt;	     /* Number of aux entries. */
	Elf64_Word	vd_hash;     /* Hash value of name. */
	Elf64_Word	vd_aux;	     /* Offset to aux entries. */
	Elf64_Word	vd_next;     /* Offset to next version definition. */
} Elf64_Verdef;

typedef struct {
	Elf64_Half	vn_version;  /* Version number. */
	Elf64_Half	vn_cnt;	     /* Number of aux entries. */
	Elf64_Word	vn_file;     /* Offset of associated file name. */
	Elf64_Word	vn_aux;	     /* Offset of vernaux array. */
	Elf64_Word	vn_next;     /* Offset of next verneed entry. */
} Elf64_Verneed;

typedef Elf64_Half	Elf64_Versym;

#define VER_NDX_HIDDEN	0x8000U	    /* Ignore symbol presence. */
#define VER_NDX(X)	((X) & ~VER_NDX_HIDDEN)

#define VER_NEED_HIDDEN	VER_NDX_HIDDEN
#define VER_NEED_IDX(X)	VER_NDX(X)

#define VER_DEF_IDX(X)	VER_NDX(X)

/*
 * The header for GNU-style hash sections.
 */

typedef struct {
	uint32_t	gh_nbuckets;	/* Number of hash buckets. */
	uint32_t	gh_symndx;	/* First visible symbol in .dynsym. */
	uint32_t	gh_maskwords;	/* #maskwords used in bloom filter. */
	uint32_t	gh_shift2;	/* Bloom filter shift count. */
} Elf_GNU_Hash_Header;

#endif	/* _SYS_ELFDEFINITIONS_H_ */

#undef _USE_SYS_ELFDEFINITIONS_H_
#endif  /* defined(_USE_SYS_ELFDEFINITIONS_H_) */
