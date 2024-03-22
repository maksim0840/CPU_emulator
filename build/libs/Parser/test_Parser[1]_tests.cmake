add_test([=[Parser.file_opening_error]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser/test_Parser]==] [==[--gtest_filter=Parser.file_opening_error]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parser.file_opening_error]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Parser.scan_test1]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser/test_Parser]==] [==[--gtest_filter=Parser.scan_test1]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parser.scan_test1]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Parser.scan_test2]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser/test_Parser]==] [==[--gtest_filter=Parser.scan_test2]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parser.scan_test2]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Parser.scan_test3]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser/test_Parser]==] [==[--gtest_filter=Parser.scan_test3]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parser.scan_test3]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Parser.scan_test4]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser/test_Parser]==] [==[--gtest_filter=Parser.scan_test4]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parser.scan_test4]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Parser]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_Parser_TESTS Parser.file_opening_error Parser.scan_test1 Parser.scan_test2 Parser.scan_test3 Parser.scan_test4)