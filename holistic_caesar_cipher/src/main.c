#include <stdio.h>
#include <string.h>
#include <ctype.h>

void hcc(char * input)
{
	printf("%s", "Encrypted text:\n");

	char punct[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	// Unrecognised characters by the C locale:
	// "£¬"
	unsigned long punct_len = sizeof(punct) - 1;

	int shift = 1;
	while ( shift != 48 )
	{
		for ( unsigned int i = 0; i < strlen(input); i++ )
		{
			// Handle alpha characters.
			if ( isalpha(input[i]) )
			{
				// Uppercase:
				if ( isupper(input[i]) )
				{
					printf("%c",
					((input[i] - 'A' + shift) % 26 + 'A')
					); 
				}
				// Lowercase:
				if ( islower(input[i]) )
				{
					printf("%c",
					((input[i] - 'a' + shift) % 26 + 'a')
					);
				}
			}
			// Handle numbers:
			if ( isdigit(input[i]) )
			{
				printf("%c",
				((input[i] - '0' + shift) % 10 + '0')
				);
			}
			// Handle special characters:
			if ( ispunct(input[i]) )
			{
				char * current_char = strchr(punct, input[i]);
				printf("%c",
				punct[(current_char - punct + shift) % punct_len]
				);
			}
		}
		switch(shift)
		{
			case 5:
			printf("%s", " - ROT5");
			break;

			case 13:
			printf("%s", " - ROT13");
			break;

			case 18:
			printf("%s", " - ROT18");
			break;

			case 47:
			printf("%s", " - ROT47");
			break;

			default:
			printf(" - %d", shift);
			break;
		}
		printf("%s", "\n");

		shift++;
	}
}

int main()
{
	char input[512];

	printf("%s", "Input plaintext:\n");
	fgets(input, 512, stdin);

	hcc(input);

	return 0;
}
