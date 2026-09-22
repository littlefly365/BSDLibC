/*	$NetBSD: main.c,v 1.5 2016/09/05 01:00:07 sevan Exp $	*/

/*-
 * Copyright (c) 1999 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Luke Mewburn.
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>

#ifndef lint
__RCSID("$NetBSD: main.c,v 1.5 2016/09/05 01:00:07 sevan Exp $");
#endif /* not lint */

#include <sys/types.h>
#include <fts.h>

#define SMALL		1 /* No ACL */
#define NO_PRINT	1

/* POSIX (IEEE Std 1003.1-2001) says we should use 512 blocks */
#define	POSIX_BLOCK_SIZE	512
extern long blocksize;		/* block size units */

extern int f_accesstime;	/* use time of last access */
extern int f_flags;		/* show flags associated with a file */
extern int f_grouponly;		/* long listing without owner */
extern int f_humanize;		/* humanize size field */
extern int f_commas;        /* separate size field with commas */
extern int f_inode;		/* print inode */
extern int f_longform;		/* long listing format */
extern int f_octal;		/* print octal escapes for nongraphic characters */
extern int f_octal_escape;	/* like f_octal but use C escapes if possible */
extern int f_sectime;		/* print the real time for all files */
extern int f_size;		/* list size in short listing */
extern int f_statustime;	/* use time of last mode change */
extern int f_type;		/* add type character for non-regular files */
extern int f_typedir;		/* add type character for directories */
extern int f_nonprint;		/* show unprintables as ? */
extern int f_fullpath;		/* print full pathname, not filename */
extern int f_leafonly;		/* when recursing, print leaf names only */

typedef struct {
	FTSENT *list;
	u_int64_t btotal;
	int entries;
	unsigned int maxlen;
	int s_block;
	int s_flags;
	int s_group;
	int s_inode;
	int s_nlink;
	int s_size;
	int s_user;
	int s_major;
	int s_minor;
} DISPLAY;

typedef struct {
	char *user;
	char *group;
	char *flags;
	char data[1];
} NAMES;

int	 acccmp(const FTSENT *, const FTSENT *);
int	 revacccmp(const FTSENT *, const FTSENT *);
int	 modcmp(const FTSENT *, const FTSENT *);
int	 revmodcmp(const FTSENT *, const FTSENT *);
int	 namecmp(const FTSENT *, const FTSENT *);
int	 revnamecmp(const FTSENT *, const FTSENT *);
int	 statcmp(const FTSENT *, const FTSENT *);
int	 revstatcmp(const FTSENT *, const FTSENT *);
int	 sizecmp(const FTSENT *, const FTSENT *);
int	 revsizecmp(const FTSENT *, const FTSENT *);

int	 ls_main(int, char *[]);

int	 printescaped(const char *);
void	 printacol(DISPLAY *);
void	 printcol(DISPLAY *);
void	 printlong(DISPLAY *);
void	 printscol(DISPLAY *);
void	 printstream(DISPLAY *);
int	 safe_print(const char *);

int
main(int argc, char *argv[])
{

	return ls_main(argc, argv);
	/* NOTREACHED */
}
/*	$NetBSD: ls.c,v 1.79 2024/12/11 12:56:31 simonb Exp $	*/

/*
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 1989, 1993, 1994\
 The Regents of the University of California.  All rights reserved.");
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)ls.c	8.7 (Berkeley) 8/5/94";
#else
__RCSID("$NetBSD: ls.c,v 1.79 2024/12/11 12:56:31 simonb Exp $");
#endif
#endif /* not lint */

#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <fts.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <pwd.h>
#include <grp.h>
#include <util.h>

static void	 display(FTSENT *, FTSENT *);
static int	 mastercmp(const FTSENT **, const FTSENT **);
static void	 traverse(int, char **, int);

static void (*printfcn)(DISPLAY *);
static int (*sortfcn)(const FTSENT *, const FTSENT *);

#define	BY_NAME 0
#define	BY_SIZE 1
#define	BY_TIME	2

long blocksize;			/* block size units */
int termwidth = 80;		/* default terminal width */
int sortkey = BY_NAME;
int rval = EXIT_SUCCESS;	/* exit value - set if error encountered */

/* flags */
int f_accesstime;		/* use time of last access */
int f_column;			/* columnated format */
int f_columnacross;		/* columnated format, sorted across */
int f_flags;			/* show flags associated with a file */
int f_grouponly;		/* long listing without owner */
int f_humanize;			/* humanize the size field */
int f_commas;			/* separate size field with comma */
int f_inode;			/* print inode */
int f_listdir;			/* list actual directory, not contents */
int f_listdot;			/* list files beginning with . */
int f_longform;			/* long listing format */
int f_nonprint;			/* show unprintables as ? */
int f_nosort;			/* don't sort output */
int f_numericonly;		/* don't convert uid/gid to name */
int f_octal;			/* print octal escapes for nongraphic characters */
int f_octal_escape;		/* like f_octal but use C escapes if possible */
int f_recursive;		/* ls subdirectories also */
int f_reversesort;		/* reverse whatever sort is used */
int f_sectime;			/* print the real time for all files */
int f_singlecol;		/* use single column output */
int f_size;			/* list size in short listing */
int f_statustime;		/* use time of last mode change */
int f_stream;			/* stream format */
int f_type;			/* add type character for non-regular files */
int f_typedir;			/* add type character for directories */
int f_whiteout;			/* show whiteout entries */
int f_fullpath;			/* print full pathname, not filename */
int f_leafonly;			/* when recursing, print leaf names only */

__dead static void
usage(void)
{

	(void)fprintf(stderr,
	    "usage: %s [-1AaBbCcdFfghikLlMmnOoPpqRrSsTtuWwXx] [file ...]\n",
	    getprogname());
	exit(EXIT_FAILURE);
	/* NOTREACHED */
}

