#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void print_usage()
{
	printf("%s\n\n", "Usage: ./xorcrypt <-e>/<-d> <file.txt/file.xc>/<file.xc/file.txt> <key>");
	printf("%s\n\n", "i.e.        encrypt/decrypt  input-file         output-file        key");
	printf("%s\n",   "File extensions are not a requirement,");
	printf("%s\n",   "i.e. '.txt'/'.xc' are not strictly necessary,");
	printf("%s\n\n", "but are recommended for xorcrypt-encrypted file identification.");
	exit(1);
}

void _xor(FILE * file, unsigned int key, std::ofstream &output_file)
{
	char current_byte;

	while ( ((current_byte = fgetc(file)) != EOF) )
	{
		output_file.put(static_cast<char>(current_byte ^ key));
	}
}

void encrypt(FILE * input_file, std::string output_filename, unsigned int key)
{
	// Writing to an encrypted file.
	std::string encrypted_filename = output_filename;

	std::ofstream encrypted_file;
	encrypted_file.open(encrypted_filename, std::ios::out | std::ios::binary);

	_xor(input_file, key, encrypted_file);

	encrypted_file.close();
}

void decrypt(FILE * input_file, std::string output_filename, unsigned int key)
{
	// Writing to a decrypted file.
	std::string filename = output_filename;

	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);

	_xor(input_file, key, file);

	file.close();
}

int main(int argc, char **argv)
{
	// **argv
	// ./xorcrypt <encrypt/decrypt> <txt/xc> <xc/txt> <key>
	// total = 5, ^[1]              ^[2]     ^[3]     ^[4]

	if ( !(argc == 5) ) { print_usage(); }

	FILE * file = fopen(argv[2], "rb");
	unsigned int key = atoi(argv[4]);

	// Get filename to be able to handle file safely.
	std::string input_filename;
	input_filename = argv[2];

	// if fopen() returns NULL, the file does not exist.
	if ( file == NULL )
	{
		std::cout << "Cannot read file '" << input_filename << "'!\n";
		exit(1);
	}

	// Get output filename to be able to write to the file stated by the user.
	std::string output_filename;
	output_filename = argv[3];

	if ( strcmp(argv[1], "-e") == 0 )
	{
		encrypt(file, output_filename, key);
	}
	else if ( strcmp(argv[1], "-d") == 0 )
	{
		if ( strstr(argv[2], ".xc") == NULL )
		{
			char opt;
			printf("%s\n", "Input file is not an '.xc' file! Are you sure?");
			printf("%s", "[y/n]: ");
			scanf("%c", &opt);
			if ( opt == 'n' ) { printf("%s\n", "Terminating..."); exit(1); }
		}

		decrypt(file, output_filename, key);
	}
	else { print_usage(); }

	// Close the input file.
	fclose(file);

	return 0;
}
