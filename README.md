# so_long  

so_long is a 2D game project written in C, using the **MLX42** library for graphics rendering. The goal of the project is to create a simple game where the player collects items, avoids obstacles, and reaches an exit. It showcases fundamental concepts of game development, including rendering, player input, and collision detection.

## How It Works  
1. **Game Map**  
   - The game is initialized with a map provided as a `.ber` file. The map defines walls, collectibles, the player’s starting position, and the exit.  
   - The map is validated to ensure it meets specific criteria (e.g., rectangular shape, valid characters, at least one collectible and one exit).  

2. **Rendering**  
   - The game world is rendered using the **MLX42** library, with sprites representing walls, the player, collectibles, and the exit.  

3. **Player Movement**  
   - The player moves using the keyboard (e.g., `W`, `A`, `S`, `D` for up, left, down, and right). Movement is restricted to valid tiles (e.g., no walking through walls).  

4. **Game Logic**  
   - The player must collect all collectibles before they can exit the level.  
   - The game tracks the number of moves the player has made, which is displayed on the screen.  

5. **Error Handling**  
   - The program handles invalid maps, file errors, and incorrect configurations gracefully by displaying appropriate error messages and exiting cleanly.  

## What I Learned  
- Fundamentals of 2D game development, including sprite rendering and movement.  
- How to use the **MLX42** library for creating graphical applications.  
- Techniques for parsing and validating input files (e.g., game maps).  
- Implementing collision detection and simple game mechanics.  
- Debugging graphical applications and handling edge cases like invalid input or unexpected behavior.  