int
ls_main(int argc, char *argv[])
{
	static char dot[] = ".", *dotav[] = { dot, NULL };
	struct winsize win;
	int ch, fts_options;
	int kflag = 0;
	const char *p;

	setprogname(argv[0]);
	(void)setlocale(LC_ALL, "");

	/* Terminal defaults to -Cq, non-terminal defaults to -1. */
	if (isatty(STDOUT_FILENO)) {
		if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) == 0 &&
		    win.ws_col > 0)
			termwidth = win.ws_col;
		f_column = f_nonprint = 1;
	} else
		f_singlecol = 1;

	/* Root is -A automatically. */
	if (!getuid())
		f_listdot = 1;

	fts_options = FTS_PHYSICAL;
	while ((ch = getopt(argc, argv, "1AaBbCcdFfghikLlMmnOoPpqRrSsTtuWwXx"))
	    != -1) {
		switch (ch) {
		/*
		 * The -1, -C, -l, -m and -x options all override each other so
		 * shell aliasing works correctly.
		 */
		case '1':
			f_singlecol = 1;
			f_column = f_columnacross = f_longform = f_stream = 0;
			break;
		case 'C':
			f_column = 1;
			f_columnacross = f_longform = f_singlecol = f_stream =
			    0;
			break;
		case 'g':
			if (f_grouponly != -1)
				f_grouponly = 1;
			f_longform = 1;
			f_column = f_columnacross = f_singlecol = f_stream = 0;
			break;
		case 'l':
			f_longform = 1;
			f_column = f_columnacross = f_singlecol = f_stream = 0;
			/* Never let -g take precedence over -l. */
			f_grouponly = -1;
			break;
		case 'm':
			f_stream = 1;
			f_column = f_columnacross = f_longform = f_singlecol =
			    0;
			break;
		case 'x':
			f_columnacross = 1;
			f_column = f_longform = f_singlecol = f_stream = 0;
			break;
		/* The -c and -u options override each other. */
		case 'c':
			f_statustime = 1;
			f_accesstime = 0;
			break;
		case 'u':
			f_accesstime = 1;
			f_statustime = 0;
			break;
		case 'F':
			f_type = 1;
			break;
		case 'L':
			fts_options &= ~FTS_PHYSICAL;
			fts_options |= FTS_LOGICAL;
			break;
		case 'R':
			f_recursive = 1;
			break;
		case 'f':
			f_nosort = 1;
			/* FALLTHROUGH */
		case 'a':
			fts_options |= FTS_SEEDOT;
			/* FALLTHROUGH */
		case 'A':
			f_listdot = 1;
			break;
		/* The -B option turns off the -b, -q and -w options. */
		case 'B':
			f_nonprint = 0;
			f_octal = 1;
			f_octal_escape = 0;
			break;
		/* The -b option turns off the -B, -q and -w options. */
		case 'b':
			f_nonprint = 0;
			f_octal = 0;
			f_octal_escape = 1;
			break;
		/* The -d option turns off the -R option. */
		case 'd':
			f_listdir = 1;
			f_recursive = 0;
			break;
		case 'i':
			f_inode = 1;
			break;
		case 'k':
			blocksize = 1024;
			kflag = 1;
			f_humanize = 0;
			break;
		/* The -h option forces all sizes to be measured in bytes. */
		case 'h':
			f_humanize = 1;
			kflag = 0;
			f_commas = 0;
			break;
		case 'M':
			f_humanize = 0;
			f_commas = 1;
			break;
		case 'n':
			f_numericonly = 1;
			f_longform = 1;
			f_column = f_columnacross = f_singlecol = f_stream = 0;
			break;
		case 'O':
			f_leafonly = 1;
			break;
		case 'o':
			f_flags = 1;
			break;
		case 'P':
			f_fullpath = 1;
			break;
		case 'p':
			f_typedir = 1;
			break;
		/* The -q option turns off the -B, -b and -w options. */
		case 'q':
			f_nonprint = 1;
			f_octal = 0;
			f_octal_escape = 0;
			break;
		case 'r':
			f_reversesort = 1;
			break;
		case 'S':
			sortkey = BY_SIZE;
			break;
		case 's':
			f_size = 1;
			break;
		case 'T':
			f_sectime = 1;
			break;
		case 't':
			sortkey = BY_TIME;
			break;
		case 'W':
			f_whiteout = 1;
			break;
		/* The -w option turns off the -B, -b and -q options. */
		case 'w':
			f_nonprint = 0;
			f_octal = 0;
			f_octal_escape = 0;
			break;
		case 'X':
			fts_options |= FTS_XDEV;
			break;
		default:
		case '?':
			usage();
		}
	}
	argc -= optind;
	argv += optind;

	if (f_column || f_columnacross || f_stream) {
		if ((p = getenv("COLUMNS")) != NULL)
			termwidth = atoi(p);
	}

	/*
	 * If both -g and -l options, let -l take precedence.
	 */
	if (f_grouponly == -1)
		f_grouponly = 0;

	/*
	 * If not -F, -i, -l, -p, -S, -s or -t options, don't require stat
	 * information.
	 */
	if (!f_inode && !f_longform && !f_size && !f_type && !f_typedir &&
	    sortkey == BY_NAME)
		fts_options |= FTS_NOSTAT;

	/*
	 * If not -F, -d or -l options, follow any symbolic links listed on
	 * the command line.
	 */
	if (!f_longform && !f_listdir && !f_type)
		fts_options |= FTS_COMFOLLOW;

	/*
	 * If -W, show whiteout entries
	 */
#ifdef FTS_WHITEOUT
	if (f_whiteout)
		fts_options |= FTS_WHITEOUT;
