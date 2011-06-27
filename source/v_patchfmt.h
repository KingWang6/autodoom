// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright(C) 2011 James Haley
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//--------------------------------------------------------------------------
//
// DESCRIPTION:
//  Patch format verification and load-time processing code
//
//-----------------------------------------------------------------------------

#ifndef V_PATCHFMT_H__
#define V_PATCHFMT_H__

#include "w_wad.h"

struct patch_t;

class PatchLoader : public WadLumpLoader
{
public:
   virtual bool verifyData(const void *data, size_t size) const;
   virtual bool formatData(void *data, size_t size) const;
   virtual int  getErrorMode() const;

   static patch_t *CacheName(WadDirectory &dir, const char *name, int tag);
   static patch_t *CacheNum(WadDirectory &dir, int lumpnum, int tag);
};

// A global instance of PatchLoader for passing to WadDirectory methods
extern PatchLoader patchFmt;

#endif

// EOF
