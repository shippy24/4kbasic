

#include <math.h>
#include "mzk.h"
#include "system.h"



// put here your synth
void mzk_init( short *buffer )
{
	float fl;
	float fr;
    for( int i=0; i<MZK_NUMSAMPLES; i++ ) 
    {
		if (i % 2 == 0) {
			fl = sinf(6.2831f * 440.0f * (float)i / (float)MZK_RATE);
			fr = sinf(6.2831f * 587.3f * (float)i / (float)MZK_RATE);
		}
		else if (i % 3 == 0)
		{
			fl = sinf(6.2831f * 110.0f * (float)i / (float)MZK_RATE);
			fr = sinf(6.2831f * 253.3f * (float)i / (float)MZK_RATE);
		}
		else {
			fl = sinf(6.2831f * 55.0f * (float)i / (float)MZK_RATE);
			fr = sinf(6.2831f * 78.3f * (float)i / (float)MZK_RATE);
		}
        buffer[2 * i + 0] = f2i(fl*32767.0f);
        buffer[2 * i + 1] = f2i(fr*32767.0f);
    }
}