#endif

	/* If -i, -l, or -s, figure out block size. */
	if (f_inode || f_longform || f_size) {
		if (!kflag)
			(void)getbsize(NULL, &blocksize);
		blocksize /= POSIX_BLOCK_SIZE;
	}

	/* Select a sort function. */
	if (f_reversesort) {
		switch (sortkey) {
		case BY_NAME:
			sortfcn = revnamecmp;
			break;
		case BY_SIZE:
			sortfcn = revsizecmp;
			break;
		case BY_TIME:
			if (f_accesstime)
				sortfcn = revacccmp;
			else if (f_statustime)
				sortfcn = revstatcmp;
			else /* Use modification time. */
				sortfcn = revmodcmp;
			break;
		}
	} else {
		switch (sortkey) {
		case BY_NAME:
			sortfcn = namecmp;
			break;
		case BY_SIZE:
			sortfcn = sizecmp;
			break;
		case BY_TIME:
			if (f_accesstime)
				sortfcn = acccmp;
			else if (f_statustime)
				sortfcn = statcmp;
			else /* Use modification time. */
				sortfcn = modcmp;
			break;
		}
	}

	/* Select a print function. */
	if (f_singlecol)
		printfcn = printscol;
	else if (f_columnacross)
		printfcn = printacol;
	else if (f_longform)
		printfcn = printlong;
	else if (f_stream)
		printfcn = printstream;
	else
		printfcn = printcol;

	if (argc)
		traverse(argc, argv, fts_options);
	else
		traverse(1, dotav, fts_options);
	return rval;
	/* NOTREACHED */
}

static int output;			/* If anything output. */

/*
 * Traverse() walks the logical directory structure specified by the argv list
 * in the order specified by the mastercmp() comparison function.  During the
 * traversal it passes linked lists of structures to display() which represent
 * a superset (may be exact set) of the files to be displayed.
 */
static void
traverse(int argc, char *argv[], int options)
{
	FTS *ftsp;
	FTSENT *p, *chp;
	int ch_options, error;

	if ((ftsp =
	    fts_open(argv, options, f_nosort ? NULL : mastercmp)) == NULL)
		err(EXIT_FAILURE, NULL);

	display(NULL, fts_children(ftsp, 0));
	if (f_listdir) {
		(void)fts_close(ftsp);
		return;
	}

	/*
	 * If not recursing down this tree and don't need stat info, just get
	 * the names.
	 */
	ch_options = !f_recursive && options & FTS_NOSTAT ? FTS_NAMEONLY : 0;

	while ((p = fts_read(ftsp)) != NULL)
		switch (p->fts_info) {
		case FTS_DC:
			warnx("%s: directory causes a cycle", p->fts_name);
			break;
		case FTS_DNR:
		case FTS_ERR:
			warnx("%s: %s", p->fts_path, strerror(p->fts_errno));
			rval = EXIT_FAILURE;
			break;
		case FTS_D:
			if (p->fts_level != FTS_ROOTLEVEL &&
			    p->fts_name[0] == '.' && !f_listdot) {
				(void)fts_set(ftsp, p, FTS_SKIP);
				break;
			}

			/*
			 * If already output something, put out a newline as
			 * a separator.  If multiple arguments, precede each
			 * directory with its name.
			 */
			if (!f_leafonly) {
				if (output)
					(void)printf("\n%s:\n", p->fts_path);
				else if (argc > 1) {
					(void)printf("%s:\n", p->fts_path);
					output = 1;
				}
			}

			chp = fts_children(ftsp, ch_options);
			display(p, chp);

			if (!f_recursive && chp != NULL)
				(void)fts_set(ftsp, p, FTS_SKIP);
			break;
		}
	error = errno;
	(void)fts_close(ftsp);
	errno = error;
	if (errno)
		err(EXIT_FAILURE, "fts_read");
}

/*
 * Display() takes a linked list of FTSENT structures and passes the list
 * along with any other necessary information to the print function.  P
 * points to the parent directory of the display list.
 */
