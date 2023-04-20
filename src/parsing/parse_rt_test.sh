cd ../../build;
make;
cd ../src/parsing;

echo file arguments;

echo test1 == win;
../../build/miniRT rt_test_files/test1.rt;
echo test2 == fail;
../../build/miniRT rt_test_files/test2.rt;
echo test3 == win;
../../build/miniRT rt_test_files/test3.rt;
echo test4 == fail;
../../build/miniRT rt_test_files/test4.rt;
echo test5 == win;
../../build/miniRT rt_test_files/test5.rt;
echo test6 == fail;
../../build/miniRT rt_test_files/test6.rt;
echo test7 == win;
../../build/miniRT rt_test_files/test7.rt;
echo test8 == fail;
../../build/miniRT rt_test_files/test8.rt;
echo test9 == win;
../../build/miniRT rt_test_files/test9.rt;
echo test10 == fail;
../../build/miniRT rt_test_files/test10.rt;

echo crazy file names ;

echo test1 == win;
../../build/miniRT rt_test_files/1.rt;
echo test2 == fail;
../../build/miniRT rt_test_files/.rt;
echo test3 == win;
../../build/miniRT rt_test_files/A.rt;
echo test4 == fail;
../../build/miniRT rt_test_files/A.rrt;
echo test5 == win;
../../build/miniRT rt_test_files/_.rt;
echo test6 == fail;
../../build/miniRT rt_test_files/test6.r.t;
echo test7 == win;
../../build/miniRT rt_test_files/bla.rt;
echo test8 == fail;
../../build/miniRT rt_test_files/bla......rt;