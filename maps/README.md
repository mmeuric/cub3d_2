
## Test related to textures : 

### Working file : 

### Bug in file : 

1.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_bad_extention.cub
2.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_forbidden.cub
3.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_none.cub
4.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_dir.cub
5.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_invalid.cub
6.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_not_xpm.cub
7.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_duplicates.cub
8.	LC_ALL=C valgrind ./cub3D ./maps/bad/textures_S_missing.cub

## Test related to colors : 

### Working file : 

-	LC_ALL=C valgrind ./cub3D ./maps/good/colors_test_1.cub
-	LC_ALL=C valgrind ./cub3D ./maps/good/colors_test_2.cub
-	LC_ALL=C valgrind ./cub3D ./maps/good/colors_test_3.cub


### Bug in file : 

#### 	Duplicated 
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_ceiling_duplicated.cub
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_floor_duplicated.cub

####	Invalid amounts
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_invalid_rgb_amount_nbs.cub

####	Inputed amount
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_invalid_rgb_big_int.cub
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_invalid_rgb_negtive.cub

####	Missing 
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_missing_ceiling_rgb.cub
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_missing.cub
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_missing_floor_rgb.cub
- LC_ALL=C valgrind ./cub3D ./maps/bad/color_none.cub