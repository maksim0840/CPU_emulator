add_test([=[Stack.constructor]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack]==] [==[--gtest_filter=Stack.constructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Stack.constructor]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Stack.assignment_operator]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack]==] [==[--gtest_filter=Stack.assignment_operator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Stack.assignment_operator]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Stack.push]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack]==] [==[--gtest_filter=Stack.push]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Stack.push]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Stack.pop]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack]==] [==[--gtest_filter=Stack.pop]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Stack.pop]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Stack.top]=]  [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack]==] [==[--gtest_filter=Stack.top]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Stack.top]=]  PROPERTIES WORKING_DIRECTORY [==[/home/user/Documents/C++/cpu_emulator/build/libs/Stack]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_Stack_TESTS Stack.constructor Stack.assignment_operator Stack.push Stack.pop Stack.top)