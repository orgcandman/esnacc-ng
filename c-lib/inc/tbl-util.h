/*
 * tbl-util.h - type table utilities.
 *
 *
 * Mike Sample
 *
 * Copyright (C) 1993 Michael Sample
 *            and the University of British Columbia
 *
 * This library is free software; you can redistribute it and/or
 * modify it provided that this copyright/license information is retained
 * in original form.
 *
 * If you modify this file, you must clearly indicate your changes.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $Header: /baseline/SNACC/c-lib/inc/tbl-util.h,v 1.4 2003/12/17 19:05:03 gronej Exp $
 * $Log: tbl-util.h,v $
 * Revision 1.4  2003/12/17 19:05:03  gronej
 * SNACC baseline merged with PER v1_7 tag
 *
 * Revision 1.3.2.1  2003/11/05 14:58:55  gronej
 * working PER code merged with esnacc_1_6
 *
 * Revision 1.3  2002/10/21 17:13:24  mcphersc
 * fixed long int
 *
 * Revision 1.2  2001/07/12 19:34:09  leonberp
 * Changed namespace to SNACC and added compiler options: -ns and -nons.  Also removed dead code.
 *
 * Revision 1.1.1.1  2000/08/21 20:35:55  leonberp
 * First CVS Version of SNACC.
 *
 * Revision 1.1  1995/07/27 08:55:59  rj
 * first check-in after being merged into .../c-lib/.
 *
 */

/*
 * these rely on the TBLTagClass enum starting at zero
 * and being in the order: UNIVERSAL, APPLICATION, CONTEXT, PRIVATE
 */
#define TblTagClassToBer(tblClass) (tblClass << 6)
#define BerTagClassToTbl(berClass) (berClass >> 6)
#define TagsEquiv(asnTag, tblTag) (((tblTag)->encTag == (asnTag)) ||\
         (((tblTag)->form == ANY_FORM) &&\
          ((tblTag)->encTag == DECONSIFY (asnTag))))


char *LoadFile PROTO ((char *tblFileName, unsigned long  *size));

TBL *LoadTblFile PROTO ((char *tblFileName));

TBLTypeDef *TblFindTypeDef PROTO ((TBL *tbl, char *moduleName, char *typeName, TBLModule **tblModHndl));

TBLTypeDef *TblFindTypeDefInMod PROTO ((TBLModule *tbl, char *typeName));

TBLTypeDef *TblFindTypeDefByIndex PROTO ((TBL *tbl,TBLTypeDefId id));

TBLModule *TblFindModule PROTO ((TBL *tbl, char *modName));