static void
display(FTSENT *p, FTSENT *list)
{
	struct stat *sp;
	DISPLAY d;
	FTSENT *cur;
	NAMES *np;
	u_int64_t btotal;
	off_t maxsize;
	blkcnt_t maxblock;
	ino_t maxinode;
	int maxmajor, maxminor;
	uint32_t maxnlink;
	int bcfile, entries, flen, glen, ulen, maxflags, maxgroup;
	unsigned int maxlen;
	int maxuser, needstats;
	const char *user, *group;
	char buf[21];		/* 64 bits == 20 digits, +1 for NUL */
	char nuser[12], ngroup[12];
	char *flags = NULL;

	/*
	 * If list is NULL there are two possibilities: that the parent
	 * directory p has no children, or that fts_children() returned an
	 * error.  We ignore the error case since it will be replicated
	 * on the next call to fts_read() on the post-order visit to the
	 * directory p, and will be signalled in traverse().
	 */
	if (list == NULL)
		return;

	needstats = f_inode || f_longform || f_size;
	flen = 0;
	maxinode = maxnlink = 0;
	bcfile = 0;
	maxuser = maxgroup = maxflags = maxlen = 0;
	btotal = maxblock = maxsize = 0;
	maxmajor = maxminor = 0;
	for (cur = list, entries = 0; cur; cur = cur->fts_link) {
		if (cur->fts_info == FTS_ERR || cur->fts_info == FTS_NS) {
			warnx("%s: %s",
			    cur->fts_name, strerror(cur->fts_errno));
			cur->fts_number = NO_PRINT;
			rval = EXIT_FAILURE;
			continue;
		}

		/*
		 * P is NULL if list is the argv list, to which different rules
		 * apply.
		 */
		if (p == NULL) {
			/* Directories will be displayed later. */
			if (cur->fts_info == FTS_D && !f_listdir) {
				cur->fts_number = NO_PRINT;
				continue;
			}
		} else {
			/* Only display dot file if -a/-A set. */
			if (cur->fts_name[0] == '.' && !f_listdot) {
				cur->fts_number = NO_PRINT;
				continue;
			}
		}
		if (cur->fts_namelen > maxlen)
			maxlen = cur->fts_namelen;
		if (needstats) {
			sp = cur->fts_statp;
			if (sp->st_blocks > maxblock)
				maxblock = sp->st_blocks;
			if (sp->st_ino > maxinode)
				maxinode = sp->st_ino;
			if (sp->st_nlink > maxnlink)
				maxnlink = sp->st_nlink;
			if (sp->st_size > maxsize)
				maxsize = sp->st_size;
			if (S_ISCHR(sp->st_mode) || S_ISBLK(sp->st_mode)) {
				bcfile = 1;
				if (major(sp->st_rdev) > maxmajor)
					maxmajor = major(sp->st_rdev);
				if (minor(sp->st_rdev) > maxminor)
					maxminor = minor(sp->st_rdev);
			}

			btotal += sp->st_blocks;
			if (f_longform) {
				if (f_numericonly ||
				    (user = user_from_uid(sp->st_uid, 0)) ==
				    NULL) {
					(void)snprintf(nuser, sizeof(nuser),
					    "%u", sp->st_uid);
					user = nuser;
				}
				if (f_numericonly ||
				    (group = group_from_gid(sp->st_gid, 0)) ==
				    NULL) {
					(void)snprintf(ngroup, sizeof(ngroup),
					    "%u", sp->st_gid);
					group = ngroup;
				}
				if ((ulen = strlen(user)) > maxuser)
					maxuser = ulen;
				if ((glen = strlen(group)) > maxgroup)
					maxgroup = glen;
				if (f_flags) {
					flags =
					    flags_to_string((u_long)sp->st_flags, "-");
					if ((flen = strlen(flags)) > maxflags)
						maxflags = flen;
				} else
					flen = 0;

				if ((np = malloc(sizeof(NAMES) +
				    ulen + glen + flen + 2)) == NULL)
					err(EXIT_FAILURE, NULL);

				np->user = &np->data[0];
				(void)strcpy(np->user, user);
				np->group = &np->data[ulen + 1];
				(void)strcpy(np->group, group);

				if (f_flags) {
					np->flags = &np->data[ulen + glen + 2];
				  	(void)strcpy(np->flags, flags);
					free(flags);
				}
				cur->fts_pointer = np;
			}
		}
		++entries;
	}

	if (!entries)
		return;

	d.list = list;
	d.entries = entries;
	d.maxlen = maxlen;
	if (needstats) {
		d.btotal = btotal;
		if (f_humanize) {
			d.s_block = 4; /* min buf length for humanize_number */
		} else {
			(void)snprintf(buf, sizeof(buf), "%lld",
			    (long long)howmany(maxblock, blocksize));
			d.s_block = strlen(buf);
			if (f_commas) /* allow for commas before every third digit */
				d.s_block += (d.s_block - 1) / 3;
		}
		d.s_flags = maxflags;
		d.s_group = maxgroup;
		(void)snprintf(buf, sizeof(buf), "%llu",
		    (unsigned long long)maxinode);
		d.s_inode = strlen(buf);
		(void)snprintf(buf, sizeof(buf), "%u", maxnlink);
		d.s_nlink = strlen(buf);
		if (f_humanize) {
			d.s_size = 4; /* min buf length for humanize_number */
		} else {
			(void)snprintf(buf, sizeof(buf), "%lld",
			    (long long)maxsize);
			d.s_size = strlen(buf);
			if (f_commas) /* allow for commas before every third digit */
				d.s_size += (d.s_size - 1) / 3;
		}
		d.s_user = maxuser;
		if (bcfile) {
			(void)snprintf(buf, sizeof(buf), "%d", maxmajor);
			d.s_major = strlen(buf);
			(void)snprintf(buf, sizeof(buf), "%d", maxminor);
			d.s_minor = strlen(buf);
			if (d.s_major + d.s_minor + 2 > d.s_size)
				d.s_size = d.s_major + d.s_minor + 2;
			else if (d.s_size - d.s_minor - 2 > d.s_major)
				d.s_major = d.s_size - d.s_minor - 2;
		} else {
			d.s_major = 0;
			d.s_minor = 0;
		}
	}

	printfcn(&d);
	output = 1;

	if (f_longform)
		for (cur = list; cur; cur = cur->fts_link)
			free(cur->fts_pointer);
}

/*
 * Ordering for mastercmp:
 * If ordering the argv (fts_level = FTS_ROOTLEVEL) return non-directories
 * as larger than directories.  Within either group, use the sort function.
 * All other levels use the sort function.  Error entries remain unsorted.
 */
static int
mastercmp(const FTSENT **a, const FTSENT **b)
{
	int a_info, b_info;

	a_info = (*a)->fts_info;
	if (a_info == FTS_ERR)
		return (0);
	b_info = (*b)->fts_info;
	if (b_info == FTS_ERR)
		return (0);

	if (a_info == FTS_NS || b_info == FTS_NS) {
		if (b_info != FTS_NS)
			return (1);
		else if (a_info != FTS_NS)
			return (-1);
		else
			return (namecmp(*a, *b));
	}

	if (a_info != b_info && !f_listdir &&
	    (*a)->fts_level == FTS_ROOTLEVEL) {
		if (a_info == FTS_D)
			return (1);
		else if (b_info == FTS_D)
			return (-1);
	}
	return (sortfcn(*a, *b));
}
/*	$NetBSD: print.c,v 1.59 2024/12/11 12:56:31 simonb Exp $	*/

/*
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)print.c	8.5 (Berkeley) 7/28/94";
#else
__RCSID("$NetBSD: print.c,v 1.59 2024/12/11 12:56:31 simonb Exp $");
#endif
#endif /* not lint */

