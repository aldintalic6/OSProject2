# OSProject2

Members: Aldin Talić, Admir Nedžibović

Listing of files/directories in submission: Main folder "OS-Project2" contains: README.md, program.c (code of the program). 

*************************

Instructions for compiling: 
- open terminal in "OSProject2" directory. 
- to compile type gcc -Wall -o program program.c 
- to run ./program

*************************

- The mmap system call allows a process to request a specific range of memory to be mapped into its 
address space. 

- The munmap system call is used to deallocate the memory mapping created by the mmap system call

*************************

- When the mmap system call is used, the VSZ (virtual memory) consumption will increase by the size of the mapped page. In the code, the getpagesize() is used to retrieve the page size. 

- When data is added to the empty page, the RSS (physical memory) consumption will increase since there is now data in the page 