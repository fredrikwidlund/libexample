libexample
==========
http://fredrikwidlund.github.io/libexample/

Library template including unit testing, code coverage, memory leakage tests, and continuous integration tests.

Installation
------------

    ./autogen.sh
    ./configure
    make
    sudo make install

Tests
-----

Requires cmocka (http://cmocka.org/) to be installed, as well as valgrind (http://valgrind.org/) for memory tests.

    make check