#include <sys/param.h>
#include <sys/stat.h>
#ifndef SMALL
#include <sys/acl.h>
#endif

#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <fts.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tzfile.h>
#include <unistd.h>
#include <util.h>

extern int termwidth;

static int	printaname(FTSENT *, int, int);
static void	printlink(FTSENT *);
static void	printtime(time_t);
static void	printtotal(DISPLAY *dp);
static int	printtype(u_int);
#ifndef SMALL
static void	aclmode(char *, const FTSENT *);
#endif

static time_t	now;

#define	IS_NOPRINT(p)	((p)->fts_number == NO_PRINT)

static int
safe_printpath(const FTSENT *p) {
	int chcnt;

	if (f_fullpath) {
		chcnt = safe_print(p->fts_path);
		chcnt += safe_print("/");
	} else
		chcnt = 0;
	return chcnt + safe_print(p->fts_name);
}

static int
printescapedpath(const FTSENT *p) {
	int chcnt;

	if (f_fullpath) {
		chcnt = printescaped(p->fts_path);
		chcnt += printescaped("/");
	} else
		chcnt = 0;

	return chcnt + printescaped(p->fts_name);
}

static int
printpath(const FTSENT *p) {
	if (f_fullpath)
		return printf("%s/%s", p->fts_path, p->fts_name);
	else
		return printf("%s", p->fts_name);
}

void
printscol(DISPLAY *dp)
{
	FTSENT *p;

	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		(void)printaname(p, dp->s_inode, dp->s_block);
		(void)putchar('\n');
	}
}

void
printlong(DISPLAY *dp)
{
	struct stat *sp;
	FTSENT *p;
	NAMES *np;
	char buf[20], szbuf[5];

	now = time(NULL);

	if (!f_leafonly)
		printtotal(dp);		/* "total: %u\n" */
	
	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		sp = p->fts_statp;
		if (f_inode)
			(void)printf("%*"PRIu64" ", dp->s_inode, sp->st_ino);
		if (f_size) {
			if (f_humanize) {
				if ((humanize_number(szbuf, sizeof(szbuf),
				    sp->st_blocks * S_BLKSIZE,
				    "", HN_AUTOSCALE,
				    (HN_DECIMAL | HN_B | HN_NOSPACE))) == -1)
					err(1, "humanize_number");
				(void)printf("%*s ", dp->s_block, szbuf);
			} else {
				(void)printf(f_commas ? "%'*llu " : "%*llu ",
				    dp->s_block,
				    (unsigned long long)howmany(sp->st_blocks,
				    blocksize));
			}
		}
		(void)strmode(sp->st_mode, buf);
#ifndef SMALL
		aclmode(buf, p);
#endif
		np = p->fts_pointer;
		(void)printf("%s %*lu ", buf, dp->s_nlink,
		    (unsigned long)sp->st_nlink);
		if (!f_grouponly)
			(void)printf("%-*s  ", dp->s_user, np->user);
		(void)printf("%-*s  ", dp->s_group, np->group);
		if (f_flags)
			(void)printf("%-*s ", dp->s_flags, np->flags);
		if (S_ISCHR(sp->st_mode) || S_ISBLK(sp->st_mode))
			(void)printf("%*lld, %*lld ",
			    dp->s_major, (long long)major(sp->st_rdev),
			    dp->s_minor, (long long)minor(sp->st_rdev));
		else
			if (f_humanize) {
				if ((humanize_number(szbuf, sizeof(szbuf),
				    sp->st_size, "", HN_AUTOSCALE,
				    (HN_DECIMAL | HN_B | HN_NOSPACE))) == -1)
					err(1, "humanize_number");
				(void)printf("%*s ", dp->s_size, szbuf);
			} else {
				(void)printf(f_commas ? "%'*llu " : "%*llu ", 
				    dp->s_size, (unsigned long long)
				    sp->st_size);
			}
		if (f_accesstime)
			printtime(sp->st_atime);
		else if (f_statustime)
			printtime(sp->st_ctime);
		else
			printtime(sp->st_mtime);
		if (f_octal || f_octal_escape)
			(void)safe_printpath(p);
		else if (f_nonprint)
			(void)printescapedpath(p);
		else
			(void)printpath(p);

		if (f_type || (f_typedir && S_ISDIR(sp->st_mode)))
			(void)printtype(sp->st_mode);
		if (S_ISLNK(sp->st_mode))
			printlink(p);
		(void)putchar('\n');
	}
}

void
printcol(DISPLAY *dp)
{
	static FTSENT **array;
	static int lastentries = -1;
	FTSENT *p;
	int base, chcnt, col, colwidth, num;
	int numcols, numrows, row;

	colwidth = dp->maxlen;
	if (f_inode)
		colwidth += dp->s_inode + 1;
	if (f_size) {
		if (f_humanize)
			colwidth += dp->s_size + 1;
		else
			colwidth += dp->s_block + 1;
	}
	if (f_type || f_typedir)
		colwidth += 1;

	colwidth += 1;

	printtotal(dp);				/* "total: %u\n" */

	if (termwidth < 2 * colwidth) {
		printscol(dp);
		return;
	}

	/*
	 * Have to do random access in the linked list -- build a table
	 * of pointers.
	 */
	if (dp->entries > lastentries) {
		FTSENT **newarray;

		newarray = realloc(array, dp->entries * sizeof(FTSENT *));
		if (newarray == NULL) {
			warn(NULL);
			printscol(dp);
			return;
		}
		lastentries = dp->entries;
		array = newarray;
	}
	for (p = dp->list, num = 0; p; p = p->fts_link)
		if (p->fts_number != NO_PRINT)
			array[num++] = p;

	numcols = termwidth / colwidth;
	colwidth = termwidth / numcols;		/* spread out if possible */
	numrows = num / numcols;
	if (num % numcols)
		++numrows;

	for (row = 0; row < numrows; ++row) {
		for (base = row, chcnt = col = 0; col < numcols; ++col) {
			chcnt = printaname(array[base], dp->s_inode,
			    f_humanize ? dp->s_size : dp->s_block);
			if ((base += numrows) >= num)
				break;
			while (chcnt++ < colwidth)
				(void)putchar(' ');
		}
		(void)putchar('\n');
	}
}

