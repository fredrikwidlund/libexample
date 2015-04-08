LIB_CFLAGS = -O3 -flto -std=c11

if HAVE_FAT_LTO_OBJECTS
LIB_CFLAGS += -ffat-lto-objects
endif

LIB_TEST_CFLAGS = -O0 -g -ftest-coverage -fprofile-arcs -std=c11 -I/opt/local/include
LDADD_TEST_FLAGS = -L. -lexample_test -lcmocka -L/opt/local/lib

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

SOURCE_FILES = src/example.c
HEADER_FILES = src/example.h

lib_LTLIBRARIES= libexample.la
libexample_la_CFLAGS = $(LIB_CFLAGS)
libexample_la_LDFLAGS = -static
libexample_la_SOURCES = $(SOURCE_FILES) $(HEADER_FILES)

check_LIBRARIES = libexample_test.a
libexample_test_a_CFLAGS = $(LIB_TEST_CFLAGS)
libexample_test_a_SOURCES = $(SOURCE_FILES) $(HEADER_FILES)

BUILD_TESTS = test/test_example
TESTS = $(BUILD_TESTS) test/test_valgrind.sh test/test_coverage.sh

check_PROGRAMS = $(BUILD_TESTS)
check_SCRIPTS = test
TEST_LD_WRAP = -Wl,--wrap=malloc -Wl,--wrap=calloc -Wl,--wrap=realloc -Wl,--wrap=aligned_alloc
AM_CFLAGS = $(LIB_TEST_CFLAGS)
AM_LDFLAGS = $(LDADD_TEST_FLAGS) $(TEST_LD_WRAP)

test_test_example_SOURCES = test/test_example.c test/test_util.c

headerfilesdir = $(includedir)/example
headerfiles_HEADERS = $(HEADER_FILES)

mainheaderdir = $(includedir)
mainheader_HEADERS = src/example.h

dist_man3_MANS = man/example.3
dist_noinst_SCRIPTS = autogen.sh test/test_valgrind.sh test/test_coverage.sh

CLEANFILES = {./,src,test}/*.{gcno,gcda,gcov}
MAINTAINERCLEANFILES = aclocal.m4 config.h.in configure Makefile.in libexample-*.tar.gz INSTALL

maintainer-clean-local:
	rm -rf autotools m4 libexample-0.1.0
