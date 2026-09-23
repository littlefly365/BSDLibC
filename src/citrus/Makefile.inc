.PATH: ${.CURDIR}/citrus

SRCS+=citrus_bcs.c citrus_bcs_strtol.c citrus_bcs_strtoul.c citrus_csmapper.c citrus_ctype.c \
      citrus_ctype_fallback.c citrus_db.c citrus_db_factory.c citrus_db_hash.c citrus_esdb.c \
      citrus_hash.c citrus_iconv.c citrus_lc_ctype.c citrus_lc_messages.c citrus_lc_monetary.c \
      citrus_lc_numeric.c citrus_lc_time.c citrus_lookup.c citrus_lookup_factory.c citrus_mapper.c \
      citrus_memstream.c citrus_mmap.c citrus_module.c citrus_none.c citrus_pivot_factory.c \
      citrus_prop.c citrus_stdenc.c

.include "${.CURDIR}/citrus/modules/Makefile.inc"
