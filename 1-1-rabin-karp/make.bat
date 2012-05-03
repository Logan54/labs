cl.exe /O2 main.c hash.c rehash.c seek_substring_RK.c rewrite.c
link.exe -out:main.exe main.obj hash.obj rehash.obj seek_substring_RK.obj rewrite.obj