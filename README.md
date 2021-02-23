# find-text
Creating a command line application to find and replace strings in text files

How to use:
To use the program, enter nmake find to compile.
After compilation, specify a string to be found and if a replacement is wanted to be done, specify what it should be replaced with what in the command line.

How to build (for Microsoft Compiler):
Type nmake find into the console
Once compiled, in order to FIND a string in either of the text files, type in find followed by the string you are looking for and -i followed by the name of the textfile .txt

i.e.
find eve -i single_words_test.txt

gives the following output:
level
everything
level
developers
level
level
level
level
However
level
level

In order to FIND and REPLACE a string in either of the text files:
Do the same as above however add -r followed by the string you want the first string to be replaced with

i.e.
find eve -i sentences_test.txt -r TREE

This will find every string containing 'eve' and replace it with 'TREE'
i.e.
level -> lTREEl

Ignoring case works does not work in the program, however adding -c in the command line will not break the program and will still work for -i and -r if specified.

