#/bin/sh
version=18
cp googleBook.cpp googleBook_v$version.cpp
./googleBook < a_example.txt >a$version.out
./googleBook < b_read_on.txt >b$version.out
./googleBook < c_incunabula.txt >c$version.out
./googleBook < d_tough_choices.txt >d$version.out
./googleBook < e_so_many_books.txt >e$version.out
./googleBook < f_libraries_of_the_world.txt >f$version.out
