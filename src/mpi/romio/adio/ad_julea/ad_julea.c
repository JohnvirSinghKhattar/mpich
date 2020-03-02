/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *
 *   Copyright (C) 2020 TODO
 *   See COPYRIGHT notice in top-level directory.
 */

#include "ad_julea.h"

/* adioi.h has the ADIOI_Fns_struct define */
#include "adioi.h"

struct ADIOI_Fns_struct ADIO_JULEA_operations = {
    ADIOI_JULEA_Open,     /* Open */
    ADIOI_JULEA_ReadContig,       /* ReadContig */
    ADIOI_JULEA_WriteContig,      /* WriteContig */
    ADIOI_GEN_Close,    /* Close */

    "JULEA:",     /* fsname: just a string */
#if defined(F_SETLKW64)
    ADIOI_GEN_SetLock   /* SetLock */
#else
    ADIOI_GEN_SetLock64 /* SetLock */
#endif
};