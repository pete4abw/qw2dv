/* FREEWARE
 * Use, modify, freely
 * No warranty
 * Peter Hyman
 * pete@peterhyman.com
 */

#include <stdio.h>
#include <stdlib.h>

// DVORAK
static char dv[]=" `1234567890[]~!@#$%^&*(){}',.pyfgcrl/=\\\"<>PYFGCRL?+|aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ";

// QWERTY
static char qw[]=" `1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?";

static int len = sizeof(dv);

int main(int argc, char *argv[])
{
	int convert = 0;	// 0 = q to d, 1 = d to q
	char *word_to_convert;

	fprintf(stdout,"dv=%s\nqw=%s\n", dv, qw);

	if (argc == 1)
	{
		fprintf(stderr,"usage %s: q|d word_to_convert\n", argv[0]);
		exit(1);
	}
	else if (argc == 2)
		word_to_convert = argv[1];
	else if (argc == 3)
	{
		convert = (*argv[1] == 'd' ? 1 : \
			  (*argv[1] == 'D' ? 1 : 0));
		word_to_convert = argv[2];
	}
	else
	{
		fprintf(stderr,"too many arguments %s\n", argv[0]);
		exit(1);
	}
	fprintf(stdout,"word_to_convert = %s, convert = %s, size of static var: %d\n", word_to_convert, convert == 0 ? "q2d" : "d2q", len);

	int i, j;
	for ( i = 0; word_to_convert[i] != '\0'; i++ )
	{
		for ( j = 0; j < len; j++ )
		{
			if ( convert == 0 )	// convert qwerty to dvorak
			{
				if ( word_to_convert[i] == qw[j] )
				{
					putc(dv[j], stdout);
					break;
				}
			}
			else			// convert dvorak to qwerty
			{
				if ( word_to_convert[i] == dv[j] )
				{
					putc(qw[j], stdout);
					break;
				}
			}
		}
	}
	putc('\n', stdout);
}
