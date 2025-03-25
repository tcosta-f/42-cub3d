# 42-cub3d
## Group Name: Cub3D³

## Group:

- Bruno Almeida
- Tiago Sousa

## Usage:

`./cub3d map_file`

## Check Leaks:

`valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all`

## Cub3D Task List:

TODO

## Cub3D Test List:

TODO

## Cub3D tester:

TODO

## Basic Steps to Build the Thing:
1. Checking and Parsing
   1. Check first character. If inside scope (NO, SO, WE, EA, C, F, space) ok. If not, set error, exit.
   2. If space comes before any of these, possible map detected before configs, set error, exit.
   3. Check if we have duplicated Key. If so, set error, exit.
   4. Check any line for invalid character or key. If line starts with space before we got all keys, set error, exit.
   5. After a configuration key, ignore all spaces. Validate value.
   6. 1. Is it a file? Check:
         - Valid Filename;
         - File Access;
         - Are spaces AFTER the configuration info?
         - Texture is valid? Can be stored as an Image in MinilibX?
         - If any set error, exit.
      2. Is it color? Check:
         - Are all 3 values inside RGB values (between 0 and 255), with no spaces between them?
   7. Parse Map.
   8. Check if map:
      - Has any invalid chars. Anything apart from ' ', 1, 0, N, S, E, W is invalid;
      - Is surrounded by walls;
      - Has player;
      - All white spaces inside the map are surrounded by walls;
      - Has no empty lines between it.
2. Setup Window
   - Open window in a size (let's look for the size in Wolf3D. I think it was 320x240)
3. Start Game Loop
   - Draw screen
   - update values
   - update screen
4. Gracefully shutdown (Free everything)
   - destroy structures
   - free everything

## Research
### Theory
- [Raycasting 1](https://lodev.org/cgtutor/raycasting.html)
- [Raycasting 2](https://lodev.org/cgtutor/raycasting2.html)
- [Raycasting 3](https://lodev.org/cgtutor/raycasting3.html)
- [Raycasting 4](https://lodev.org/cgtutor/raycasting4.html)

## Tutorial
https://github.com/gleal42/cub3d
https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/
https://hackmd.io/@nszl/H1LXByIE2
https://gitlab.com/madebypixel02/cub3d
