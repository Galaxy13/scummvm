/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef BLADERUNNER_AESC_H
#define BLADERUNNER_AESC_H

#include "bladerunner/color.h"

#include "common/array.h"

namespace Common {
class ReadStream;
}

namespace BladeRunner {
class BladeRunnerEngine;

class AESC {
public:
	struct Entry
	{
		Color256 palette[16];
		uint16   x;
		uint16   y;
		uint16   width;
		uint16   height;
		uint16   z;
		uint8   *data;
	};

	BladeRunnerEngine *_vm;

	Common::Array<Entry>  _entries;
	uint8                *_data;
	int                   _dataSize;

public:
	AESC(BladeRunnerEngine *vm, int size);
	~AESC();

	void readVqa(Common::SeekableReadStream *stream);
	void getColor(Color256 *outColor, uint16 x, uint16 y, uint16 z);

	//TODO
	//bool isAffectingArea(int x, int y, int width, int height, int unk);
};
} // End of namespace BladeRunner

#endif
