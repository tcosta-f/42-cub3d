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

### A. Project Setup & Preparation
- Set up your project repository, Makefile, and libft integration
- Configure the miniLibX (MLX) library

### B. Parsing & Configuration (Parser)

#### 1. File Reading & Input Validation
- Open the `.cub` file passed as an argument  
- Read the file contents and split into lines

#### 2. Parsing Configuration Elements
- Parse texture identifiers (`NO`, `SO`, `WE`, `EA`) and validate file paths  
- Parse floor (`F`) and ceiling (`C`) colors: split the comma‑separated values and verify they lie within `[0,255]`  
- Verify that no required element is missing

#### 3. Map Parsing & Validation
- Identify the map part (after all config elements)  
- Ensure the map is composed of valid characters (`0`, `1`, `N`, `S`, `E`, `W`, and space)  
- Validate the map is closed (surrounded by walls)  
- Verify there is exactly one player start position

### C. Environment & Game Initialization

#### 1. Window & Graphics Setup
- Open a window with miniLibX  
- Set up image buffers and load textures

#### 2. Game Variables Initialization
- Set the player’s position, orientation, and movement parameters  
- Prepare color values for floor and ceiling

### D. Ray Casting Engine & Rendering

#### 1. Ray Casting Algorithm
- Calculate rays for each screen column  
- Detect wall hits and compute distances

#### 2. Wall Rendering
- Draw textured vertical stripes scaled by distance

#### 3. Floor & Ceiling Rendering
- Fill floor and ceiling with colors (or textures)

### E. Event Handling & Player Movement

#### 1. Input Handling
- Handle `W`, `A`, `S`, `D` for movement and arrow keys for rotation  
- Handle `ESC` key and window close (red‑cross) events

#### 2. Collision Detection
- Prevent movement through walls  
- Handle diagonal or high‑speed movement edge cases

### F. Error Handling & Clean‑up
- Free all dynamic memory (maps, textures, etc.)  
- Implement graceful exit routines (close window, free resources)

### G. Bonus Features (Optional)
- Add a minimap to display the player’s position  
- Implement animated sprites or doors  
- Add mouse‑based rotation


## Cub3D Test List:

### 1. Parser Edge Cases

- **Missing Configuration Data**  
  - `.cub` file without one or more texture identifiers (`NO`, `SO`, `WE`, `EA`)  
  - Missing floor (`F`) or ceiling (`C`) color definitions  

- **Syntax & Format Errors**  
  - Extra spaces or missing commas in color definitions  
  - Invalid identifiers or mixed characters  

- **Map Specific Cases**  
  - Map not enclosed by walls (open map)  
  - Multiple starting positions or none at all  

- **File Issues**  
  - Wrong file extension (not `.cub`) or empty file  
  - Elements out of expected order  

- **Duplicate or Unexpected Data**  
  - Duplicate definitions for a single element (e.g., two `NO` lines)  
  - Extra lines after the map  

### 2. Game Edge Cases

#### 2.1 Ray Casting & Rendering

- **Boundary Cases**  
  - Player standing extremely close to a wall (avoid division by zero)  
  - Very narrow corridors or tiny map rooms  

- **Texture Issues**  
  - Missing or unreadable texture files  
  - Odd texture dimensions (non‑power‑of‑two, very large)  

- **Screen Edge Artifacts**  
  - Extreme rotation angles causing rendering glitches  

#### 2.2 Player Movement & Collision

- **Collision Detection**  
  - Moving into walls at various angles  
  - High‑speed movement clipping through walls  

- **Input Handling**  
  - Simultaneous key presses (e.g., rotate + move)  
  - Moving at map corners or edges  

#### 2.3 Window & Event Handling

- **Window Events**  
  - Minimizing, maximizing, or dragging the window during play  
  - Clicking the close button (red cross)  

- **Performance & Resources**  
  - Memory leaks when reloading scenes or textures  
  - Frame rate drops on complex maps  


## Basic Steps to Build the Thing:
1. Checking and Parsing
   1. ✅Check first character. If inside scope (NO, SO, WE, EA, C, F, space) ok. If not, set error, exit.
   2. ✅If space comes before any of these, possible map detected before configs, set error, exit.
   3. ✅Check if we have duplicated Key. If so, set error, exit.
   4. ✅Check any line for invalid character or key. If line starts with space before we got all keys, set error, exit.
   5. ✅After a configuration key, ignore all spaces. Validate value.
   6. 1. ✅Is it a file? Check:
         - ✅Valid Filename;
         - ✅File Access;
         - ✅Are spaces AFTER the configuration info?
         - ✅Texture is valid? Can be stored as an Image in MinilibX?
         - ✅If any set error, exit.
      2. ✅Is it color? Check:
         - ✅Are all 3 values inside RGB values (between 0 and 255), with no spaces between them?
   7. ✅Parse Map.
   8. Check if map:
      - ✅Has any invalid chars. Anything apart from ' ', 1, 0, N, S, E, W is invalid;
      - Is surrounded by walls;
      - Has player;
      - Has more than 1 player;
      - If player is inside walls, without empty spaces around it.
      - All white spaces inside the map are surrounded by walls;
      - ✅Has no empty lines between it.
      - No player or 0 can be near a ' ' (space);
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
