/*
 * Copyright 2010-2017 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#include "test.h"

#include <bx/easing.h>
#include <bx/file.h>

TEST_CASE("easing", "")
{
	if (BX_ENABLED(false) )
	{
		bx::WriterI* writer = bx::getStdOut();

		for (uint32_t ee = 0; ee < bx::Easing::Count; ++ee)
		{
			bx::writePrintf(writer, "\n\n%d\n", ee);

			const bx::EaseFn easing = bx::getEaseFunc(bx::Easing::Enum(ee) );

			const int32_t nx = 64;
			const int32_t ny = 10;

			bx::writePrintf(writer, "\t///      ^\n");

			for (int32_t yy = ny+4; yy >= -5; --yy)
			{
				const float ys = float(yy    )/float(ny);
				const float ye = float(yy+1.0)/float(ny);

				bx::writePrintf(writer, "\t///      %c", yy != 0 ? '|' : '+');

				for (int32_t xx = 0; xx < nx; ++xx)
				{
					int32_t jj = 0;
					for (; jj < 10; ++jj)
					{
						const float tt = float(xx*10+jj)/10.0f/float(nx);
						const float vv = easing(tt);

						if (vv >= ys
						&&  vv <  ye)
						{
							bx::writePrintf(writer, "*");
							break;
						}
					}

					if (jj == 10)
					{
						bx::writePrintf(writer, "%c", yy != 0 ? ' ' : '-');
					}
				}

				bx::writePrintf(writer, "%s\n", yy != 0 ? "" : ">");
			}
		}
	}
}
