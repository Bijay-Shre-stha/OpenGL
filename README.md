
# Install GLFW and GLEW

+ GLFW
  + Download GLFW from [here](https://www.glfw.org/download.html)
  + Extract the downloaded file
  + Copy folder to `C:\glfw-3.4.bin.WIN32\`

+ GLEW
  + Download GLEW from [here](http://glew.sourceforge.net/)
  + Extract the downloaded file
  + Copy folder to `C:\glew-2.1.0\`


# Create .vscode Folder in the Project Directory
- create `c_cpp_properties.json` file
- create `tasks.json` file

# Create Project Directory
+ copy the `main.cpp` file to the project directory


# c_cpp_properties.json


```json
{
  "configurations": [
    {
      "name": "windows-gcc-x86",
      "includePath": [
        "${workspaceFolder}/**"
      ],
      "compilerPath": "C:/MinGW/bin/gcc.exe",
      "cStandard": "${default}",
      "cppStandard": "${default}",
      "intelliSenseMode": "windows-gcc-x86",
      "compilerArgs": [
        ""
      ]
    }
  ],
  "version": 4
}
```

# tasks.json

```json
{
    "tasks": [
        {
            "label": "C/C++: gcc.exe build active file",
            "type": "cppbuild",
            "command": "C:/MinGW/bin/gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe",
                "-I",
                "C:\\glfw-3.4.bin.WIN32\\include",
                "-I",
                "C:\\glew-2.1.0\\include",
                "-L",
                "C:\\glew-2.1.0\\lib\\Release\\x64",
                "-L",
                "C:\\glfw-3.4.bin.WIN32\\lib-mingw-w64",
                "-lglfw3dll",
                "-lglew32",
                "-lopengl32",
            ],
            "options": {
                "cwd": "C:/MinGW/bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task generated by Debugger."
        }
    ],
    "version": "2.0.0"
}
```


# Code Runner Execution Map

```json
"cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -I C:\\glfw-3.4.bin.WIN32\\include -I C:\\glew-2.1.0\\include -L C:\\glew-2.1.0\\lib\\Release\\x64 -L C:\\glfw-3.4.bin.WIN32\\lib-mingw-w64 -lglfw3dll -lglew32 -lopengl32 && ./$fileNameWithoutExt",
````




# Additional Driver

+ Add `glfw3.dll` to the project directory from `C:\glfw-3.4.bin.WIN32\lib-mingw-w64`


# Run the Code



- Open the project directory in the terminal
- Run the following command
```bash
g++ main.cpp -o main -I C:\glfw-3.4.bin.WIN32\include -I C:\glew-2.1.0\include -L C:\glew-2.1.0\lib\Release\x64 -L C:\glfw-3.4.bin.WIN32\lib-mingw-w64 -lglfw3dll -lglew32 -lopengl32 && ./main
```

# Output
![alt output](image.png)

# Contributors
- -Bijay Shrestha ([GitHub](https://github.com/Bijay-Shre-stha)), March-2024
