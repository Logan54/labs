cl.exe /O2 /nologo /c /TC memoryFree.c getEdges.c main.c searchAndPrint.c allocArrayOfLists.c readFirstValues.c
link.exe /OUT:9-dijkstra-path.exe memoryFree.obj getEdges.obj main.obj searchAndPrint.obj allocArrayOfLists.obj readFirstValues.obj