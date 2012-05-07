cl.exe /O2 main.c seek_substring_BM.c rewrite.c
link.exe /out:BM.exe main.obj seek_substring_BM.obj rewrite.obj
