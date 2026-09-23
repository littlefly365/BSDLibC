.PATH: ${.CURDIR}/locale

SRCS+=__mb_cur_max.c _wctrans.c _wctype.c c16rtomb.c c32rtomb.c c8rtomb.c dummy_lc_collate.c \
      duplocale.c fix_grouping.c freelocale.c generic_lc_all.c global_locale.c iswctype_mb.c \
      localeconv.c mbrtoc16.c mbrtoc32.c mbrtoc8.c multibyte_amd1.c multibyte_c90.c newlocale.c \
      nl_langinfo.c rune.c runetable.c setlocale.c wcscoll.c wcsftime.c wcstod.c wcstof.c \
      wcstoimax.c wcstol.c wcstold.c wcstoll.c wcstoul.c wcstoull.c wcstoumax.c wcsxfrm.c

