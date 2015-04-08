#!/bin/sh

#!/bin/sh

for file in $(find src -type f -name '*.c' -exec basename {} \; | sed 's/\.c//g' | sort)
do
    echo [$file]
    test=$(gcov -b src/libexample_test_a-$file | grep -A4 File.*$file)
    echo "$test"
    echo "$test" | grep '% of' | grep '100.00%' >/dev/null || exit 1
    echo "$test" | grep '% of' | grep -v '100.00%' >/dev/null && exit 1
done
exit 0