void
printacol(DISPLAY *dp)
{
	FTSENT *p;
	int chcnt, col, colwidth;
	int numcols;

	colwidth = dp->maxlen;
	if (f_inode)
		colwidth += dp->s_inode + 1;
	if (f_size) {
		if (f_humanize)
			colwidth += dp->s_size + 1;
		else
			colwidth += dp->s_block + 1;
	}
	if (f_type || f_typedir)
		colwidth += 1;

	colwidth += 1;

	printtotal(dp);				/* "total: %u\n" */

	if (termwidth < 2 * colwidth) {
		printscol(dp);
		return;
	}

	numcols = termwidth / colwidth;
	colwidth = termwidth / numcols;		/* spread out if possible */

	chcnt = col = 0;
	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		if (col >= numcols) {
			chcnt = col = 0;
			(void)putchar('\n');
		}
		chcnt = printaname(p, dp->s_inode,
		    f_humanize ? dp->s_size : dp->s_block);
		while (chcnt++ < colwidth)
			(void)putchar(' ');
		col++;
	}
	(void)putchar('\n');
}

void
printstream(DISPLAY *dp)
{
	FTSENT *p;
	int col;
	int extwidth;

	extwidth = 0;
	if (f_inode)
		extwidth += dp->s_inode + 1;
	if (f_size) {
		if (f_humanize)
			extwidth += dp->s_size + 1;
		else 
			extwidth += dp->s_block + 1;
	}
	if (f_type)
		extwidth += 1;

	for (col = 0, p = dp->list; p != NULL; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		if (col > 0) {
			(void)putchar(','), col++;
			if (col + 1 + extwidth + (int)p->fts_namelen >= termwidth)
				(void)putchar('\n'), col = 0;
			else
				(void)putchar(' '), col++;
		}
		col += printaname(p, dp->s_inode,
		    f_humanize ? dp->s_size : dp->s_block);
	}
	(void)putchar('\n');
}

/*
 * print [inode] [size] name
 * return # of characters printed, no trailing characters.
 */
static int
printaname(FTSENT *p, int inodefield, int sizefield)
{
	struct stat *sp;
	int chcnt;
	char szbuf[5];

	sp = p->fts_statp;
	chcnt = 0;
	if (f_inode)
		chcnt += printf("%*"PRIu64" ", inodefield, sp->st_ino);
	if (f_size) {
		if (f_humanize) {
			if ((humanize_number(szbuf, sizeof(szbuf), sp->st_size,
			    "", HN_AUTOSCALE,
			    (HN_DECIMAL | HN_B | HN_NOSPACE))) == -1)
				err(1, "humanize_number");
			chcnt += printf("%*s ", sizefield, szbuf);
		} else {
			chcnt += printf(f_commas ? "%'*llu " : "%*llu ",
			    sizefield, (unsigned long long)
			    howmany(sp->st_blocks, blocksize));
		}
	}
	if (f_octal || f_octal_escape)
		chcnt += safe_printpath(p);
	else if (f_nonprint)
		chcnt += printescapedpath(p);
	else
		chcnt += printpath(p);
	if (f_type || (f_typedir && S_ISDIR(sp->st_mode)))
		chcnt += printtype(sp->st_mode);
	return (chcnt);
}

static void
printtime(time_t ftime)
{
	int i;
	const char *longstring;

	if ((longstring = ctime(&ftime)) == NULL) {
			   /* 012345678901234567890123 */
		longstring = "????????????????????????";
	}
	for (i = 4; i < 11; ++i)
		(void)putchar(longstring[i]);

#define	SIXMONTHS	((DAYSPERNYEAR / 2) * SECSPERDAY)
	if (f_sectime)
		for (i = 11; i < 24; i++)
			(void)putchar(longstring[i]);
	else if (ftime + SIXMONTHS > now && ftime - SIXMONTHS < now)
		for (i = 11; i < 16; ++i)
			(void)putchar(longstring[i]);
	else {
		(void)putchar(' ');
		for (i = 20; i < 24; ++i)
			(void)putchar(longstring[i]);
	}
	(void)putchar(' ');
}

/*
 * Display total used disk space in the form "total: %u\n".
 * Note: POSIX (IEEE Std 1003.1-2001) says this should be always in 512 blocks,
 * but we humanise it with -h, or separate it with commas with -M, and use 1024
 * with -k.
 */
static void
printtotal(DISPLAY *dp)
{
	char szbuf[5];
	
	if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size)) {
		if (f_humanize) {
			if ((humanize_number(szbuf, sizeof(szbuf),
			    dp->btotal * POSIX_BLOCK_SIZE,
			    "", HN_AUTOSCALE,
			    (HN_DECIMAL | HN_B | HN_NOSPACE))) == -1)
				err(1, "humanize_number");
			(void)printf("total %s\n", szbuf);
		} else {
			(void)printf(f_commas ? "total %'llu\n" :
			    "total %llu\n", (unsigned long long)
			    howmany(dp->btotal, blocksize));
		}
	}
}

static int
printtype(u_int mode)
{
	switch (mode & S_IFMT) {
	case S_IFDIR:
		(void)putchar('/');
		return (1);
	case S_IFIFO:
		(void)putchar('|');
		return (1);
	case S_IFLNK:
		(void)putchar('@');
		return (1);
	case S_IFSOCK:
		(void)putchar('=');
		return (1);
	case S_IFWHT:
		(void)putchar('%');
		return (1);
	}
	if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
		(void)putchar('*');
		return (1);
	}
	return (0);
}

