cl.exe /O2 main.c sift.c heap_sort.c
link.exe -out:main.exe main.obj heap_sort.obj sift.obj