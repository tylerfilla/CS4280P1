3
scanner_table.gen.h
p1::scanner::next_token()

Tyler Filla
CS 4280
Project 1

Description
===========

I chose to create the scanner using a finite state automaton (option 3). As a
matter of design, I also wanted to make each keyword its own token. This, of
course, complicated the table significantly, so I created a small program to
generate the table source code from a simple text file. This allows me to
reference FSA states by name, which allowed much more convenient fixes when
bugs inevitably cropped up.

The FSA table is modelled in table.txt. On build, the table is generated in
scanner_table.gen.h. The p1::scanner<T>::next_token() function in scanner.h is
the primary driver, though it calls upon sibling member functions for small
tasks (such as mapping the input alphabet to a smaller domain than the entirety
of ASCII, which helps keep the table small).

There are no complementary *.cpp files for the *.h files, as templates are
involved. The size of the scanner class, for instance, cannot be known without
knowing the size of the input iterator type. Similarly, a scanner object cannot
be used in the scanner_tester class without knowing its full type. Some small
functions could be broken out into *.cpp files, but I don't see a practical
reason to do so.

Building
========

Run the following command to build everything:
$ make

To regenerate the FSA table:
$ make tablegen
./tablegen table.txt