static void
printlink(FTSENT *p)
{
	int lnklen;
	char name[MAXPATHLEN + 1], path[MAXPATHLEN + 1];

	if (p->fts_level == FTS_ROOTLEVEL)
		(void)snprintf(name, sizeof(name), "%s", p->fts_name);
	else
		(void)snprintf(name, sizeof(name),
		    "%s/%s", p->fts_parent->fts_accpath, p->fts_name);
	if ((lnklen = readlink(name, path, sizeof(path) - 1)) == -1) {
		(void)fprintf(stderr, "\nls: %s: %s\n", name, strerror(errno));
		return;
	}
	path[lnklen] = '\0';
	(void)printf(" -> ");
	if (f_octal || f_octal_escape)
		(void)safe_print(path);
	else if (f_nonprint)
		(void)printescaped(path);
	else
		(void)printf("%s", path);
}

#ifndef SMALL
/*
 * Add a + after the standard rwxrwxrwx mode if the file has an
 * ACL. strmode() reserves space at the end of the string.
 */
static void
aclmode(char *buf, const FTSENT *p)
{
	char name[MAXPATHLEN + 1];
	int ret, trivial;
	static dev_t previous_dev = NODEV;
	static int supports_acls = -1;
	static int type = ACL_TYPE_ACCESS;
	acl_t facl;

	/*
	 * XXX: ACLs are not supported on whiteouts and device files
	 * residing on UFS.
	 */
	if (S_ISCHR(p->fts_statp->st_mode) || S_ISBLK(p->fts_statp->st_mode) ||
	    S_ISWHT(p->fts_statp->st_mode))
		return;

	if (previous_dev == p->fts_statp->st_dev && supports_acls == 0)
		return;

	if (p->fts_level == FTS_ROOTLEVEL)
		snprintf(name, sizeof(name), "%s", p->fts_name);
	else
		snprintf(name, sizeof(name), "%s/%s",
		    p->fts_parent->fts_accpath, p->fts_name);

	if (supports_acls == -1 || previous_dev != p->fts_statp->st_dev) {
		previous_dev = p->fts_statp->st_dev;
		supports_acls = 0;

		ret = lpathconf(name, _PC_ACL_NFS4);
		if (ret > 0) {
			type = ACL_TYPE_NFS4;
			supports_acls = 1;
		} else if (ret < 0 && errno != EINVAL) {
			warn("%s", name);
			return;
		}
		if (supports_acls == 0) {
			ret = lpathconf(name, _PC_ACL_EXTENDED);
			if (ret > 0) {
				type = ACL_TYPE_ACCESS;
				supports_acls = 1;
			} else if (ret < 0 && errno != EINVAL) {
				warn("%s", name);
				return;
			}
		}
	}
	if (supports_acls == 0)
		return;
	facl = acl_get_link_np(name, type);
	if (facl == NULL) {
		warn("%s", name);
		return;
	}
	if (acl_is_trivial_np(facl, &trivial)) {
		acl_free(facl);
		warn("%s", name);
		return;
	}
	if (!trivial)
		buf[10] = '+';
	acl_free(facl);
}
#endif
/*	$NetBSD: cmp.c,v 1.17 2003/08/07 09:05:14 agc Exp $	*/

/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)cmp.c	8.1 (Berkeley) 5/31/93";
#else
__RCSID("$NetBSD: cmp.c,v 1.17 2003/08/07 09:05:14 agc Exp $");
#endif
#endif /* not lint */

#include <sys/types.h>
#include <sys/stat.h>

#include <fts.h>
#include <string.h>

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || \
    defined(_XOPEN_SOURCE) || defined(__NetBSD__)
#define ATIMENSEC_CMP(x, op, y) ((x)->st_atimensec op (y)->st_atimensec)
#define CTIMENSEC_CMP(x, op, y) ((x)->st_ctimensec op (y)->st_ctimensec)
#define MTIMENSEC_CMP(x, op, y) ((x)->st_mtimensec op (y)->st_mtimensec)
#else
#define ATIMENSEC_CMP(x, op, y) \
	((x)->st_atimespec.tv_nsec op (y)->st_atimespec.tv_nsec)
#define CTIMENSEC_CMP(x, op, y) \
	((x)->st_ctimespec.tv_nsec op (y)->st_ctimespec.tv_nsec)
#define MTIMENSEC_CMP(x, op, y) \
	((x)->st_mtimespec.tv_nsec op (y)->st_mtimespec.tv_nsec)
#endif

int
namecmp(const FTSENT *a, const FTSENT *b)
{

	return (strcmp(a->fts_name, b->fts_name));
}

int
revnamecmp(const FTSENT *a, const FTSENT *b)
{

	return (strcmp(b->fts_name, a->fts_name));
}

