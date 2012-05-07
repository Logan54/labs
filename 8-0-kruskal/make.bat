cl.exe /TC /c /O2 allocArrayOfEdges.c getEdges.c main.c readFirstValues.c searchTree.c
link.exe /OUT:kruskal.exe /NOLOGO allocArrayOfEdges.obj getEdges.obj main.obj readFirstValues.obj searchTree.obj