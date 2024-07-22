 #include <iostream>
 int main(int argc, char *argv[]) {
 return (argc != 3 || link(argv[1], argv[2]) ==-1) ?
 (perror("link"), 1) : (std::cout << "Hard link created.\n", 0);
 }
