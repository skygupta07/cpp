/*
to check if a given DAG contains cycle or not -> we can apply kahn's algorithm....(i.e. 
topological sorting)


-> to detect cycle in an undirected graph we can use bfs , dfs, or dsu...

cycle detection using dsu kiya 
-> pehle sabko khudse hi associate kiya then union karte gaye find fn se parent nikal
nikal ke ...

at any moment if you are adding a new edge and if somehow it was present already in the 
same group then this current edge will create a cycle....






*/