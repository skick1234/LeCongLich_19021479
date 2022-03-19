1s: 1.server.c
	gcc 1.server.c -o out/1.server
	./out/1.server || true
1c: 1.client.c
	gcc 1.client.c -o out/1.client
	./out/1.client || true
2s: 2.server.c
	gcc 2.server.c -o out/2.server
	./out/2.server || true
2c: 2.client.c
	gcc 2.client.c -o out/2.client
	./out/2.client || true
3s: 3.server.c
	gcc 3.server.c -o out/3.server
	./out/3.server || true
3c: 3.client.c
	gcc 3.client.c -o out/3.client
	./out/3.client || true
4s: 4.server.c
	gcc 4.server.c -o out/4.server -pthread
	./out/4.server || true
4c: 4.client.c
	gcc 4.client.c -o out/4.client
	./out/4.client || true