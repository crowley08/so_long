/*La Minilibx est une bibliothèque graphique minimaliste souvent utilisée pour créer des applications graphiques en langage C, principalement sur macOS. Voici comment vous pourriez gérer la fenêtre en utilisant la Minilibx :

1. **Initialisation de la fenêtre** : La Minilibx fournit une fonction `mlx_init()` pour initialiser la connexion avec le serveur graphique.

2. **Création de la fenêtre** : Utilisez la fonction `mlx_new_window()` pour créer une nouvelle fenêtre. Vous devez fournir des paramètres tels que la largeur, la hauteur et le titre de la fenêtre.

3. **Gestion des événements** : La Minilibx ne fournit pas de boucle d'événements intégrée. Vous devez gérer les événements système directement. Par exemple, vous pouvez utiliser la fonction `mlx_loop_hook()` pour spécifier une fonction de rappel qui sera appelée à chaque itération de la boucle principale.

4. **Dessin dans la fenêtre** : Utilisez les fonctions de dessin fournies par la Minilibx, telles que `mlx_pixel_put()` pour dessiner des pixels individuels ou `mlx_string_put()` pour afficher du texte.

5. **Mise à jour de la fenêtre** : Vous pouvez utiliser la fonction `mlx_put_image_to_window()` pour afficher une image ou une texture dans la fenêtre. Assurez-vous d'appeler `mlx_loop()` pour commencer la boucle principale du programme.

Voici un exemple minimal de gestion de fenêtre en utilisant la Minilibx :

```c*/
#include "./minilibx-linux/mlx.h"

int main() {
    void *mlx;
    void *win;

    // Initialisation de la connexion avec le serveur graphique
    mlx = mlx_init();

    // Création de la fenêtre
    win = mlx_new_window(mlx, 800, 600, "Ma Fenêtre");

    // Boucle principale du programme
    mlx_loop(mlx);

    return 0;
}
/*```

Ce code crée simplement une fenêtre de 800x600 pixels intitulée "Ma Fenêtre". Pour ajouter des fonctionnalités comme le dessin, la gestion des événements, etc., vous devrez ajouter du code supplémentaire en utilisant les fonctions fournies par la Minilibx.*/
