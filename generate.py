#!/usr/bin/env python3
import os
day = "Day1"

os.mkdir(day)

with open(f"{day}/{day}.cpp", 'w') as f:
    f.write(f'''#include "{day}.hpp"\n''')

with open(f"{day}/{day}.hpp", 'w') as f:
    f.write(f'')

with open(f"{day}/Test{day}.cpp", 'w') as f:
    f.write(f'''#include "{day}.hpp"\n''')

    f.write('''#include "gtest/gtest.h"\n\n''')
    f.write("TEST(Test{}, initialize)".format(day))
    f.write('''{\n''')
    f.write('''    ASSERT_EQ(1, 1);\n''')
    f.write('''    }\n\n''')

    f.write('''int main(int argc, char **argv) {\n''')
    f.write('''  ::testing::InitGoogleTest(&argc, argv);\n''')
    f.write('''return RUN_ALL_TESTS();\n''')
    f.write('''}\n''')



with open("Makefile", 'a') as f:
    f.write(f"{day.lower()}:\n")
    f.write(f"\t$(CC) {day}/{day}.cpp {day}/Test{day}.cpp $(GTEST_FLAGS) -o run\n")
