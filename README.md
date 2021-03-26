# my_crd

write a program to allow storing, deleting and retrieving values associated with keys. Both keys and values are positive, possibly big integers. The program will receive commands and display results.

For that, you must implement a data structure that supports all the operations listed below to execute the commands properly :

Inserting an entry with a key and a value
Removing an entry given its key
Looking up an entry given its key
The program does not take any argument. Commands are read from standard input, and results must be displayed on standard output.
We must be able to compile your program using make: the resulting program must be named my_crd, and must be located at the root of your repository.

The insertion command must obey the following rules:
  . If the key does not already exist, it is inserted
  . If the key already exists, its current value is updated
  . In both cases, the key must be displayed as a result
  Format: <key> <value>
  
The removal command must obey the following rules:
  . If the key exists, it is removed, and its value is displayed as a result
  . If the key does not exist, -1 is displayed as a result
  Format: <key> D

The lookup command must obey the following rules:
  . If the key exists, its value is displayed as a result
  . If the key does not exist, -1 is displayed as a result
  Format: <key>
  
  You can use the following functions and macros: NULL; write; ad; malloc; free; getline
