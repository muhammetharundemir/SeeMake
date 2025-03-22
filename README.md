# SeeMake
Create CMakeLists.txt file with one line command

## Installation
Clone the repository:
```bash
git clone https://github.com/muhammetharundemir/SeeMake.git
```

Change to the directory:
```bash
cd SeeMake/
```

## Usage
Copy "SeeMake" file and paste it in the directory you are working in.  

  
Then, go to the directory you are working in via the terminal.  

  
Create CMakeLists.txt file:
```bash
./SeeMake <output-file-name> <cpp-version-number>
```
For help:
```bash
./SeeMake -h
```

Example-1:  

  
→  Output File Name: myRunFile  

  
→  C++ Version: C++17  

  
```bash
./SeeMake myRunFile 17
``` 

Example-2:  

  
→  Output File Name: main  

  
→  C++ Version: C++20  

  
```bash
./SeeMake
```

  
After CMakeLists.txt created:
```bash
cmake -B build && cmake --build build
```
  
Then you have output file in build folder.

## Note
If you want to create SeeMake run file. You can use this code:
```bash
cd SeeMake/
g++ src/main.cpp src/seeMake.cpp -std=c++20 -I include -o SeeMake
```

## Contributing
We welcome contributions from the community. If you'd like to contribute, please fork the repository and submit a pull request.