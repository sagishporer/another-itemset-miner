# Another Itemset Miner
AIM (Another Itemset Miner) is a (2004) state of the art itemset miner. It took part in FIMI 2003 & 2004 frequent itemset mining workshops/contests.

For more information about FIMI and detailed experiments see the FIMI web page:
http://fimi.ua.ac.be/

## Usage
To compile the software on unix machines run 'make' to complie fim_all executable. On windows use your favorite C++ compiler. The implementation was tested on VC++ 7 & VC++ 7.1

To run the software:
fim_all <InputFile> <MinSupport> OutputFile

example:
fim_all chess.dat 2000

## Input
The dataset input must use the following ASCII format only:
Every transaction is on a separate line as a list of items separated by white space and ending with a newline.
Every item is a non-negative integer.

## Output
After execution, the program prints the number of frequent itemsets for each length between 1 and k separately to the standard output stream, with k being the size of the largest itemset.
If an output file was specified:

All frequent itemsets will be printed to to the file in the following format:
Every line contains a single frequent itemset as a list of items separated by whitespace. At the end of the line, the support (number of transactions) is printed thus: (XXXX). 