int
modcmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_mtime > a->fts_statp->st_mtime)
		return (1);
	else if (b->fts_statp->st_mtime < a->fts_statp->st_mtime)
		return (-1);
	else if (MTIMENSEC_CMP(b->fts_statp, >, a->fts_statp))
		return (1);
	else if (MTIMENSEC_CMP(b->fts_statp, <, a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revmodcmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_mtime > a->fts_statp->st_mtime)
		return (-1);
	else if (b->fts_statp->st_mtime < a->fts_statp->st_mtime)
		return (1);
	else if (MTIMENSEC_CMP(b->fts_statp, >, a->fts_statp))
		return (-1);
	else if (MTIMENSEC_CMP(b->fts_statp, <, a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

int
acccmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_atime > a->fts_statp->st_atime)
		return (1);
	else if (b->fts_statp->st_atime < a->fts_statp->st_atime)
		return (-1);
	else if (ATIMENSEC_CMP(b->fts_statp, >, a->fts_statp))
		return (1);
	else if (ATIMENSEC_CMP(b->fts_statp, <, a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revacccmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_atime > a->fts_statp->st_atime)
		return (-1);
	else if (b->fts_statp->st_atime < a->fts_statp->st_atime)
		return (1);
	else if (ATIMENSEC_CMP(b->fts_statp, >, a->fts_statp))
		return (-1);
	else if (ATIMENSEC_CMP(b->fts_statp, <, a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

int
statcmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_ctime > a->fts_statp->st_ctime)
		return (1);
	else if (b->fts_statp->st_ctime < a->fts_statp->st_ctime)
		return (-1);
	else if (CTIMENSEC_CMP(b->fts_statp, >, a->fts_statp))
		return (1);
	else if (CTIMENSEC_CMP(b->fts_statp, <, a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revstatcmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_ctime > a->fts_statp->st_ctime)
		return (-1);
	else if (b->fts_statp->st_ctime < a->fts_statp->st_ctime)
		return (1);
	else if (CTIMENSEC_CMP(b->fts_statp, >, a->fts_statp))
		return (-1);
	else if (CTIMENSEC_CMP(b->fts_statp, <, a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

int
sizecmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_size > a->fts_statp->st_size)
		return (1);
	if (b->fts_statp->st_size < a->fts_statp->st_size)
		return (-1);
	else
		return (namecmp(a, b));
}

int
revsizecmp(const FTSENT *a, const FTSENT *b)
{

	if (b->fts_statp->st_size > a->fts_statp->st_size)
		return (-1);
	if (b->fts_statp->st_size < a->fts_statp->st_size)
		return (1);
	else
		return (revnamecmp(a, b));
}
/*	$NetBSD: util.c,v 1.34 2011/08/29 14:44:21 joerg Exp $	*/

/*
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)util.c	8.5 (Berkeley) 4/28/95";
#else
__RCSID("$NetBSD: util.c,v 1.34 2011/08/29 14:44:21 joerg Exp $");
#endif
#endif /* not lint */

#include <sys/types.h>
#include <sys/stat.h>

#include <err.h>
#include <fts.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vis.h>
#include <wchar.h>
#include <wctype.h>

int
safe_print(const char *src)
{
	size_t len;
	char *name;
	int flags;

	flags = VIS_NL | VIS_OCTAL | VIS_WHITE;
	if (f_octal_escape)
		flags |= VIS_CSTYLE;

	len = strlen(src);
	if (len != 0 && SIZE_T_MAX/len <= 4) {
		errx(EXIT_FAILURE, "%s: name too long", src);
		/* NOTREACHED */
	}

	name = (char *)malloc(4*len+1);
	if (name != NULL) {
		len = strvis(name, src, flags);
		(void)printf("%s", name);
		free(name);
		return len;
	} else
		errx(EXIT_FAILURE, "out of memory!");
		/* NOTREACHED */
}

/*
 * The reasons why we don't use putwchar(wc) here are:
 * - If wc == L'\0', we need to restore the initial shift state, but
 *   the C language standard doesn't say that putwchar(L'\0') does.
 * - It isn't portable to mix a wide-oriented function (i.e. getwchar)
 *   with byte-oriented functions (printf et al.) in same FILE.
 */
static int
printwc(wchar_t wc, mbstate_t *pst)
{
	size_t size;
	char buf[MB_LEN_MAX];

	size = wcrtomb(buf, wc, pst);
	if (size == (size_t)-1) /* This shouldn't happen, but for sure */
		return 0;
	if (wc == L'\0') {
		/* The following condition must be always true, but for sure */
		if (size > 0 && buf[size - 1] == '\0')
			--size;
	}
	if (size > 0)
		fwrite(buf, 1, size, stdout);
	return wc == L'\0' ? 0 : wcwidth(wc);
}

int
printescaped(const char *src)
{
	int n = 0;
	mbstate_t src_state, stdout_state;
	/* The following +1 is to pass '\0' at the end of src to mbrtowc(). */
	const char *endptr = src + strlen(src) + 1;

	/*
	 * We have to reset src_state each time in this function, because
	 * the codeset of src pathname may not match with current locale.
	 * Note that if we pass NULL instead of src_state to mbrtowc(),
	 * there is no way to reset the state.
	 */
	memset(&src_state, 0, sizeof(src_state));
	memset(&stdout_state, 0, sizeof(stdout_state));
	while (src < endptr) {
		wchar_t wc;
		size_t rv, span = endptr - src;

#if 0
		/*
		 * XXX - we should fix libc instead.
		 * Theoretically this should work, but our current
		 * implementation of iso2022 module doesn't actually work
		 * as expected, if there are redundant escape sequences
		 * which exceed 32 bytes.
		 */
		if (span > MB_CUR_MAX)
			span = MB_CUR_MAX;
#endif
		rv = mbrtowc(&wc, src, span, &src_state);
		if (rv == 0) { /* assert(wc == L'\0'); */
			/* The following may output a shift sequence. */
			n += printwc(wc, &stdout_state);
			break;
		}
		if (rv == (size_t)-1) { /* probably errno == EILSEQ */
			n += printwc(L'?', &stdout_state);
			/* try to skip 1byte, because there is no better way */
			src++;
			memset(&src_state, 0, sizeof(src_state));
		} else if (rv == (size_t)-2) {
			if (span < MB_CUR_MAX) { /* incomplete char */
				n += printwc(L'?', &stdout_state);
				break;
			}
			src += span; /* a redundant shift sequence? */
		} else {
			n += printwc(iswprint(wc) ? wc : L'?', &stdout_state);
			src += rv;
		}
	}
	return n;
}
