/*Dans la Minilibx, la gestion des événements se fait en utilisant la fonction `mlx_hook()`. Cette fonction permet de définir des fonctions de rappel (callback) qui seront appelées lorsqu'un événement spécifique se produit. Voici comment vous pouvez gérer les événements avec la Minilibx :

1. **Définition des fonctions de rappel** : Vous devez définir des fonctions de rappel pour chaque type d'événement que vous souhaitez gérer, tels que les clics de souris, les mouvements de souris, les pressions de touches, etc.

2. **Enregistrement des fonctions de rappel** : Utilisez `mlx_hook()` pour associer chaque fonction de rappel à l'événement correspondant. Vous devez fournir des paramètres tels que l'identifiant de la fenêtre, le type d'événement et la fonction de rappel à appeler.

3. **Boucle principale du programme** : Utilisez `mlx_loop()` pour démarrer la boucle principale du programme, où les événements seront traités et les fonctions de rappel seront appelées en conséquence.

Voici un exemple simple de gestion des événements de souris et de clavier avec la Minilibx :

```c*/
#include "mlx.h"
#include <stdio.h>

// Fonction de rappel pour les clics de souris
int mouse_click(int button, int x, int y, void *param) {
    printf("Clic de souris : bouton %d, position (%d, %d)\n", button, x, y);
    return 0;
}

// Fonction de rappel pour les pressions de touche
int key_press(int keycode, void *param) {
    printf("Touche pressée : code %d\n", keycode);
    return 0;
}

int main() {
    void *mlx;
    void *win;

    // Initialisation de la connexion avec le serveur graphique
    mlx = mlx_init();

    // Création de la fenêtre
    win = mlx_new_window(mlx, 800, 600, "Gestion des événements");

    // Enregistrement des fonctions de rappel pour les événements de souris et de clavier
    mlx_hook(win, 2, 1L<<0, key_press, NULL); // 2 pour key_press
    mlx_hook(win, 4, 1L<<2, mouse_click, NULL); // 4 pour mouse_click

    // Boucle principale du programme
    mlx_loop(mlx);

    return 0;
}
/*```

Dans cet exemple, les fonctions `key_press` et `mouse_click` sont définies comme des fonctions de rappel pour les pressions de touche et les clics de souris respectivement. Ensuite, ces fonctions sont enregistrées avec `mlx_hook()` pour être appelées lors des événements correspondants (clic de souris ou pression de touche). La boucle principale du programme est ensuite démarrée avec `mlx_loop()`, ce qui permet à votre programme de rester actif et de gérer les événements en continu.*/
