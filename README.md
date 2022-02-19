# so_long 
![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/letumany/so_long)
####  ```and thanks for all the fish```
<img width="1301" alt="so_long" src="https://user-images.githubusercontent.com/73405731/151946959-00fbc806-52c3-45ee-8a1d-42d76e81b453.png">



## Description  
 This project is a very small 2D game. It is built to make you work with
textures, sprites. And some very basic gameplay elements.

## How play the game
To play this game you can use any map of your choice as long follow the following rules:

* The extension need be `.ber`
* Its must be rectangular, surrounded by wall `1`
* Must have only one exit, only one player and at least one collectible
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |


### Control of play
You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT`.  
For restart the game press `ESC` or click on the red cross of window.
To win the game its necessary pick up all collectible and pass for the exit.

### How execute the game
To start the game you need run the command `make` root directory.
This will compile the executable file `so_long`, to execute its necessary run `./so_long map_files/map.ber` or any map of your choice.

## Makefile rules


| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program                |<img width="1301" alt="Screen Shot 2022-02-01 at 13 47 50" src="https://user-images.githubusercontent.com/73405731/151946448-d3656324-0bd4-4ab1-88c2-5830deea016f.png">

## Final grade
<img width="499" alt="Screen Shot 2022-02-06 at 01 29 09" src="https://user-images.githubusercontent.com/73405731/152659675-48c71b58-a809-459d-8ce5-87b5f1dd0835.png">
