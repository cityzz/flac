/* replaygain - Convenience lib for calculating/storing ReplayGain in FLAC
 * Copyright (C) 2002  Josh Coalson
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
 * This wraps the gain_analysis lib, which is LGPL.  This wrapper
 * allows analysis of different input resolutions by automatically
 * scaling the input signal
 */

#ifndef FLAC__SHARE__REPLAYGAIN_H
#define FLAC__SHARE__REPLAYGAIN_H

#if defined(FLAC__NO_DLL) || defined(unix) || defined(__CYGWIN__) || defined(__CYGWIN32__)
#define REPLAYGAIN_API

#else

#ifdef REPLAYGAIN_API_EXPORTS
#define	REPLAYGAIN_API	_declspec(dllexport)
#else
#define REPLAYGAIN_API	_declspec(dllimport)
#define __LIBNAME__ "replaygain.lib"
#pragma comment(lib, __LIBNAME__)
#undef __LIBNAME__

#endif
#endif

#include "FLAC/metadata.h"

#ifdef __cplusplus
extern "C" {
#endif

REPLAYGAIN_API FLAC__bool FLAC__replaygain_is_valid_sample_frequency(unsigned sample_frequency);

REPLAYGAIN_API FLAC__bool FLAC__replaygain_init(unsigned sample_frequency);

/* 'bps' must be valid for FLAC, i.e. >=4 and <= 32 */
REPLAYGAIN_API FLAC__bool FLAC__replaygain_analyze(const FLAC__int32 * const input[], FLAC__bool is_stereo, unsigned bps, unsigned samples);

REPLAYGAIN_API float FLAC__replaygain_get_album_gain();
REPLAYGAIN_API float FLAC__replaygain_get_title_gain();

/* These three functions return an error string on error, or NULL if successful */
REPLAYGAIN_API const char *FLAC__replaygain_analyze_file(const char *filename, float *title_gain, float *title_peak);
REPLAYGAIN_API const char *FLAC__replaygain_store_to_vorbiscomment(FLAC__StreamMetadata *block, float album_gain, float album_peak, float title_gain, float title_peak);
REPLAYGAIN_API const char *FLAC__replaygain_store_to_file(const char *filename, float album_gain, float album_peak, float title_gain, float title_peak, FLAC__bool preserve_modtime);

#ifdef __cplusplus
}
#endif

#endif