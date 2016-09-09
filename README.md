# mbfc

mbfc is a minimalistic Brainfuck interpreter and compiler
to the C language.

## Building

The only things you need to compile mbfc is GNU Make and a
C++14 compliant compiler. Running ```make``` at the root
of the project will create the mbfc executable.

## Usage

mbfc [FILE] [OPTIONS...]

Options:

-h, --help	Displays this help.

-i	Interprets the code instead of compiling.

-o FILE	Sets the file to compile into. If absent, writes to stdout.

### Example:

Interpret a file called hello_world.bf:

    mbfc -i hello_world.bf

Compile a file called hello_world.bf into hello_world.c:

    mbfc hello_world.bf -o hello_world.bf

## Possible enhancments

- Optimizations
- Proper indentation of produced C code
- Support of other target languages than C

## Author

Moray Baruh
contact@moraybaruh.com

## License

mbfc is available under the MIT license. See the LICENSE file for more info.
