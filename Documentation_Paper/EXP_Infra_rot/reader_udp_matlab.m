u=udp('localhost', 9300);
fopen(u);
A=fread(u, 10);
disp( A );
fclose(u);