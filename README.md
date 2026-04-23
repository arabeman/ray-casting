# Ray-Casting

A raycasting engine with textured walls, sprites, and a minimap.

![demo](demo.gif)

## Authors

- [arabeman](https://github.com/arabeman)
- [NingenUman](https://github.com/NingenUman)

## Build

```bash
make          # builds ray-casting (mandatory)
make bonus    # builds ray-casting_bonus
make re       # clean + rebuild
make fclean   # remove objects + binaries
make wipe_all # removes everything including minilibx-linux clone
```

## Dependencies

- **libft**: Built automatically first (internal library at `libft/`).
- **minilibx-linux**: Cloned from GitHub on first build into `minilibx-linux/`. This is auto-deleted by `wipe_all`.

## Architecture

| Directory | Purpose |
|-----------|---------|
| `src/` | Main game: parsing, window, raycasting, key input |
| `bonus/` | Extended features: minimap, fog, animations, door, viewmodel |
| `inc/` | Headers (`cub3d.h`, `const.h`, `struct.h`) |
| `libft/` | Custom C library (no external dependencies) |

- Entry point: `src/main.c` (mandatory) or `bonus/main_bonus.c`
- Build outputs: `cub3D` and `cub3D_bonus` binaries
- Compiler: `gcc -Wall -Wextra -Werror -g`

## Running

```bash
./cub3D maps/<map_file.cub>
./cub3D_bonus maps/<map_file.cub>
```

## Notes

- No test framework. Validate manually by running with `.cub` map files in `map/`.
- libft bonus (`libft/Makefile bonus:`) is separate from project bonus.
- `wipe_all` removes the minilibx clone - run `make` again to re-clone.