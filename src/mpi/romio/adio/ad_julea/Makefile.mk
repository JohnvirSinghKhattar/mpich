## -*- Mode: Makefile; -*-
## vim: set ft=automake :
##
## (C) 2020 by TODO.
##     See COPYRIGHT in top-level directory.
##

if BUILD_AD_JULEA

noinst_HEADERS += adio/ad_julea/ad_julea.h

romio_other_sources +=            \
    adio/ad_julea/ad_julea_read.c     \
    adio/ad_julea/ad_julea_open.c     \
    adio/ad_julea/ad_julea_write.c    \
    adio/ad_julea/ad_julea.c

endif BUILD_AD_JULEA