/*Dans la Minilibx, vous pouvez choisir les couleurs en utilisant la structure `t_color`, et vous pouvez afficher des textures ou des images en utilisant des images au format XPM. Voici comment vous pouvez faire ces deux choses :

### Choix des couleurs :

Pour choisir une couleur, vous utilisez une structure `t_color` qui contient les valeurs RGB (rouge, vert, bleu) de la couleur que vous souhaitez utiliser.

Exemple de création d'une couleur rouge :

```c*/
typedef struct  s_color
{
    int r;
    int g;
    int b;
}               t_color;

t_color red_color;

red_color.r = 255;
red_color.g = 0;
red_color.b = 0;
/*```

### Affichage des textures ou des images :

Pour afficher des textures ou des images, vous pouvez les charger au format XPM. Les images XPM sont essentiellement des tableaux de chaînes de caractères qui représentent les pixels de l'image.

Exemple de définition d'une image XPM :

```c
char *image[] = {
    "40 40 2 1",
    "   c #000000",
    ".  c #FFFFFF",
    "                                        ",
    "                                        ",
    "                                        ",
    "                      ........          ",
    "                   ..........          ",
    "                .............          ",
    "              ..............          ",
    "            ..............            ",
    "          ...............             ",
    "         ..............               ",
    "       .............                 ",
    "      ............                   ",
    "     ...........                     ",
    "    ..........                       ",
    "   ..........                        ",
    "  ..........                          ",
    " ..........                           ",
    " ..........                           ",
    " ..........                           ",
    " ..........                           ",
    " ..........                           ",
    " ...........                          ",
    "  ..........                          ",
    "   ..........                         ",
    "    .............                     ",
    "     .............                    ",
    "      .............                   ",
    "       ..............                 ",
    "         ...............              ",
    "           ..............             ",
    "             ..............           ",
    "               ...............        ",
    "                 ...............      ",
    "                   ...............    ",
    "                     ..............   ",
    "                       .............. ",
    "                          ............",
    "                            ........ .",
    "                                      "};

```

Vous pouvez ensuite utiliser `mlx_string_put()` pour afficher cette image à l'écran en spécifiant les coordonnées x et y où vous voulez que l'image apparaisse.

```c
mlx_string_put(mlx, win, x, y, 0xFFFFFF, image);
```

Cela affichera l'image dans la fenêtre `win` aux coordonnées `x` et `y`, avec une couleur de fond noire (0x000000) et une couleur de premier plan blanche (0xFFFFFF).

En combinant ces techniques, vous pouvez choisir des couleurs et afficher des textures ou des images dans votre application graphique avec la Minilibx.*/
